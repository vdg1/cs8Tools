#ifndef LOGFILEDATA_H
#define LOGFILEDATA_H

#include <QBrush>
#include <QDateTime>
#include <QFont>
#include <QString>
#include <QVariant>

struct logFileLineItem {
  QDateTime date;
  QString message;
  QString id;
  int level;
  quint64 hash;
  double ts;
  QVariant userData;
  QBrush foregroundColor, backgroundColor;
  QFont font;
  QString type;
};

class logFileData : public QVector<logFileLineItem> {
public:
  logFileData();

public:
  QStringList toStringList();
  QStringList messageTypes();
  int lastValidLine() const;

protected:
  QStringList m_messageCache;
  QStringList updateCache();
};
#endif // LOGFILEDATA_H
