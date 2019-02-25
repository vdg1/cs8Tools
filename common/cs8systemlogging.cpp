#include "cs8systemlogging.h"

#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>
#include <QStandardPaths>
#include <QTime>
#include <iostream>

namespace LOGUTILS {
static QString logFileName;

void initLogFileName() {
  logFileName = QString(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation) + "/" + logFolderName +
                        "/Log_%1__%2.txt")
                    .arg(QFileInfo(QCoreApplication::applicationFilePath()).fileName())
                    .arg(QDateTime::currentDateTime().toString(Qt::ISODate).replace(":", "-"));
}

/**
 * @brief deletes old log files, only the last ones are kept
 */
void deleteOldLogs() {
  QDir dir;
  dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
  dir.setSorting(QDir::Time | QDir::Reversed);
  dir.setPath(QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation) + "/" + logFolderName);

  QFileInfoList list = dir.entryInfoList();
  if (list.size() <= LOGFILES) {
    return; // no files to delete
  } else {
    for (int i = 0; i < (list.size() - LOGFILES); i++) {
      QString path = list.at(i).absoluteFilePath();
      QFile file(path);
      file.remove();
    }
  }
}

bool initLogging() {
#ifdef NDEBUG
  // Create folder for logfiles if not exists
  QString logFolder = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation) + "/" + logFolderName;
  qDebug() << "Save logs to " << logFolder;
  if (!QDir(logFolder).exists()) {
    QDir().mkdir(logFolder);
  }

  deleteOldLogs();   // delete old log files
  initLogFileName(); // create the logfile name
  qDebug() << " write to log file:" << logFileName;
  QFile outFile(logFileName);
  if (outFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
    qInstallMessageHandler(LOGUTILS::myMessageHandler);
    return true;
  } else {
    return false;
  }
#else
  return true;
#endif
}

void myMessageHandler(QtMsgType type, const QMessageLogContext & /*context*/,
                      const QString &txt) {
    // check file size and if needed create new log!
    {
        QFile outFileCheck(logFileName);
        qint64 size = outFileCheck.size();

        if (size > LOGSIZE) // check current log size
        {
            deleteOldLogs();
            initLogFileName();
        }
    }

    QFile outFile(logFileName);
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);

    switch (type) {
    case QtInfoMsg:
        ts << QDateTime::currentDateTime().toString(Qt::ISODate)
           << ":I: " << txt << endl;
        break;
    case QtDebugMsg:
        ts << QDateTime::currentDateTime().toString(Qt::ISODate)
           << ":D: " << txt << endl;
        break;
    case QtWarningMsg:
        ts << QDateTime::currentDateTime().toString(Qt::ISODate)
           << ":W: " << txt << endl;
        break;
    case QtCriticalMsg:
        ts << QDateTime::currentDateTime().toString(Qt::ISODate)
           << ":C: " << txt << endl;
        break;
    case QtFatalMsg:
        ts << QDateTime::currentDateTime().toString(Qt::ISODate)
           << ":F: " << txt << endl;
    }
}
} // namespace LOGUTILS
