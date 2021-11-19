#include "logfilemodel.h"
#include "cs8logfiledata.h"
#include "cs8metainformationmodel.h"
#include "cs8systemconfigurationmodel.h"
#include "dialoghighlightconfiguration.h"

#include <QApplication>
#include <QCheckBox>
#include <QDebug>
#include <QLocale>
#include <QMessageBox>
#include <QProgressDialog>
#include <QStringList>
#include <QTextBlockFormat>
#include <QTextCursor>
#include <QtConcurrent>

logFileModel::logFileModel(QObject *parent)
    : QAbstractTableModel(parent), m_lastValidLineWithDate(0),
      telnetConnection(nullptr) {
  m_metaInformation = new cs8MetaInformationModel(this);
  connect(&m_watcher, &QFutureWatcherBase::finished, this,
          &logFileModel::slotLoadingFinished);
  connect(this, &logFileModel::p_setLogLine, this,
          &logFileModel::slotSetLogLine, Qt::QueuedConnection);
  connect(this, &logFileModel::p_setHighlight, this,
          &logFileModel::slotSetHighlight, Qt::QueuedConnection);
  connect(this, &logFileModel::p_setLogSize, this,
          &logFileModel::slotSetLogSize, Qt::QueuedConnection);
  connect(this, &logFileModel::p_resetHighlight, this,
          &logFileModel::slotResetHighlight, Qt::QueuedConnection);
  connect(this, &logFileModel::readingComplete, this,
          &logFileModel::slotReadingComplete, Qt::QueuedConnection);
  connect(m_metaInformation, &cs8MetaInformationModel::metaInformationAvailable,
          [=] { emit metaInformationAvailable(); });
}

logFileModel::~logFileModel() { m_future.waitForFinished(); }

cs8MetaInformationModel *logFileModel::metaInformationModel() const {
  return m_metaInformation;
}

QString logFileModel::URLId() const { return m_metaInformation->URLId(); }

/*
   int logFileModel::rowCount(const QModelIndex &parent) const
   {
    return logData.count ();
   }
 */

/*
 * int logFileModel::columnCount(const QModelIndex &parent) const
   {
    return 2;
   }
 */

/*
   QVariant logFileModel::data(const QModelIndex &index, int role) const
   {
    if (!index.isValid ())
        return QVariant();

    uint row=index.row ();
    if (role==Qt::DisplayRole)
    {
        if (index.column ()==0){
            return logData.at (row).timeStamp;
        }
        if (index.column ()==1){
            return logData.at (row).message;
        }
    }
    return QVariant();
   }
 */

void logFileModel::loadData(const QStringList &data) {
  m_future = QtConcurrent::run(this, &logFileModel::loadFileData, data);
  m_watcher.setFuture(m_future);
  // loadFileData(data);
  // slotLoadingFinished();
}
void logFileModel::slotSetLogLine(int row, const QDateTime &timeStamp,
                                  const QString &message, int level, double ms,
                                  const QString &type) {
  setLine(row, timeStamp, message, level, ms, type);
  // m_logData.append(message);
}

void logFileModel::slotSetHighlight(int row, QFont font, QBrush fgBrush,
                                    QBrush bgBrush, bool highLight_) {
  setData(index(row, 1), font, Qt::FontRole);
  setData(index(row, 1), bgBrush, Qt::BackgroundRole);
  setData(index(row, 1), fgBrush, Qt::ForegroundRole);
  if (highLight_)
    emit highLight(row, rowCount(), fgBrush);
}

void logFileModel::slotSetLogSize(int rowCount) {
  clear();
  setRowCount(rowCount);
}

void logFileModel::slotAppendRows(int rowCount) { Q_UNUSED(rowCount); }

void logFileModel::slotResetHighlight() { emit resetHighlight(); }

