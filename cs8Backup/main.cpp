/**************************************************************************
 *   Copyright (C) 2006 by Volker Drewer-Gutland                          *
 *   volker.drewer@gmx.de                                                     *
 **
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 **
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 **
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <QApplication>
#include <QSettings>
#include <QTranslator>

#include "cs8ControllerComponent.h"
#include "ftpwindow.h"
#include <stdio.h>
#include <stdlib.h>

#include "cs8systemlogging.h"
#include <../common/version.h>

int main(int argc, char *argv[]) {
  // qInstallMsgHandler(crashingMessageHandler);

  qDebug() << "Application start";
  Q_INIT_RESOURCE(cs8Backup);

  QApplication app(argc, argv);
  // Setting the Application version
  // app.setApplicationVersion( APP_VERSION );

  QCoreApplication::setOrganizationName("Saxe Group");
  QCoreApplication::setApplicationName("CS8 Tools");
  QCoreApplication::setApplicationVersion(PRODUCT_VERSION_STRING);

  LOGUTILS::initLogging();

  QSettings setting;

  QTranslator translator;
  translator.load(setting.value("lang").toString());
  qApp->installTranslator(&translator);

  // register cs8 file engine to QT
  // cs8FileEngineHandler engine;

  FtpWindow ftpWin;
  ftpWin.show();
  return app.exec();
}
