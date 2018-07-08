/********************************************************************************
** Form generated from reading UI file 'dialogrobotdetails.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGROBOTDETAILS_H
#define UI_DIALOGROBOTDETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogRobotDetails
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QComboBox *cbMachineSerialumber;
    QLineEdit *lineEdit;

    void setupUi(QDialog *DialogRobotDetails)
    {
        if (DialogRobotDetails->objectName().isEmpty())
            DialogRobotDetails->setObjectName(QStringLiteral("DialogRobotDetails"));
        DialogRobotDetails->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogRobotDetails);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(DialogRobotDetails);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 91, 16));
        cbMachineSerialumber = new QComboBox(DialogRobotDetails);
        cbMachineSerialumber->setObjectName(QStringLiteral("cbMachineSerialumber"));
        cbMachineSerialumber->setGeometry(QRect(140, 30, 69, 22));
        cbMachineSerialumber->setEditable(true);
        lineEdit = new QLineEdit(DialogRobotDetails);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 110, 151, 20));
        lineEdit->setFrame(true);
        lineEdit->setClearButtonEnabled(true);

        retranslateUi(DialogRobotDetails);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogRobotDetails, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogRobotDetails, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogRobotDetails);
    } // setupUi

    void retranslateUi(QDialog *DialogRobotDetails)
    {
        DialogRobotDetails->setWindowTitle(QApplication::translate("DialogRobotDetails", "Robot Details", Q_NULLPTR));
        label->setText(QApplication::translate("DialogRobotDetails", "Machine Serial Number:", Q_NULLPTR));
        lineEdit->setInputMask(QApplication::translate("DialogRobotDetails", "F99/NNNNN/C/99", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogRobotDetails: public Ui_DialogRobotDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGROBOTDETAILS_H