void logFileModel::slotLineReceived(const QString &data) {
  QStringList lines = data.split("\n");
  foreach (QString line, lines) {
    qDebug() << "Received line: " << line;
    QLocale locale(QLocale::English, QLocale::UnitedKingdom);
    QString message;
    QDateTime timeStamp;
    int pos = line.indexOf("]:");
    int lineNumber = rowCount();
    setRowCount(rowCount() + 1, -1);
    if (pos != -1) {
      QString t = line.left(pos + 1);
      /*item.*/ timeStamp = locale.toDateTime(t, m_dateFormat);
      /*item.*/ message = line.mid(pos + 3, 999);
      if (!m_firstTimeStampFound) {
        m_timeSpanFrom = /*item.*/ timeStamp;
        m_firstTimeStampFound = true;
      }
      m_timeSpanTill = /*item.*/ timeStamp;
      m_lastValidLineWithDate = lineNumber;
      m_diffToComputerTime = timeStamp.secsTo(QDateTime::currentDateTime());
    } else
      /*item.*/ message = line;
    lineNumber = rowCount() - 1;
    slotSetLogLine(lineNumber, timeStamp, message, cs8LogFileData::Anything, 0,
                   "msg");
    runHighlightRules(lineNumber, lineNumber);
    emit logMessageReceived();
  }
}

void logFileModel::slotStateChanged(QAbstractSocket::SocketState state) {
  qDebug() << "Socket state changed" << state;
}

QString logFileModel::filePath() const { return m_filePath; }

cs8LogFileData::FileType logFileModel::fileType() const { return m_fileType; }

qint64 logFileModel::diffToComputerTime() const { return m_diffToComputerTime; }

void logFileModel::slotRunHighlightRules() { runHighlightRules(); }

int logFileModel::swapLineCount() const { return m_swapLineCount; }

void logFileModel::preProcessData(const QStringList &lines) {
  Q_UNUSED(lines);
  // remove invalid lines at beginning of file
  // while (lines.count()>0 && !lines.at(0).startsWith("["))
  //    lines.removeAt(0);
  // remove swap tags in file
  // for(int i=1; i<lines.count(); i++)
  //{
  //    if (lines[i].contains("Log restarted after swap"))
  //        lines[i-1]="";
  //}
}

bool logFileModel::loadFileData(const QStringList &data) {
  // logData.clear ();
  bool validLogFile = true;
  m_lastValidLineWithDate = 0;
  m_logData.clear();

  preProcessData(data);

  QRegExp rx;
  rx.setPattern("(^\\[.*\\]): (.*)");

  // bool firstTimeStampFound=false;
  QLocale locale(QLocale::English, QLocale::UnitedKingdom);
  QString message;
  int level = 0;
  int lineNumber = 0;
  bool ok;
  double timeStamp;
  QDateTime dateTime;
  QDateTime dateTimeOffset;
  QString type;
  qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss")
           << "Start reading in file with " << data.count() << "rows";
  emit p_setLogSize(data.count());

  // check if file is valid
  if (data.count() == 0 || m_dateFormat == QString()) {
    validLogFile = false;
  }

  foreach (QString line, data) {
    if (m_fileType == cs8LogFileData::CS9) {
      QJsonDocument doc = QJsonDocument::fromJson(line.toUtf8());
      QJsonObject obj;
      QJsonValue value;
      QJsonArray dataArray;
      // check validity of the document
      if (!doc.isNull()) {
        if (doc.isObject()) {
          obj = doc.object();
          // valid log entry
          if (obj.keys().contains("entry")) {
            value = obj.value("entry");
            obj = value.toObject();
            // qDebug() << obj;
            dateTime = obj.value("date").toVariant().toDateTime();
            timeStamp = obj.value("ts").toVariant().toDouble(&ok);
            dataArray = obj.value("data").toArray();
            if (!ok)
              timeStamp = 0;

            type = obj.value("type").toString();
            level = cs8LogFileData::levelNames.indexOf(
                obj.value("lvl").toVariant().toString());
            level = level == -1 ? cs8LogFileData::Anything : level;

            if (type == QStringLiteral("msg")) {
              message = obj.value("val").toString();
            } else if (type == QStringLiteral("key")) {
              message = obj.value("val").toString();
            } else if (type == QStringLiteral("run")) {
              message = "";
              dateTimeOffset = dateTime;
            } else {
              qDebug() << "unknown entry type row " << lineNumber;
            }
            // replace place holders in message
            buildMessageString(message, dataArray);
            /*
             * if (dataArray.size() > 0) {
              QRegExp rx;
              rx.setPattern("(%[usdg]){1}");
              rx.setMinimal(false);
              rx.setCaseSensitivity(Qt::CaseInsensitive);
              int pos = 0;
              while ((pos = rx.indexIn(message, pos)) != -1) {
                QString val = dataArray.first()
                                  .toObject()
                                  .value("val")
                                  .toVariant()
                                  .toString();
                qDebug() << "Replace " << rx.cap(0) << " at pos " << pos
                         << " with " << val;
                message.replace(pos, rx.matchedLength(), val);
                dataArray.removeFirst();
                pos += rx.matchedLength();
              }
            }
*/

            // timeStamp=(timeStamp-floor(timeStamp))*1000;
            // store ms in QDateTime
            // qint64 ms=static_cast<qint64>((timeStamp-floor(timeStamp))*1000);
            // dateTime=dateTime.addMSecs(ms);
            // keep ns in separate field, because QDateTime does not support ns
            // timeStamp=timeStamp*1000;
            // timeStamp=static_cast<quint64>(((timeStamp)-floor(timeStamp))*1000);
            if (!m_firstTimeStampFound) {
              m_timeSpanFrom = /*item.*/ dateTime;
              m_firstTimeStampFound = true;
            }
            m_timeSpanTill = /*item.*/ dateTime;
            m_lastValidLineWithDate = lineNumber;

            emit p_setLogLine(lineNumber, dateTime, message, level, timeStamp,
                              type);
            lineNumber++;
          }
        } else {
          qDebug() << "Document is not an object" << endl;
        }
      } else {
        qDebug() << "Invalid JSON:" << line;
      }

    } else {
      // logFileLineItem item;
      int pos = line.indexOf("]:");
      if (pos != -1) {
        QString t = line.left(pos + 1);
        /*item.*/ dateTime = locale.toDateTime(t, m_dateFormat);
        /*item.*/ message = line.mid(pos + 3, 999);
        if (!m_firstTimeStampFound) {
          m_timeSpanFrom = /*item.*/ dateTime;
          m_firstTimeStampFound = true;
        }
        m_timeSpanTill = /*item.*/ dateTime;
        m_lastValidLineWithDate = lineNumber;
      } else
        /*item.*/ message = line;
      emit p_setLogLine(lineNumber, dateTime, message,
                        cs8LogFileData::Undefined, 0, "msg");
      lineNumber++;
    }
  }
  qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss")
           << "Reading completed";
  qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss")
           << "hash id:" << m_hashLogFile;
  emit readingComplete(validLogFile);
  return validLogFile;
}

QString logFileModel::logMessage(int row) const {
  QModelIndex idx = index(row, 2);
  if (!idx.isValid())
    return QString();
  return data(idx).toString();
}

QDateTime logFileModel::logTimeStamp(int row) const {
  QModelIndex idx = index(row, 0);
  if (!idx.isValid())
    return QDateTime();
  return data(idx, Qt::UserRole).toDateTime();
}

QString logFileModel::logTimeStampString(int row) const {
  QModelIndex idx = index(row, 0);
  if (!idx.isValid())
    return QString();
  return data(idx, Qt::UserRole).toDateTime().toString("MMM dd yyyy hh:mm:ss");
}

cs8LogFileData::MessageLevel logFileModel::logLevel(int row) const {
  QModelIndex idx = index(row, 1);
  if (!idx.isValid())
    return cs8LogFileData::Anything;
  return static_cast<cs8LogFileData::MessageLevel>(
      data(idx, Qt::UserRole).toInt());
}

qint64 logFileModel::ns(int row) const {
  QModelIndex idx = index(row, 0);
  if (!idx.isValid())
    return 0;
  return data(idx, Qt::UserRole).toInt();
}

uint logFileModel::hash() const { return m_hashLogFile; }

int logFileModel::lastValidLineWithTimeStamp() const {
  return m_lastValidLineWithDate;
}

QStringList logFileModel::messageList() { return m_logData.toStringList(); }

QStringList logFileModel::typeList() { return m_logData.messageTypes(); }

QString logFileModel::getLines(int start, int count) {
  QTextDocument doc;
  QTextCursor cursor(&doc);
  QTextCharFormat fmt;
  QBrush brush;
  QFont font;
  QString line;

  for (int row = qMax(0, start);
       row < qMin(qMax(0, start) + count, m_logData.size() - 1); ++row) {
    brush = m_logData[row].foregroundColor;
    font = m_logData[row].font;
    line = QString("%3:[%1]:%2\n")
               .arg(m_logData[row].date.toString("dd/MM/yyyy hh:mm:ss"))
               .arg(m_logData[row].message)
               .arg(row + 1, 5);

    fmt.setFont(font);
    fmt.setFontFamily("courier");
    fmt.setForeground(QBrush(brush.color()));
    cursor.movePosition(QTextCursor::EndOfBlock);
    cursor.setCharFormat(fmt);
    cursor.insertText(line);
  }
  return doc.toHtml();
}

