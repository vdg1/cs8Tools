/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QClipboard>
#include <QCloseEvent>
#include <QDesktopServices>
#include <QFileDialog>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QMimeData>
#include <QSettings>
#include <QSignalMapper>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStandardPaths>
#include <QTimer>

#include <cs8connectdialog.h>

#include "../common/databaseconnection.h"
#include "aboutdialog.h"
#include "cs8metainformationmodel.h"
#include "cs8searchwidget.h"
#include "cs8systemconfigurationmodel.h"
#include "dialoghighlightconfiguration.h"
#include "logfilemodel.h"
#include "mainwindow.h"
#include "mdichild.h"

void MainWindow::parseArguments() {
  if (qApp->arguments().count() > 1) {
    if (QFile::exists(qApp->arguments().at(1))) {
      loadFile(qApp->arguments().at(1));
    }
  }
}

MainWindow::MainWindow() : QMainWindow() {
  ui.setupUi(this);

  ui.mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
  ui.mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

  connect(ui.mdiArea, &QMdiArea::subWindowActivated, this,
          &MainWindow::updateMenus);
  windowMapper = new QSignalMapper(this);
  connect(windowMapper, SIGNAL(mapped(QWidget *)), this,
          SLOT(setActiveSubWindow(QWidget *)));
  connect(ui.treeViewSystemConfigurations, &QTreeView::doubleClicked, this,
          &MainWindow::slotDoubleClickedSystemConfig);

  createDBConnection();
  createActions();
  createMenus();
  createStatusBar();
  updateMenus();

  highlightItems = new highlightItemList();

  readSettings();
  readRules();

  setWindowTitle(tr("CS8 Log File Viewer"));
  setUnifiedTitleAndToolBarOnMac(true);

  // check if about dialog shall be shown for first time after update
  QSettings settings;
  if (settings.value("cs8LogFileViewer/releaseNotes", "").toString() !=
      qApp->applicationVersion()) {
    QTimer::singleShot(0, this, SLOT(about()));
    settings.setValue("cs8LogFileViewer/releaseNotes",
                      qApp->applicationVersion());
  }
}

void MainWindow::handleMessage(const QString &message) {
  enum Action { Nothing, Open } action;

  qDebug() << "Received message:" << message;

  action = Nothing;
  QString filename;
  if (!message.isEmpty()) {
    QStringList arguments = message.split("@@");
    if (arguments[0] == QStringLiteral("[open]")) {
      filename = arguments[1];
      action = Open;
    }
    if (QFile::exists(arguments[0])) {
      filename = arguments[0];
      action = Open;
    }
  }

  switch (action) {
  case Open:
    emit needToShow();
    QTimer::singleShot(100, [=]() {
      raise();
      activateWindow();
      loadFile(filename);
    });
    break;

  case Nothing:
    emit needToShow();
    break;
  };
}

void MainWindow::closeEvent(QCloseEvent *event) {
  ui.mdiArea->closeAllSubWindows();
  if (false && ui.mdiArea->currentSubWindow()) {
    event->ignore();
  } else {
    writeSettings();
    writeRules();
    event->accept();
  }
}

void MainWindow::open() {
  QSettings settings;

  QString fileName = QFileDialog::getOpenFileName(
      this, tr("Open log file"), settings.value("lastOpenDir").toString(),
      tr("Log Files (*.log *.old)"));
  if (!fileName.isEmpty()) {
    settings.setValue("lastOpenDir", QFileInfo(fileName).absolutePath());
    loadFile(fileName);
  }
}

void MainWindow::copy(bool withRobotInfo) {
  if (activeMdiChild()) {
    QClipboard *clip = QApplication::clipboard();
    QMimeData *data = new QMimeData;

    data->setData("text/html",
                  activeMdiChild()->getSelectedLines(true).toLatin1());
    qDebug() << "is html: " << data->hasHtml();
    // clip->setMimeData(data);
    clip->setText(activeMdiChild()->getSelectedLines(false, withRobotInfo));
  }
}

void MainWindow::about() {
  aboutDialog dlg(":/files/releasenotes.txt", this);
  dlg.exec();
}

void MainWindow::resizeSystemConfigViewColumns() {
  ui.treeViewSystemConfigurations->resizeColumnToContents(0);
  ui.treeViewSystemConfigurations->resizeColumnToContents(1);
}

