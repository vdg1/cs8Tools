#include "cs8metainformationmodel.h"
#include "cs8systemconfigurationmodel.h"
#include "cs8systemconfigurationset.h"
#include "machinecatalogue.h"
#include <QtSql>
#include <dialoggetmachinedata.h>

cs8MetaInformationModel::cs8MetaInformationModel(QObject *parent) : QSqlTableModel(parent), m_model(0) {
  setTable("tbLogFiles");
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
  // if (qobject_cast<logFileModel*>(parent))
  //    setLogData (qobject_cast<logFileModel*>(parent));
}

cs8SystemConfigurationModel *cs8MetaInformationModel::systemConfigurationModel() { return m_systemConfigurationModel; }

void cs8MetaInformationModel::setLogData(logFileModel *logData) {
  m_model = logData;
  m_systemConfigurationModel->setLogData(logData);
}

int cs8MetaInformationModel::currentRow() { return activeRow; }

cs8MetaInformationModel::Preselection cs8MetaInformationModel::dlgOpenSwapFile(qint64 hash) {
  QSqlTableModel table;
  table.setTable("tbLogFiles");
  table.setFilter(QString("hashLogFile='%1'").arg(hash));
  table.select();
  QSqlRecord record = table.record(0);
  return static_cast<Preselection>(table.rowCount() == 0 ? Unset : record.value("dlgOpenSwap").toInt());
}

void cs8MetaInformationModel::setDlgOpenSwapFile(qint64 hash, Preselection value) {
  QSqlTableModel table;
  table.setTable("tbLogFiles");
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
}

cs8MetaInformationModel::Preselection cs8MetaInformationModel::dlgIgnoreTimeGap(qint64 hash) {
  QSqlTableModel table;
  table.setTable("tbLogFiles");
  table.setFilter(QString("hashLogFile='%1'").arg(hash));
  table.select();
  QSqlRecord record = table.record(0);
  return static_cast<Preselection>(table.rowCount() == 0 ? Unset : record.value("dlgIgnoreTimeGap").toInt());
}

void cs8MetaInformationModel::setDlgIgnoreTimeGap(qint64 hash, cs8MetaInformationModel::Preselection value) {
  QSqlTableModel table;
  table.setTable("tbLogFiles");
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
  table.setTable("tbLogFiles");
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
bool cs8MetaInformationModel::selectRecord(uint hash) {

  for (int i = 0; i < rowCount(); i++) {
    if (data(index(i, indexHashLogFile)).toUInt() == hash) {
      activeRow = i;
      emit informationUpdated(activeRow);
      return true;
    }
  }
  insertRow(0);
  activeRow = 0;
  setData(index(activeRow, indexHashLogFile), hash);
  setData(index(activeRow, indexSpanFrom), m_model->logTimeStamp(0));
  setData(index(activeRow, indexSpanTill), m_model->logTimeStamp(m_model->lastValidLineWithTimeStamp()));
  setData(index(activeRow, indexIdControllers), m_systemConfigurationModel->systemConfigurationSet()->machineNumber());
  setData(index(activeRow, indexIdArms), m_systemConfigurationModel->systemConfigurationSet()->armType());
  submitAll();
  emit informationUpdated(activeRow);
  return false;
}

void cs8MetaInformationModel::process(logFileModel *logData) {}

void cs8MetaInformationModel::slotProcessingConfigurationsFinished() {
  // check if a serial number was detected in log file
  QString serialNumber = m_systemConfigurationModel->machineSerialNumber();
  QString armSerialNumber = m_systemConfigurationModel->armSerialNumber();
  // check if robot table already knows of this robot

  // firstTimeOpened = !selectRecord(m_model->hash());
  firstTimeOpened = true;
  if (firstTimeOpened) {
    machineCatalogue catalogue;
    QString customer, internalNumber;
    if (catalogue.findByMachineNumber(serialNumber, customer, internalNumber, m_URLId)) {
      /// TODO
      m_systemConfigurationModel->setMachineInfo(customer, internalNumber, serialNumber, QString());
    } else {
      DialogGetMachineData dlg;
      dlg.setSerialNumber(serialNumber);
      dlg.remoteCatalogue();
      if (dlg.exec() == QDialog::Accepted) {
        m_systemConfigurationModel->setMachineInfo(dlg.customer(), dlg.internalNumber(), serialNumber, QString());
        // add to local database
        catalogue.addLocalEntry(serialNumber, armSerialNumber, dlg.customer(), dlg.internalNumber());
      }
    }
  }
  /// TODO
  firstTimeOpened = true;
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