void logFileModel::setHighlightRules(highlightItemList *list) {
  m_highlightRules = list;
}

void logFileModel::setLine(int row, const QDateTime &timeStamp,
                           const QString &message, int level, double ns,
                           const QString &type) {
  Q_ASSERT(row < rowCount());
  int r = row == -1 ? rowCount() - 1 : row;

  if (!setData(index(r, 0), timeStamp, Qt::DisplayRole))
    qDebug() << "Set timestamp failed " << rowCount() << row;
  setData(index(r, 0), ns, Qt::UserRole);
  setData(index(r, 2), message, Qt::DisplayRole);
  setData(index(r, 1), level, Qt::DisplayRole);

  setData(
      index(r, 2),
      QString("[%1]:%2").arg(timeStamp.toString("dd/MM/yy HH:mm:ss"), message),
      Qt::UserRole);
  setData(index(r, 1), type, Qt::UserRole);
}

QVariant logFileModel::headerData(int section, Qt::Orientation orientation,
                                  int role) const {
  if (role != Qt::DisplayRole)
    return QVariant();

  if (orientation == Qt::Horizontal) {
    switch (section) {
    case 0:
      return tr("Time Stamp");
      break;

    case 1:
      return tr("Level");
      break;

    case 2:
      return tr("Message");
      break;

    default:
      return QVariant();
      break;
    }
  }
  if (orientation == Qt::Vertical)
    return QString("%1").arg(section + 1);

  return QVariant();
}

bool logFileModel::setData(const QModelIndex &index, const QVariant &value,
                           int role) {
  if (!index.isValid() || index.row() >= m_logData.size())
    return false;

  switch (role) {
  case Qt::FontRole:
    m_logData[index.row()].font = qvariant_cast<QFont>(value);
    break;

  case Qt::DisplayRole:
    switch (index.column()) {
    case 0:
      m_logData[index.row()].date = value.toDateTime();
      break;

    case 1:
      m_logData[index.row()].level = value.toInt();
      break;

    case 2:
      m_logData[index.row()].message = value.toString().trimmed();
      break;
    }
    break;

  case Qt::ForegroundRole: {
    QBrush b = value.value<QBrush>();
    m_logData[index.row()].foregroundColor = b;
    break;
  }
  case Qt::BackgroundColorRole: {
    QBrush b = value.value<QBrush>();
    m_logData[index.row()].backgroundColor = b;
    break;
  }
  case Qt::UserRole:
    switch (index.column()) {
    case 0:
      m_logData[index.row()].ts = value.value<double>();
      break;
    case 1:
      m_logData[index.row()].type = value.toString();
      break;
    default:
      m_logData[index.row()].userData = value;
      break;
    }
  }
  return true;
}

bool logFileModel::loadLogFile(QFile *logFile, QFile *swapFile) {
  m_hashSwapFile = 0;
  m_swapLineCount = 0;
  m_firstTimeStampFound = false;

  cs8LogFileData logFileData;
  cs8LogFileData swapFileData;
  bool loadSwapFile = true;

  logFileData.load(logFile);
  m_filePath = logFile->fileName();
  m_hashLogFile = logFileData.hashLogFile();
  m_dateFormat = logFileData.dateFormat();
  m_fileType = logFileData.fileType();

  if (swapFile != nullptr) {
    swapFileData.load(swapFile);
    m_hashSwapFile = swapFileData.hashLogFile();
    m_swapLineCount = swapFileData.rawData().count();
    //
    // check time gap
    qint64 timeGap = swapFileData.endDate().secsTo(logFileData.startDate());
    bool timeGapTooBig = timeGap > /*5 * 60*/ 5 || timeGap < 0;

    if (timeGapTooBig) {
      switch (cs8MetaInformationModel::dlgIgnoreTimeGap(m_hashLogFile)) {
      case cs8MetaInformationModel::Unset: {
        QMessageBox dlg;
        QCheckBox *cb = new QCheckBox(tr("Don't ask me again for this file."));
        dlg.setText(
            tr("The time gap between the log file and the swap file is "
               "invalid."
               "The swap file ends at %1, the log file starts at %2. Do you "
               "still want to load the swap file?")
                .arg(swapFileData.endDate().toString("yyyy-MM-dd HH:mm:ss"))
                .arg(logFileData.startDate().toString("yyyy-MM-dd HH:mm:ss")));
        dlg.setWindowTitle(tr("Log Swap File"));
        dlg.setCheckBox(cb);
        dlg.setIcon(QMessageBox::Question);
        dlg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        if (dlg.exec() == QMessageBox::No) {
          loadSwapFile = false;
          cs8MetaInformationModel::setDlgIgnoreTimeGap(
              m_hashLogFile, cb->isChecked() ? cs8MetaInformationModel::No
                                             : cs8MetaInformationModel::Unset);
        } else
          cs8MetaInformationModel::setDlgIgnoreTimeGap(
              m_hashLogFile, cb->isChecked() ? cs8MetaInformationModel::Yes
                                             : cs8MetaInformationModel::Unset);
        break;
      }

      case cs8MetaInformationModel::No:
        loadSwapFile = false;
        break;

      default:
        loadSwapFile = true;
        break;
      }
    }
  }
  loadData(loadSwapFile ? swapFileData.rawData() + logFileData.rawData()
                        : logFileData.rawData());
  return true;
}

