TEMPLATE = subdirs
CONFIG += c++11 no_batch

SUBDIRS = version \
         cs8Backup\
          cs8BackupSync \
          cs8LogFileViewer \
          installer

installer.depends=cs8Backup cs8BackupSync cs8LogFileViewer
