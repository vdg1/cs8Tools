#include "cs8connectdialog.h"
#include <QDialogButtonBox>
#include <QHostAddress>
#include <QLineEdit>
#include <QPushButton>
#include "ui_cs8connectdialog.h"

cs8ConnectDialog::cs8ConnectDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::cs8ConnectDialog) {
  ui->setupUi(this);
  ui->cpIPAddress->lineEdit()->setInputMask("000.000.000.000;_)");
  ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

cs8ConnectDialog::~cs8ConnectDialog() { delete ui; }

QString cs8ConnectDialog::address() const {
  return ui->cpIPAddress->currentText();
}

quint16 cs8ConnectDialog::port() const {
  return static_cast<quint16>(ui->sbPortNumber->value());
}

bool cs8ConnectDialog::loadLogFile() const {
  return ui->cbLoadStoredLog->isChecked();
}

void cs8ConnectDialog::changeEvent(QEvent *e) {
  QDialog::changeEvent(e);
  switch (e->type()) {
    case QEvent::LanguageChange:
      ui->retranslateUi(this);
      break;
    default:
      break;
  }
}

void cs8ConnectDialog::accepted() {
  /// TODO
  /// Add address to history
}

void cs8ConnectDialog::on_cpIPAddress_currentTextChanged(const QString &arg1) {
  QHostAddress adr;
  ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(adr.setAddress(arg1));
}
