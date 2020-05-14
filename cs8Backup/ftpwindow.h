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

#ifndef FTPWINDOW_H
#define FTPWINDOW_H

#include "ui_mainForm.h"
#include "zipper.h"
#include <QDateTime>
#include <QHash>
#include <QMainWindow>
#include <QSqlTableModel>

class QFile;
class QDir;
class QLabel;
class QLineEdit;
class QListWidget;
class QListWidgetItem;
class QProgressDialog;
class QPushButton;
class QUrlInfo;
class QDomElement;
class QStatusBar;
class QComboBox;
class QMovie;
class cs8NetworkScanner;
class cs8Controller;
class QFtp;
class DetailProgressDialog;
class cs8CheckUpdate;
class QWinTaskbarButton;

class FtpWindow : public QMainWindow {
  Q_OBJECT
  Q_ENUMS(State)

protected slots:
  void slotSelectDownLoadDir();

public:
  FtpWindow(QWidget *parent = nullptr);
  ~FtpWindow();

  void startSyncProcess();
  bool storeBackupLog(const QString &serialNumber, const QString &backupName,
                      const QString &baseDir);

  enum State { Idle, Scanning, PreparingBackup, LoadFileList, DownloadFiles };
private slots:

  void cancelDownload();
  void compressingFile(const QString fileName, int idx, int count);
  void completed(bool result);

  void updateDataTransferRate(qint64, qint64, qint64 rate);
  void recursiveList(const QStringList &path);
  QString getSerialNumber();
  void downloadFiles();
  QString orderNumber(const QDomElement &element);
  void readHistory();
  void writeHistory();
  void on_action_About_triggered();
  void on_action_About_Qt_triggered();
  void on_action_Default_Backup_Settings_triggered();
  void on_actionLanguage_triggered();
  void on_action_User_Interface_triggered();
  void on_btSelectDownloadDir_clicked();
  void on_btDownload_clicked();

  void slotOnlineState(bool online, int, const QString &errorString);
  void on_leUserName_textEdited(QString);
  void on_lePassword_textEdited(QString);

  void slotScannerStarted();
  void slotScannerStopped();
  void slotScanCompleted(uint count);
  void slotDetected(const QString &);

  void on_actionRescan_Updates_triggered();

  void on_btUpdate_clicked();
  void on_action_Preferences_triggered();

  void on_leDownloadDir_textChanged(const QString &arg1);
  void slotSelectionChanged(QItemSelection topLeft, QItemSelection bottomRight);

  void on_pushButtonExplore_clicked();
  void updateFTPUserProfile();

  void on_actionCheck_for_Updates_triggered();

  void on_leIPAddress_editTextChanged(const QString &);

private:
  DetailProgressDialog *m_progressDialog;
  Ui::MainWindow ui;
  QHash<QString, bool> isDirectory;
  cs8NetworkScanner *m_scanner;
  cs8Controller *m_controller;
  QLabel *m_transferRateLabel;
  QMovie *m_ScannerMovie;
  QMovie *m_LoadingDataMovie;
  cs8CheckUpdate *m_checkUpdate;
  QWinTaskbarButton *m_button;
  QSqlTableModel *m_backupDataTable;
  QTimer *m_timerDelayedProfileUpdate;
  int nConfigCmdID;
  QString configBuffer;
  QString m_serialNumber;
  QString m_downloadDir;
  QString m_backupName;
  zipper zip;
  QString m_appData;
  QString m_defaultDir;
  bool prepareDownload();
  void saveSettings();
  QString getBackupName(const QString &serialNumber_);
  State m_state;
  void setFileTimestamp(const QString &fileName_, const QDateTime &timeStamp_);
  void setupPaths();
  void restoreWindow();
  void setupUi();
  void createObjects();
  void checkDBTables();
  bool validateDownloadDir(QString &validationResult);
  bool bBlockDownload;

protected:
  void closeEvent(QCloseEvent *event) override;
  bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif
