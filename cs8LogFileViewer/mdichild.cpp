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

#include <QCheckBox>
#include <QClipboard>
#include <QCloseEvent>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QMdiSubWindow>
#include <QMenu>
#include <QMessageBox>
#include <QSortFilterProxyModel>
#include <QTextDocumentFragment>

#include "cs8logfilefiltermodel.h"
#include "cs8metainformationmodel.h"
#include "cs8systemconfigurationmodel.h"
#include "dialogalternativeeditor.h"
#include "logfilemodel.h"
#include "mdichild.h"
#include "ui_mdiChild.h"

MdiChild::MdiChild(QWidget *parent)
    : QMdiSubWindow(parent), ui(new Ui::mdiChild), m_scrollToBottomWhenLineReceived(true), m_contextMenu(nullptr) {
  ui->setupUi(this);
  setCurrentFile("");
  delete layout();
  setLayout(ui->verticalLayout);
  setAttribute(Qt::WA_DeleteOnClose);

  m_fileWatcher = new QFileSystemWatcher(this);
  connect(m_fileWatcher, &QFileSystemWatcher::fileChanged, this, &MdiChild::slotFileChanged);

  m_fileWatcherTimer = new QTimer(this);
  connect(m_fileWatcherTimer, &QTimer::timeout, this, &MdiChild::slotFileChangedTimeout);

  m_model = new logFileModel(this);
  m_filterModel = new cs8LogFileFilterModel(this);
  m_filterModel->setSourceModel(m_model);
  connect(m_model, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this,
          SLOT(socketStateChanged(QAbstractSocket::SocketState)));

  ui->view->setModel(m_filterModel);
  ui->view->setContextMenuPolicy(Qt::CustomContextMenu);
  connect(ui->view, &QTableView::customContextMenuRequested, this, &MdiChild::slotContextMenuRequested);
  connect(ui->view->selectionModel(), &QItemSelectionModel::selectionChanged, this, &MdiChild::slotSelectionChanged);

  ui->widgetInformation->setModel(m_model->metaInformationModel());
  showInformation(false);

  connect(this, &QMdiSubWindow::windowStateChanged, this, &MdiChild::slotWindowStateChanged);
  connect(m_model, &logFileModel::readingComplete, this, &MdiChild::slotLoadingFinished);

  scrollbar = new cs8ScrollBar(ui->view);
  scrollbar->setModel(m_filterModel);
  connect(m_model, &logFileModel::highLight, scrollbar, &cs8ScrollBar::addHighlight);
  connect(m_model, &logFileModel::resetHighlight, scrollbar, &cs8ScrollBar::resetHighlight);
  connect(m_filterModel, &cs8LogFileFilterModel::orderChanged, scrollbar, &cs8ScrollBar::reverseHighlights);
  connect(scrollbar, &cs8ScrollBar::scrollToRow, this, &MdiChild::scrollToLine);

  connect(m_model, &logFileModel::logMessageReceived, this, &MdiChild::slotLogMessageReceived);
  ui->view->setVerticalScrollBar(scrollbar);

  ui->gpInformation->hide();
}

