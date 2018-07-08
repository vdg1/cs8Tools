#include "backupstorage.h"
#include <../common/machinecatalogue.h>
#include <QApplication>
#include <QDebug>
#include <QDirIterator>
#include <QFile>
#include <QProgressDialog>
#include <QtConcurrent/QtConcurrent>
#include <QtCore>

backupStorage::backupStorage(QObject *parent) : QObject(parent) {
  m_storageFileName = QString(getenv("COMPUTERNAME")) + ".bck";
}

void backupStorage::setStorageBasePath(const QString &path) {
  m_storageBasePath = path + "/";
}

void backupStorage::setAppDataPath(const QString &path) {
  m_appDataDir = path + "/";
}

QStringList backupStorage::backupSets(QString &base) {

  // read local machine catalogue
  QStringList localList = localCatalogue(m_appDataDir, m_storageBasePath, base);
  // read remote machine catalogue
  machineCatalogue remoteCatalogue;
  QStringList remoteList =
      remoteCatalogue.remoteCatalogue(m_storageBasePath, base);
  // merge lists
  localList.append(remoteList);
  // remove duplicates
  localList.removeDuplicates();
  qDebug() << "Found storage entries: " << localList;
  return localList;
}

void backupStorage::updateStorage(bool async) {
  if (!async) {
    QProgressDialog progress;
    progress.setLabelText(tr("Please wait. Updating storage information"));
    progress.setRange(0, 0);
    progress.setValue(0);
    qApp->processEvents();
    update(m_storageBasePath, m_storageBasePath);
    progress.reset();
  } else
    QtConcurrent::run(&update, m_storageBasePath, m_storageBasePath);
}

void backupStorage::addToStorage(const QString &newPath) {
  QFile file(m_storageBasePath + m_storageFileName);
  if (!file.open(QIODevice::Append | QIODevice::Text))
    return;
  file.write(newPath.toLatin1() + "\n");
  file.close();
}

void backupStorage::cleanupResultList(QStringList resultist) {
  QRegExp rx;
  rx.setPattern("F[0-9]{2}_.{6}_[A|C]_(\\d){2}");
  for (int i = 0; i < resultist.size(); ++i) {
    if (!resultist.at(i).contains(rx)) {
      resultist.removeAt(i);
      i--;
    }
  }
}

QStringList backupStorage::localCatalogue(const QString & /* dataPath */,
                                          const QString &storageBasePath,
                                          const QString &base) {
  QRegExp rx = QRegExp("(.*/|^)" + base + "[^/]*(?!/)$");
  QStringList list;

  QDir dir;
  dir.setCurrent(storageBasePath);
  QStringList bckFiles = dir.entryList(QStringList() << "*.bck");

  foreach (QString storageFileName, bckFiles) {
    qDebug() << "Loading storage " << storageFileName;
    QFile file(storageBasePath + storageFileName);
    if (!file.exists() || file.size() == 0) {
      qDebug() << "Need to update storage";
      updateStorage();
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      return QStringList();

    // QRegExp rx=QRegExp(".*/"+base+"\\w*(?!/)$");
    // .*/F07_57U5A1_C_01(\w|\s|\d|\.)*(?!/)$

    while (!file.atEnd()) {
      QString line = file.readLine();
      line.chop(1);
      if (line.contains(rx)) {
        QDir dir;
        if (dir.exists(storageBasePath + line))
          list << QDir::toNativeSeparators(storageBasePath + line);
      }
    }

    file.close();
  }
  return list;
}

void backupStorage::update(const QString &basePath, const QString &path) {
  qDebug() << "Updating storage...";
  QStringList resultist;

  updateRecursive(resultist, basePath, path);

  // clean up list
  QRegExp rx;
  rx.setPattern("F[0-9]{2}_.{6}_[A|C]_(\\d){2}");
  for (int i = 0; i < resultist.size(); ++i) {
    if (!resultist.at(i).contains(rx)) {
      resultist.removeAt(i);
      i--;
    }
  }

  QFile file(path + QString(getenv("COMPUTERNAME")) + ".bck");
  if (file.exists())
    file.remove();

  if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    return;

  QTextStream s(&file);
  s << resultist.join("\n"); // file.write (resultist.join ("\n"));
  file.close();
  qDebug() << "Updating storage...done";
}

void backupStorage::updateRecursive(QStringList &resultList,
                                    const QString &basePath,
                                    const QString &path) {

  QDir dir(path);
  QFileInfoList entryList =
      dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
  foreach (QFileInfo info, entryList) {
    if (info.isDir()) {
      bool isRobotDir = true;
      QDir d;
      if (d.exists(info.absoluteFilePath() + "/log") ||
          d.exists(info.absoluteFilePath() + "/usr") ||
          d.exists(info.absoluteFilePath() + "/sys"))
        isRobotDir = false;

      // do not search directories within a backup
      if (info.absoluteFilePath().endsWith("/log") ||
          info.absoluteFilePath().endsWith("/usr") ||
          info.absoluteFilePath().endsWith("/sys"))
        isRobotDir = false;

      QRegExp rx;
      rx.setPattern("F[0-9]{2}_.{6}_[A|C]_(\\d){2}");
      if (info.absoluteFilePath().split("/").last().contains(rx)) {
        resultList.append(
            info.absoluteFilePath().toLatin1().remove(0, basePath.length()));
        // resultList.write(info.absoluteFilePath().toLatin1().remove(0,
        // basePath.length()) + "\n");
        isRobotDir = false;
      }

      if (isRobotDir) {
        // write path name to file, remove backup directory prefix
        resultList.append(
            info.absoluteFilePath().toLatin1().remove(0, basePath.length()));
        // resultList.write(info.absoluteFilePath().toLatin1().remove(0,
        // basePath.length()) + "\n");
        updateRecursive(resultList, basePath, info.absoluteFilePath());
      }
    }
  }
}
