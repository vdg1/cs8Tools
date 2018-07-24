/********************************************************************************
** Form generated from reading UI file 'dialoggetmachinedata.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGGETMACHINEDATA_H
#define UI_DIALOGGETMACHINEDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogGetMachineData
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lbHeader;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QComboBox *cbInternalNumber;
    QLabel *label_2;
    QComboBox *cbCustomerName;
    QLabel *label_3;
    QCheckBox *cbInformMaintainer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogGetMachineData)
    {
        if (DialogGetMachineData->objectName().isEmpty())
            DialogGetMachineData->setObjectName(QStringLiteral("DialogGetMachineData"));
        DialogGetMachineData->resize(400, 244);
        verticalLayout = new QVBoxLayout(DialogGetMachineData);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lbHeader = new QLabel(DialogGetMachineData);
        lbHeader->setObjectName(QStringLiteral("lbHeader"));
        QFont font;
        font.setPointSize(12);
        lbHeader->setFont(font);
        lbHeader->setTextFormat(Qt::PlainText);
        lbHeader->setWordWrap(true);

        verticalLayout->addWidget(lbHeader);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        cbInternalNumber = new QComboBox(DialogGetMachineData);
        cbInternalNumber->setObjectName(QStringLiteral("cbInternalNumber"));
        cbInternalNumber->setEditable(true);
        cbInternalNumber->setInsertPolicy(QComboBox::InsertAlphabetically);

        gridLayout->addWidget(cbInternalNumber, 1, 1, 1, 1);

        label_2 = new QLabel(DialogGetMachineData);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        cbCustomerName = new QComboBox(DialogGetMachineData);
        cbCustomerName->setObjectName(QStringLiteral("cbCustomerName"));
        cbCustomerName->setEditable(true);
        cbCustomerName->setInsertPolicy(QComboBox::InsertAlphabetically);

        gridLayout->addWidget(cbCustomerName, 0, 1, 1, 1);

        label_3 = new QLabel(DialogGetMachineData);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        cbInformMaintainer = new QCheckBox(DialogGetMachineData);
        cbInformMaintainer->setObjectName(QStringLiteral("cbInformMaintainer"));
        cbInformMaintainer->setChecked(true);

        verticalLayout->addWidget(cbInformMaintainer);

        buttonBox = new QDialogButtonBox(DialogGetMachineData);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(cbCustomerName, cbInternalNumber);
        QWidget::setTabOrder(cbInternalNumber, cbInformMaintainer);
        QWidget::setTabOrder(cbInformMaintainer, buttonBox);

        retranslateUi(DialogGetMachineData);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogGetMachineData, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogGetMachineData, SLOT(reject()));

        cbInternalNumber->setCurrentIndex(-1);
        cbCustomerName->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(DialogGetMachineData);
    } // setupUi

    void retranslateUi(QDialog *DialogGetMachineData)
    {
        DialogGetMachineData->setWindowTitle(QApplication::translate("DialogGetMachineData", "Robot System Information", Q_NULLPTR));
        lbHeader->setText(QApplication::translate("DialogGetMachineData", "The robot system with serial number %1 could not be found neither in the machine catalogue nor in your backup storage.\n"
"Please enter some details about this robot system:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cbInternalNumber->setToolTip(QApplication::translate("DialogGetMachineData", "Enter here the customers' internal machine number.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("DialogGetMachineData", "Customer:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cbCustomerName->setToolTip(QApplication::translate("DialogGetMachineData", "Enter here the customers name.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("DialogGetMachineData", "Internal No:", Q_NULLPTR));
        cbInformMaintainer->setText(QApplication::translate("DialogGetMachineData", "Inform the catalogue maintainer about \n"
"this robot via mail", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogGetMachineData: public Ui_DialogGetMachineData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGGETMACHINEDATA_H
