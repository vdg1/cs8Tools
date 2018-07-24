/****************************************************************************
**
** Copyright (C) 2004-2006 Trolltech AS. All rights reserved.
**
** This file is part of the example classes of the Qt Toolkit.
**
** This file may be used under the terms of the GNU General Public
** License version 2.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of
** this file.  Please review the following information to ensure GNU
** General Public Licensing requirements will be met:
** http://www.trolltech.com/products/qt/opensource.html
**
** If you are unsure which license is appropriate for your use, please
** review the following information:
** http://www.trolltech.com/products/qt/licensing.html or contact the
** sales department at sales@trolltech.com.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#include <QStandardPaths>
#include <QtCore>
#include <QtDebug>
#include <QtGui>
#include <QtNetwork>
#include <QtXml>

#include <QFileDialog>
#include <QInputDialog>
#include <QLineEdit>
#include <QMessageBox>
#include <QProgressDialog>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QWhatsThis>
#include <QWinTaskbarButton>
#include <QWinTaskbarProgress>

#include <../common/aboutdialog.h>
#include <../common/cs8checkupdate.h>
#include <../common/databaseconnection.h>

#include "detailprogressdialog.h"
#include "ftpwindow.h"

#include "backupstorage.h"
#include "downloaddirdialog.h"
#include "getserialnumberdialog.h"
#include "selectbackupfolderdialog.h"
#include "settingsdialog.h"
#include "ui_aboutDialog.h"

#include "cs8ControllerComponent.h"
#include "qftp.h"

#include "dialoggetmachinedata.h"
#include "windows.h"

Q_DECLARE_METATYPE(QUrlInfo *)

void FtpWindow::setupPaths() {
  QSettings setting;
  m_appData = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
  QDir d;
  d.mkpath(m_appData);
  m_defaultDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Staubli/RobotBackups";
  ui.leDownloadDir->setText(
      QDir::toNativeSeparators(setting.value("directories/downloadDir", m_defaultDir).toString()));
  qDebug() << "Generic Data Location: " << QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation);
}

void FtpWindow::restoreWindow() {
  QSettings settings;
  settings.beginGroup("MainWindow");
  restoreGeometry(settings.value("mainWindowGeometry").toByteArray());
  // create docks, toolbars, etc…
  restoreState(settings.value("mainWindowState").toByteArray());
  settings.endGroup();
  readHistory();
}

void FtpWindow::setupUi() {
  QSettings setting;
  ui.checkBoxSys->setChecked(setting.value("defaultSys", true).toBool());
  ui.checkBoxUsr->setChecked(setting.value("defaultUsr", true).toBool());
  ui.checkBoxLog->setChecked(setting.value("defaultLog", true).toBool());
  ui.tableViewDetectedControllers->setModel(m_scanner);
  connect(ui.tableViewDetectedControllers->selectionModel(), &QItemSelectionModel::selectionChanged, this,
          &FtpWindow::slotSelectionChanged);

  QString Octet = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
  QRegExpValidator *validator =
      new QRegExpValidator(QRegExp("^" + Octet + "\\." + Octet + "\\." + Octet + "\\." + Octet + "$"), this);

  ui.leIPAddress->setValidator(validator);
  ui.leIPAddress->setAutoCompletion(true);
  ui.leIPAddress->lineEdit()->setInputMask("000.000.000.000");

  restoreWindow();

  m_transferRateLabel = new QLabel(this);
  statusBar()->addPermanentWidget(m_transferRateLabel);
  statusBar()->showMessage(tr("Disconnected"));

  m_movie = new QMovie();
  m_movie->setFileName(":res/loading19.gif");
  ui.lbScannerStatus->setMovie(m_movie);

  m_progressDialog = new DetailProgressDialog(this);
  connect(m_controller, &cs8Controller::transferProgress, m_progressDialog, &DetailProgressDialog::setDetailProgress);
  // connect( m_progressDialog, &QProgressDialog::canceled, this,
  // &FtpWindow::cancelDownload );

  m_button = new QWinTaskbarButton(this);
  // button->setOverlayIcon(QIcon(":/loading.png"));
}

void FtpWindow::createObjects() {
  createDBConnection();

  m_controller = new cs8Controller();

  m_controller->enableOnlineCheck(true);
  connect(m_controller, &cs8Controller::onlineChanged, this, &FtpWindow::slotOnlineState);
  connect(m_controller, &cs8Controller::transferProgress, this, &FtpWindow::updateDataTransferRate);

  m_scanner = new cs8NetworkScanner(this);
  connect(m_scanner, &cs8NetworkScanner::scannerStarted, this, &FtpWindow::slotScannerStarted);
  connect(m_scanner, &cs8NetworkScanner::scannerStopped, this, &FtpWindow::slotScannerStopped);
  connect(m_scanner, &cs8NetworkScanner::detected, this, &FtpWindow::slotDetected);
  connect(m_scanner, &cs8NetworkScanner::scanCompleted, this, &FtpWindow::slotScanCompleted);
  /// TODO
  QTimer::singleShot(0, m_scanner, SLOT(start()));
}

void FtpWindow::startSyncProcess() {
  QFile f("cs8BackupSync.exe");
  if (f.exists()) {
    QProcess p;
    if (!p.startDetached(f.fileName()))
      QMessageBox::warning(this, tr("CS8 Backup"), tr("Failed to start sycronisation process"), QMessageBox::Ok);
  }
  m_checkUpdate = new cs8CheckUpdate(this);
  QTimer::singleShot(100, m_checkUpdate, SLOT(checkForUpdates()));
}

void FtpWindow::checkDBTables() {
  createDBConnection();

  m_backupDataTable = new QSqlTableModel(this);
  m_backupDataTable->setTable("backupData");
  m_backupDataTable->setEditStrategy(QSqlTableModel::OnFieldChange);
  QSettings settings;
  settings.setValue("lastBackup", QDateTime::currentDateTime().toString(Qt::ISODate));
}

FtpWindow::FtpWindow(QWidget *parent) : QMainWindow(parent), m_progressDialog(0) {
  ui.setupUi(this);

  checkDBTables();

  createObjects();

  setupUi();

  setupPaths();

  startSyncProcess();

  // check if about dialog shall be shown for first time after update
  QSettings settings;
  if (settings.value("cs8Backup/releaseNotes", "").toString() != qApp->applicationVersion()) {
    QTimer::singleShot(0, this, SLOT(on_action_About_triggered()));
    settings.setValue("cs8Backup/releaseNotes", qApp->applicationVersion());
  }
}

void FtpWindow::on_btDownload_clicked() {
  if (ui.leIPAddress->findText(ui.leIPAddress->currentText()) == -1) {
    ui.leIPAddress->insertItem(ui.leIPAddress->count(), ui.leIPAddress->currentText());
  }
  writeHistory();
  QSettings setting;
  setting.setValue("controllers/lastAddress", ui.leIPAddress->lineEdit()->text());

  m_scanner->cancel();
  m_progressDialog->show();
  m_progressDialog->setTotalMaximum(3);
  m_progressDialog->setTotalValue(1);
  m_progressDialog->setDetailText(tr("Connecting..."));
  m_controller->enableOnlineCheck(false);
  m_controller->setAddress(ui.leIPAddress->currentText());
  m_controller->setLoginData(ui.leUserName->text(), ui.lePassword->text());

  m_progressDialog->setTotalValue(2);
  m_progressDialog->setDetailText(tr("Retrieving order number..."));
  m_downloadDir = ui.leDownloadDir->text();
  m_serialNumber = getSerialNumber();

  m_progressDialog->setTotalValue(3);
  statusBar()->showMessage(tr("Connected to %1").arg(m_serialNumber /*leIPAddress->lineEdit() ->text() ) */));
  m_progressDialog->hide();
  QApplication::restoreOverrideCursor();

  downloadFiles();
  m_controller->enableOnlineCheck(true);
  m_scanner->start(true);
}