void MainWindow::slotDoubleClickedSystemConfig(const QModelIndex &index) {
  if (activeMdiChild() != nullptr) {
    cs8SystemConfigurationModel *model =
        qobject_cast<cs8SystemConfigurationModel *>(
            ui.treeViewSystemConfigurations->model());
    if (model->data(index, Qt::UserRole).isValid()) {
      int lineNumber = model->data(index, Qt::UserRole).toInt();
      activeMdiChild()->scrollToLine(lineNumber);
    }
  }
}

void MainWindow::updateMenus() {
  bool hasMdiChild = (activeMdiChild() != nullptr);
  closeAct->setEnabled(hasMdiChild);
  closeAllAct->setEnabled(hasMdiChild);
  tileAct->setEnabled(hasMdiChild);
  cascadeAct->setEnabled(hasMdiChild);
  nextAct->setEnabled(hasMdiChild);
  previousAct->setEnabled(hasMdiChild);
  separatorAct->setVisible(hasMdiChild);
  ui.actHide_USR_messages->setEnabled(hasMdiChild);

  if (hasMdiChild) {
    // update tool bars and dock widgets
    ui.actCopy->setEnabled(activeMdiChild()->hasSelection());

    cs8SystemConfigurationModel *model = activeMdiChild()
                                             ->model()
                                             ->metaInformationModel()
                                             ->systemConfigurationModel();
    ui.treeViewSystemConfigurations->setModel(model);
    connect(model, &cs8SystemConfigurationModel::completed, this,
            &MainWindow::resizeSystemConfigViewColumns);

    ui.widgetSearch->setModel(activeMdiChild()->model());
    ui.actHide_USR_messages->setChecked(!activeMdiChild()->showsUSRMessages());
    ui.actionHide_Swap_File_Messages->setChecked(
        !activeMdiChild()->showsSwapFileMessages());
    ui.actionOpen_Machine_File->setEnabled(
        !activeMdiChild()->model()->URLId().isEmpty());
    ui.actionReverse_Order->setChecked(activeMdiChild()->reverseOrder());
    ui.actionScroll_to_Bottom->setChecked(
        activeMdiChild()->scrollToBottomWhenLineReceived());
    ui.actionShow_Errors->setEnabled(activeMdiChild()->model()->fileType() ==
                                     cs8LogFileData::CS9);
    ui.actionShow_Warnings->setEnabled(activeMdiChild()->model()->fileType() ==
                                       cs8LogFileData::CS9);
    ui.actionShow_Information->setEnabled(
        activeMdiChild()->model()->fileType() == cs8LogFileData::CS9);
    ui.actionShow_Errors->setChecked(activeMdiChild()->showsErrorMessages());
    ui.actionShow_Warnings->setChecked(
        activeMdiChild()->showsWarningMessages());
    ui.actionShow_Information->setChecked(
        activeMdiChild()->showsInformationMesages());

    for (int row = 0; row < model->rowCount(); row++) {
      ui.treeViewSystemConfigurations->expand(model->index(row, 0));
    }
    resizeSystemConfigViewColumns();

    connect(ui.widgetSearch, &cs8SearchWidget::lineSelected, activeMdiChild(),
            &MdiChild::scrollToLine);
    connect(activeMdiChild()->model(), &logFileModel::readingComplete,
            ui.widgetSearch, &cs8SearchWidget::updateSearchParameters);
  }
}

void MainWindow::updateWindowMenu() {
  ui.menu_Window->clear();
  ui.menu_Window->addAction(closeAct);
  ui.menu_Window->addAction(closeAllAct);
  ui.menu_Window->addSeparator();
  ui.menu_Window->addAction(tileAct);
  ui.menu_Window->addAction(cascadeAct);
  ui.menu_Window->addSeparator();
  ui.menu_Window->addAction(nextAct);
  ui.menu_Window->addAction(previousAct);
  ui.menu_Window->addAction(separatorAct);

  QList<QMdiSubWindow *> windows = ui.mdiArea->subWindowList();
  separatorAct->setVisible(!windows.isEmpty());

  for (int i = 0; i < windows.size(); ++i) {
    MdiChild *child = qobject_cast<MdiChild *>(windows.at(i));

    QString text;
    if (i < 9) {
      text = tr("&%1 %2").arg(i + 1).arg(child->userFriendlyCurrentFile());
    } else {
      text = tr("  %1").arg(child->userFriendlyCurrentFile());
    }
    QAction *action = ui.menu_Window->addAction(text);
    action->setCheckable(true);
    action->setChecked(child == activeMdiChild());
    connect(action, SIGNAL(triggered()), windowMapper, SLOT(map()));
    windowMapper->setMapping(action, windows.at(i));
  }
}

MdiChild *MainWindow::createMdiChild() {
  MdiChild *child = new MdiChild;
  child->model()->setHighlightRules(highlightItems);
  ui.mdiArea->addSubWindow(child);
  child->setAttribute(Qt::WA_DeleteOnClose);
  connect(child, &MdiChild::copyAvailable, ui.actCopy, &QAction::setEnabled);
  connect(child, &MdiChild::deactivated, this,
          &MainWindow::slotChildDeactivated);
  connect(this, &MainWindow::highlightRulesChanged, child->model(),
          &logFileModel::slotRunHighlightRules);
  return child;
}

void MainWindow::createActions() {
  closeAct = new QAction(tr("Cl&ose"), this);
  closeAct->setStatusTip(tr("Close the active window"));
  connect(closeAct, &QAction::triggered, ui.mdiArea,
          &QMdiArea::closeActiveSubWindow);

  closeAllAct = new QAction(tr("Close &All"), this);
  closeAllAct->setStatusTip(tr("Close all the windows"));
  connect(closeAllAct, &QAction::triggered, ui.mdiArea,
          &QMdiArea::closeAllSubWindows);

  tileAct = new QAction(tr("&Tile"), this);
  tileAct->setStatusTip(tr("Tile the windows"));
  connect(tileAct, &QAction::triggered, ui.mdiArea, &QMdiArea::tileSubWindows);

  cascadeAct = new QAction(tr("&Cascade"), this);
  cascadeAct->setStatusTip(tr("Cascade the windows"));
  connect(cascadeAct, &QAction::triggered, ui.mdiArea,
          &QMdiArea::cascadeSubWindows);

  nextAct = new QAction(tr("Ne&xt"), this);
  nextAct->setShortcuts(QKeySequence::NextChild);
  nextAct->setStatusTip(tr("Move the focus to the next window"));
  connect(nextAct, &QAction::triggered, ui.mdiArea,
          &QMdiArea::activateNextSubWindow);

  previousAct = new QAction(tr("Pre&vious"), this);
  previousAct->setShortcuts(QKeySequence::PreviousChild);
  previousAct->setStatusTip(tr("Move the focus to the previous "
                               "window"));
  connect(previousAct, &QAction::triggered, ui.mdiArea,
          &QMdiArea::activatePreviousSubWindow);

  separatorAct = new QAction(this);
  separatorAct->setSeparator(true);

  aboutAct = new QAction(tr("&About"), this);
  aboutAct->setStatusTip(tr("Show the application's About box"));
  connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

  aboutQtAct = new QAction(tr("About &Qt"), this);
  aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
  connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

  for (int i = 0; i < MaxRecentFiles; ++i) {
    recentFileActs[i] = new QAction(this);
    recentFileActs[i]->setVisible(false);
    connect(recentFileActs[i], &QAction::triggered, this,
            &MainWindow::openRecentFile);
  }

  ui.actionOpen_Machine_File->setEnabled(false);
}

void MainWindow::createMenus() {
  QMenu *fileMenu;
  fileMenu = ui.menu_File;
  for (int i = 0; i < MaxRecentFiles; ++i)
    fileMenu->insertAction(ui.actExit, recentFileActs[i]);
  fileMenu->insertSeparator(ui.actExit);

  connect(ui.menu_Window, &QMenu::aboutToShow, this,
          &MainWindow::updateWindowMenu);

  menuBar()->addSeparator();

  helpMenu = menuBar()->addMenu(tr("&Help"));
  helpMenu->addAction(aboutAct);
  helpMenu->addAction(aboutQtAct);

  updateRecentFileActions();
  updateWindowMenu();

  m_contextMenu = new QMenu(this);
  m_contextMenu->addAction(ui.actCopy);
  m_contextMenu->addAction(ui.actionCopy_lines_and_add_info);
  m_contextMenu->addAction(ui.actionSend_selected_lines_to);
  m_contextMenu->addAction(ui.actionOpen_Machine_File);
}

void MainWindow::createStatusBar() { statusBar()->showMessage(tr("Ready")); }

