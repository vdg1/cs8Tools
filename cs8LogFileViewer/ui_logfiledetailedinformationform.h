/********************************************************************************
** Form generated from reading UI file 'logfiledetailedinformationform.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGFILEDETAILEDINFORMATIONFORM_H
#define UI_LOGFILEDETAILEDINFORMATIONFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_logFileDetailedInformationForm
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditArmSerialNumber;
    QLabel *label_3;
    QLineEdit *lineEditCustomer;
    QLabel *label_5;
    QLineEdit *lineEditSpanFrom;
    QLabel *label_6;
    QLineEdit *lineEditSpanTill;
    QLabel *label_2;
    QLineEdit *lineEditControllerSerialNumber;
    QLabel *label_4;
    QLineEdit *lineEditCustomersMachineNumber;
    QLabel *label_7;
    QLineEdit *lineEditArmType;

    void setupUi(QWidget *logFileDetailedInformationForm)
    {
        if (logFileDetailedInformationForm->objectName().isEmpty())
            logFileDetailedInformationForm->setObjectName(QStringLiteral("logFileDetailedInformationForm"));
        logFileDetailedInformationForm->resize(765, 300);
        gridLayout = new QGridLayout(logFileDetailedInformationForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(logFileDetailedInformationForm);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditArmSerialNumber = new QLineEdit(logFileDetailedInformationForm);
        lineEditArmSerialNumber->setObjectName(QStringLiteral("lineEditArmSerialNumber"));

        gridLayout->addWidget(lineEditArmSerialNumber, 0, 1, 1, 1);

        label_3 = new QLabel(logFileDetailedInformationForm);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        lineEditCustomer = new QLineEdit(logFileDetailedInformationForm);
        lineEditCustomer->setObjectName(QStringLiteral("lineEditCustomer"));

        gridLayout->addWidget(lineEditCustomer, 0, 3, 1, 1);

        label_5 = new QLabel(logFileDetailedInformationForm);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 4, 1, 1);

        lineEditSpanFrom = new QLineEdit(logFileDetailedInformationForm);
        lineEditSpanFrom->setObjectName(QStringLiteral("lineEditSpanFrom"));
        lineEditSpanFrom->setAlignment(Qt::AlignCenter);
        lineEditSpanFrom->setReadOnly(true);

        gridLayout->addWidget(lineEditSpanFrom, 0, 5, 1, 1);

        label_6 = new QLabel(logFileDetailedInformationForm);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 6, 1, 1);

        lineEditSpanTill = new QLineEdit(logFileDetailedInformationForm);
        lineEditSpanTill->setObjectName(QStringLiteral("lineEditSpanTill"));
        lineEditSpanTill->setLayoutDirection(Qt::RightToLeft);
        lineEditSpanTill->setAlignment(Qt::AlignCenter);
        lineEditSpanTill->setReadOnly(true);

        gridLayout->addWidget(lineEditSpanTill, 0, 7, 1, 1);

        label_2 = new QLabel(logFileDetailedInformationForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditControllerSerialNumber = new QLineEdit(logFileDetailedInformationForm);
        lineEditControllerSerialNumber->setObjectName(QStringLiteral("lineEditControllerSerialNumber"));

        gridLayout->addWidget(lineEditControllerSerialNumber, 1, 1, 1, 1);

        label_4 = new QLabel(logFileDetailedInformationForm);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        lineEditCustomersMachineNumber = new QLineEdit(logFileDetailedInformationForm);
        lineEditCustomersMachineNumber->setObjectName(QStringLiteral("lineEditCustomersMachineNumber"));

        gridLayout->addWidget(lineEditCustomersMachineNumber, 1, 3, 1, 1);

        label_7 = new QLabel(logFileDetailedInformationForm);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        lineEditArmType = new QLineEdit(logFileDetailedInformationForm);
        lineEditArmType->setObjectName(QStringLiteral("lineEditArmType"));

        gridLayout->addWidget(lineEditArmType, 2, 1, 1, 1);


        retranslateUi(logFileDetailedInformationForm);

        QMetaObject::connectSlotsByName(logFileDetailedInformationForm);
    } // setupUi

    void retranslateUi(QWidget *logFileDetailedInformationForm)
    {
        logFileDetailedInformationForm->setWindowTitle(QApplication::translate("logFileDetailedInformationForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("logFileDetailedInformationForm", "Arm SR:", Q_NULLPTR));
        label_3->setText(QApplication::translate("logFileDetailedInformationForm", "Customer:", Q_NULLPTR));
        label_5->setText(QApplication::translate("logFileDetailedInformationForm", "Span from:", Q_NULLPTR));
        label_6->setText(QApplication::translate("logFileDetailedInformationForm", "-", Q_NULLPTR));
        label_2->setText(QApplication::translate("logFileDetailedInformationForm", "Controller SR:", Q_NULLPTR));
        label_4->setText(QApplication::translate("logFileDetailedInformationForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Customers</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Machine Number</span></p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("logFileDetailedInformationForm", "Arm Type:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class logFileDetailedInformationForm: public Ui_logFileDetailedInformationForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGFILEDETAILEDINFORMATIONFORM_H