bool MdiChild::loadFile(const QString &fileName) {
  bool hasSwapFile = false;
  QFile oldFile;
  QFile file(fileName);
  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    QMessageBox::warning(this, tr("CS8 Log File Viewer"),
                         tr("Cannot read file %1:\n%2.").arg(fileName, file.errorString()));
    return false;
  }

  // check if *.old also exist in same directory
  QFileInfo info(fileName);
  // read hash of file
  QTextStream in(&file);
  qint64 hash = qHash(in.readAll());
  file.seek(0);

  if (info.fileName().contains(QRegExp("(errors|system|user).log"))) {
    QString oldFileName = info.path() + "/" + info.baseName() + ".old";
    oldFile.setFileName(oldFileName);

    if (oldFile.exists()) {
      bool openSwapFile = false;
      switch (m_model->metaInformationModel()->dlgOpenSwapFile(hash)) {
      case cs8MetaInformationModel::Unset: {
        QMessageBox dlg;
        QCheckBox *cb = new QCheckBox(tr("Don't ask me again for this file."));
        dlg.setText(tr("A swap file %1 was detected in same directory. Do you want "
                       "to merge the two files?")
                        .arg(QDir::toNativeSeparators(fileName))
                        .arg(file.errorString()));
        dlg.setWindowTitle(tr("Log Swap File"));
        dlg.setCheckBox(cb);
        dlg.setIcon(QMessageBox::Question);
        dlg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if (dlg.exec() == QMessageBox::Yes) {
          m_model->metaInformationModel()->setDlgOpenSwapFile(hash, cb->isChecked() ? cs8MetaInformationModel::Yes
                                                                                    : cs8MetaInformationModel::Unset);
          openSwapFile = true;
        } else {
          m_model->metaInformationModel()->setDlgOpenSwapFile(hash, cb->isChecked() ? cs8MetaInformationModel::No
                                                                                    : cs8MetaInformationModel::Unset);
          openSwapFile = false;
        }
        break;
      }

      case cs8MetaInformationModel::Yes: {
        openSwapFile = true;
        break;
      }

      default: {
        openSwapFile = false;
        break;
      }
      }
      if (openSwapFile) {
        if (!oldFile.open(QFile::ReadOnly | QFile::Text)) {
          QMessageBox::warning(
              this, tr("CS8 Log File Viewer"),
              tr("Cannot read file %1:\n%2.").arg(QDir::toNativeSeparators(fileName), file.errorString()));
        } else {
          hasSwapFile = true;
        }
      }
    }
  }
  QApplication::setOverrideCursor(Qt::WaitCursor);

  // m_model->loadData(logText);
  if (!hasSwapFile)
    m_model->loadLogFile(&file);
  else
    m_model->loadLogFile(&file, &oldFile);

  // hide LEVEL column for CS8 log files
  if (m_model->fileType() != cs8LogFileData::CS9)
    ui->view->hideColumn(1);
  m_fileName = fileName;
  m_fileWatcher->addPath(fileName);
  // qDebug() << m_fileWatcher->files();
  // ui->widgetInformation->selectRow(m_model->metaInformationModel()->hash());
  QApplication::restoreOverrideCursor();
  curFile = QFileInfo(fileName).canonicalFilePath();
  QString title =
      QDir::toNativeSeparators(fileName + (hasSwapFile ? QString(" + " + info.baseName() + ".old") : QString("")));
  setCurrentFile(title);
  setWindowIcon(QIcon(":/icons/32x32/32x32/mimetypes/text-x-log.png"));
  return true;
}

bool MdiChild::connectToHost(const QString &address, quint16 port, bool loadLogFile) {
  setCurrentFile(QString("CS8:%1:%2").arg(address).arg(port));
  setWindowIcon(QIcon(":/icons/32x32/32x32/actions/network-disconnect.png"));
  ui->view->hideColumn(1);
  return m_model->connectToController(cs8LogInterface::CS8, address, port, loadLogFile);
}

QString MdiChild::userFriendlyCurrentFile() {
  return curFile; // strippedName(curFile);
}

QString MdiChild::currentFile() const { return curFile; }

QString MdiChild::currentFilePath() const {
  QFileInfo info(curFile);
  return info.absolutePath();
}

logFileModel *MdiChild::model() const { return m_model; }

void MdiChild::closeEvent(QCloseEvent * /**event*/) { m_model->deleteLater(); }

void MdiChild::setCurrentFile(const QString &fileName) {
  // curFile = QFileInfo(fileName).canonicalFilePath();

  setWindowModified(false);
  setWindowTitle(fileName + "[*]");
}

QString MdiChild::strippedName(const QString &fullFileName) { return QFileInfo(fullFileName).fileName(); }

void MdiChild::setupContextMenu() {}

bool MdiChild::scrollToBottomWhenLineReceived() const { return m_scrollToBottomWhenLineReceived; }

