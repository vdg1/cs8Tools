#include "cs8systemconfigurationset.h"

#include <QDebug>

QDebug operator<<(QDebug debug, const cs8SystemConfigurationSet *c) {
  QDebugStateSaver saver(debug);
  debug.nospace() << '[' << c->from() << '-' << c->to() << "] (";
  QHashIterator<QString, cs8SystemConfigurationItem *> item(c->items());
  while (item.hasNext()) {
    item.next();
    debug.nospace() << item.key() << ":" << item.value()->value << (item.hasNext() ? "| " : "");
  }
  debug.nospace() << ')';

  return debug;
}

cs8SystemConfigurationSet::cs8SystemConfigurationSet() {
  m_settingKeywords << "Arm serial number"
                    << "Machine Number"
                    << "Arm"
                    << "Arm Type"
                    << "VAL3"
                    << "System"
                    << "Starc"
                    << "Configuration Version"
                    // mark setting with "[" to indicate they are dynamic and to
                    // be excluded when parsing system settings
                    << "[Power hour count";
  QString checksumRegExp("(($|\\{[0-9a-f]{8}\\})$)");
  QString logIdRegExp("(<0x\\d{4}> )*");

  foreach (QString keyword, m_settingKeywords) {
    addItem(keyword,
            QStringLiteral("^%1%3(:| =) ([^{]*)%2").arg(logIdRegExp).arg(checksumRegExp).arg(keyword.remove("[")),
            keyword.contains("["));
  }
}

QString cs8SystemConfigurationSet::machineNumber() const {
  if (!m_items.value("Machine Number")->value.isEmpty())
    return m_items.value("Machine Number")->value;
  else
    return QString();
}

QString cs8SystemConfigurationSet::armNumber() const {
  if (!m_items.value("Arm serial number")->value.isEmpty())
    return m_items.value("Arm serial number")->value;
  else
    return QString();
}

QString cs8SystemConfigurationSet::armType() const {
  if (!m_items.value("Arm Type")->value.isEmpty())
    return m_items.value("Arm Type")->value;
  else
    return QString("unknown");
}

cs8SystemConfigurationSet::~cs8SystemConfigurationSet() {}

/*! Returns a hash of configuration items contained in a configuration set
 *
 */
QHash<QString, cs8SystemConfigurationItem *> cs8SystemConfigurationSet::items() const { return m_items; }

/*! Set the line number from which this configuration set is used.
 *
 * @param lineNumber the line number where this system configuration set starts.
 */
void cs8SystemConfigurationSet::setFrom(int lineNumber, const QDateTime &timeStamp) {
  m_from = lineNumber;
  m_timeStampFrom = timeStamp;
}

/*! Set the line number until which this configuration set is used.
 *
 * @param value the line number where this system configuration set ends.
 */
void cs8SystemConfigurationSet::setTo(int value, const QDateTime &timeStamp) {
  m_to = value;
  m_timeStampTo = timeStamp;
}

void cs8SystemConfigurationSet::setWorkingHours(cs8SystemConfigurationItem *value) {
  if (value != nullptr)
    m_items["Power hour count"] = value;
}

cs8SystemConfigurationItem *cs8SystemConfigurationSet::workingHours() {
  if (items().contains("Power hour count"))
    return items().value("Power hour count");
  else
    return nullptr;
}

/*! Returns the line number where this system configuration set starts.
 *
 */
int cs8SystemConfigurationSet::to() const { return m_to; }

QDateTime cs8SystemConfigurationSet::timeStampTo() const { return m_timeStampTo; }

/*! Returns the line number where this system configuration set ends.
 *
 */
int cs8SystemConfigurationSet::from() const { return m_from; }

QDateTime cs8SystemConfigurationSet::timeStampFrom() const { return m_timeStampFrom; }

/*! Returns a tool tip containing the configuration items arranged in a table.
 *
 * @return QString a table encoded in html.
 */
QString cs8SystemConfigurationSet::toolTip() const {
  QString tooltip = ("System Configuration<hr><table>");

  QHashIterator<QString, cs8SystemConfigurationItem *> i(m_items);
  while (i.hasNext()) {
    i.next();
    tooltip += "<tr><td>" + i.key() + "</td><td>" + i.value()->value + "</td></tr>";
  }
  tooltip += "</table>";
  return tooltip;
}

bool cs8SystemConfigurationSet::operator==(cs8SystemConfigurationSet *set) const {
  if (set->items().count() != m_items.count())
    return false;

  QHashIterator<QString, cs8SystemConfigurationItem *> i(m_items);
  while (i.hasNext()) {
    i.next();
    qDebug() << i.key() << ": " << i.value();
    if (set->items().contains(i.key())) {
      if (set->items().value(i.key()) != i.value())
        return false;
    } else
      return false;
  }
  return true;
}

void cs8SystemConfigurationSet::addItem(const QString &name, const QString &rx, bool dynamicItem,
                                        const QString &value) {
  cs8SystemConfigurationItem *item = new cs8SystemConfigurationItem(name, rx, dynamicItem, value);
  m_items[name] = item;
}

bool cs8SystemConfigurationSet::isEqual(cs8SystemConfigurationSet *set) const {
  if (set->items().count() != m_items.count())
    return false;

  QHashIterator<QString, cs8SystemConfigurationItem *> i(m_items);
  while (i.hasNext()) {
    i.next();
    //			qDebug() << i.key() << ": " << i.value();
    if (set->items().contains(i.key())) {
      // qDebug() << i.key() << ": " << i.value()->value << "   " <<
      // set->items().value(i.key())->value;
      // ignore dynamic items
      if (set->items().value(i.key())->value != i.value()->value && !set->items().value(i.key())->dynamic)
        return false;
    } else
      return false;
  }
  return true;
}

void cs8SystemConfigurationSet::dumpData() {
  qDebug() << "from: " << from() << " to: " << to();
  QHashIterator<QString, cs8SystemConfigurationItem *> i(items());
  while (i.hasNext()) {
    i.next();
    qDebug() << "item: " << i.key() << " value: " << i.value()->value;
  }
}

bool cs8SystemConfigurationSet::isEmpty() const {

  QHashIterator<QString, cs8SystemConfigurationItem *> i(items());
  while (i.hasNext()) {
    i.next();
    if (!i.value()->value.isEmpty())
      return false;
    // qDebug() << "item: " << i.key() << " value: " << i.value()->value;
  }
  return true;
}
