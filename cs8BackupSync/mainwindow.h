#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>

#include <QFileSystemWatcher>
#include <QSystemTrayIcon>

class cs8CheckUpdate;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  void syncBackupsToRemote();
public slots:
  void handleMessage(const QString &message);
  void restoreSettings();
  void saveSettings();

signals:
  void needToShow();

protected:
  void changeEvent(QEvent *e);

protected slots:
  void iconActivated(QSystemTrayIcon::ActivationReason reason);
  void slotUpdateCheckFinished(const QStringList &updates, const QStringList &versions, bool error);

private slots:
  void on_pbRemotePathBrowse_clicked();

  void on_pbCatalogueFileBrowse_clicked();

  void on_cbEnableCatalogueImport_toggled(bool);

  void on_cbEnableSync_toggled(bool);

  void pollData();

  void updateCatalogue();

  void slotAskToQuit();

  void on_leCatalogueFile_textChanged(const QString &);

  void on_actionAbout_triggered();

  void on_actionAbout_Qt_triggered();

  void on_cbAvoidVpn_toggled(bool);

  void on_leMaintainer_editingFinished();

  void on_pbConfigureImport_clicked();

  void slotCheckUpdate();

  void on_cbAutoStart_toggled(bool);

  void on_leCatalogue_URL_editingFinished();

private:
  Ui::MainWindow *ui;
  QMenu *trayIconMenu;
  QSystemTrayIcon *trayIcon;
  QTimer *pollTimer;
  QFileSystemWatcher *watcher;
  cs8CheckUpdate *m_checkUpdate;

  QAction *restoreAction;
  QAction *quitAction;
  QAction *updateAction;
  void createTrayIcon();
  void createActions();
  void checkAutoStart();
};

#endif // MAINWINDOW_H