bool FtpWindow::storeBackupLog(const QString &serialNumber, const QString &backupName, const QString &baseDir) {

  QSqlRecord record = m_backupDataTable->record();
  //"`ctrlSerial`	varchar,"
  //"`backupDir`	varchar,"
  //"`backupName`	varchar,"
  //`createdOn`  varchar,"
  //"`archived`	INTEGER"
  record.setValue("ctrlSerial", serialNumber);
  record.setValue("backupDir", baseDir);
  record.setValue("backupName", backupName);
  record.setValue("createdOn", QDateTime::currentDateTime().toString());
  record.setValue("archived", 0);
  // set base dir
  if (m_backupDataTable->insertRecord(0, record)) {
    qDebug() << "Failed to insert row";
    return false;
  } else
    return true;
}

void FtpWindow::downloadFiles() {
  // ui.connectButton->setEnabled(false);
  ui.btDownload->setEnabled(false);
  QSettings settings;
  saveSettings();
  int i = 0;
  bool ok;
  bool completedWithoutError = true;
  ok = prepareDownload();
  if (ok) {
    // progressDialog->setWindowTitle("CS8 Backup")
    /// TODO: use old time stamp in case of resume

    QString backupName = getBackupName(m_serialNumber);
    QSettings setting;

    m_progressDialog->setTotalMaximum(ui.fileList->count());

    m_button->setWindow(this->windowHandle());
    m_button->progress()->setMaximum(ui.fileList->count());
    m_button->progress()->setVisible(true);
    QString fileName;
    QString lastError;

    int retry = settings.value("automaticRetries", 5).toInt();

    while (ui.fileList->count() > 0) {
      m_progressDialog->setTotalValue(++i);

      m_button->progress()->setValue(i);

      if (!isDirectory[ui.fileList->item(0)->text()]) {
        fileName = ui.fileList->item(0)->text();

        QDir dir;
        QString path;
        QString localFileName = m_downloadDir + "/" + backupName + fileName;
        // path=localFileName.left(path.length()-path.lastIndexOf("/"));
        path = dir.absoluteFilePath(localFileName);
        path = path.remove(path.lastIndexOf("/"), path.length());
        // statusLabel->setText(tr("path %1...").arg(path));

        // make local path
        dir.mkpath(path);

        QFile file;
        QUrl url = m_controller->url();
        url.setPath(fileName);

        m_progressDialog->setDetailText(tr("Downloading %1\n to %2 %3...")
                                            .arg(fileName)
                                            .arg(m_downloadDir + "/" + m_serialNumber + "/" + backupName)
                                            .arg(retry > 0 ? tr(" (Retries left %1) ").arg(retry) : ""));
        m_progressDialog->show();

        // ok = file.copy( url.toString(), localFileName );
        qint64 remoteSize = 0;
        ok = m_controller->downloadFile(fileName, localFileName, remoteSize);
        if (!ok) {
          lastError = m_controller->lastError();
          qDebug() << "transfer failed:" << lastError;
        }
        if (ok) {
          QUrlInfo *infoItem =
              reinterpret_cast<QUrlInfo *>(qvariant_cast<void *>(ui.fileList->item(0)->data(Qt::UserRole)));

          // remoteSize = infoItem->size();
          file.setFileName(localFileName);
          qint64 localSize = file.size();
          // set time stamp
          QSettings settings;
          if (settings.value("preserveTimeStamp", false).toBool()) {
            setFileTimestamp(localFileName, infoItem->lastModified());
          }
          lastError = QString("Remote size: %1 bytes, remote size: %2 bytes.").arg(remoteSize).arg(localSize);
          // ignore file size differences when downlaoding log files (the might
          // grow during backup...)
          ok = (remoteSize == localSize) ||
               (localFileName.contains("errors.log") || localFileName.contains("errors.old"));
        }

        if (!ok) {
          if (retry > 0) {
            retry--;
            // delete local file on retry
            file.remove(localFileName);
          } else {
            switch (QMessageBox::critical(this, tr("Error"),
                                          tr("Downloading the file %1 failed!\n%2").arg(fileName).arg(lastError),
                                          QMessageBox::Retry | QMessageBox::Ignore | QMessageBox::Cancel)) {
            case QMessageBox::Cancel:
              ui.fileList->clear();
              completedWithoutError = false;
              break;

            case QMessageBox::Retry:
              // delete local file on retry
              file.remove(localFileName);
              retry = settings.value("automaticRetries", 5).toInt();
              break;

            case QMessageBox::Ignore:
              ok = true;
              completedWithoutError = false;
              break;

            default:
              break;
            }
          }
        }
      }

      // remove item from list when download of file is completed
      if (ok) {
        QListWidgetItem *item = ui.fileList->takeItem(0);
        delete item;
        retry = settings.value("automaticRetries", 5).toInt();
        statusBar()->showMessage(tr("Downloaded file %1").arg(fileName));
      }
    }

    m_transferRateLabel->setText("");

    m_progressDialog->setTotalText(QLatin1String(""));
    m_progressDialog->hide();
    m_button->progress()->setVisible(false);

    // statusLabel->setText(tr("Backup completed") );
    statusBar()->showMessage(tr("Backup completed"));
    if (completedWithoutError) {
      if (setting.value("profiles/" + ui.leIPAddress->lineEdit()->text() + "/compress", "false").toBool()) {
        connect(&zip, &zipper::compressingFile, this, &FtpWindow::compressingFile);
        connect(&zip, SIGNAL(completed(bool)), this, (SLOT(completed(bool))));
        zip.compressDir(m_downloadDir + "/" + backupName + "/", m_downloadDir + "/" + backupName + ".zip", true);
        storeBackupLog(m_serialNumber, QDir::toNativeSeparators(m_downloadDir + "/" + backupName + ".zip"),
                       ui.leDownloadDir->text());
      }

      QMessageBox::information(this, tr("Backup completed"), tr("Backup has been completed!"));
    } else {
      if (QMessageBox::critical(this, tr("Backup completed with errors"),
                                tr("The backup completed with errors!\n"
                                   "Not all files are successfully downloaded. "
                                   "Do you want to keep the downloaded files?"),
                                QMessageBox::Yes | QMessageBox::No) == QMessageBox::No) {
        // delete local backup files
        QDir dir(m_downloadDir + "/" + backupName);
        dir.removeRecursively();
      }
    }
  }
}

