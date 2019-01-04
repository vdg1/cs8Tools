#include "logfiledetailedinformationform.h"
#include "ui_logfiledetailedinformationform.h"

#include <QDataWidgetMapper>
#include <cs8metainformationmodel.h>

logFileDetailedInformationForm::logFileDetailedInformationForm(QWidget *parent)
    : QWidget(parent), ui(new Ui::logFileDetailedInformationForm) {
  ui->setupUi(this);
  setEnabled(false);
  m_mapper = new QDataWidgetMapper(this);
}

logFileDetailedInformationForm::~logFileDetailedInformationForm() { delete ui; }

void logFileDetailedInformationForm::setModel(cs8MetaInformationModel *model) {
  m_mapper->setModel(model);
  m_mapper->addMapping(ui->lineEditArmSerialNumber, model->fieldIndex("id_arms"));
  m_mapper->addMapping(ui->lineEditSpanFrom, model->fieldIndex("spanFrom"));
  m_mapper->addMapping(ui->lineEditSpanTill, model->fieldIndex("spanTill"));
  m_mapper->addMapping(ui->lineEditControllerSerialNumber, model->fieldIndex("id_controllers"));
  m_mapper->addMapping(ui->lineEditArmType, model->fieldIndex("armType"));
  connect(model, SIGNAL(informationUpdated(int)), this, SLOT(selectRecord(int)));
}

void logFileDetailedInformationForm::selectRow(int row) {
  qFatal("Shouldn't be here....");
  m_mapper->setCurrentIndex(row);
  setEnabled(true);
}

void logFileDetailedInformationForm::selectRecord(int row) { m_mapper->setCurrentIndex(row); }