void MainWindow::readSettings() {
  QSettings settings;

  restoreGeometry(settings.value("mainWindowGeometry").toByteArray());
  restoreState(settings.value("mainWindowState").toByteArray());

  m_dataDir = settings
                  .value("dataDir", QStandardPaths::writableLocation(
                                        QStandardPaths::AppLocalDataLocation))
                  .toString();

  settings.beginGroup("Search");
  ui.widgetSearch->setSearchText(settings.value("searchText").toString());
  ui.widgetSearch->setIsRegExp(
      settings.value("regularExpression", false).toBool());
  settings.endGroup();
  /*
     QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
     QSize size = settings.value("size", QSize(400, 400)).toSize();
     bool maximized = settings.value("maximized",false).toBool ();
     move(pos);
     resize(size);
     if (maximized)
      showMaximized ();
   */
}

void MainWindow::writeSettings() {
  QSettings settings;
  settings.setValue("mainWindowGeometry", saveGeometry());
  settings.setValue("mainWindowState", saveState());
  settings.setValue("dataDir", m_dataDir);
  settings.beginGroup("Search");
  settings.setValue("searchText", ui.widgetSearch->searchText());
  settings.setValue("regularExpression", ui.widgetSearch->isRegExp());
  settings.endGroup();
}

void MainWindow::readRules() {
  QString fileName(
      QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) +
      "/settings.ini");
  QFile file(fileName);
  if (!file.exists()) {
    qDebug() << __FUNCDNAME__ << "Read settings from "
             << qApp->applicationDirPath() + "/settings.ini";
    QString sourceFileName(qApp->applicationDirPath() + "/settings.ini");
    QFile source(sourceFileName);
    source.copy(fileName);
  }
  QSettings settings(fileName, QSettings::IniFormat);

  int count = settings.beginReadArray("highlightRules");
  for (int i = count - 1; i >= 0; i--) {
    settings.setArrayIndex(i);
    highlightItems->addRule(
        0, settings.value("String").toString(),
        settings.value("isRegularExpression", false).toBool(),
        settings.value("Background").toString(),
        settings.value("Foreground").toString(),
        settings.value("Bold").toBool(), settings.value("IgnoreCase").toBool(),
        settings.value("Italic").toBool(), settings.value("highLight").toBool(),
        static_cast<cs8LogFileData::MessageLevel>(
            settings.value("level").toInt()));
  }
  settings.endArray();
}

void MainWindow::writeRules() {
  QSettings settings(
      QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) +
          "/settings.ini",
      QSettings::IniFormat);
  settings.remove("highlightRules");
  settings.beginWriteArray("highlightRules");
  for (int i = 0; i < highlightItems->rowCount(); i++) {
    settings.setArrayIndex(i);
    settings.setValue("String", highlightItems->searchString(i));
    settings.setValue("isRegularExpression",
                      highlightItems->isRegularExpression(i));
    settings.setValue("Background", highlightItems->backgroundColor(i));
    settings.setValue("Foreground", highlightItems->foregroundColor(i));
    settings.setValue("Bold", highlightItems->bold(i));
    settings.setValue("IgnoreCase", highlightItems->ignoreCase(i));
    settings.setValue("Italic", highlightItems->italic(i));
    settings.setValue("highLight", highlightItems->highlightInScrollbar(i));
    settings.setValue("level", highlightItems->level(i));
  }
  settings.endArray();
}

MdiChild *MainWindow::activeMdiChild() {
  if (QMdiSubWindow *activeSubWindow = ui.mdiArea->activeSubWindow())
    return qobject_cast<MdiChild *>(activeSubWindow);
  return 0;
}

QMdiSubWindow *MainWindow::findMdiChild(const QString &fileName) {
  QString canonicalFilePath = fileName;
  if (!fileName.startsWith("CS8:"))
    canonicalFilePath = QFileInfo(fileName).canonicalFilePath();

  foreach (QMdiSubWindow *window, ui.mdiArea->subWindowList()) {
    MdiChild *mdiChild = qobject_cast<MdiChild *>(window /*->widget()*/);
    if (mdiChild->currentFile() == canonicalFilePath)
      return window;
  }
  return 0;
}

void MainWindow::setActiveSubWindow(QWidget *window) {
  if (!window)
    return;
  ui.mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(window));
}

void MainWindow::on_actOpen_triggered() { open(); }

void MainWindow::on_actCopy_triggered() { copy(); }

void MainWindow::on_actExit_triggered() { qApp->closeAllWindows(); }

void MainWindow::on_actHide_USR_messages_triggered(bool checked) {
  if (activeMdiChild() != 0)
    activeMdiChild()->showUSRMessages(!checked);
}

