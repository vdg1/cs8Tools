#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qxtcsvmodel.h"

#include <QDateTime>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include <QSqlRecord>
#include <QStandardPaths>
#include <QSystemTrayIcon>
#include <QTimer>

#include <../common/aboutdialog.h>
#include <../common/cs8checkupdate.h>
#include <../common/databaseconnection.h>
#include <../common/dialogmachinecatalogueimportconfiguration.h>
#include <../common/machinecatalogue.h>
#include <../common/vpnconnectivity.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  // start
  createDBConnection();

  ui->setupUi(this);
  watcher = new QFileSystemWatcher(this);
  connect(watcher, &QFileSystemWatcher::fileChanged, this,
          &MainWindow::updateCatalogue);

  m_checkUpdate = new cs8CheckUpdate(this);
  m_checkUpdate->enableRegularCheck(600);
  connect(m_checkUpdate, &cs8CheckUpdate::checkCompleted, this,
          &MainWindow::slotUpdateCheckFinished);
  QTimer::singleShot(100, m_checkUpdate, SLOT(checkForUpdates()));

  createActions();
  createTrayIcon();
  restoreSettings();

  // qxtLog->addLoggerEngine( "logger", new QxtBasicFileLoggerEngine( m_appData
  // + "/cs8BackSync.log" ) );  qxtLog->info( "cs8BackupSync started" );

  // trayIcon->showMessage(tr("CS8 Backup & Logging Tools Sync started"),
  // tr(""), QSystemTrayIcon::Information, 5);

  pollTimer = new QTimer(this);
  pollTimer->start(60000);
  connect(pollTimer, &QTimer::timeout, this, &MainWindow::pollData);
  pollData();
  checkAutoStart();

  // check if about dialog shall be shown for first time after update
  QSettings settings;
  if (settings.value("cs8BackupSync/releaseNotes", "").toString() !=
      qApp->applicationVersion()) {
    on_actionAbout_triggered();
    settings.setValue("cs8BackupSync/releaseNotes", qApp->applicationVersion());
  }
}

MainWindow::~MainWindow() {
  // qxtLog->info() << "cs8BackupSync ended";
  delete ui;
}

void MainWindow::on_actionAbout_triggered() {
  aboutDialog widget(":/files/releasenotes.txt", this);
  widget.exec();
}

void MainWindow::on_actionAbout_Qt_triggered() { qApp->aboutQt(); }

void MainWindow::changeEvent(QEvent *e) {
  QMainWindow::changeEvent(e);
  switch (e->type()) {
  case QEvent::LanguageChange:
    ui->retranslateUi(this);
    break;
  default:
    break;
  }
}

void MainWindow::handleMessage(const QString &message) {
  enum Action { Nothing, Open, Quit } action;

  action = Nothing;
  qDebug() << "handle message: " << message.toLower();
  if (message.toLower().startsWith(QStringLiteral("/quit"))) {
    action = Quit;
  } else if (!message.isEmpty()) {
    action = Open;
  }
  if (action == Nothing) {
    emit needToShow();
    return;
  }

  switch (action) {
  case Quit: {
    qApp->quit();
  } break;

  case Open: {
    emit needToShow();
  } break;
  default:
    break;
  };
}

