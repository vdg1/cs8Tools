#include "wizardcreatebackup.h"
#include "ui_wizardcreatebackup.h"

WizardCreateBackup::WizardCreateBackup(QWidget *parent)
    : QWizard(parent), ui(new Ui::WizardCreateBackup) {
  ui->setupUi(this);
}

WizardCreateBackup::~WizardCreateBackup() { delete ui; }

void WizardCreateBackup::changeEvent(QEvent *e) {
  QWizard::changeEvent(e);
  switch (e->type()) {
  case QEvent::LanguageChange:
    ui->retranslateUi(this);
    break;
  default:
    break;
  }
}