QString FtpWindow::getSerialNumber() {
  QString controllerSerial = m_controller->controllerSerialNumber();
  QString armSerial = m_controller->armSerialNumber();

  QString baseDir;
  if (controllerSerial.isEmpty() && armSerial.isEmpty()) {
    // The orderNumber could not be determined because either options.cfx
    // neither arm.cfx were found or they were found but the orderNumber tag in
    // the file was not set properly.

    bool ok;

    QString text = getSerialNumberDialog::getText(this, &ok);
    if (ok && !text.isEmpty())
      baseDir = text;
    else
      baseDir = tr("Unkown System");
  } else if (controllerSerial.isEmpty() && !armSerial.isEmpty()) {
    // The order number is the serial number of the attached arm. Ask the user
    // to modify the serial number to the serial number of the controller
    bool ok;
    QString text = QInputDialog::getText(this, tr("Controller Serial Number"),
                                         tr("The serial number of the controller could not be determined. "
                                            "However, the serial number of the attached arm was found."
                                            "\nYou can change the serial number manually below:"),
                                         QLineEdit::Normal, armSerial, &ok);
    if (ok && !text.isEmpty())
      baseDir = text;
  } else
    baseDir = controllerSerial;
  return baseDir;
}

QString FtpWindow::orderNumber(const QDomElement &element) {
  for (int i = 0; i < element.elementsByTagName("String").count(); i++) {
    QDomNode node = element.elementsByTagName("String").at(i);
    if (node.toElement().attribute("name") == "orderNumber") {
      // check if orderNumber value is not an empty string
      QString orderNumber = node.toElement().attribute("value");
      if (!orderNumber.isEmpty()) {
        return orderNumber.replace("/", "_");
      }
    }
  }
  // return empty string in case order number could not be determined
  // return ui.leIPAddress->lineEdit()->text();
  return QString();
}

//(.*)(-\\*)

void FtpWindow::cancelDownload() { ui.fileList->clear(); }

void FtpWindow::recursiveList(const QStringList &pathList) {
  foreach (QString path, pathList) {
    QList<QUrlInfo> list;
    m_controller->getFolderContents(path, list);
    /*
     * dir.setPath( QString( "cs8://%1:%2@%3%4" )
                 .arg( ui.leUserName->text() )
                 .arg( ui.lePassword->text() )
                 .arg( ui.leIPAddress->currentText() )
                 .arg( path ) );
       QList<QFileInfo> list = dir.entryInfoList( QDir::AllEntries );
     */
    QStringList pathElements;
    foreach (QUrlInfo info, list) {
      qDebug() << info.name();
      pathElements = info.name().split("/");

      if (pathElements.last() != "." && pathElements.last() != "..") {
        QListWidgetItem *item = new QListWidgetItem;
        QUrlInfo *itemInfo = new QUrlInfo(info);
        QVariant v(QMetaType::VoidStar, &itemInfo);
        item->setData(Qt::UserRole, v);
        item->setText(info.name());
        QPixmap pixmap(!info.isFile() ? ":/images/dir.png" : ":/images/file.png");
        item->setIcon(pixmap);
        statusBar()->showMessage("Adding: " + info.name());
        isDirectory[info.name()] = info.isDir();
        ui.fileList->addItem(item);

        if (info.isDir()) {
          recursiveList(QStringList() << info.name());
        }
        if (!ui.fileList->currentItem()) {
          ui.fileList->setCurrentItem(ui.fileList->item(0));
        }
      }
    }
  }
}

