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

cs8SystemConfigurationSet::cs8SystemConfigurationSet() : m_to(), m_from() {
  m_settingKeywords.insertMulti("Arm serial number", "Arm serial number");
  m_settingKeywords.insertMulti("Arm serial number", "Arm S/N");
  m_settingKeywords.insertMulti("Machine Number", "Machine Number");
  m_settingKeywords.insertMulti("Machine Number", "Controller S/N");
  m_settingKeywords.insertMulti("Arm", "Arm");
  m_settingKeywords.insertMulti("Arm Type", "Arm Type");
  m_settingKeywords.insertMulti("VAL3", "VAL3");
  m_settingKeywords.insertMulti("System", "System");
  m_settingKeywords.insertMulti("Starc", "Starc");
  m_settingKeywords.insertMulti("Configuration Version", "Configuration Version");
  //
  m_settingKeywords.insertMulti("Hardware/Starc Serial Number",
                                "STARC-SerialNumber");
  m_settingKeywords.insertMulti("Hardware/Starc FPGA", "STARC-FpgaVersion");
  m_settingKeywords.insertMulti("Hardware/Encoder 1", "STARC-Version Encoder1");
  m_settingKeywords.insertMulti("Hardware/Encoder 2", "STARC-Version Encoder2");
  m_settingKeywords.insertMulti("Hardware/Encoder 3", "STARC-Version Encoder3");
  m_settingKeywords.insertMulti("Hardware/Encoder 4", "STARC-Version Encoder4");
  m_settingKeywords.insertMulti("Hardware/Encoder 5", "STARC-Version Encoder5");
  m_settingKeywords.insertMulti("Hardware/Encoder 6", "STARC-Version Encoder6");
  m_settingKeywords.insertMulti("Hardware/MCP", "MCP firmware version");
  m_settingKeywords.insertMulti("Hardware/CPU", "CPU board");
  m_settingKeywords.insertMulti("Hardware/RSI", "RSI Board rev");
  // mark setting with "[" to indicate they are dynamic and to
  // be excluded when parsing system settings
  m_settingKeywords.insertMulti("Power hour count", "[Power hour count");
  QString checksumRegExp("(($|\\{[0-9a-f]{8}\\})$)");
  QString logIdRegExp("(<0x\\d{4}> )*");

  QHashIterator<QString, QString> i(m_settingKeywords);
  while (i.hasNext()) {
    i.next();
    QString value = i.value();
    addItem(i.key(),
            QStringLiteral("^%1%3(:| =)\\s{0,1}([^{]*)%2").arg(logIdRegExp).arg(checksumRegExp).arg(value.remove("[")),
            i.value().startsWith("["));
  }
}

QString cs8SystemConfigurationSet::machineNumber() const { return itemValue("Machine Number"); }

QString cs8SystemConfigurationSet::armNumber() const { return itemValue("Arm serial number"); }

QString cs8SystemConfigurationSet::armType() const { return itemValue("Arm Type"); }

QString cs8SystemConfigurationSet::itemValue(const QString &key) const {
  if (m_items.contains(key) && !m_items.value(key)->value.isEmpty())
    return m_items.value(key)->value;
  else
    return QString();
}

cs8SystemConfigurationSet::~cs8SystemConfigurationSet() {}

QMultiHash<QString, cs8SystemConfigurationItem *> cs8SystemConfigurationSet::items() const { return m_items; }

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

void cs8SystemConfigurationSet::setWorkingHours(cs8SystemConfigurationItem *item) {
  if (item != nullptr)
    m_items.replace("Power hour count", new cs8SystemConfigurationItem("Power hour count", item->rx.pattern(),
                                                                       item->dynamic, item->value, item->line));
}

cs8SystemConfigurationItem *cs8SystemConfigurationSet::workingHours() const {
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
  m_items.insertMulti(name, item);
}

bool cs8SystemConfigurationSet::isEqual(cs8SystemConfigurationSet *other) const {
  // if (other->items().count() != m_items.count())
  //  return false;

  QHashIterator<QString, cs8SystemConfigurationItem *> i(m_items);
  while (i.hasNext()) {
    i.next();
    //			qDebug() << i.key() << ": " << i.value();
    if (other->items().contains(i.key())) {
      qDebug() << i.key() << ": " << i.value()->value << "   " << other->items().value(i.key())->value;
      // ignore dynamic items
      if (other->items().value(i.key())->value != i.value()->value && !other->items().value(i.key())->dynamic)
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

  QHashIterator<QString, cs8SystemConfigurationItem *> i(m_items);
  while (i.hasNext()) {
    i.next();
    if (!i.value()->value.isEmpty())
      return false;
    // qDebug() << "item: " << i.key() << " value: " << i.value()->value;
  }
  return true;
}

void cs8SystemConfigurationSet::removeEmptyItems() {
  QHashIterator<QString, cs8SystemConfigurationItem *> i(m_items);
  while (i.hasNext()) {
    i.next();
    if (i.value()->value.isEmpty()) {
      qDebug() << "Remove item: " << i.key() << ":" << i.value();
      m_items.remove(i.key(), i.value());
    }
  }
}
