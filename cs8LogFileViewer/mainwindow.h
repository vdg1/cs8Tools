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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dialoghighlightconfiguration.h"
#include <./ui_mainwindow.h>
#include <QMainWindow>

class MdiChild;
QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QMdiArea;
class QMdiSubWindow;
class QSignalMapper;
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow();

protected:
  void closeEvent(QCloseEvent *event);

public slots:
  void handleMessage(const QString &message);

signals:
  void needToShow();
  void highlightRulesChanged();

protected slots:
  void resizeSystemConfigViewColumns();

private slots:
  void slotDoubleClickedSystemConfig(const QModelIndex &index);
  void open();
  void copy(bool withRobotInfo = false);
  void about();
  void updateMenus();
  void updateWindowMenu();
  void updateRecentFileActions();

  void setActiveSubWindow(QWidget *window);

  void on_actOpen_triggered();

  void on_actCopy_triggered();

  void on_actExit_triggered();

  void on_actHide_USR_messages_triggered(bool checked);
  void openRecentFile();
  void loadFile(const QString &fileName_);
  void parseArguments();

  void on_actionHighlighting_triggered();
  void slotChildDeactivated();

  void on_actionNext_System_Start_triggered();

  void on_actionPrevious_System_Start_triggered();

  void on_actionHide_Swap_File_Messages_triggered(bool checked);

  void on_actionReverse_Order_triggered(bool checked);

  void on_actionOnline_triggered();

  void on_actionSend_selected_lines_to_triggered();

  void on_actionSave_as_triggered();

  void on_actionOpen_Machine_File_triggered();

  void on_actionScroll_to_Bottom_triggered(bool checked);

  void on_actionReset_Dialog_Options_triggered();

  void on_actionCopy_lines_and_add_info_triggered();

  void on_actionShow_Warnings_toggled(bool arg1);

  void on_actionShow_Information_toggled(bool arg1);

  void on_actionShow_Errors_toggled(bool arg1);

  void on_actionCreate_Annotation_triggered();

  void on_tbDeleteAnnotaion_triggered(QAction *arg1);

private:
  void createActions();
  void createMenus();
  void createStatusBar();
  void readSettings();
  void writeSettings();
  void readRules();
  void writeRules();
  void connectToController(const QString &address, quint16 port, bool loadLogFile);
  highlightItemList *highlightItems;
  MdiChild *createMdiChild();
  MdiChild *activeMdiChild();
  QMdiSubWindow *findMdiChild(const QString &fileName);
  Ui::MainWindow ui;

  QSignalMapper *windowMapper;

  QMenu *helpMenu;
  QMenu *m_contextMenu;
  QAction *closeAct;
  QAction *closeAllAct;
  QAction *tileAct;
  QAction *cascadeAct;
  QAction *nextAct;
  QAction *previousAct;
  QAction *separatorAct;
  QAction *aboutAct;
  QAction *aboutQtAct;

  QString m_dataDir;

  enum { MaxRecentFiles = 15 };
  QAction *recentFileActs[MaxRecentFiles];
};

#endif