void FtpWindow::updateDataTransferRate(qint64 /*done*/, qint64 /*total*/, qint64 rate) {
  // qDebug() << "rate" << rate << "bytes/sec";
  if (rate != 0) {
    m_transferRateLabel->setText(tr("Transfer Rate %1 KB/s").arg(rate / 1024, 5));
    m_progressDialog->setTotalText(tr("Total Progress (downloading at %1 KB/s):").arg(rate / 1024, 5));
  } else {
    m_transferRateLabel->setText(QLatin1Literal(""));
    // m_progressDialog->setTotalText(QLatin1Literal(""));
  }
}

void FtpWindow::readHistory() {
  QSettings setting;
  QStringList list;
  int size = setting.beginReadArray("history");
  for (int i = 0; i < size; ++i) {
    setting.setArrayIndex(i);
    list.append(setting.value("address").toString());
    // leIPAddress->insertItem( i, setting.value( "address" ).toString() );
  }
  setting.endArray();
  list.sort();
  list.removeDuplicates();
  ui.leIPAddress->insertItems(0, list);
  ui.leIPAddress->setEditText(setting.value("controllers/lastAddress", "localhost").toString());
}

void FtpWindow::writeHistory() {
  QSettings setting;
  setting.remove("history");
  setting.beginWriteArray("history");
  for (int i = 0; i < ui.leIPAddress->count(); ++i) {
    setting.setArrayIndex(i);
    setting.setValue("address", ui.leIPAddress->itemText(i));
  }
  setting.endArray();
}

FtpWindow::~FtpWindow() {
  writeHistory();
  QSettings settings;
  settings.beginGroup("MainWindow");
  settings.setValue("mainWindowGeometry", saveGeometry());
  settings.setValue("mainWindowState", saveState());
  settings.endGroup();
}

bool FtpWindow::prepareDownload() {
  // find existing backups
  // get dirs in download folder
  m_progressDialog->setTotalMaximum(0);
  m_progressDialog->setTotalMinimum(0);
  m_progressDialog->setDetailText(tr("Searching existing backups"));
  m_progressDialog->show();

  QStringList backupList;
  backupStorage storage;
  storage.setStorageBasePath(m_downloadDir);
  storage.setAppDataPath(m_appData);
  backupList = storage.backupSets(m_serialNumber);

  m_progressDialog->hide();

  if (backupList.count() != 0) {
    QString item;
    if (backupList.count() > 1) {
      selectBackupFolderDialog dlg(this, m_serialNumber, backupList);
      dlg.exec();
      item = dlg.selectedBackup();
    } else
      item = backupList.at(0);
    m_downloadDir = QDir::fromNativeSeparators(item);
    m_downloadDir = m_downloadDir.left(item.lastIndexOf(QString("/")));
    // m_serialNumber = item;
    // m_serialNumber=m_serialNumber.remove(0, m_downloadDir.length()+1);
  } else {
    DialogGetMachineData dlg;
    dlg.setSerialNumber(m_serialNumber);
    dlg.remoteCatalogue();
    if (dlg.exec() == QDialog::Accepted) {
      m_downloadDir += dlg.backupPath();
    }
  }

  downloadDirDialog dialog(this, m_serialNumber, m_downloadDir);
  if (!dialog.exec())
    return false;

  // m_serialNumber=dialog.baseDir();
  m_downloadDir = dialog.downloadDir();

  // update storage if a new robot has been added or backup location has been
  // modified by user
  if (backupList.count() == 0)
    storage.updateStorage(true);
  if (dialog.modified())
    storage.addToStorage(m_downloadDir + "/" + dialog.baseDir());

  m_progressDialog->setDetailText(tr("Generating file list..."));
  m_progressDialog->show();

  if (QMessageBox::question(
          this, tr("Confirmation"),
          tr("Do you want to download the backup to\n%1?").arg(QDir::toNativeSeparators(m_downloadDir)),
          QMessageBox::Yes, QMessageBox::Cancel, QMessageBox::NoButton) == QMessageBox::Cancel) {
    m_progressDialog->hide();
    return false;
  }

  QSettings setting;
  // progressDialog->setValue( 5);
  m_progressDialog->setDetailText(tr("Retrieving contents..."));
  QStringList paths;

  if (ui.rbPartitions->isChecked()) {
    if (setting.value("profiles/" + ui.leIPAddress->lineEdit()->text() + "/backupLog", "true").toBool()) {
      paths << "/log";
    }

    // progressDialog->setValue( 3);
    if (setting.value("profiles/" + ui.leIPAddress->lineEdit()->text() + "/backupUsr", "true").toBool()) {
      paths << "/usr";
    }

    // progressDialog->setValue( 4);
    if (setting.value("profiles/" + ui.leIPAddress->lineEdit()->text() + "/backupSys", "true").toBool()) {
      paths << "/sys";
    }
  } else if (ui.rbCompleteSystem) {
    paths << "/log"
          << "/usr"
          << "/sys";
  } else {
    paths << "/sys/configs";
    paths << "/usr/configs";
  }
  recursiveList(paths);
  return true;
}

