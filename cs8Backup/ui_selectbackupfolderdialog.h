/********************************************************************************
** Form generated from reading UI file 'selectbackupfolderdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTBACKUPFOLDERDIALOG_H
#define UI_SELECTBACKUPFOLDERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_selectBackupFolderDialogClass
{
public:
    QVBoxLayout *vboxLayout;
    QLabel *label;
    QTableWidget *listWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *selectBackupFolderDialogClass)
    {
        if (selectBackupFolderDialogClass->objectName().isEmpty())
            selectBackupFolderDialogClass->setObjectName(QStringLiteral("selectBackupFolderDialogClass"));
        selectBackupFolderDialogClass->resize(607, 300);
        vboxLayout = new QVBoxLayout(selectBackupFolderDialogClass);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        label = new QLabel(selectBackupFolderDialogClass);
        label->setObjectName(QStringLiteral("label"));

        vboxLayout->addWidget(label);

        listWidget = new QTableWidget(selectBackupFolderDialogClass);
        if (listWidget->columnCount() < 2)
            listWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        listWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        listWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget->setAlternatingRowColors(true);
        listWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        listWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        listWidget->setShowGrid(false);
        listWidget->setSortingEnabled(true);

        vboxLayout->addWidget(listWidget);

        buttonBox = new QDialogButtonBox(selectBackupFolderDialogClass);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);


        retranslateUi(selectBackupFolderDialogClass);
        QObject::connect(buttonBox, SIGNAL(accepted()), selectBackupFolderDialogClass, SLOT(accept()));
        QObject::connect(listWidget, SIGNAL(doubleClicked(QModelIndex)), selectBackupFolderDialogClass, SLOT(accept()));

        QMetaObject::connectSlotsByName(selectBackupFolderDialogClass);
    } // setupUi

    void retranslateUi(QDialog *selectBackupFolderDialogClass)
    {
        selectBackupFolderDialogClass->setWindowTitle(QApplication::translate("selectBackupFolderDialogClass", "Select Backup Folder", Q_NULLPTR));
        label->setText(QApplication::translate("selectBackupFolderDialogClass", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Multiple backups of controller </span><span style=\" font-size:8pt; font-weight:600;\">%1</span><span style=\" font-size:8pt;\"> have been found.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">Please select a backup folder from the list below:</p></body></html>", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = listWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("selectBackupFolderDialogClass", "Backup Location", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = listWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("selectBackupFolderDialogClass", "Last Backup", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class selectBackupFolderDialogClass: public Ui_selectBackupFolderDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTBACKUPFOLDERDIALOG_H
