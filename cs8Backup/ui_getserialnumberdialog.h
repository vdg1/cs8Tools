/********************************************************************************
** Form generated from reading UI file 'getserialnumberdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETSERIALNUMBERDIALOG_H
#define UI_GETSERIALNUMBERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_getSerialNumberDialogClass
{
public:
    QVBoxLayout *vboxLayout;
    QVBoxLayout *vboxLayout1;
    QLabel *icon;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *getSerialNumberDialogClass)
    {
        if (getSerialNumberDialogClass->objectName().isEmpty())
            getSerialNumberDialogClass->setObjectName(QStringLiteral("getSerialNumberDialogClass"));
        getSerialNumberDialogClass->resize(331, 154);
        vboxLayout = new QVBoxLayout(getSerialNumberDialogClass);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        vboxLayout1 = new QVBoxLayout();
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        icon = new QLabel(getSerialNumberDialogClass);
        icon->setObjectName(QStringLiteral("icon"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(icon->sizePolicy().hasHeightForWidth());
        icon->setSizePolicy(sizePolicy);

        vboxLayout1->addWidget(icon);

        label = new QLabel(getSerialNumberDialogClass);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setWordWrap(true);

        vboxLayout1->addWidget(label);


        vboxLayout->addLayout(vboxLayout1);

        lineEdit = new QLineEdit(getSerialNumberDialogClass);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        vboxLayout->addWidget(lineEdit);

        label_2 = new QLabel(getSerialNumberDialogClass);
        label_2->setObjectName(QStringLiteral("label_2"));

        vboxLayout->addWidget(label_2);

        buttonBox = new QDialogButtonBox(getSerialNumberDialogClass);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);


        retranslateUi(getSerialNumberDialogClass);
        QObject::connect(buttonBox, SIGNAL(accepted()), getSerialNumberDialogClass, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), getSerialNumberDialogClass, SLOT(reject()));

        QMetaObject::connectSlotsByName(getSerialNumberDialogClass);
    } // setupUi

    void retranslateUi(QDialog *getSerialNumberDialogClass)
    {
        getSerialNumberDialogClass->setWindowTitle(QApplication::translate("getSerialNumberDialogClass", "Serial Number Information", Q_NULLPTR));
        icon->setText(QString());
        label->setText(QApplication::translate("getSerialNumberDialogClass", "The serial number of the controller could not be determined. Please enter the serial number manually below:", Q_NULLPTR));
        lineEdit->setInputMask(QString());
        label_2->setText(QApplication::translate("getSerialNumberDialogClass", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">(Example: <span style=\" font-weight:600;\">F08/123AB1/C/01</span>)</p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class getSerialNumberDialogClass: public Ui_getSerialNumberDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETSERIALNUMBERDIALOG_H
