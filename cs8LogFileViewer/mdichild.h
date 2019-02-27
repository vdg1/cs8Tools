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

#ifndef MDICHILD_H
#define MDICHILD_H

#include <QAbstractSocket>
#include <QFileSystemWatcher>
#include <QItemSelection>
#include <QMdiSubWindow>
#include <QTextEdit>
#include <QTimer>

#include "cs8scrollbar.h"

class logFileModel;
class cs8LogFileFilterModel;

namespace Ui {
class mdiChild;
}

class MdiChild : public QMdiSubWindow {
  Q_OBJECT

public:
  explicit MdiChild(QWidget *parent = 0);

  bool loadFile(const QString &fileName);
  bool connectToHost(const QString &address, quint16 port, bool loadLogFile);
  bool hasSelection();
  QString userFriendlyCurrentFile();
  QString currentFile() const;
  QString currentFilePath() const;
  logFileModel *model() const;
  bool showsUSRMessages();
  bool showsSwapFileMessages();
  bool showsInformationMesages();
  bool showsWarningMessages();
  bool showsErrorMessages();
  bool reverseOrder();
  QString getSelectedLines(bool formated = true, bool withRobotInfo = false) const;

  void setContextMenu(QMenu *contextMenu);

  bool scrollToBottomWhenLineReceived() const;
  void setScrollToBottomWhenLineReceived(bool scrollToBottomWhenLineReceived);
  void selectedRowNumbers(int &start, int &end);

public slots:

  void showUSRMessages(bool show = true);
  void showInformation(bool show = true);
  void scrollToLine(int line);
  void jumpToStart(int delta);
  void showSwapFileMessages(bool show = true);
  void showErrorMessages(bool show = true);
  void showWarningMessages(bool show = true);
  void showInformationMessages(bool show = true);
  void setReverseOrder(bool reverse = false);

  void adjustColumnWidth();

protected:
  void closeEvent(QCloseEvent *);

signals:
  void copyAvailable(bool available);
  void deactivated();

protected slots:
  void slotSelectionChanged(QItemSelection newSelection, QItemSelection oldSelection);
  void slotLoadingFinished(bool validLogFile);
  void slotWindowStateChanged(Qt::WindowStates, Qt::WindowStates newState);
  void slotFileChanged(const QString &fileName);
  void slotFileChangedTimeout();
  void slotLogMessageReceived();
  void slotContextMenuRequested(QPoint point);

private slots:
  void on_pushButton_clicked();
  void socketStateChanged(QAbstractSocket::SocketState state);

private:
  void setCurrentFile(const QString &fileName);
  QString strippedName(const QString &fullFileName);
  void setupContextMenu();
  Ui::mdiChild *ui;
  QString curFile;
  QString m_fileName, m_fileNameWatched;
  bool m_scrollToBottomWhenLineReceived;

  logFileModel *m_model;
  cs8LogFileFilterModel *m_filterModel;
  cs8ScrollBar *scrollbar;
  QFileSystemWatcher *m_fileWatcher;
  QTimer *m_fileWatcherTimer;
  QMenu *m_contextMenu;
};

#endif
