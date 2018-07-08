/********************************************************************************
** Form generated from reading UI file 'dialogmachinecatalogueimportconfiguration.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMACHINECATALOGUEIMPORTCONFIGURATION_H
#define UI_DIALOGMACHINECATALOGUEIMPORTCONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogMachineCatalogueImportConfiguration
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout_3;
    QCheckBox *cbWithHeader;
    QLabel *label_8;
    QSpinBox *sbUrlId;
    QFormLayout *formLayout_2;
    QLabel *label;
    QSpinBox *sbControllerSerialNumber;
    QLabel *label_10;
    QSpinBox *sbArmSerialNumber;
    QFormLayout *formLayout;
    QLabel *label_2;
    QSpinBox *sbCustomerName;
    QLabel *label_3;
    QSpinBox *sbInternalNumber;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QLabel *label_4;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_11;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_9;
    QLineEdit *leControllerSerialNumber;
    QLineEdit *leArmSerialNumber;
    QLineEdit *leCustomerName;
    QLineEdit *leInternalNumber;
    QLineEdit *leURLId;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogMachineCatalogueImportConfiguration)
    {
        if (DialogMachineCatalogueImportConfiguration->objectName().isEmpty())
            DialogMachineCatalogueImportConfiguration->setObjectName(QStringLiteral("DialogMachineCatalogueImportConfiguration"));
        DialogMachineCatalogueImportConfiguration->resize(767, 519);
        verticalLayout = new QVBoxLayout(DialogMachineCatalogueImportConfiguration);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        cbWithHeader = new QCheckBox(DialogMachineCatalogueImportConfiguration);
        cbWithHeader->setObjectName(QStringLiteral("cbWithHeader"));

        formLayout_3->setWidget(0, QFormLayout::SpanningRole, cbWithHeader);

        label_8 = new QLabel(DialogMachineCatalogueImportConfiguration);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_8);

        sbUrlId = new QSpinBox(DialogMachineCatalogueImportConfiguration);
        sbUrlId->setObjectName(QStringLiteral("sbUrlId"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, sbUrlId);


        horizontalLayout->addLayout(formLayout_3);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label = new QLabel(DialogMachineCatalogueImportConfiguration);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        sbControllerSerialNumber = new QSpinBox(DialogMachineCatalogueImportConfiguration);
        sbControllerSerialNumber->setObjectName(QStringLiteral("sbControllerSerialNumber"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, sbControllerSerialNumber);

        label_10 = new QLabel(DialogMachineCatalogueImportConfiguration);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_10);

        sbArmSerialNumber = new QSpinBox(DialogMachineCatalogueImportConfiguration);
        sbArmSerialNumber->setObjectName(QStringLiteral("sbArmSerialNumber"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, sbArmSerialNumber);


        horizontalLayout->addLayout(formLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(DialogMachineCatalogueImportConfiguration);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        sbCustomerName = new QSpinBox(DialogMachineCatalogueImportConfiguration);
        sbCustomerName->setObjectName(QStringLiteral("sbCustomerName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, sbCustomerName);

        label_3 = new QLabel(DialogMachineCatalogueImportConfiguration);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        sbInternalNumber = new QSpinBox(DialogMachineCatalogueImportConfiguration);
        sbInternalNumber->setObjectName(QStringLiteral("sbInternalNumber"));

        formLayout->setWidget(1, QFormLayout::FieldRole, sbInternalNumber);


        horizontalLayout->addLayout(formLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(DialogMachineCatalogueImportConfiguration);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setSortingEnabled(true);

        verticalLayout->addWidget(tableView);

        label_4 = new QLabel(DialogMachineCatalogueImportConfiguration);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_5 = new QLabel(DialogMachineCatalogueImportConfiguration);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        label_11 = new QLabel(DialogMachineCatalogueImportConfiguration);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 0, 1, 1, 1);

        label_7 = new QLabel(DialogMachineCatalogueImportConfiguration);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        label_6 = new QLabel(DialogMachineCatalogueImportConfiguration);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 3, 1, 1);

        label_9 = new QLabel(DialogMachineCatalogueImportConfiguration);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 0, 4, 1, 1);

        leControllerSerialNumber = new QLineEdit(DialogMachineCatalogueImportConfiguration);
        leControllerSerialNumber->setObjectName(QStringLiteral("leControllerSerialNumber"));
        leControllerSerialNumber->setReadOnly(true);

        gridLayout->addWidget(leControllerSerialNumber, 1, 0, 1, 1);

        leArmSerialNumber = new QLineEdit(DialogMachineCatalogueImportConfiguration);
        leArmSerialNumber->setObjectName(QStringLiteral("leArmSerialNumber"));
        leArmSerialNumber->setReadOnly(true);

        gridLayout->addWidget(leArmSerialNumber, 1, 1, 1, 1);

        leCustomerName = new QLineEdit(DialogMachineCatalogueImportConfiguration);
        leCustomerName->setObjectName(QStringLiteral("leCustomerName"));
        leCustomerName->setReadOnly(true);

        gridLayout->addWidget(leCustomerName, 1, 2, 1, 1);

        leInternalNumber = new QLineEdit(DialogMachineCatalogueImportConfiguration);
        leInternalNumber->setObjectName(QStringLiteral("leInternalNumber"));
        leInternalNumber->setReadOnly(true);

        gridLayout->addWidget(leInternalNumber, 1, 3, 1, 1);

        leURLId = new QLineEdit(DialogMachineCatalogueImportConfiguration);
        leURLId->setObjectName(QStringLiteral("leURLId"));
        leURLId->setReadOnly(true);

        gridLayout->addWidget(leURLId, 1, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(DialogMachineCatalogueImportConfiguration);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogMachineCatalogueImportConfiguration);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogMachineCatalogueImportConfiguration, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogMachineCatalogueImportConfiguration, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogMachineCatalogueImportConfiguration);
    } // setupUi

    void retranslateUi(QDialog *DialogMachineCatalogueImportConfiguration)
    {
        DialogMachineCatalogueImportConfiguration->setWindowTitle(QApplication::translate("DialogMachineCatalogueImportConfiguration", "Catalogue Import Configuration", Q_NULLPTR));
        cbWithHeader->setText(QApplication::translate("DialogMachineCatalogueImportConfiguration", "With Header", Q_NULLPTR));
        label_8->setText(QApplication::translate("DialogMachineCatalogueImportConfiguration", "URL Id:", Q_NULLPTR));
        label->setText(QApplication::translate("DialogMachineCatalogueImportConfiguration", "Controller Serial Number Column", Q_NULLPTR));
        label_10->setText(QApplication::translate("DialogMachineCatalogueImportConfiguration", "Arm Serial Number Column", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogMachineCatalogueImportConfiguration", "Customer Name Column", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogMachineCatalogueImportConfiguration", "Internal Number Column", Q_NULLPTR));
        label_4->setText(QApplication::translate("DialogMachineCatalogueImportConfiguration", "Extracted Data Example:", Q_NULLPTR));
        label_5->setText(QApplication::translate("DialogMachineCatalogueImportConfiguration", "Controller Serial Number", Q_NULLPTR));
        label_11->setText(QApplication::translate("DialogMachineCatalogueImportConfiguration", "Arm Serial Number", Q_NULLPTR));
        label_7->setText(QApplication::translate("DialogMachineCatalogueImportConfiguration", "Customer Name", Q_NULLPTR));
        label_6->setText(QApplication::translate("DialogMachineCatalogueImportConfiguration", "Internal Number", Q_NULLPTR));
        label_9->setText(QApplication::translate("DialogMachineCatalogueImportConfiguration", "URL Id", Q_NULLPTR));
        leControllerSerialNumber->setPlaceholderText(QApplication::translate("DialogMachineCatalogueImportConfiguration", "No valid value", Q_NULLPTR));
        leArmSerialNumber->setText(QString());
        leArmSerialNumber->setPlaceholderText(QApplication::translate("DialogMachineCatalogueImportConfiguration", "No valid value", Q_NULLPTR));
        leCustomerName->setPlaceholderText(QApplication::translate("DialogMachineCatalogueImportConfiguration", "No valid value", Q_NULLPTR));
        leInternalNumber->setPlaceholderText(QApplication::translate("DialogMachineCatalogueImportConfiguration", "No valid value", Q_NULLPTR));
        leURLId->setPlaceholderText(QApplication::translate("DialogMachineCatalogueImportConfiguration", "No valid value", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogMachineCatalogueImportConfiguration: public Ui_DialogMachineCatalogueImportConfiguration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMACHINECATALOGUEIMPORTCONFIGURATION_H