bool logFileModel::saveLogFile(const QString &fileName) {
  QFile file(fileName);
  if (!file.open(QFile::ReadWrite))
    return false;

  QTextStream out(&file);
  QString lineData;
  for (int line = 0; line < rowCount(); line++) {
    lineData = QString("[%1]: %2\n")
                   .arg(logTimeStampString(line))
                   .arg(logMessage(line));
    out << lineData;
  }
  file.close();
  return true;
}

void logFileModel::downloadLogFile(const QString &address) {
  QProgressDialog progressDlg("Loading file /log/errors.log", "", 0, 100,
                              qApp->activeWindow());
  progressDlg.setModal(true);
  progressDlg.setCancelButton(0);

  cs8Controller *controller = new cs8Controller(this);
  QByteArray buffer;
  controller->setAddress(address);
  controller->setLoginData("default", "");
  connect(controller, &cs8Controller::transferProgress,
          [&](qint64 done, qint64 total) {
            progressDlg.setMaximum(total);
            progressDlg.setValue(done);
          });
  if (controller->getFileContent("/log/errors.log", buffer)) {
    QTextStream in(buffer);
    loadData(in.readAll().split("\n"));
  } else {
    QMessageBox::critical(qApp->activeWindow(), tr("Error"),
                          tr("Loading file /log/errors.log failed: %1")
                              .arg(controller->lastError()));
  }
  controller->deleteLater();
}

bool logFileModel::connectToController(
    const cs8LogInterface::ControllerType type, const QString &address,
    quint16 port, bool loadLogFile) {
  m_dateFormat = "[MMM dd yyyy hh:mm:ss]";

  if (loadLogFile) {
    if (type == cs8LogInterface::CS8) {
      m_fileType = cs8LogFileData::CS8;
      downloadLogFile(address);
    } else {
      m_fileType = cs8LogFileData::CS9;
    }
  }

  telnetConnection = new cs8Telnet(this);
  telnetConnection->connectToHost(address, port);

  connect(telnetConnection, &cs8LogInterface::telnetLine, this,
          &logFileModel::slotLineReceived);

  connect(telnetConnection, &cs8LogInterface::connectionError,
          [=](const QAbstractSocket::SocketError error) {
            qDebug() << __FUNCTION__ << " Connection error: " << error;
          });
  connect(telnetConnection, &cs8LogInterface::stateChanged,
          [=](const QAbstractSocket::SocketState state) {
            qDebug() << __FUNCTION__ << " Connection state changed: " << state;
            emit stateChanged(state);
          });

  return true;
}

void logFileModel::process() {
  runHighlightRules();
  m_metaInformation->setLogData(this);
}

int logFileModel::rowCount(const QModelIndex &) const {
  return m_logData.size();
}

int logFileModel::columnCount(const QModelIndex &) const { return 3; }

