#include "dialogmachinecatalogueimportconfiguration.h"
#include "machinecatalogue.h"
#include "ui_dialogmachinecatalogueimportconfiguration.h"

#include <QDebug>
#include <QFile>
#include <QSortFilterProxyModel>
#include <QStandardPaths>

DialogMachineCatalogueImportConfiguration::DialogMachineCatalogueImportConfiguration(QWidget *parent,
                                                                                     const QString &filePath)
    : QDialog(parent), ui(new Ui::DialogMachineCatalogueImportConfiguration), m_catalogueFilePath(filePath) {
  ui->setupUi(this);
  machineCatalogue catalogue;

  m_model = new xlsTableModel(this);
  m_model->setSource(m_catalogueFilePath, ui->cbWithHeader->isChecked());

  m_proxyModel = new QSortFilterProxyModel(this);
  m_proxyModel->setSourceModel(m_model);
  ui->tableView->setModel(m_proxyModel);
  connect(ui->tableView->selectionModel(), &QItemSelectionModel::currentRowChanged, this,
          &DialogMachineCatalogueImportConfiguration::selectionChanged);
  if (m_model->rowCount() > 0)
    ui->tableView->selectionModel()->setCurrentIndex(m_proxyModel->index(0, 0), QItemSelectionModel::Rows);
  //
  ui->cbWithHeader->setChecked(catalogue.withHeader());
  ui->sbCustomerName->setValue(catalogue.customerNameColumn());
  ui->sbInternalNumber->setValue(catalogue.internalNumberColumn());
  ui->sbControllerSerialNumber->setValue(catalogue.controllerSerialNumberColumn());
  ui->sbArmSerialNumber->setValue(catalogue.armSerialNumberColumn());
  ui->sbUrlId->setValue(catalogue.URLIdColumn());
}

DialogMachineCatalogueImportConfiguration::~DialogMachineCatalogueImportConfiguration() { delete ui; }

void DialogMachineCatalogueImportConfiguration::setCatalogueFile(const QString &filePath) {
  m_catalogueFilePath = filePath;
}

void DialogMachineCatalogueImportConfiguration::changeEvent(QEvent *e) {
  QDialog::changeEvent(e);
  switch (e->type()) {
  case QEvent::LanguageChange:
    ui->retranslateUi(this);
    break;
  default:
    break;
  }
}

void DialogMachineCatalogueImportConfiguration::on_cbWithHeader_toggled(bool arg1) {
  updatedSelectedRowData();
  m_model->setWithHeader(arg1);
  ui->tableView->reset();
}

void DialogMachineCatalogueImportConfiguration::selectRow(int row) {
  ui->leCustomerName->setText(
      m_model->data(m_model->index(row, qMin(m_model->columnCount(), ui->sbCustomerName->value()))).toString());
  ui->leInternalNumber->setText(
      m_model->data(m_model->index(row, qMin(m_model->columnCount(), ui->sbInternalNumber->value()))).toString());
  ui->leControllerSerialNumber->setText(
      m_model->data(m_model->index(row, qMin(m_model->columnCount(), ui->sbControllerSerialNumber->value())))
          .toString());
  ui->leArmSerialNumber->setText(
      m_model->data(m_model->index(row, qMin(m_model->columnCount(), ui->sbArmSerialNumber->value()))).toString());
  ui->leURLId->setText(
      m_model->data(m_model->index(row, qMin(m_model->columnCount(), ui->sbUrlId->value()))).toString());
}

void DialogMachineCatalogueImportConfiguration::selectionChanged(QModelIndex selected, QModelIndex) {
  int row = selected.row();

  selectRow(row);
}

void DialogMachineCatalogueImportConfiguration::on_buttonBox_accepted() {
  machineCatalogue catalogue;
  catalogue.setWithHeader(ui->cbWithHeader->isChecked());
  catalogue.setCustomerNameColumn(ui->sbCustomerName->value());
  catalogue.setControllerSerialNumberColumn(ui->sbControllerSerialNumber->value());
  catalogue.setArmSerialNumberColumn(ui->sbArmSerialNumber->value());
  catalogue.setInternalNumberColumn(ui->sbInternalNumber->value());
  catalogue.setURLIdColumn(ui->sbUrlId->value());
}

void DialogMachineCatalogueImportConfiguration::on_sbCustomerName_valueChanged(int) {}

void DialogMachineCatalogueImportConfiguration::on_sbInternalNumber_valueChanged(int) { updatedSelectedRowData(); }

void DialogMachineCatalogueImportConfiguration::on_sbUrlId_valueChanged(int /*arg1*/) { updatedSelectedRowData(); }

void DialogMachineCatalogueImportConfiguration::on_sbControllerSerialNumber_valueChanged(int /*arg1*/) {
  updatedSelectedRowData();
}

void DialogMachineCatalogueImportConfiguration::on_sbArmSerialNumber_valueChanged(int /*arg1*/) {
  updatedSelectedRowData();
}

void DialogMachineCatalogueImportConfiguration::updatedSelectedRowData() {
  if (ui->tableView->selectionModel()->selectedRows().count() > 0) {
    int row = ui->tableView->selectionModel()->selectedRows().at(0).row();
    selectRow(row);
  }
}