void FtpWindow::saveSettings() {
  QSettings setting;
  setting.setValue("profiles/" + ui.leIPAddress->lineEdit()->text() + "/username", ui.leUserName->text());
  setting.setValue("profiles/" + ui.leIPAddress->lineEdit()->text() + "/password",
                   ui.leUserName->text().contains("staubli", Qt::CaseInsensitive) ? "" : ui.lePassword->text());
  setting.setValue("profiles/" + ui.leIPAddress->lineEdit()->text() + "/backupSys", ui.checkBoxSys->checkState());
  setting.setValue("profiles/" + ui.leIPAddress->lineEdit()->text() + "/backupUsr", ui.checkBoxUsr->checkState());
  setting.setValue("profiles/" + ui.leIPAddress->lineEdit()->text() + "/backupLog", ui.checkBoxLog->checkState());
  setting.setValue("profiles/" + ui.leIPAddress->lineEdit()->text() + "/compress", ui.checkBoxCompress->checkState());
  setting.setValue("profiles/" + ui.leIPAddress->lineEdit()->text() + "/backupPartitions",
                   ui.rbPartitions->isChecked());
  setting.setValue("profiles/" + ui.leIPAddress->lineEdit()->text() + "/completeSystem",
                   ui.rbCompleteSystem->isChecked());
  setting.setValue("profiles/" + ui.leIPAddress->lineEdit()->text() + "/configs", ui.rbConfigs->isChecked());
  // setting.setValue("directories/downloadDir", ui.leDownloadDir->text() );
}

void FtpWindow::compressingFile(const QString fileName, int idx, int count) {
  m_progressDialog->setTotalValue(idx);
  m_progressDialog->setTotalMaximum(count);
  m_progressDialog->setDetailText("Compressing file: " + fileName);
  m_progressDialog->show();
}

void FtpWindow::completed(bool result) {
  m_progressDialog->hide();
  if (!result)
    QMessageBox::critical(this, tr("Error"), tr("Error while compressing the backup!"), QMessageBox::Ok,
                          QMessageBox::NoButton);

  // do not quit application after compression is complete
  // qApp->quit();
}

