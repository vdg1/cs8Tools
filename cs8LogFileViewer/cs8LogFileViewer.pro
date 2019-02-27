
TEMPLATE = app



PACKAGE_DIR=$$PWD/../installer/packages/org.vdg.cs8Tools.cs8LogViewer
include (../common/common.pri)
HEADERS       += mainwindow.h \
                mdichild.h \
    logfilemodel.h \
    cs8systemconfigurationmodel.h \
    cs8systemconfigurationset.h \
    cs8metainformationmodel.h \
    logfiledetailedinformationform.h \
    cs8searchwidget.h \
    dialoghighlightconfiguration.h \
    cs8colorlabel.h \
    cs8scrollbar.h \
    dialogrobotdetails.h \
    cs8robotcataloguetable.h \
    dialogalternativeeditor.h \
    cs8logfilefiltermodel.h \
    cs8logfiledata.h \
    cs8connectdialog.h \
    logfiledata.h \
    cs8logfileannotations.h \
    cs8annotationeditor.h

SOURCES       += main.cpp \
                mainwindow.cpp \
                mdichild.cpp \
    logfilemodel.cpp \
    cs8systemconfigurationmodel.cpp \
    cs8systemconfigurationset.cpp \
    cs8metainformationmodel.cpp \
    logfiledetailedinformationform.cpp \
    cs8searchwidget.cpp \
    dialoghighlightconfiguration.cpp \
    cs8colorlabel.cpp \
    cs8scrollbar.cpp \
    dialogrobotdetails.cpp \
    cs8robotcataloguetable.cpp \
    dialogalternativeeditor.cpp \
    cs8logfilefiltermodel.cpp \
    cs8logfiledata.cpp \
    cs8connectdialog.cpp \
    logfiledata.cpp \
    cs8logfileannotations.cpp \
    cs8annotationeditor.cpp

DESTDIR = ../bin


FORMS += \
    forms/mainwindow.ui \
    forms/mdiChild.ui \
    forms/logfiledetailedinformationform.ui \
    forms/cs8searchwidget.ui \
    forms/dialoghighlightconfiguration.ui \
    dialogrobotdetails.ui \
    dialogalternativeeditor.ui \
    forms/cs8connectdialog.ui \
    cs8annotationeditor.ui

QT += sql widgets gui concurrent winextras

OTHER_FILES +=  resource/resources.rc
RC_FILE = resource/resources.rc
RESOURCES     +=  resource/cs8logviewer.qrc ../../Icons/resources.qrc

LIBS += -lWs2_32



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../_Libraries/cs8Components/cs8Components/lib/ -lcs8ControllerComponent
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../_Libraries/cs8Components/cs8Components/lib/ -lcs8ControllerComponentd

INCLUDEPATH += $$PWD/../../_Libraries/cs8Components/cs8Components/include
DEPENDPATH += $$PWD/../../_Libraries/cs8Components/cs8Components/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../_Libraries/cs8Components/cs8Components/lib/libcs8ControllerComponent.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../_Libraries/cs8Components/cs8Components/lib/libcs8ControllerComponentd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../_Libraries/cs8Components/cs8Components/lib/cs8ControllerComponent.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../_Libraries/cs8Components/cs8Components/lib/cs8ControllerComponentd.lib

CONFIG(release, debug|release) {
  message( "release" )
}
CONFIG(debug, debug|release) {
  message( "debug" )
}
