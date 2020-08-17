#include "cs8logfiledata.h"

#include <QDebug>
#include <QRegularExpression>
#include <QTextStream>

QStringList cs8LogFileData::levelNames = QStringList() << "Anything"
                                                       << "INFO"
                                                       << "WARN"
                                                       << "ERROR"
                                                       << "UNDEFINED";

cs8LogFileData::cs8LogFileData(QObject *parent)
    : QObject(parent), m_hashLogFile(0) {}

void cs8LogFileData::load(QFile *file) {
  QTextStream in(file);
  QString input = in.readAll();
  m_hashLogFile = qHash(input);
  m_rawData = input.split("\n");
  process();
}

QString cs8LogFileData::guessDateFormat(const QStringList &lines) {
  QStringList dateFormats = QStringList() << "[MMM dd yyyy hh:mm:ss]"
                                          << "[dd/MM/yy hh:mm:ss]"
                                          << "[MM/dd/yy hh:mm:ss]";

  foreach (QString line, lines) {
    if (line.startsWith("[")) {
      /*
         QRegExp rx;
         rx.setPattern(
          "^\\[(JAN|FEB|MAR|APR|MAY|JUN|JUL|AUG|SEP|OCT|NOV|DEC)");
         if (rx.indexIn(line) != -1)
          format = "[MMM dd yyyy hh:mm:ss]";
         else
          format = "[dd/MM/yy hh:mm:ss]";
         qDebug() << "cs8LogModel::guessDateFormat: " << format;
         return format;
       */
      for (auto f : dateFormats) {
        qDebug() << line.split("]:").first();
        if (QDateTime::fromString(line.split("]:").first() + "]", f).isValid())
          return f;
      }
    }
  }
  return QString();
}

cs8LogFileData::FileType cs8LogFileData::fileType() const { return m_fileType; }

void cs8LogFileData::identifyTimeStamps() {
  if (m_fileType != CS9) {
    m_dateFormat = guessDateFormat(m_rawData);
    m_startDate = QDateTime();
    m_endDate = QDateTime();
    QLocale locale(QLocale::English, QLocale::UnitedKingdom);
    QDateTime recentTimestamp;
    int pos = 0;
    QString t;
    foreach (QString line, m_rawData) {
      pos = line.indexOf("]:");
      if (pos != -1) {
        recentTimestamp = locale.toDateTime(line.left(pos + 1), m_dateFormat);
        if (m_startDate.isNull()) {
          m_startDate = recentTimestamp;
        }
      }
    }
    if (!recentTimestamp.isNull())
      m_endDate = recentTimestamp;
  } else
    // 2017-05-05T09:17:49
    m_dateFormat = "yyyy-MM-ddThh:mm:ss";
  qDebug() << "Log file spans from " << m_startDate << " to " << m_endDate;
}

void cs8LogFileData::identifyFileContent() {

  // check if file is a CS9 log file
  if (m_rawData.at(0).startsWith(QStringLiteral("{\"entry\":")))
    m_fileType = CS9;
  else {
    // check if log file is a legacy CS8 file
    QRegExp rx("\\{([a-f0-9]{8})\\}$");
    if (m_rawData.at(0).contains(rx))
      m_fileType = CS8;
    else
      m_fileType = CS8;
  }
}

void cs8LogFileData::process() {
  qDebug() << "process start:" << QDateTime::currentDateTime();
  identifyFileContent();

  identifyTimeStamps();

  QRegularExpression rxTimeStamp("\\[(.*)\\]:");
  QRegularExpression rxId("<0x[a-f0-9]{4}>");
  QRegularExpression rxHash("\\{([a-f0-9]{8})\\}$");
  bool ok;
  m_data.clear();
  foreach (QString line, m_rawData) {
    logFileLineItem item;
    // qDebug() << rxHash.match(line) << rxId.match(line) <<
    // rxTimeStamp.match(line);
    item.hash = rxHash.match(line).captured(1).toInt(&ok, 16);
    line.remove(rxHash);
    item.id = rxId.match(line).captured(1);
    line.remove(rxId);
    item.date = QDateTime::fromString(rxTimeStamp.match(line).captured(1),
                                      m_dateFormat);
    line.remove(rxTimeStamp);
    item.message = line.simplified();
    m_data.append(item);
  }
  qDebug() << "process done:" << QDateTime::currentDateTime();
}

QDateTime cs8LogFileData::endDate() const { return m_endDate; }

QDateTime cs8LogFileData::startDate() const { return m_startDate; }

QString cs8LogFileData::dateFormat() const { return m_dateFormat; }

QStringList cs8LogFileData::rawData() const { return m_rawData; }

uint cs8LogFileData::hashLogFile() const { return m_hashLogFile; }