void FtpWindow::slotSelectDownLoadDir() {
  QSettings settings;
  m_downloadDir = settings.value("directories/downloadDir", QDir::homePath() + "/robots").toString();
  m_downloadDir =
      QFileDialog::getExistingDirectory(this, tr("Choose a directory where you want to store the downloaded backup:"),
                                        m_downloadDir, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

  settings.setValue("directories/downloadDir", m_downloadDir);
}

void FtpWindow::on_action_About_triggered() {
  aboutDialog widget(this);
  widget.exec();
}

void FtpWindow::on_action_About_Qt_triggered() { qApp->aboutQt(); }
void FtpWindow::on_action_Default_Backup_Settings_triggered() {
  settingsDialog *dlg = new settingsDialog(this, 0);
  dlg->exec();
  delete dlg;
  QSettings setting;
  ui.leDownloadDir->setText(
      QDir::toNativeSeparators(setting.value("directories/downloadDir", QDir::homePath() + "/robots").toString()));
}

void FtpWindow::on_actionLanguage_triggered() {
  settingsDialog *dlg = new settingsDialog(this, 1);
  dlg->exec();
  delete dlg;
  QSettings setting;
  ui.leDownloadDir->setText(
      QDir::toNativeSeparators(setting.value("directories/downloadDir", QDir::homePath() + "/robots").toString()));
}

void FtpWindow::on_action_User_Interface_triggered() {
  settingsDialog *dlg = new settingsDialog(this, 2);
  dlg->exec();
  delete dlg;
  QSettings setting;
  ui.leDownloadDir->setText(
      QDir::toNativeSeparators(setting.value("directories/downloadDir", QDir::homePath() + "/robots").toString()));
}

void FtpWindow::on_btSelectDownloadDir_clicked() {
  QString dir = ui.leDownloadDir->text();
  QString newDir = QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("Select a backup folder"), dir));
  if (!newDir.isEmpty()) {
    ui.leDownloadDir->setText(QDir::toNativeSeparators(newDir));
    if (newDir != dir) {
      QMessageBox msgBox(this);
      /*QPushButton *sessionButton = */ msgBox.addButton(tr("&Use the folder only for this session"),
                                                         QMessageBox::AcceptRole);
      QPushButton *defaultButton = msgBox.addButton(tr("&Set the folder as default"), QMessageBox::RejectRole);
      msgBox.setInformativeText(tr("You have changed the download folder."
                                   "\nDo you want to use the folder only for this session or do you "
                                   "want to set it as the default"
                                   " download folder?"));
      msgBox.setIcon(QMessageBox::Question);
      msgBox.exec();
      if (msgBox.clickedButton() == defaultButton) {
        QSettings setting;
        setting.setValue("directories/downloadDir", ui.leDownloadDir->text());
      }
    }
  }
}

void FtpWindow::slotOnlineState(bool online, int /*error*/, const QString &errorString) {
  ui.btDownload->setEnabled(online);
  if (!online)
    statusBar()->showMessage(
        tr("Cannot connect to controller %1: %2").arg(ui.leIPAddress->currentText()).arg(errorString));
  else
    statusBar()->showMessage(tr("Controller %1 (%2) is online")
                                 .arg(ui.leIPAddress->currentText())
                                 .arg(m_scanner->serialNumber(ui.leIPAddress->currentText())));
}

void FtpWindow::on_leUserName_textEdited(QString) {
  m_controller->setLoginData(ui.leUserName->text(), ui.lePassword->text());
}

void FtpWindow::on_lePassword_textEdited(QString) {
  m_controller->setLoginData(ui.leUserName->text(), ui.lePassword->text());
}

void FtpWindow::slotScannerStopped() {
  // ui.lbScannerStatus->setText (tr("Scanner is stopped"));
  m_movie->stop();
  ui.btUpdate->setEnabled(true);
}

void FtpWindow::slotScannerStarted() {
  // ui.lbScannerStatus->setText (tr("Scanner is active"));
  m_movie->start();
  ui.btUpdate->setEnabled(false);
}

void FtpWindow::on_actionRescan_Updates_triggered() {
  ui.statusbar->showMessage(tr("Updating storage information..."), 5000);
  backupStorage storage;
  storage.setStorageBasePath(ui.leDownloadDir->text());
  storage.updateStorage(true);
}

void FtpWindow::on_btUpdate_clicked() { m_scanner->start(); }

void FtpWindow::on_action_Preferences_triggered() {
  settingsDialog *dlg = new settingsDialog(this, 0);
  dlg->setDefaultDir(m_defaultDir);
  dlg->exec();
  delete dlg;
  QSettings setting;
  ui.leDownloadDir->setText(
      QDir::toNativeSeparators(setting.value("directories/downloadDir", m_defaultDir).toString()));
}

QString FtpWindow::getBackupName(const QString &serialNumber_) {
  QSettings settings;

  QString name = settings.value("backupNameTemplate", "_%SN").toString();
  name.replace("%SN", serialNumber_);
  name = QDateTime::currentDateTime().toString("yyyyMMdd-hhmm") + name;
  qDebug() << "Using backup name" << name;
  return name;
}