void MainWindow::openRecentFile() {
  QAction *action = qobject_cast<QAction *>(sender());
  if (action) {
    if (action->data().toString().startsWith("CS8:")) {
      QStringList list = action->data().toString().split(":");
      quint16 port = list.size() > 2 ? list[2].toUInt() : 23;

      connectToController(list[1], port, true);
    } else {
      loadFile(action->data().toString());
    }
  }
}

void MainWindow::loadFile(const QString &fileName_) {
  qDebug() << __FUNCTION__ << "Open file:" << fileName_;
  QString fileName = QDir::toNativeSeparators(fileName_);
  QMdiSubWindow *existing = findMdiChild(fileName);
  if (existing) {
    emit needToShow();
    ui.mdiArea->setActiveSubWindow(existing);
    return;
  }

  MdiChild *child = createMdiChild();
  child->setContextMenu(m_contextMenu);
  connect(child->model(), &logFileModel::loadingFinished, this,
          &MainWindow::updateMenus);
  connect(child->model(), &logFileModel::metaInformationAvailable, this,
          &MainWindow::updateMenus);
  if (child->loadFile(fileName)) {
    statusBar()->showMessage(tr("File loaded"), 2000);
    child->show();
  } else {
    child->close();
  }

  QSettings settings;
  QStringList files = settings.value("recentFileList").toStringList();
  files.removeAll(fileName);
  files.prepend(fileName);
  while (files.size() > MaxRecentFiles)
    files.removeLast();

  settings.setValue("recentFileList", files);
  updateRecentFileActions();
}

void MainWindow::updateRecentFileActions() {
  QSettings settings;
  QStringList files = settings.value("recentFileList").toStringList();

  for (int i = 0; i < files.count(); i++) {
    files[i] = QDir::toNativeSeparators(files[i]);
    if (!QFile::exists(files[i]) && !files[i].startsWith("CS8:")) {
      files.removeAt(i);
      i--;
    }
  }
  files.removeDuplicates();

  int numRecentFiles = qMin(files.size(), static_cast<int>(MaxRecentFiles));

  for (int i = 0; i < numRecentFiles; ++i) {
    QString text = tr("&%1 %2").arg(i + 1).arg((files[i]));
    recentFileActs[i]->setText(text);
    recentFileActs[i]->setData(files[i]);
    recentFileActs[i]->setVisible(true);
  }
  for (int j = numRecentFiles; j < MaxRecentFiles; ++j)
    recentFileActs[j]->setVisible(false);

  separatorAct->setVisible(numRecentFiles > 0);
}

void MainWindow::on_actionHighlighting_triggered() {
  DialogHighLightConfiguration dialog;
  dialog.setItemList(highlightItems);
  dialog.exec();

  if (dialog.modified())
    emit highlightRulesChanged();
}

void MainWindow::slotChildDeactivated() {
  qDebug() << "child deactivated: " << sender();
  disconnect(ui.widgetSearch, SIGNAL(lineSelected(int)), sender(),
             SLOT(scrollToLine(int)));
}

void MainWindow::on_actionNext_System_Start_triggered() {
  if (activeMdiChild() != nullptr)
    activeMdiChild()->jumpToStart(+1);
}

void MainWindow::on_actionPrevious_System_Start_triggered() {
  if (activeMdiChild() != nullptr)
    activeMdiChild()->jumpToStart(-1);
}

void MainWindow::on_actionHide_Swap_File_Messages_triggered(bool checked) {
  if (activeMdiChild() != nullptr)
    activeMdiChild()->showSwapFileMessages(!checked);
}

void MainWindow::on_actionReverse_Order_triggered(bool checked) {
  if (activeMdiChild() != nullptr)
    activeMdiChild()->setReverseOrder(checked);
}

void MainWindow::on_actionOnline_triggered() {
  cs8ConnectDialog dlg;
  if (dlg.exec()) {
    connectToController(dlg.address(), dlg.port(), dlg.loadLogFile());
  }
}

