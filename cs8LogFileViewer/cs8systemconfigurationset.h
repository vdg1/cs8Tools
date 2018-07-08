#ifndef CS8SYSTEMCONFIGURATIONSET_H_
#define CS8SYSTEMCONFIGURATIONSET_H_

#include <QDateTime>
#include <QHash>
#include <QList>
#include <QMetaType>
#include <QObject>
#include <QRegExp>
#include <QStringList>

struct cs8SystemConfigurationItem {
  cs8SystemConfigurationItem(const QString &name_, const QString &rx_,
                             bool dynamic_, const QString value_ = "?",
                             int line_ = -1) {
    rx.setPattern(rx_);
    line = line_;
    value = value_;
    name = name_;
    dynamic = dynamic_;
  }
  QRegExp rx;
  QString value;
  int line;
  QString name;
  bool dynamic;
};

class cs8LogTranslator;

class cs8SystemConfigurationSet {

public:
  cs8SystemConfigurationSet();
  virtual ~cs8SystemConfigurationSet();
  QHash<QString, cs8SystemConfigurationItem *> items() const;
  void setFrom(int lineNumber, const QDateTime &timeStamp);
  void setTo(int value, const QDateTime &timeStamp);
  void setWorkingHours(cs8SystemConfigurationItem *value);
  cs8SystemConfigurationItem *workingHours();
  int to() const;
  int from() const;
  QDateTime timeStampTo() const;
  QDateTime timeStampFrom() const;
  QString toolTip() const;
  void addItem(const QString &name, const QString &rx, bool dynamicItem,
               const QString &value = QString());

  bool operator==(cs8SystemConfigurationSet *set) const;
  bool isEqual(cs8SystemConfigurationSet *set) const;
  void dumpData();
  QString machineNumber() const;
  QString armNumber() const;
  QString armType() const;
  bool isEmpty() const;

protected:
  QHash<QString, cs8SystemConfigurationItem *> m_items;
  QStringList m_settingKeywords;
  int m_from;
  int m_to;
  QDateTime m_timeStampFrom, m_timeStampTo;
};

Q_DECLARE_METATYPE(cs8SystemConfigurationSet *)
QDebug operator<<(QDebug debug, const cs8SystemConfigurationSet *c);

#endif /*CS8SYSTEMCONFIGURATIONSET_H_*/
