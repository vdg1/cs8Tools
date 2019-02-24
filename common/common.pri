MAJOR_VERSION=5
MINOR_VERSION=7


VERSION = 5.7

# Define the preprocessor macro to get the application version in our application.
DEFINES += APP_VERSION=\\\"$$VERSION\\\"

INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD
QT += network xml sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    ../common/aboutdialog.h \
    ../common/version.h \
    ../common/vpnconnectivity.h \
    ../common/machinecatalogue.h \
    ../common/dialogmachinecatalogueimportconfiguration.h \
    #$$PWD/qxtcsvmodel.h \
    #$$PWD/qxtglobal.h \
    $$PWD/cs8checkupdate.h \
    $$PWD/dialoggetmachinedata.h \
    $$PWD/databaseconnection.h \
    $$PWD/xlstablemodel.h \
    $$PWD/dialogwhatsnew.h \
    $$PWD/cs8systemlogging.h \
    $$PWD/cs8serialnumbervalidator.h

SOURCES += \
    ../common/aboutdialog.cpp \
    ../common/vpnconnectivity.cpp \
    ../common/machinecatalogue.cpp \
    ../common/dialogmachinecatalogueimportconfiguration.cpp \
    #$$PWD/qxtcsvmodel.cpp \
    $$PWD/cs8checkupdate.cpp \
    $$PWD/dialoggetmachinedata.cpp \
    $$PWD/databaseconnection.cpp \
    $$PWD/xlstablemodel.cpp \
    $$PWD/dialogwhatsnew.cpp \
    $$PWD/cs8systemlogging.cpp \
    $$PWD/cs8serialnumbervalidator.cpp

FORMS += \
    $$PWD/ui/aboutDialog.ui \
    $$PWD/ui/dialoggetmachinedata.ui \
    $$PWD/ui/dialogmachinecatalogueimportconfiguration.ui \
    $$PWD/dialogwhatsnew.ui \
    $$PWD/dialogwhatsnew.ui

# increase build number
# increase build number only in release mode
CONFIG(release, debug|release) {
    build_nr.commands = $$PWD/build_inc.bat $$shell_path($$_PRO_FILE_PWD_)
    build_nr.depends = FORCE
    QMAKE_EXTRA_TARGETS += build_nr
    PRE_TARGETDEPS += build_nr
    system(build_inc.bat $$shell_path($$_PRO_FILE_PWD_))
}
BUILD_NO=$$cat($$_PRO_FILE_PWD_"/build.txt")

# set version information
# message($$_PRO_FILE_PWD_"/build.txt >> "$$BUILD_NO)
NW_VERSION=$${MAJOR_VERSION}.$${MINOR_VERSION}.$${BUILD_NO}
SED=$$quote(C:\Progra~2\GnuWin32\bin\sed.exe  s/Revision://g)

DEFINES += "VERSION_RC=$${NW_VERSION}"
#NW_SVN = $$system(svnversion $$_PRO_FILE_PWD_ -n)
#NW_SVN = $$system(svn info $$_PRO_FILE_PWD_ | findstr "Revision: " | $${SED})
#DEFINES += "SVN_RC=$${NW_SVN}"
DEFINES += "PRODUCT_VERSION_STRING=\\\"$${NW_VERSION}\\\""
#PROD_VERSION=$${NW_VERSION}.$${NW_SVN}
PROD_VERSION=$${NW_VERSION}
# BUILDDATE = $$system(echo %date:/=-% )
BUILDDATE=$$system(powershell get-date -format "{yyyy-MM-dd}")
message("product version of $$_PRO_FILE_PWD_: "$${PROD_VERSION}" date: "$${BUILDDATE})

# update package files
package=$$cat($$PACKAGE_DIR/meta/package.template.xml,blob)
package=$$replace(package, _VERSION_, $$PROD_VERSION)
package=$$replace(package, _DATE_, $$BUILDDATE)
write_file($$PACKAGE_DIR/meta/package.xml,package)


#RESOURCES += \
#    ../common/version.qrc

include(./thirdParty/qtsingleapplication/qtsingleapplication.pri)
include(./thirdParty/QtXlsxWriter/src/xlsx/qtxlsx.pri)


DISTFILES += \
    build_inc.bat \
    $$PWD/build_inc.bat
