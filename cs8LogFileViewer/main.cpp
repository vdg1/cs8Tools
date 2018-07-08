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

#include <QApplication>
#include <qtsingleapplication.h>

#include "cs8systemlogging.h"
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QCoreApplication::setOrganizationName("SAXE Group");
  QCoreApplication::setApplicationName("CS8 Tools");
  QCoreApplication::setApplicationVersion(PRODUCT_VERSION_STRING);
  SharedTools::QtSingleApplication instance("CS8 Log File Viewer", argc, argv);

  LOGUTILS::initLogging();

  // Q_INIT_RESOURCE(resources);
  /*
     QApplication app(argc, argv);
     MainWindow mainWin;
   #if defined(Q_OS_SYMBIAN)
     mainWin.showMaximized();
   #else
     mainWin.show();
   #endif
     return app.exec();
   */

  // QApplication instance(argc, argv);
  QString message;
  for (int a = 1; a < argc; ++a) {
    message += argv[a];
    if (a < argc - 1)
      message += "@@";
  }
  if (!message.isEmpty())
    message = "[open]@@" + message;

  if (instance.sendMessage(message))
    return 0;

  MainWindow mw;

  instance.setActivationWindow(&mw, true);
  QObject::connect(&instance, &SharedTools::QtSingleApplication::messageReceived, &mw, &MainWindow::handleMessage);

  // instance.setActivationWindow(&mw, false);
  QObject::connect(&mw, &MainWindow::needToShow, &instance, &SharedTools::QtSingleApplication::activateWindow);
  mw.handleMessage(message);
  mw.show();
  return instance.exec();
}