QVariant logFileModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid() || index.row() >= m_logData.size())
    return false;

  QVariant val;
  switch (role) {
  case Qt::FontRole:
    val = m_logData[index.row()].font;
    break;

  case Qt::DisplayRole:
    switch (index.column()) {
    case 0: {
      val = m_logData[index.row()].date.toString("dd/MM/yyyy hh:mm:ss");
      break;
    }

    case 1: {
      val = m_logData[index.row()].level > 0
                ? cs8LogFileData::levelNames.at(m_logData[index.row()].level)
                : QString("");
      break;
    }

    case 2: {
      val = m_logData[index.row()].message;
      break;
    }
      /*
          case 3:
            double d = (double)m_logData[index.row()].ts;
            return QString("| %1").arg(d, 0, 'f', 4);
            */
    }
    break;

  case Qt::ForegroundRole: {
    val = m_logData[index.row()].foregroundColor;
    break;
  }
  case Qt::BackgroundColorRole: {
    val = m_logData[index.row()].backgroundColor;
    break;
  }
  case Qt::UserRole: {
    switch (index.column()) {
    case 0:
      val = m_logData[index.row()].date;
      break;
    case 1:
      val = m_logData[index.row()].level;
      break;
    default:
      val = m_logData[index.row()].userData;
      break;
    }
    break;
  }
  }
  return val;
}

void logFileModel::clear() {
  beginResetModel();
  m_logData.clear();
  endResetModel();
}

void logFileModel::setRowCount(int totalRowCount, int startRowForInsert) {
  if (totalRowCount == 0)
    return;
  int rowsToInsert = qMax(0, totalRowCount - rowCount());
  if (startRowForInsert == -1)
    startRowForInsert = rowCount();
  beginInsertRows(QModelIndex(), startRowForInsert,
                  startRowForInsert + rowsToInsert - 1);
  m_logData.resize(totalRowCount);
  // m_logData.resize(totalRowCount);
  // for (int i=startRowForInsert;i<totalRowCount;i++)
  //{
  //    m_tableData[i]=rowData;
  //}
  endInsertRows();
}

void logFileModel::runHighlightRules(int startRow_, int endRow_) {
  qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss")
           << "Running highlight rules ...";
  emit p_resetHighlight();
  for (int row = (startRow_ == -1 ? 0 : qMax(0, startRow_ - 1));
       row < (endRow_ == -1 ? rowCount() : endRow_); row++) {
    for (int rule = 0; rule < m_highlightRules->rowCount(); rule++) {
      QString line = logMessage(row);
      cs8LogFileData::MessageLevel level = logLevel(row);
      bool testHit;
      if (m_highlightRules->isRegularExpression(rule))
        testHit = line.contains(QRegExp(m_highlightRules->searchString(rule)));
      else
        testHit = line.contains(m_highlightRules->searchString(rule));
      if ((testHit && !(m_highlightRules->searchString(rule).isEmpty()) &&
           (level == cs8LogFileData::Anything ||
            level == cs8LogFileData::Undefined)) ||
          (m_highlightRules->searchString(rule).isEmpty() &&
           level == m_highlightRules->level(rule) &&
           level != cs8LogFileData::Undefined)) {
        QFont font;
        QBrush fgBrush, bgBrush;
        font.setBold(m_highlightRules->bold(rule));
        font.setItalic(m_highlightRules->italic(rule));
        bgBrush.setColor(m_highlightRules->backgroundColor(rule));
        fgBrush.setColor(m_highlightRules->foregroundColor(rule));

        emit p_setHighlight(row, font, fgBrush, bgBrush,
                            m_highlightRules->highlightInScrollbar(rule));
      }
    }
  }
  qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss")
           << "Running highlight rules completed";
}

void logFileModel::buildMessageString(QString &message,
                                      const QJsonArray &dataArray) {
    qDebug() << dataArray;
    for (auto data : dataArray) {
        qDebug() << data;
        if (data.toObject()["data"].isArray()) {
            QString intermediate = data.toObject()["val"].toString();
            buildMessageString(intermediate, data.toObject()["data"].toArray());
            // buildMessageString(data.toObject()["val"].toString(), message);
            QRegularExpression rx;
            rx.setPattern("(%[usdg]){1}");
            rx.setPatternOptions(rx.CaseInsensitiveOption);
            auto match = rx.match(message);
            message.replace(match.capturedStart(), match.capturedLength(),
                            intermediate);
        } else {
            QRegularExpression rx;
            rx.setPattern("(%[usdg]){1}");
            rx.setPatternOptions(rx.CaseInsensitiveOption);
            auto match = rx.match(message);
            message.replace(
                match.capturedStart(), match.capturedLength(),
                QString("%1").arg(
                    data.toObject().value("val").toVariant().toString()));
        }
    }
}

void logFileModel::slotLoadingFinished() {
  qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss")
           << "Loading completed";
  emit loadingFinished();
}

void logFileModel::slotReadingComplete(bool valid) {
  if (valid)
    process();
}
