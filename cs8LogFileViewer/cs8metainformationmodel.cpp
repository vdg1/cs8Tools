#include "cs8metainformationmodel.h"
#include "cs8systemconfigurationmodel.h"
#include "cs8systemconfigurationset.h"
#include "machinecatalogue.h"
#include <QtSql>
#include <dialoggetmachinedata.h>

cs8MetaInformationModel::cs8MetaInformationModel(QObject *parent) : QSqlTableModel(parent), m_model(nullptr) {
  setTable(TABLE_NAME_LOG_FILES);
  select();

  qDebug() << "Selecting table for meta information: " << lastError().text();

  m_systemConfigurationModel = new cs8SystemConfigurationModel(this);
  connect(m_systemConfigurationModel, &cs8SystemConfigurationModel::completed, this,
          &cs8MetaInformationModel::slotProcessingConfigurationsFinished);

  indexHashLogFile = fieldIndex("hashLogFile");
  indexHashSwapFile = fieldIndex("hashSwapFile");
  indexArchived = fieldIndex("archived");
  indexSpanFrom = fieldIndex("spanFrom");
  indexSpanTill = fieldIndex("spanTill");
  indexIdControllers = fieldIndex("idController");
  indexIdArms = fieldIndex("idArm");
  indexDlgOpenSwap = fieldIndex("dlgOpenSwap");
  indexDlgIgnoreTimeGap = fieldIndex("dlgIgnoreTimeGap");
  indexFirstOpened = fieldIndex("firstOpen");
  indexLastOpen = fieldIndex("lastOpen");
}

cs8SystemConfigurationModel *cs8MetaInformationModel::systemConfigurationModel() { return m_systemConfigurationModel; }

void cs8MetaInformationModel::setLogData(logFileModel *logData) {
  m_model = logData;
  m_systemConfigurationModel->setLogData(logData);
}

cs8MetaInformationModel::Preselection cs8MetaInformationModel::dlgOpenSwapFile(qint64 hash) {
  QSqlTableModel table;
  table.setTable(TABLE_NAME_LOG_FILES);
  table.setFilter(QString("hashLogFile='%1'").arg(hash));
  table.select();
  return static_cast<Preselection>(table.rowCount() == 0 ? Unset : table.record(0).value("dlgOpenSwap").toInt());
}

void cs8MetaInformationModel::setDlgOpenSwapFile(qint64 hash, Preselection value) {
  /*QSqlTableModel table;
  table.setTable(TABLE_NAME_LOG_FILES);
  table.setFilter(QString("hashLogFile='%1'").arg(hash));
  table.select();
  if (table.rowCount() == 0) {
    QSqlRecord record = table.record();
    record.setValue("hashLogFile", hash);
    record.setValue("dlgOpenSwap", value);
    table.insertRecord(0, record);
  } else {
    QSqlRecord record = table.record(0);
    record.setValue("dlgOpenSwap", value);
    table.setRecord(0, record);
  }
  table.submitAll();
  */

  setFilter(QString("hashLogFile='%1'").arg(hash));
  select();
  if (rowCount() == 0) {
    QSqlRecord record = this->record();
    record.setValue(indexHashLogFile, hash);
    record.setValue(indexFirstOpened, QDateTime::currentDateTime());
    record.setValue(indexDlgOpenSwap, value);
    insertRecord(0, record);
  } else {
    QSqlRecord record = this->record(0);
    record.setValue(indexDlgOpenSwap, value);
    setRecord(0, record);
  }
  submitAll();
  setFilter("");
  select();
}

cs8MetaInformationModel::Preselection cs8MetaInformationModel::dlgIgnoreTimeGap(qint64 hash) {
  QSqlTableModel table;
  table.setTable(TABLE_NAME_LOG_FILES);
  table.setFilter(QString("hashLogFile='%1'").arg(hash));
  table.select();
  QSqlRecord record = table.record(0);
  return static_cast<Preselection>(table.rowCount() == 0 ? Unset : record.value("dlgIgnoreTimeGap").toInt());
}

void cs8MetaInformationModel::setDlgIgnoreTimeGap(qint64 hash, cs8MetaInformationModel::Preselection value) {
  QSqlTableModel table;
  table.setTable(TABLE_NAME_LOG_FILES);
  table.setFilter(QString("hashLogFile='%1'").arg(hash));
  table.select();
  if (table.rowCount() == 0) {
    QSqlRecord record = table.record();
    record.setValue("hashLogFile", hash);
    record.setValue("dlgIgnoreTimeGap", value);
    table.insertRecord(0, record);
  } else {
    QSqlRecord record = table.record(0);
    record.setValue("dlgIgnoreTimeGap", value);
    table.setRecord(0, record);
  }
  table.submitAll();
}

void cs8MetaInformationModel::resetDialogOptions() {
  QSqlTableModel table;
  table.setTable(TABLE_NAME_LOG_FILES);
  table.select();
  for (int row = 0; row < table.rowCount(); row++) {
    QSqlRecord record = table.record(row);
    record.setValue("dlgIgnoreTimeGap", Unset);
    record.setValue("dlgOpenSwap", Unset);
    table.setRecord(row, record);
  }
  table.submitAll();
}

/*
  Returns true if a record of this file already exists
  */
