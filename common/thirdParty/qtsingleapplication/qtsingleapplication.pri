INCLUDEPATH	+= $$PWD
DEPENDPATH      += $$PWD
HEADERS		+= $$PWD/qtsingleapplication.h $$PWD/qtlocalpeer.h
SOURCES		+= $$PWD/qtsingleapplication.cpp $$PWD/qtlocalpeer.cpp

QT *= network widgets
include(../qtlockedfile/qtlockedfile.pri)

gotqtlockedfile = $$find(HEADERS, .*qtlockedfile.h)
isEmpty(gotqtlockedfile):include(../qtlockedfile/qtlockedfile.pri)
x
win32:contains(TEMPLATE, lib):contains(CONFIG, shared) {
  message(Building lib)
    DEFINES += QT_QTSINGLEAPPLICATION_EXPORT=__declspec(dllexport)
}
