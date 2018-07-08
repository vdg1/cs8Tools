#-------------------------------------------------
#
# Project created by QtCreator 2014-01-12T19:45:32
#
#-------------------------------------------------

QT       += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = cs8BackupSync
TEMPLATE = app
DESTDIR = ../bin

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

OTHER_FILES +=  resource/resources.rc
RC_FILE += resource/resources.rc

MAJOR_VERSION=5
MINOR_VERSION=1

include (../common/common.pri)

RESOURCES += \
    resources.qrc
