/********************************************************************************
** Form generated from reading UI file 'cs8connectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CS8CONNECTDIALOG_H
#define UI_CS8CONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_cs8ConnectDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QRadioButton *rbCS8;
    QRadioButton *rbCS9;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *cpIPAddress;
    QLabel *label_2;
    QSpinBox *sbPortNumber;
    QCheckBox *cbLoadStoredLog;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *cs8ConnectDialog)
    {
        if (cs8ConnectDialog->objectName().isEmpty())
            cs8ConnectDialog->setObjectName(QStringLiteral("cs8ConnectDialog"));
        cs8ConnectDialog->resize(388, 154);
        verticalLayout = new QVBoxLayout(cs8ConnectDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(cs8ConnectDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        rbCS8 = new QRadioButton(cs8ConnectDialog);
        rbCS8->setObjectName(QStringLiteral("rbCS8"));
        rbCS8->setChecked(true);

        horizontalLayout->addWidget(rbCS8);

        rbCS9 = new QRadioButton(cs8ConnectDialog);
        rbCS9->setObjectName(QStringLiteral("rbCS9"));
        rbCS9->setEnabled(false);

        horizontalLayout->addWidget(rbCS9);


        verticalLayout->addLayout(horizontalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(cs8ConnectDialog);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        cpIPAddress = new QComboBox(cs8ConnectDialog);
        cpIPAddress->setObjectName(QStringLiteral("cpIPAddress"));
        cpIPAddress->setEditable(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, cpIPAddress);

        label_2 = new QLabel(cs8ConnectDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        sbPortNumber = new QSpinBox(cs8ConnectDialog);
        sbPortNumber->setObjectName(QStringLiteral("sbPortNumber"));
        sbPortNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        sbPortNumber->setAccelerated(true);
        sbPortNumber->setMinimum(1);
        sbPortNumber->setMaximum(65000);
        sbPortNumber->setValue(23);

        formLayout->setWidget(1, QFormLayout::FieldRole, sbPortNumber);


        verticalLayout->addLayout(formLayout);

        cbLoadStoredLog = new QCheckBox(cs8ConnectDialog);
        cbLoadStoredLog->setObjectName(QStringLiteral("cbLoadStoredLog"));

        verticalLayout->addWidget(cbLoadStoredLog);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(cs8ConnectDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(cpIPAddress, sbPortNumber);
        QWidget::setTabOrder(sbPortNumber, cbLoadStoredLog);
        QWidget::setTabOrder(cbLoadStoredLog, rbCS8);
        QWidget::setTabOrder(rbCS8, rbCS9);

        retranslateUi(cs8ConnectDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), cs8ConnectDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), cs8ConnectDialog, SLOT(reject()));
        QObject::connect(rbCS8, SIGNAL(toggled(bool)), sbPortNumber, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(cs8ConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *cs8ConnectDialog)
    {
        cs8ConnectDialog->setWindowTitle(QApplication::translate("cs8ConnectDialog", "Dialog", Q_NULLPTR));
        label_3->setText(QApplication::translate("cs8ConnectDialog", "Controller Type", Q_NULLPTR));
        rbCS8->setText(QApplication::translate("cs8ConnectDialog", "CS8", Q_NULLPTR));
        rbCS9->setText(QApplication::translate("cs8ConnectDialog", "CS9", Q_NULLPTR));
        label->setText(QApplication::translate("cs8ConnectDialog", "Controller IP Address:", Q_NULLPTR));
        label_2->setText(QApplication::translate("cs8ConnectDialog", "Port:", Q_NULLPTR));
        cbLoadStoredLog->setText(QApplication::translate("cs8ConnectDialog", "Load log data from log file", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cs8ConnectDialog: public Ui_cs8ConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CS8CONNECTDIALOG_H