void MainWindow::restoreSettings() {
  QSettings settings;
  ui->cbEnableCatalogueImport->blockSignals(true);
  ui->cbEnableSync->blockSignals(true);
  ui->cbAvoidVpn->blockSignals(true);
  ui->leCatalogueFile->blockSignals(true);
  ui->leRemotePath->blockSignals(true);
  ui->leMaintainer->blockSignals(true);
  ui->cbAutoStart->blockSignals(true);

  ui->cbAutoStart->setChecked(settings.value("autoStart", true).toBool());
  ui->cbEnableSync->setChecked(settings.value("enableSync", true).toBool());
  ui->cbAvoidVpn->setChecked(settings.value("avoidVPNSync", true).toBool());
  ui->leRemotePath->setText(QDir::toNativeSeparators(
      settings.value("remotePath", QString::fromUtf8("S:/Service/RobotBackups"))
          .toString()));
  ui->cbEnableCatalogueImport->setChecked(
      settings.value("enableCatalogueImport", true).toBool());
  ui->leCatalogueFile->setText(QDir::toNativeSeparators(
      settings
          .value("catalogueFile",
                 QString::fromUtf8("S:/Service/RobotBackups/Catalogue.xlsx"))
          .toString()));
  ui->leMaintainer->setText(settings.value("maintainer").toString());
  ui->leCatalogue_URL->setText(settings.value("catalogueURL").toString());

  ui->leMaintainer->blockSignals(false);
  ui->cbEnableCatalogueImport->blockSignals(false);
  ui->cbEnableSync->blockSignals(false);
  ui->leCatalogueFile->blockSignals(false);
  ui->leRemotePath->blockSignals(false);
  ui->cbAvoidVpn->blockSignals(false);
  ui->cbAutoStart->blockSignals(false);
}

void MainWindow::saveSettings() {
  QSettings settings;
  settings.setValue("enableSync", ui->cbEnableSync->isChecked());
  settings.setValue("avoidVPNSync", ui->cbAvoidVpn->isChecked());
  settings.setValue("remotePath", ui->leRemotePath->text());
  settings.setValue("enableCatalogueImport",
                    ui->cbEnableCatalogueImport->isChecked());
  settings.setValue("catalogueFile", ui->leCatalogueFile->text());
  settings.setValue("catalogueURL", ui->leCatalogue_URL->text());
  settings.setValue("maintainer", ui->leMaintainer->text());
  settings.setValue("autoStart", ui->cbAutoStart->isChecked());
}

void MainWindow::createTrayIcon() {
  trayIconMenu = new QMenu(this);
  // trayIconMenu->addAction(minimizeAction);
  // rayIconMenu->addAction(maximizeAction);
  trayIconMenu->addAction(restoreAction);
  trayIconMenu->addAction(updateAction);
  trayIconMenu->addSeparator();
  trayIconMenu->addAction(quitAction);

  trayIcon = new QSystemTrayIcon(this);
  trayIcon->setContextMenu(trayIconMenu);

  QIcon icon;
  icon.addFile(":/icons/resource/logo.png");
  if (icon.isNull())
    qDebug() << "System tray icon could not be loaded";

  trayIcon->setIcon(icon);
  trayIcon->show();
  trayIcon->setToolTip(tr("cs8 Backup & Logging Tools Sync"));
  setWindowIcon(icon);

  connect(trayIcon, &QSystemTrayIcon::activated, this,
          &MainWindow::iconActivated);
}

void MainWindow::createActions() {
  restoreAction = new QAction(tr("&Open Settings"), this);
  connect(restoreAction, &QAction::triggered, this, &QWidget::showNormal);

  quitAction = new QAction(tr("&Quit"), this);
  connect(quitAction, &QAction::triggered, this, &MainWindow::slotAskToQuit);

  updateAction = new QAction(tr("Check for updates"), this);
  connect(updateAction, &QAction::triggered, this,
          &MainWindow::slotCheckUpdate);
}

void MainWindow::checkAutoStart() {
  QSettings settings;
  QString appName = QApplication::applicationName();
  QString path = QApplication::applicationFilePath();
  QSettings regSettings(
      "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run",
      QSettings::NativeFormat);
  if (settings.value("autoStart", true).toBool())
    regSettings.setValue(appName, path.replace('/', '\\'));
  else
    regSettings.remove(appName);
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason) {
  switch (reason) {
  case QSystemTrayIcon::Trigger:
  case QSystemTrayIcon::DoubleClick:
    break;
  case QSystemTrayIcon::MiddleClick:
    break;
  default:;
  }
}

void MainWindow::slotUpdateCheckFinished(const QStringList &updates,
                                         const QStringList &versions,
                                         bool error) {
  if (!error && updates.count() != 0)
    trayIcon->showMessage(tr("cs8Tools Update"), tr("Updates available!"));
}

