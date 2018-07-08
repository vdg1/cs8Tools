#include "machinecatalogue.h"
#include "xlstablemodel.h"
//#include "qxtcsvmodel.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QRegularExpression>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlField>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QStandardPaths>
#include <xlsxdocument.h>

void machineCatalogue::checkDBTables() {
  QSqlDatabase db = QSqlDatabase::database();
  QSqlQuery q;
  if (!db.tables().contains("machineCatalogue")) {
    if (!q.exec(QLatin1String("CREATE TABLE `machineCatalogue` ("
                              "`id`	INTEGER PRIMARY KEY AUTOINCREMENT,"
                              "`ctrlSerial`	varchar,"
                              "`armSerial`	varchar,"
                              "`customerName`	varchar,"
                              "`internalNumber`	varchar,"
                              "`catalogueID`	varchar,"
                              "`localyAdded`	INTEGER"
                              ");")))
      qDebug() << "Failed to create table machineCatalogue:" << q.lastError();
  }
  db.commit();
}

machineCatalogue::machineCatalogue(QObject *parent) : QObject(parent) {
  m_appData = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);

  // checkDBTables();
  m_table = new QSqlTableModel(this);
  m_table->setTable("machineCatalogue");
  m_table->setEditStrategy(QSqlTableModel::OnFieldChange);
  if (!m_table->select()) {
    qDebug() << "Table select failed on import: ";
  }
}

QStringList machineCatalogue::remoteCatalogue(const QString &storageBasePath, const QString &base) {
  QStringList catalogueList;
  QString b = base;

  QRegExp rx("[<>:\"/\\\|?*]");
  // b.remove(QRegExp("[_/\\\\]"));
  b.replace(rx, "_");

  m_table->setFilter(QStringLiteral("ctrlSerial='%1'").arg(b));
  m_table->select();

  for (int i = 0; i < m_table->rowCount(); i++) {
    QSqlRecord record = m_table->record(i);

    QString customerName = record.value("customerName").toString();
    customerName.replace(rx, "_");
    QString internalNo = record.value("internalNumber").toString();
    internalNo.replace(rx, "_");
    catalogueList << QDir::toNativeSeparators(storageBasePath + customerName + "/" + internalNo + "/" + b);
  }
  return catalogueList;
}

qint32 machineCatalogue::controllerSerialNumberColumn() const {
  QSettings settings;
  return settings.value("controllerSerialNumberColumn", 1).toInt();
}

qint32 machineCatalogue::armSerialNumberColumn() const {
  QSettings settings;
  return settings.value("armSerialNumberColumn", 2).toInt();
}

qint32 machineCatalogue::customerNameColumn() const {
  QSettings settings;
  return settings.value("customerNameColumn", 5).toInt();
}

qint32 machineCatalogue::internalNumberColumn() const {
  QSettings settings;
  return settings.value("internalNumberColumn", 4).toInt();
}

bool machineCatalogue::withHeader() const {
  QSettings settings;
  return settings.value("withHeader", true).toBool();
}

QStringList machineCatalogue::customers() const {

  QStringList list;
  QString s;
  m_table->setFilter("");
  for (int i = 0; i < m_table->rowCount(); i++) {
    s = m_table->record(i).value("customerName").toString();
    if (!s.isEmpty())
      list.append(s);
  }
  list.removeDuplicates();
  list.sort();
  return list;
}

QStringList machineCatalogue::internalNumbers() const {
  QStringList list;
  QString s;
  m_table->setFilter("");
  for (int i = 0; i < m_table->rowCount(); i++) {
    s = m_table->record(i).value("internalNumber").toString();
    if (!s.isEmpty())
      list.append(s);
  }
  list.removeDuplicates();
  list.sort();
  return list;
}

QString machineCatalogue::filePath() const { return m_appData + "/" + CATALOGUE_FILENAME; }

bool machineCatalogue::findByMachineNumber(const QString &serialNumber, QString &customer, QString &internalNumber,
                                           QString &UrlId) {
  QRegExp rx("[<>:\"/\\\|?*]");
  QString search = serialNumber;
  search.replace(rx, "_");

  m_table->setFilter(QStringLiteral("ctrlSerial='%1'").arg(search));
  m_table->select();
  if (m_table->rowCount() != 0) {
    QSqlRecord record = m_table->record(0);
    customer = record.value("customerName").toString();
    internalNumber = record.value("internalNumber").toString();
    UrlId = record.value("catalogueID").toString();
    return true;
  } else {
    customer = QString("");
    internalNumber = QString("");
    UrlId = QString("");
    return false;
  }
}

void machineCatalogue::setControllerSerialNumberColumn(int arg) {
  QSettings settings;
  settings.setValue("controllerSerialNumberColumn", arg);
}

void machineCatalogue::setArmSerialNumberColumn(int arg) {
  QSettings settings;
  settings.setValue("armSerialNumberColumn", arg);
}

void machineCatalogue::setCustomerNameColumn(int arg) {
  QSettings settings;
  settings.setValue("setCustomerNameColumn", arg);
}

void machineCatalogue::setInternalNumberColumn(int arg) {
  QSettings settings;
  settings.setValue("setInternalNumberColumn", arg);
}

void machineCatalogue::setWithHeader(bool arg) {
  QSettings settings;
  settings.setValue("setWithHeader", arg);
}