void MainWindow::connectToController(const QString &address, quint16 port,
                                     bool loadLogFile) {
  qDebug() << __FUNCTION__ << "Connect to:" << address << ":" << port;
  QString fileName = QString("CS8:%1:%2").arg(address).arg(port);
  QMdiSubWindow *existing = findMdiChild(fileName);
  if (existing) {
    emit needToShow();
    ui.mdiArea->setActiveSubWindow(existing);
    return;
  }

  MdiChild *child = createMdiChild();
  child->setContextMenu(m_contextMenu);
  if (child->connectToHost(address, port, loadLogFile)) {
    statusBar()->showMessage(tr("Connecting to %1:%2").arg(address).arg(port),
                             2000);
    child->show();
  } else {
    child->close();
  }

  QSettings settings;
  QStringList files = settings.value("recentFileList").toStringList();
  files.removeAll(fileName);
  files.prepend(fileName);
  while (files.size() > MaxRecentFiles)
    files.removeLast();

  settings.setValue("recentFileList", files);
  updateRecentFileActions();
}

void MainWindow::on_actionSend_selected_lines_to_triggered() {
  if (activeMdiChild()) {
    QString serialNumber = activeMdiChild()
                               ->model()
                               ->metaInformationModel()
                               ->systemConfigurationModel()
                               ->machineSerialNumber();
    QString subject = QString("Emailing log data from %1").arg(serialNumber);
    QString body = QString("\nLog data from %1:\n\n[..]\n%2\n[..]\n")
                       .arg(serialNumber)
                       .arg(activeMdiChild()->getSelectedLines(false));
    QString url = QString("mailto:?subject=%1&body=%2").arg(subject).arg(body);
    QDesktopServices::openUrl(QUrl(url));
  }
}

void MainWindow::on_actionSave_as_triggered() {
  if (activeMdiChild()) {
    MdiChild *child = activeMdiChild();
    QString serialNumber = child->model()
                               ->metaInformationModel()
                               ->systemConfigurationModel()
                               ->machineSerialNumber();
    QString timeStamp = child->model()
                            ->metaInformationModel()
                            ->systemConfigurationModel()
                            ->timeStampFrom()
                            .toString(Qt::ISODate)
                            .replace(":", "-");

    QString suggestedFileName =
        QDir::toNativeSeparators(child->currentFilePath() + "/errors_" +
                                 serialNumber + "_" + timeStamp + ".log");

    QString fileName = QFileDialog::getSaveFileName(
        this, tr("Save log data as..."), suggestedFileName, "*.log");
    if (!fileName.isEmpty()) {
      if (child->model()->saveLogFile(fileName)) {
        QUrl url;
        QFileInfo info(fileName);
        url.setScheme("url");
        url.setUrl(info.absolutePath());
        url.setScheme("file");

        QMessageBox::information(this, tr("Log file export"),
                                 tr("The log is saved to <a href='%2'>%1</a>.")
                                     .arg(QDir::toNativeSeparators(fileName))
                                     .arg(url.toString()));
      } else
        QMessageBox::critical(this, tr("Log file export"),
                              tr("Saving log to %1 failed!").arg(fileName));
    }
  }
}

void MainWindow::on_actionOpen_Machine_File_triggered() {
  if (activeMdiChild()) {
    QSettings settings;
    qDebug() << settings.fileName();
    if (!settings.value("catalogueURL").toString().isEmpty()) {
      QString id = activeMdiChild()->model()->URLId();
      if (!id.isEmpty()) {

        QString url = QString("%1").arg(
            settings.value("catalogueURL").toString().arg(id));
        QDesktopServices::openUrl(url);
      }
    } else {
      QMessageBox::critical(this, tr("Online machine catalogue"),
                            tr("No URL is configured for the online machine "
                               "catalogue. Please check settings!"));
    }
  }
}

void MainWindow::on_actionScroll_to_Bottom_triggered(bool checked) {
  if (activeMdiChild() != nullptr)
    activeMdiChild()->setScrollToBottomWhenLineReceived(checked);
}

void MainWindow::on_actionReset_Dialog_Options_triggered() {
  if (QMessageBox::question(this, tr("Dialog Options"),
                            tr("Do you want to reset all dialog options?")) ==
      QMessageBox::Yes)
    cs8MetaInformationModel::resetDialogOptions();
}

void MainWindow::on_actionCopy_lines_and_add_info_triggered() { copy(true); }

void MainWindow::on_actionShow_Warnings_toggled(bool arg1) {
  if (activeMdiChild())
    activeMdiChild()->showWarningMessages(arg1);
}

void MainWindow::on_actionShow_Information_toggled(bool arg1) {
  if (activeMdiChild())
    activeMdiChild()->showInformationMessages(arg1);
}

void MainWindow::on_actionShow_Errors_toggled(bool arg1) {
  if (activeMdiChild())
    activeMdiChild()->showErrorMessages(arg1);
}