void MdiChild::setScrollToBottomWhenLineReceived(bool scrollToBottomWhenLineReceived) {
  m_scrollToBottomWhenLineReceived = scrollToBottomWhenLineReceived;
}

void MdiChild::selectedRowNumbers(int &start, int &end) {
  start = ui->view->selectionModel()->selectedRows().at(0).row() + 1;
  end = ui->view->selectionModel()->selectedRows().last().row() + 1;
}

void MdiChild::setContextMenu(QMenu *contextMenu) { m_contextMenu = contextMenu; }

QString MdiChild::getSelectedLines(bool formated, bool withRobotInfo) const {
  QStringList selectedRowsText;
  QTextDocument doc;
  QTextCursor cursor(&doc);

  if (formated) {
    foreach (QModelIndex index, ui->view->selectionModel()->selectedRows(2)) {
      QBrush brush =
          ui->view->model()->data(ui->view->model()->index(index.row(), 0), Qt::ForegroundRole).value<QBrush>();
      QFont font = ui->view->model()->data(ui->view->model()->index(index.row(), 0), Qt::FontRole).value<QFont>();

      QString line = QString("[%1]:%2\n")
                         .arg(ui->view->model()->data(ui->view->model()->index(index.row(), 0)).toString())
                         .arg(ui->view->model()->data(ui->view->model()->index(index.row(), 2)).toString());

      QTextBlockFormat format;
      format.setForeground(brush);
      QTextCharFormat fmt;
      fmt.setFont(font);
      cursor.movePosition(QTextCursor::EndOfBlock);
      cursor.setBlockFormat(format);
      cursor.setBlockCharFormat(fmt);
      cursor.insertText(line);
    }
    qDebug() << doc.toHtml("utf8");
    // return doc.toHtml("utf8");
    return doc.toPlainText();
  } else {
    foreach (QModelIndex index, ui->view->selectionModel()->selectedRows(2)) {
      selectedRowsText.append(ui->view->model()->data(index, Qt::UserRole).toString());
    }
    if (withRobotInfo) {
      QString serialNumber = model()->metaInformationModel()->systemConfigurationModel()->machineSerialNumber();

      return QString("\nLog data from %1:\n\n[..]\n%2\n[..]\n").arg(serialNumber).arg(selectedRowsText.join("\n"));
    } else
      return selectedRowsText.join("\n");
  }
}

bool MdiChild::hasSelection() { return ui->view->selectionModel()->hasSelection(); }

void MdiChild::slotSelectionChanged(QItemSelection newSelection, QItemSelection oldSelection) {
  Q_UNUSED(oldSelection);
  emit copyAvailable(newSelection.count() != 0);
}

void MdiChild::adjustColumnWidth() {
  // ui->view->setColumnWidth(0,ui->view->columnWidth(0)+15);
  // ui->view->horizontalHeader()->setStretchLastSection(true);
  ui->view->resizeColumnsToContents();
}

void MdiChild::slotLoadingFinished(bool validLogFile) {
  if (!validLogFile) {
    //
    // if (QMessageBox::question(this,
    //                          tr("Log file"),
    //                          tr("The log file %1 appears not to be a CS8 log
    //                          file!"
    //                             "Do you want to open the file in an
    //                             alternative editor
    //                             instead?").arg(m_fileName),
    //                          QMessageBox::Yes,
    //                          QMessageBox::No)==QMessageBox::Yes)
    DialogAlternativeEditor dlg(this, m_fileName);
    if (dlg.exec()) {
    }
    deleteLater();
  } else {
    adjustColumnWidth();
  }
}

void MdiChild::slotWindowStateChanged(Qt::WindowStates /*oldState*/, Qt::WindowStates newState) {
  if (newState == Qt::WindowNoState)
    emit deactivated();
}

void MdiChild::slotFileChanged(const QString &fileName) {
  m_fileNameWatched = fileName;
  m_fileWatcherTimer->setSingleShot(true);
  m_fileWatcherTimer->stop();
  m_fileWatcherTimer->start(5000);
}

