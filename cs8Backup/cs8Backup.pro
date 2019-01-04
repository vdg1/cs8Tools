HEADERS = selectbackupfolderdialog.h \
    getserialnumberdialog.h \
    downloaddirdialog.h \
    ftpwindow.h \
    detailprogressdialog.h \
    zipper.h \
    settingsdialog.h \
    backupstorage.h \
    zip/zip.h \
    zip/unzip.h \
    zip/quazipnewinfo.h \
    zip/quazipfileinfo.h \
    zip/quazipfile.h \
    zip/quazip.h \
    zip/ioapi.h \
    zip/crypt.h \
    zlib/zutil.h \
    zlib/zlib.h \
    zlib/zconf.in.h \
    zlib/zconf.h \
    zlib/trees.h \
    zlib/inftrees.h \
    zlib/inflate.h \
    zlib/inffixed.h \
    zlib/inffast.h \
    zlib/deflate.h \
    zlib/crc32.h \
    wizardcreatebackup.h
SOURCES = selectbackupfolderdialog.cpp \
    getserialnumberdialog.cpp \
    downloaddirdialog.cpp \
    ftpwindow.cpp \
    main.cpp \
    zipper.cpp \
    detailprogressdialog.cpp \
    settingsdialog.cpp \
    backupstorage.cpp \
    zip/zip.c \
    zip/unzip.c \
    zip/quazipnewinfo.cpp \
    zip/quazipfile.cpp \
    zip/quazip.cpp \
    zip/ioapi.c \
    zlib/zutil.c \
    zlib/uncompr.c \
    zlib/trees.c \
    zlib/inftrees.c \
    zlib/inflate.c \
    zlib/inffast.c \
    zlib/infback.c \
    zlib/gzio.c \
    zlib/deflate.c \
    zlib/crc32.c \
    zlib/compress.c \
    zlib/adler32.c \
    wizardcreatebackup.cpp

RESOURCES += cs8Backup.qrc

QT += network \
    xml \
gui concurrent winextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets




FORMS = ui/downloaddirdialog.ui \
    ui/getserialnumberdialog.ui \
    ui/mainForm.ui \
    ui/settingsForm.ui \
    ui/selectbackupfolderdialog.ui \
    ui/detailProgressDialog.ui \
    wizardcreatebackup.ui



TARGET = cs8backup
TEMPLATE = app
DESTDIR =../bin



TRANSLATIONS += cs8backup_de.ts \
    cs8backup_se.ts \
    cs8backup_en.ts


RC_FILE += cs8res.rc

OTHER_FILES += \
    cs8res.rc

PACKAGE_DIR=$$PWD/../installer/packages/org.vdg.cs8Tools.cs8Backup
include (../common/common.pri)



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../_Libraries/cs8Components/cs8Components/lib/ -lcs8ControllerComponent
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../_Libraries/cs8Components/cs8Components/lib/ -lcs8ControllerComponentd

INCLUDEPATH += $$PWD/../../_Libraries/cs8Components/cs8Components/include
DEPENDPATH += $$PWD/../../_Libraries/cs8Components/cs8Components/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../_Libraries/cs8Components/cs8Components/lib/libcs8ControllerComponent.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../_Libraries/cs8Components/cs8Components/lib/libcs8ControllerComponentd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../_Libraries/cs8Components/cs8Components/lib/cs8ControllerComponent.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../_Libraries/cs8Components/cs8Components/lib/cs8ControllerComponentd.lib

DISTFILES += \
    releasenotes.txt

CONFIG(release, debug|release) {
  message( "release" )
}
CONFIG(debug, debug|release) {
  message( "debug" )
}
