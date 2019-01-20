#include "dialoggetmachinedata.h"
#include "ui_dialoggetmachinedata.h"

#include <QDesktopServices>
#include <QFile>
#include <QLineEdit>
#include <QSettings>
#include <QUrl>

#include <../common/machinecatalogue.h>

DialogGetMachineData::DialogGetMachineData(QWidget *parent) : QDialog(parent), ui(new Ui::DialogGetMachineData) {
  ui->setupUi(this);
  headerText = ui->lbHeader->text();
  ui->cbCustomerName->lineEdit()->setPlaceholderText("Customer Name");
  ui->cbInternalNumber->lineEdit()->setPlaceholderText("Internal number");
  ui->leControllerSerialNumber->hide();
  ui->lbSerialNumber->hide();
  m_validator = new cs8SerialNumberValidator(ui->leControllerSerialNumber);
}

DialogGetMachineData::~DialogGetMachineData() { delete ui; }

void DialogGetMachineData::setSerialNumber(const QString &serialNumber) {
  m_serialNumber = serialNumber;
  ui->lbHeader->setText(headerText.arg(serialNumber));
  if (serialNumber.isEmpty()) {
    ui->leControllerSerialNumber->show();
    ui->lbSerialNumber->show();
  }
}

void DialogGetMachineData::changeEvent(QEvent *e) {
  QDialog::changeEvent(e);
  switch (e->type()) {
  case QEvent::LanguageChange:
    ui->retranslateUi(this);
    break;

  default:
    break;
  }
}

void DialogGetMachineData::remoteCatalogue() {
  machineCatalogue catalogue;
  QStringList companies;
  companies = catalogue.customers();
  companies.insert(0, "");
  ui->cbCustomerName->addItems(companies);
  ui->cbCustomerName->lineEdit()->selectAll();

  QStringList interalNumbers;
  interalNumbers = catalogue.internalNumbers();
  interalNumbers.insert(0, "");
  ui->cbInternalNumber->addItems(interalNumbers);
}

void DialogGetMachineData::setInfoText(const QString &text) {
  headerText = text;
  ui->lbHeader->setText(headerText);
}

QString DialogGetMachineData::backupPath() const {
  QRegExp rx("[<>:\"/\\\|?*]");
  QString customer = ui->cbCustomerName->currentText();
  customer.replace(rx, "_");
  QString internalNo = ui->cbInternalNumber->currentText();
  internalNo.replace(rx, "_");
  QString p = "/" + customer + (!internalNo.isEmpty() ? "/" + internalNo : "");

  return p;
}

QString DialogGetMachineData::customer() const { return ui->cbCustomerName->currentText(); }

QString DialogGetMachineData::internalNumber() const { return ui->cbInternalNumber->currentText(); }

void DialogGetMachineData::on_buttonBox_accepted() {
  // add robot to local database
  machineCatalogue catalogue;
  catalogue.addLocalEntry(m_serialNumber, m_serialNumber, ui->cbCustomerName->currentText().trimmed(),
                          ui->cbInternalNumber->currentText().trimmed());
  if (ui->cbInformMaintainer->isChecked()) {
    QSettings settings;
    QString rcv = settings.value("maintainer", QString::fromUtf8("vdg@saxe-group.com")).toString();
    QString body = QString("Robot missing in catalogue:\n\n"
                           "Serial Number: %1\n\n"
                           "Customer: %2\n\n"
                           "Internal Number: %3\n\n")
                       .arg(m_serialNumber)
                       .arg(ui->cbCustomerName->currentText().trimmed())
                       .arg(ui->cbInternalNumber->currentText().trimmed());

    QString data = QString("mailto:%1?subject=%2&body=%3").arg(rcv).arg("Robot not in catalogue").arg(body);
    QUrl url(data);
    QDesktopServices::openUrl(url);
  }
}