void MainWindow::on_pbRemotePathBrowse_clicked() {
  QString path;
  path = QFileDialog::getExistingDirectory(
      this, tr("Select remote location of backup storage"),
      ui->leRemotePath->text());
  if (!path.isEmpty()) {
    ui->leRemotePath->setText(QDir::toNativeSeparators(path));
    saveSettings();
  }
}

void MainWindow::on_pbCatalogueFileBrowse_clicked() {
  QString fileName;
  fileName = QFileDialog::getOpenFileName(this, tr("Select catalogue file"),
                                          ui->leCatalogueFile->text(),
                                          tr("Table (*.xlsx)"));
  if (!fileName.isEmpty()) {
    ui->leCatalogueFile->setText(QDir::toNativeSeparators(fileName));
    saveSettings();
  }
}

void MainWindow::on_cbEnableCatalogueImport_toggled(bool /*checked*/) {
  saveSettings();
}

void MainWindow::on_cbEnableSync_toggled(bool /*checked*/) { saveSettings(); }

void MainWindow::syncBackupsToRemote() {
  bool vpnActive = vpnConnectivity::online();
  if (ui->cbEnableSync->isChecked() &&
      ((vpnActive && !ui->cbAvoidVpn->isChecked()) || !vpnActive)) {
    QSettings settings;
    QDateTime lastUpdate = settings.value("lastSync").toDateTime();
    QDateTime lastBackup = settings.value("lastBackup").toDateTime();
    QString remotePath = ui->leRemotePath->text();
    QFileInfo remotePathInfo(remotePath);

    if (remotePathInfo.exists() &&
        ((lastBackup > lastUpdate) || !lastUpdate.isValid())) {
      QSqlTableModel table;
      table.setTable("backupData");
      table.select();
      // qxtLog->info() << "Backup log contains " << model.rowCount() << "rows";
      for (int row = 0; row < table.rowCount(); row++) {
        QSqlRecord record = table.record(row);
        //"`ctrlSerial`	varchar,"
        //"`backupDir`	varchar,"
        //"`backupName`	varchar,"
        //"`createdOn`  varchar,"
        //"`archived`	INTEGER"
        QString backupName = record.value("backupName").toString();
        QString basePath = record.value("backupDir").toString();
        bool synced = record.value("archived").toInt() == 1;

        // qxtLog->info() << backupName << " synced: " << synced;
        // only sync if base path is part of backup path
        if (!synced && backupName.indexOf(basePath) == 0) {
          QFileInfo fileInfo;
          fileInfo.setFile(backupName);
          if (fileInfo.exists() && fileInfo.suffix() == "zip") {
            QString relFilePath = backupName;
            relFilePath.remove(0, basePath.length());
            // qxtLog->info() << "sync Backup: " << relFilePath;

            trayIcon->showMessage(tr("Syncing"),
                                  tr("Backup: %1").arg(relFilePath));
            QFile f(backupName);
            QString dest = remotePath + relFilePath;
            do {
              fileInfo.setFile(dest);
              if (fileInfo.exists()) {
                QString n = fileInfo.baseName();
                QRegExp rx("#(\\d)*");
                if (n.contains(rx)) {
                  rx.indexIn(n);
                  int id = rx.cap(0).remove(0, 1).toInt();
                  n.chop(rx.matchedLength());
                  id++;
                  n += QString("#%1").arg(id);
                } else {
                  n.append("#1");
                }
                dest =
                    fileInfo.absolutePath() + "/" + n + "." + fileInfo.suffix();
                // qxtLog->info() << "sync Backup: " <<
                // fileInfo.absoluteFilePath() << "already exist - set dest to "
                // << dest;
                fileInfo.setFile(dest);
              }
            } while (fileInfo.exists());

            QDir d;
            d.mkpath(fileInfo.absolutePath());
            if (f.copy(dest)) {
              // qxtLog->info() << "sync Backup: " <<
              // fileInfo.absoluteFilePath() << "complete";
              record.setValue("archived", 1);
              if (!table.setRecord(row, record))
                qDebug() << "Failed to update backup log";
            } else {
              trayIcon->showMessage(tr("Syncing"),
                                    tr("Error: %1").arg(f.errorString()),
                                    QSystemTrayIcon::Critical);
              // qxtLog->error() << "sync Backup: " <<
              // fileInfo.absoluteFilePath() << "failed:" << f.errorString();
            }
            qDebug() << f.errorString();
          } else {
            if (!fileInfo.exists())
              trayIcon->showMessage(tr("Syncing"),
                                    tr("Error: %1: %2")
                                        .arg(tr("The backup does not exists!"))
                                        .arg(backupName),
                                    QSystemTrayIcon::Critical);
          }
        }
      }
      /// TODO commit changes?
      settings.setValue("lastSync",
                        QDateTime::currentDateTime().toString(Qt::ISODate));
      // touch a file to indicate this is the sync directory
      QFile file(remotePath + "/.sync");
      if (file.open(QIODevice::WriteOnly)) {
        // created sync file
      }
      // qxtLog->info() << "Sync complete at: " << QDateTime::currentDateTime();
    }
  }
}

