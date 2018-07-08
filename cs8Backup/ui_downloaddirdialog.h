/********************************************************************************
** Form generated from reading UI file 'downloaddirdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADDIRDIALOG_H
#define UI_DOWNLOADDIRDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_downloadDirDialogClass
{
public:
    QVBoxLayout *vboxLayout;
    QLabel *label;
    QHBoxLayout *hboxLayout;
    QLineEdit *lineEditUserDefined;
    QToolButton *toolButtonUserDefined;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *downloadDirDialogClass)
    {
        if (downloadDirDialogClass->objectName().isEmpty())
            downloadDirDialogClass->setObjectName(QStringLiteral("downloadDirDialogClass"));
        downloadDirDialogClass->resize(400, 118);
        vboxLayout = new QVBoxLayout(downloadDirDialogClass);
        vboxLayout->setSpacing(6);
        vboxLayout->setContentsMargins(11, 11, 11, 11);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        label = new QLabel(downloadDirDialogClass);
        label->setObjectName(QStringLiteral("label"));

        vboxLayout->addWidget(label);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        lineEditUserDefined = new QLineEdit(downloadDirDialogClass);
        lineEditUserDefined->setObjectName(QStringLiteral("lineEditUserDefined"));
        lineEditUserDefined->setEnabled(true);

        hboxLayout->addWidget(lineEditUserDefined);

        toolButtonUserDefined = new QToolButton(downloadDirDialogClass);
        toolButtonUserDefined->setObjectName(QStringLiteral("toolButtonUserDefined"));
        toolButtonUserDefined->setEnabled(true);

        hboxLayout->addWidget(toolButtonUserDefined);


        vboxLayout->addLayout(hboxLayout);

        buttonBox = new QDialogButtonBox(downloadDirDialogClass);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        vboxLayout->addWidget(buttonBox);

        QWidget::setTabOrder(lineEditUserDefined, toolButtonUserDefined);
        QWidget::setTabOrder(toolButtonUserDefined, buttonBox);

        retranslateUi(downloadDirDialogClass);
        QObject::connect(buttonBox, SIGNAL(accepted()), downloadDirDialogClass, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), downloadDirDialogClass, SLOT(reject()));

        QMetaObject::connectSlotsByName(downloadDirDialogClass);
    } // setupUi

    void retranslateUi(QDialog *downloadDirDialogClass)
    {
        downloadDirDialogClass->setWindowTitle(QApplication::translate("downloadDirDialogClass", "Download Directory", Q_NULLPTR));
        label->setText(QApplication::translate("downloadDirDialogClass", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Choose the folder that will receive the backup of controller </span><span style=\" font-size:8pt; font-weight:600;\">%1</span><span style=\" font-size:8pt;\">:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\">  </p></body></html>", Q_NULLPTR));
        toolButtonUserDefined->setText(QApplication::translate("downloadDirDialogClass", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class downloadDirDialogClass: public Ui_downloadDirDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADDIRDIALOG_H