void cs8MetaInformationModel::setLogfileInfo(uint hash, const QDateTime &spanFrom, const QDateTime &spanTill,
                                             const QString &machineNumber, const QString &armType) {

  setFilter(QString("hashLogFile='%1'").arg(hash));
  select();
  if (rowCount() > 1)
    qWarning() << "Log file table has multiple entries for hash: " << hash;
  QSqlRecord record = this->record();
  record.setValue(indexHashLogFile, hash);
  record.setValue(indexSpanFrom, spanFrom);
  record.setValue(indexSpanTill, spanTill);
  record.setValue(indexIdControllers, machineNumber);
  if (!armType.isNull())
    record.setValue(indexIdArms, armType);

  if (rowCount() == 0) {
    record.setValue(indexFirstOpened, QDateTime::currentDateTime());
    insertRecord(0, record);
  } else {
    setRecord(0, record);
  }

  submitAll();
}

bool cs8MetaInformationModel::selectRecord(uint hash) {

  setFilter(QString("hashLogFile='%1'").arg(hash));
  select();
  if (rowCount() > 1)
    qWarning() << "Log file table has multiple entries for hash: " << hash;
  if (rowCount() != 0) {
    record(0).setValue(indexLastOpen, QDateTime::currentDateTime());
    if (!record(0).value(indexIdControllers).toString().isEmpty())
      m_serialNumber = record(0).value(indexIdControllers).toString();
    if (!setRecord(0, record(0)))
      qWarning() << "Failed to set record for hash " << hash;
    submitAll();
    return true;
  } else {
    setLogfileInfo(hash, m_model->logTimeStamp(0), m_model->logTimeStamp(m_model->lastValidLineWithTimeStamp()),
                   m_systemConfigurationModel->systemConfigurationSet()->machineNumber(),
                   m_systemConfigurationModel->systemConfigurationSet()->armType());
    return false;
  }
}

void cs8MetaInformationModel::process(logFileModel * /*logData*/) {}

void cs8MetaInformationModel::slotProcessingConfigurationsFinished() {
  // check if a serial number was detected in log file
  m_serialNumber = m_systemConfigurationModel->machineSerialNumber();
  QString armSerialNumber = m_systemConfigurationModel->armSerialNumber();
  // check if robot table already knows of this robot

  firstTimeOpened = !selectRecord(m_model->hash());
  machineCatalogue catalogue;

  if (firstTimeOpened) {

    QString customer, internalNumber;
    if (catalogue.findByMachineNumber(m_serialNumber, customer, internalNumber, m_URLId)) {
      /// TODO
      m_systemConfigurationModel->setMachineInfo(customer, internalNumber, m_serialNumber, QString());
    } else {
      DialogGetMachineData dlg;
      if (m_serialNumber.isEmpty()) {
        dlg.setInfoText("The robot system could not be identified since no serial number was found in the log "
                        "data.\nPlease enter some details about this robot system:");
      }
      dlg.setSerialNumber(m_serialNumber);
      dlg.remoteCatalogue();
      if (dlg.exec() == QDialog::Accepted) {
        // if serial number is empty, but user provided customer name and robot number we
        // can try to find the robot in the catalogue and fill in missing info (serial number arm and controller and
        // online catalogue URLID
        if (m_serialNumber.isEmpty() && !dlg.customer().isEmpty() && !dlg.internalNumber().isEmpty()) {
          catalogue.findByCustomerName(dlg.customer(), dlg.internalNumber(), m_serialNumber, armSerialNumber, m_URLId);
        } else if (!m_serialNumber.isEmpty() && !dlg.customer().isEmpty() && !dlg.internalNumber().isEmpty()) {
          // add to local database
          // catalogue.addLocalEntry(m_serialNumber, armSerialNumber, dlg.customer(), dlg.internalNumber());
        }
        m_systemConfigurationModel->setMachineInfo(dlg.customer(), dlg.internalNumber(), m_serialNumber, QString());
      }
    }
    if (catalogue.findByMachineNumber(m_serialNumber, customer, internalNumber, m_URLId)) {
    }
  } else {
    QString customer, internalNumber;
    if (catalogue.findByMachineNumber(m_serialNumber, customer, internalNumber, m_URLId)) {
      /// TODO
      m_systemConfigurationModel->setMachineInfo(customer, internalNumber, m_serialNumber, QString());
      setLogfileInfo(m_model->hash(), m_model->logTimeStamp(0),
                     m_model->logTimeStamp(m_model->lastValidLineWithTimeStamp()), m_serialNumber);
    }
  }
  process(m_model);

  /*
  if (firstTimeOpened){
      if (!setData (index
  (activeRow,indexSpanFrom),m_systemConfigurationModel->systemConfigurationSet
  (0)->timeStampFrom ())) qDebug() << "Setting data failed:" <<
  m_systemConfigurationModel->systemConfigurationSet (0)->timeStampFrom (); if
  (!setData
  (index(activeRow,indexSpanTill),m_systemConfigurationModel->systemConfigurationSet
  ()->timeStampTo ())) qDebug() << "Setting data failed:" <<
  m_systemConfigurationModel->systemConfigurationSet ()->timeStampTo ();
      submitAll ();
  }
  */
  emit metaInformationAvailable();
}

QString cs8MetaInformationModel::URLId() const { return m_URLId; }

QString cs8MetaInformationModel::serialNumber() const { return m_serialNumber; }

int cs8MetaInformationModel::hash() const { return m_model->hash(); }
