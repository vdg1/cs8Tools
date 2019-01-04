#ifndef LOGFILEMODEL_H
#define LOGFILEMODEL_H

#include "cs8ControllerComponent.h"
#include "cs8logfiledata.h"
#include "logfiledata.h"
//#include "qttelnet.h"
#include <QDateTime>
#include <QFile>
#include <QFuture>
#include <QFutureWatcher>
#include <QStandardItemModel>

class cs8MetaInformationModel;
class cs8SystemConfigurationModel;
class highlightItemList;

/*
struct cellData
{
    QString text;
    QVariant userData;
    QBrush foregroundColor, backgroundColor;
};
*/

class logFileModel : public QAbstractTableModel {
  Q_OBJECT
public:
  explicit logFileModel(QObject *parent = 0);
  ~logFileModel();

  cs8MetaInformationModel *metaInformationModel() const;
  QString URLId() const;
  QString logMessage(int row) const;
  QDateTime logTimeStamp(int row) const;
  QString logTimeStampString(int row) const;
  cs8LogFileData::MessageLevel logLevel(int row) const;
  qint64 ns(int row) const;
  uint hash() const;
  int lastValidLineWithTimeStamp() const;
  QStringList messageList();
  QStringList typeList();

  int rowCount(const QModelIndex & = QModelIndex()) const;
  int columnCount(const QModelIndex & = QModelIndex()) const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  QVariant headerData(int section, Qt::Orientation orientation, int role) const;
  bool setData(const QModelIndex &index, const QVariant &value, int role);
  bool loadLogFile(QFile *logFile, QFile *swapFile = nullptr);
  bool saveLogFile(const QString &fileName);
  bool connectToController(const cs8LogInterface::ControllerType type, const QString &address, quint16 port,
                           bool loadLogFile);
  int swapLineCount() const;

  qint64 diffToComputerTime() const;

  cs8LogFileData::FileType fileType() const;

signals:
  void loadingFinished();
  void readingComplete(bool);
  void highLight(int, int, QBrush);
  void resetHighlight();

  // internal signals
  void p_resetHighlight();
  void p_setLogLine(uint, const QDateTime &, const QString &, int, double, const QString &);
  void p_setHighlight(int, QFont, QBrush, QBrush, bool);
  void p_setLogSize(int);
  void logMessageReceived();
  void stateChanged(QAbstractSocket::SocketState state);
  void metaInformationAvailable();

public slots:
  void setHighlightRules(highlightItemList *list);
  void setLine(int row, const QDateTime &timeStamp, const QString &message, int level, double ns, const QString &type);
  void slotRunHighlightRules();

protected:
  void downloadLogFile(const QString &address);

protected slots:
  void slotLoadingFinished();
  void slotReadingComplete(bool valid);
  void slotSetLogLine(int row, const QDateTime &timeStamp, const QString &message, int level, double ms,
                      const QString &type);
  void slotSetHighlight(int row, QFont font, QBrush fgBrush, QBrush bgBrush, bool highLight_);
  void slotSetLogSize(int rowCount);
  void slotAppendRows(int rowCount);
  void slotResetHighlight();
  void slotLineReceived(const QString &data);
  void slotStateChanged(QAbstractSocket::SocketState state);

private:
  QString m_dateFormat;
  uint m_hashSwapFile, m_hashLogFile;
  int m_lastValidLineWithDate;
  int m_swapLineCount;
  bool m_firstTimeStampFound;
  qint64 m_diffToComputerTime;
  cs8LogFileData::FileType m_fileType;
  // keep a representation of the log as a stringlist to simplify searches
  logFileData m_logData;
  // logFileData logData;
  cs8MetaInformationModel *m_metaInformation;
  highlightItemList *m_highlightRules;

  QDateTime m_timeSpanFrom, m_timeSpanTill;

  QFutureWatcher<void> m_watcher;
  QFuture<void> m_future;
  void process();

  //  QMap<int,QString> m_cellData;
  //  QVector<QVector<cellData > > m_tableData;

  void clear();
  void setRowCount(int totalRowCount, int startRowForInsert = -1);
  void loadData(const QStringList &data);
  bool loadFileData(const QStringList &data);
  void preProcessData(const QStringList &lines);
  void runHighlightRules(int startRow_ = -1, int endRow_ = -1);

  cs8LogInterface *telnetConnection;
};

#endif // LOGFILEMODEL_H
