#include "dialogrobotdetails.h"
#include "ui_dialogrobotdetails.h"

DialogRobotDetails::DialogRobotDetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRobotDetails)
{
    ui->setupUi(this);
    ui->cbMachineSerialumber->lineEdit()->setInputMask("F99/NNNNN/C/99");
    ui->cbMachineSerialumber->lineEdit()->setClearButtonEnabled(true);
    ui->cbMachineSerialumber->setModelColumn(1);
}

DialogRobotDetails::~DialogRobotDetails()
{
    delete ui;
}