void MdiChild::slotFileChangedTimeout() {
  if (m_fileNameWatched == m_fileName && QFile::exists(m_fileNameWatched)) {
    if (QMessageBox::question(this, tr("File modification detected"),
                              tr("The log file %1 was modified. Do you want to reload it?").arg(m_fileNameWatched)) ==
        QMessageBox::Yes) {
      loadFile(m_fileNameWatched);
    }
  }
}

void MdiChild::slotLogMessageReceived() {
  if (m_scrollToBottomWhenLineReceived)
    ui->view->scrollToBottom();
}

void MdiChild::slotContextMenuRequested(QPoint point) {
  QModelIndex index = ui->view->indexAt(point);

  m_contextMenu->popup(ui->view->viewport()->mapToGlobal(point));
}

void MdiChild::showUSRMessages(bool show) {
  QApplication::setOverrideCursor(Qt::WaitCursor);
  m_filterModel->setHideUserMessages(!show);
  QApplication::restoreOverrideCursor();
}

void MdiChild::showInformation(bool show) {
  if (show) {
    ui->widgetInformation->show();
    ui->pushButton->setText(tr("Hide"));
  } else {
    ui->widgetInformation->hide();
    ui->pushButton->setText(tr("Show"));
  }
}

void MdiChild::scrollToLine(int line) {
  QModelIndex index = m_filterModel->mapFromSource(m_model->index(line, 0));
  ui->view->scrollTo(index, QAbstractItemView::PositionAtCenter);
  ui->view->selectRow(index.row());
}

void MdiChild::jumpToStart(int delta) {
  int startLine = 0;
  QRegExp rx;
  rx.setPattern("-{10,}.*");
  if (delta > 0) {
    int currentLine = ui->view->rowAt(ui->view->height());
    if (m_model->fileType() == cs8LogFileData::CS8)
      startLine = m_model->messageList().indexOf(rx, currentLine);
    else
      startLine = m_model->typeList().indexOf("run", currentLine);

    startLine = startLine == -1 ? m_model->rowCount() : startLine;
  } else {
    int currentLine = ui->view->rowAt(0);
    if (m_model->fileType() == cs8LogFileData::CS8)
      startLine = qMax(0, m_model->messageList().lastIndexOf(rx, currentLine));
    else
      startLine = qMax(0, m_model->typeList().lastIndexOf("run", currentLine));
  }
  scrollToLine(startLine);
}

void MdiChild::showSwapFileMessages(bool show) {
  QApplication::setOverrideCursor(Qt::WaitCursor);
  m_filterModel->setHideSwapFileMessages(!show);
  QApplication::restoreOverrideCursor();
}

void MdiChild::showErrorMessages(bool show) { m_filterModel->setShowError(show); }

void MdiChild::showWarningMessages(bool show) { m_filterModel->setShowWarning(show); }

void MdiChild::showInformationMessages(bool show) { m_filterModel->setShowInformation(show); }

void MdiChild::setReverseOrder(bool reverse) { m_filterModel->setReverseOrder(reverse); }

bool MdiChild::showsUSRMessages() { return !m_filterModel->hideUserMessages(); }

bool MdiChild::showsSwapFileMessages() { return !m_filterModel->hideSwapFileMessages(); }

bool MdiChild::showsInformationMesages() { return m_filterModel->showInformation(); }

bool MdiChild::showsWarningMessages() { return m_filterModel->showWarning(); }

bool MdiChild::showsErrorMessages() { return m_filterModel->showError(); }

bool MdiChild::reverseOrder() { return m_filterModel->reverseOrder(); }

void MdiChild::on_pushButton_clicked() { showInformation(!ui->widgetInformation->isVisible()); }

void MdiChild::socketStateChanged(QAbstractSocket::SocketState state) {
  switch (state) {
  case QAbstractSocket::ConnectedState:
    setWindowIcon(QIcon(":/icons/32x32/32x32/actions/network-connect.png"));
    break;

  default:
    setWindowIcon(QIcon(":/icons/32x32/32x32/actions/network-disconnect.png"));
    break;
  }
}