void FtpWindow::setFileTimestamp(const QString &fileName_, const QDateTime &timeStamp_) {
  // Create a systemtime struct
  SYSTEMTIME thesystemtime;
  thesystemtime.wYear = timeStamp_.date().year();
  thesystemtime.wMonth = timeStamp_.date().month();
  thesystemtime.wDay = timeStamp_.date().day();
  thesystemtime.wDayOfWeek = timeStamp_.date().dayOfWeek();
  thesystemtime.wHour = timeStamp_.time().hour();
  thesystemtime.wMinute = timeStamp_.time().minute();
  thesystemtime.wSecond = timeStamp_.time().second();
  thesystemtime.wMilliseconds = timeStamp_.time().msec();

  // Get current system time and then change the day to the 3rd
  // You can also change year, month, day of week etc
  // GetSystemTime(&thesystemtime);
  // thesystemtime.wDay = 3;

  // Create a FILETIME struct and convert our new SYSTEMTIME
  // over to the FILETIME struct for use in SetFileTime below
  FILETIME thefiletime;

  SystemTimeToFileTime(&thesystemtime, &thefiletime);

  // Get a handle to our file and with file_write_attributes access
  HANDLE filename = CreateFile((LPCWSTR)fileName_.utf16(), FILE_WRITE_ATTRIBUTES, FILE_SHARE_READ | FILE_SHARE_WRITE,
                               NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

  // Set the file time on the file
  SetFileTime(filename, (LPFILETIME)NULL, (LPFILETIME)NULL, &thefiletime);

  // Close our handle.
  CloseHandle(filename);
}

void FtpWindow::closeEvent(QCloseEvent *event) {
  if (ui.fileList->count() > 0) {
    QMessageBox::critical(this, "Closing cs8Backup",
                          tr("Closing cs8Backup is not possible at this moment "
                             "because a backup is currently active."));
    event->ignore();
  }
}

void FtpWindow::on_leDownloadDir_textChanged(const QString &arg1) { ui.leDownloadDir->setToolTip(arg1); }

void FtpWindow::slotSelectionChanged(QItemSelection selected, QItemSelection deselected) {
  QModelIndex index = selected.indexes().at(0);
  index = m_scanner->index(index.row(), 0);
  qDebug() << "selected: " << m_scanner->data(index).toString();
  ui.leIPAddress->setEditText(m_scanner->data(index).toString());
}

void FtpWindow::slotScanCompleted(uint count) {
  ui.tableViewDetectedControllers->setEnabled(count > 0);
  if (count == 0) {
    if (!m_controller->isOnline()) {
      QPoint p = ui.leIPAddress->mapToGlobal(QPoint(0, 0));
      p.ry() += ui.leIPAddress->height();
      QWhatsThis::showText(p, ui.leIPAddress->toolTip());
    }
  } else {
    QPoint p = ui.tableViewDetectedControllers->mapToGlobal(QPoint(0, 0));
    QWhatsThis::showText(p, ui.tableViewDetectedControllers->toolTip());
  }
}

void FtpWindow::slotDetected(const QString & /*host*/) { ui.tableViewDetectedControllers->setEnabled(true); }

void FtpWindow::on_pushButtonExplore_clicked() {
  QDesktopServices::openUrl(QUrl(QString("file:///%1").arg(ui.leDownloadDir->text())));
}

void FtpWindow::on_leIPAddress_currentTextChanged(const QString &arg1) {
  // check if input is valid
  int cursorPos = 0;
  QString line = arg1;
  if (ui.leIPAddress->lineEdit()->validator()->validate(line, cursorPos) == QValidator::Acceptable) {
    QSettings setting;
    ui.leUserName->setText(setting.value("profiles/" + arg1 + "/username", "default").toString());
    ui.lePassword->setText(setting.value("profiles/" + arg1 + "/password", "").toString());
    ui.checkBoxSys->setChecked(
        setting.value("profiles/" + arg1 + "/backupSys", setting.value("defaultSys", true).toBool()).toBool());
    ui.checkBoxUsr->setChecked(
        setting.value("profiles/" + arg1 + "/backupUsr", setting.value("defaultUsr", true).toBool()).toBool());
    ui.checkBoxLog->setChecked(
        setting.value("profiles/" + arg1 + "/backupLog", setting.value("defaultLog", true).toBool()).toBool());
    ui.checkBoxCompress->setChecked(
        setting.value("profiles/" + arg1 + "/compress", setting.value("defaultCompress").toBool()).toBool());
    ui.checkBoxCompress->setChecked(
        setting.value("profiles/" + arg1 + "/backupPartitions", setting.value("backupPartitions", true).toBool())
            .toBool());
    m_controller->setAddress(ui.leIPAddress->currentText());
    m_controller->setLoginData(ui.leUserName->text(), ui.lePassword->text());
  } else
    ui.btDownload->setEnabled(false);
}

void FtpWindow::on_actionCheck_for_Updates_triggered() { m_checkUpdate->checkForUpdates(true, true); }