bool machineCatalogue::importFile(const QString &fileName) {

  xlsTableModel sourceModel;
  sourceModel.setSource(fileName, withHeader());

  for (int row = 0; row < sourceModel.rowCount(); row++) {
    bool updateDone = false;
    // check if URL Id exist in catalogue file
    QString URLId = sourceModel.data(sourceModel.index(row, URLIdColumn())).toString();
    QString serialNumber = sourceModel.data(sourceModel.index(row, controllerSerialNumberColumn())).toString();
    serialNumber.replace(QRegularExpression("[<>:\"/\\?*]"), "_");
    //
    if (!URLId.isEmpty()) {
      // filter destination model on URLId
      m_table->setFilter(QStringLiteral("catalogueID='%1'").arg(URLId));
      qDebug() << "Found " << m_table->rowCount() << "entries with URLid " << URLId;
      // entry does exist ==> update it
      if (m_table->rowCount() != 0) {
        QSqlRecord record = m_table->record(0);
        qDebug() << "Update existing record: " << record;
        record.setValue("ctrlSerial", serialNumber);
        record.setValue("armSerial", sourceModel.data(sourceModel.index(row, armSerialNumberColumn())).toString());
        record.setValue("customerName", sourceModel.data(sourceModel.index(row, customerNameColumn())).toString());
        record.setValue("internalNumber", sourceModel.data(sourceModel.index(row, internalNumberColumn())).toString());
        record.setValue("catalogueID", sourceModel.data(sourceModel.index(row, URLIdColumn())).toString());
        record.setValue("localyAdded", false);
        m_table->setRecord(0, record);
        updateDone = true;
      }
      //
      // filter for rows that were added manually (entries added since machine
      // does not exist in catalogue yet)
      m_table->setFilter(QStringLiteral("ctrlSerial='%1' and localyAdded!=0").arg(serialNumber));

      // entry exist ==> update it and unset "locally added"
      if (m_table->rowCount() != 0) {
        QSqlRecord record = m_table->record(0);

        record.setValue("ctrlSerial", serialNumber);
        record.setValue("armSerial", sourceModel.data(sourceModel.index(row, armSerialNumberColumn())).toString());
        record.setValue("customerName", sourceModel.data(sourceModel.index(row, customerNameColumn())).toString());
        record.setValue("internalNumber", sourceModel.data(sourceModel.index(row, internalNumberColumn())).toString());
        record.setValue("catalogueID", sourceModel.data(sourceModel.index(row, URLIdColumn())).toString());
        record.setValue("localyAdded", false);
        m_table->setRecord(0, record);
        updateDone = true;
      }
      //
      // if source record was not updated yet it must be a new machine ==> add
      // it to the dest table
      if (!updateDone) {
        QSqlRecord record = m_table->record();
        record.setValue("ctrlSerial", serialNumber);
        record.setValue("armSerial", sourceModel.data(sourceModel.index(row, armSerialNumberColumn())).toString());
        record.setValue("customerName", sourceModel.data(sourceModel.index(row, customerNameColumn())).toString());
        record.setValue("internalNumber", sourceModel.data(sourceModel.index(row, internalNumberColumn())).toString());
        record.setValue("catalogueID", sourceModel.data(sourceModel.index(row, URLIdColumn())).toString());
        record.setValue("localyAdded", false);
        qDebug() << "Add record to table: " << record;
        if (!m_table->insertRecord(0, record)) {
          qDebug() << "Inserting record failed: " << record << m_table->lastError();
        }
      }
    }
  }
  //
  // find machines that have been removed from the remote catalogue
  // only check machines that have been in the remote catalogue as well
  m_table->setFilter("localyAdded==0");
  QStringList list;
  QString s;
  for (int i = 0; i < sourceModel.rowCount(); i++) {
    s = sourceModel.data(sourceModel.index(i, controllerSerialNumberColumn())).toString();
    s.replace(QRegularExpression("[<>:\"/\\?*]"), "_");
    if (!s.isEmpty())
      list.append(s);
  }
  for (int row = 0; row < m_table->rowCount(); row++) {
    if (!list.contains(m_table->record(row).value("ctrlSerial").toString())) {
      qDebug() << "Remove entry (not in remote catalogue):" << m_table->record(row);
      m_table->removeRow(row);
    }
  }

  return true;
}

int machineCatalogue::entries() const { return m_table->rowCount(); }

bool machineCatalogue::addLocalEntry(const QString &controllerSerialNumber, const QString &armSerialNumber,
                                     const QString &customer, const QString &internalNumber) {
  QSqlRecord record = m_table->record();
  record.setValue("ctrlSerial", controllerSerialNumber);
  record.setValue("armSerial", armSerialNumber);
  record.setValue("customerName", customer);
  record.setValue("internalNumber", internalNumber);

  record.setValue("localyAdded", true);
  qDebug() << "Add local record to table: " << record;
  if (!m_table->insertRecord(0, record)) {
    qDebug() << "Inserting record failed: " << record << m_table->lastError();
    return false;
  }

  return true;
}

QString machineCatalogue::appData() const { return m_appData; }

qint32 machineCatalogue::URLIdColumn() const {
  QSettings settings;
  return settings.value("URLIdColumn", 8).toInt();
}

void machineCatalogue::setURLIdColumn(const int &URLIdColumn) {
  QSettings settings;
  settings.setValue("URLIdColumn", URLIdColumn);
}
