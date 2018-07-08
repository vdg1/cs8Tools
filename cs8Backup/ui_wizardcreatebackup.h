/********************************************************************************
** Form generated from reading UI file 'wizardcreatebackup.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIZARDCREATEBACKUP_H
#define UI_WIZARDCREATEBACKUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWizard>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_WizardCreateBackup
{
public:
    QWizardPage *wizardPage1;
    QWizardPage *wizardPage2;
    QWizardPage *wizardPage3;

    void setupUi(QWizard *WizardCreateBackup)
    {
        if (WizardCreateBackup->objectName().isEmpty())
            WizardCreateBackup->setObjectName(QStringLiteral("WizardCreateBackup"));
        WizardCreateBackup->resize(865, 677);
        WizardCreateBackup->setModal(true);
        WizardCreateBackup->setWizardStyle(QWizard::ModernStyle);
        wizardPage1 = new QWizardPage();
        wizardPage1->setObjectName(QStringLiteral("wizardPage1"));
        WizardCreateBackup->addPage(wizardPage1);
        wizardPage2 = new QWizardPage();
        wizardPage2->setObjectName(QStringLiteral("wizardPage2"));
        WizardCreateBackup->addPage(wizardPage2);
        wizardPage3 = new QWizardPage();
        wizardPage3->setObjectName(QStringLiteral("wizardPage3"));
        WizardCreateBackup->addPage(wizardPage3);

        retranslateUi(WizardCreateBackup);

        QMetaObject::connectSlotsByName(WizardCreateBackup);
    } // setupUi

    void retranslateUi(QWizard *WizardCreateBackup)
    {
        WizardCreateBackup->setWindowTitle(QApplication::translate("WizardCreateBackup", "Wizard", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WizardCreateBackup: public Ui_WizardCreateBackup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIZARDCREATEBACKUP_H
