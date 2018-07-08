/********************************************************************************
** Form generated from reading UI file 'detailProgressDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILPROGRESSDIALOG_H
#define UI_DETAILPROGRESSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DetailProgressDialog
{
public:
    QVBoxLayout *vboxLayout;
    QLabel *lbDetail;
    QProgressBar *pbDetail;
    QLabel *lbTotal;
    QProgressBar *pbTotal;

    void setupUi(QDialog *DetailProgressDialog)
    {
        if (DetailProgressDialog->objectName().isEmpty())
            DetailProgressDialog->setObjectName(QStringLiteral("DetailProgressDialog"));
        DetailProgressDialog->resize(478, 104);
        vboxLayout = new QVBoxLayout(DetailProgressDialog);
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        vboxLayout->setContentsMargins(9, 9, 9, 9);
        lbDetail = new QLabel(DetailProgressDialog);
        lbDetail->setObjectName(QStringLiteral("lbDetail"));

        vboxLayout->addWidget(lbDetail);

        pbDetail = new QProgressBar(DetailProgressDialog);
        pbDetail->setObjectName(QStringLiteral("pbDetail"));
        pbDetail->setValue(24);
        pbDetail->setOrientation(Qt::Horizontal);

        vboxLayout->addWidget(pbDetail);

        lbTotal = new QLabel(DetailProgressDialog);
        lbTotal->setObjectName(QStringLiteral("lbTotal"));

        vboxLayout->addWidget(lbTotal);

        pbTotal = new QProgressBar(DetailProgressDialog);
        pbTotal->setObjectName(QStringLiteral("pbTotal"));
        pbTotal->setValue(24);
        pbTotal->setOrientation(Qt::Horizontal);

        vboxLayout->addWidget(pbTotal);


        retranslateUi(DetailProgressDialog);

        QMetaObject::connectSlotsByName(DetailProgressDialog);
    } // setupUi

    void retranslateUi(QDialog *DetailProgressDialog)
    {
        DetailProgressDialog->setWindowTitle(QApplication::translate("DetailProgressDialog", "Backup Progress", Q_NULLPTR));
        lbDetail->setText(QApplication::translate("DetailProgressDialog", "TextLabel", Q_NULLPTR));
        lbTotal->setText(QApplication::translate("DetailProgressDialog", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DetailProgressDialog: public Ui_DetailProgressDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILPROGRESSDIALOG_H
