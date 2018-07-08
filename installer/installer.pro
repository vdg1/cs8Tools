TEMPLATE = aux

INSTALLER = cs8Tools_Installer

QFIW_DIR=D:/Qt/Tools/QtInstallerFramework/3.0
INPUT = $$PWD/config/config.xml $$PWD/packages

Backup.input = $$PWD/../bin/cs8Backup.exe $$PWD/../bin/cs8BackupSync.exe
Backup.output = $$INSTALLER
Backup.commands = $$QFIW_DIR/bin/archivegen $$PWD/packages/org.vdg.cs8Tools.cs8Backup/data/data.z7 $$Backup.input
Backup.CONFIG += target_predeps no_link combine

LogFileViewer.input = $$PWD/../bin/cs8logFileViewer.exe $$PWD/../bin/settings.ini
LogFileViewer.output = $$INSTALLER
LogFileViewer.commands = $$QFIW_DIR/bin/archivegen $$PWD/packages/org.vdg.cs8Tools.cs8LogViewer/data/data.z7 $$LogFileViewer.input
LogFileViewer.CONFIG += target_predeps no_link combine

root.input = INPUT
root.output = $$INSTALLER
root.commands = $$QFIW_DIR/bin/binarycreator -v --online-only -c $$PWD/config/config.xml  -p $$PWD/packages --exclude org.vdg.cs8Tools,org.vdg.cs8Tools.cs8Backup,org.vdg.cs8Tools.cs8LogViewer cs8ToolsInstaller.exe
#-p $$PWD/packages
root.CONFIG += target_predeps no_link combine
root.depends = Backup LogFileViewer

repository.input = INPUT
repository.output = $$INSTALLER
repository.commands = "$$QFIW_DIR/bin/repogen.exe -v -r -p $$PWD/packages -i org.vdg.cs8Tools,org.vdg.cs8Tools.cs8Backup,org.vdg.cs8Tools.cs8LogViewer $$PWD/repository"
repository.CONFIG += target_predeps no_link combine
repository.depends = root

CONFIG(release, debug|release) {
QMAKE_EXTRA_TARGETS += LogFileViewer
QMAKE_EXTRA_TARGETS += Backup
QMAKE_EXTRA_TARGETS += repository
QMAKE_EXTRA_TARGETS += root

PRE_TARGETDEPS += root Backup LogFileViewer repository
}

DISTFILES += \
    packages/org.vdg.cs8Tools/meta/package.xml \
    packages/org.vdg.cs8Tools/meta/installscript.qs \
    packages/org.vdg.cs8Tools.cs8Backup/meta/installscript.qs \
    packages/org.vdg.cs8Tools.cs8LogViewer/meta/installscript.qs \
    config/config.xml \
    packages/org.vdg.cs8Tools.cs8Backup/meta/package.template.xml \
    packages/org.vdg.cs8Tools.cs8LogViewer/meta/package.template.xml \
    packages/org.vdg.cs8Tools/data/Readme.txt \
    createInstaller.bat

FORMS += \
    packages/org.vdg.cs8Tools.cs8Backup/meta/readmecheckboxform.ui

