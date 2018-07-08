#include "getserialnumberdialog.h"
#include <QMessageBox>
#include <QRegExpValidator>

getSerialNumberDialog::getSerialNumberDialog(QWidget *parent) :
    QDialog(parent)
{
    ui.setupUi(this);
    ui.icon->setPixmap(QMessageBox::standardIcon((QMessageBox::Icon)QMessageBox::Information));
    validator = new QRegExpValidator(QRegExp("F\\d\\d/[A-Z,0-9]{6}/(C|A)/\\d\\d"),
                                     this);
    //ui.lineEdit->setValidator(validator);
    ui.lineEdit->setInputMask(">F99/NNNNNN/A/99;_");
}

getSerialNumberDialog::~getSerialNumberDialog()
{

}

bool getSerialNumberDialog::isValid()
{
    int pos = 0;
    QString text = ui.lineEdit->text();
    return validator->validate(text, pos) == QValidator::Acceptable;

}

void getSerialNumberDialog::on_lineEdit_textChanged(const QString & /*text*/)
{

}

QString getSerialNumberDialog::getText(QWidget *parent, bool *ok)
{
    getSerialNumberDialog dlg(parent);
    bool accepted;
    QString result;
    do
    {
        accepted = (dlg.exec() == QDialog::Accepted);
        if (ok)
            *ok = accepted;
        if (accepted)
        {
            result = dlg.text();
            result.replace("/", "_");
        }

        if (!dlg.isValid())
        {
            if (QMessageBox::critical(
                    &dlg,
                    tr("Serial Number Information"),
                    tr("The serial number you have entered is not a valid serial number. Do you want to reenter?"),
                    QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes) == QMessageBox::No)
                accepted = true;
            else
                accepted = false;
        }
    }
    while (!dlg.isValid() && !accepted);
    return result;
}