void MainWindow::pollData() {
  updateCatalogue();
  syncBackupsToRemote();
}

void MainWindow::updateCatalogue() {
  if (ui->cbEnableCatalogueImport->isChecked()) {
    QSettings settings;
    QDateTime lastUpdate = settings.value("lastCatalogueImport").toDateTime();
    QFileInfo remoteFileInfo(ui->leCatalogueFile->text());
    machineCatalogue catalogue;
    qDebug() << "remote catalogue: " << remoteFileInfo.absoluteFilePath()
             << " exists: " << remoteFileInfo.exists()
             << " modified: " << remoteFileInfo.lastModified().toString()
             << " last update: " << lastUpdate.toString();
    if (remoteFileInfo.exists() &&
        ((remoteFileInfo.lastModified() > lastUpdate) ||
         !lastUpdate.isValid() || catalogue.entries() == 0)) {
      // qxtLog->info() << "Importing new machine catalogue";
      trayIcon->showMessage(tr("New Machine Catalogue detected"),
                            tr("Importing the new machine catalogue"));

      if (!catalogue.importFile(remoteFileInfo.absoluteFilePath())) {
        QMessageBox::critical(this, tr("CS8Backup Catalogue Update"),
                              tr("The import of the new catalogue failed!"),
                              QMessageBox::Ok);
      } else {
        trayIcon->showMessage(tr("New Machine Catalogue detected"),
                              tr("Import complete!"));
        settings.setValue("lastCatalogueImport",
                          QDateTime::currentDateTime().toString(Qt::ISODate));
      }
    }
  }
}

void MainWindow::slotAskToQuit() {
  if (QMessageBox::question(this, tr("CS8Backup Sync"),
                            tr("Are you sure you want to quit CS8Backup Sync?"),
                            QMessageBox::Yes | QMessageBox::No) ==
      QMessageBox::Yes) {
    qApp->quit();
  }
}

void MainWindow::on_leCatalogueFile_textChanged(const QString & /*arg1*/) {
  // watcher->addPath (ui->leCatalogueFile->text ());
}

void MainWindow::on_cbAvoidVpn_toggled(bool /*checked*/) { saveSettings(); }

void MainWindow::on_leMaintainer_editingFinished() { saveSettings(); }

void MainWindow::on_pbConfigureImport_clicked() {
  DialogMachineCatalogueImportConfiguration dlg(this,
                                                ui->leCatalogueFile->text());
  dlg.exec();
}

void MainWindow::slotCheckUpdate() {
  m_checkUpdate->checkForUpdates(true, true);
}

void MainWindow::on_cbAutoStart_toggled(bool /*checked*/) {
  saveSettings();
  checkAutoStart();
}

void MainWindow::on_leCatalogue_URL_editingFinished() { saveSettings(); }
