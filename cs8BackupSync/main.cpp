#include "mainwindow.h"

#include "cs8systemlogging.h"
#include "qtsingleapplication.h"
#include <../common/version.h>
#include <QApplication>
#include <QMessageBox>
#include <QSystemTrayIcon>

#include <QDebug>

#include <../common/vpnconnectivity.h>

int main(int argc, char *argv[]) {

  // Q_INIT_RESOURCE(cs8BackupSync);

  QCoreApplication::setOrganizationName("Saxe Group");
  QCoreApplication::setApplicationName("CS8 Tools");
  QCoreApplication::setApplicationVersion(PRODUCT_VERSION_STRING);
  SharedTools::QtSingleApplication instance("CS8 Backup 2 Sync", argc, argv);

  LOGUTILS::initLogging();

  QString message;
  for (int ar = 1; ar < argc; ++ar) {
    message += argv[ar];
    if (ar < argc - 1)
      message += " ";
  }

  if (instance.sendMessage(message))
    return 0;

  MainWindow mw;
  QObject::connect(&instance, &SharedTools::QtSingleApplication::messageReceived, &mw, &MainWindow::handleMessage);
  mw.handleMessage(message);
  // mw.show();

  instance.setActivationWindow(&mw, false);

  QObject::connect(&mw, &MainWindow::needToShow, &instance, &SharedTools::QtSingleApplication::activateWindow);

  if (!QSystemTrayIcon::isSystemTrayAvailable()) {
    QMessageBox::critical(0, QObject::tr("cs8BackupSync"),
                          QObject::tr("I couldn't detect any system tray on this system."));
    return 1;
  }
  QApplication::setQuitOnLastWindowClosed(false);

  return instance.exec();
}
