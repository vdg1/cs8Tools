/********************************************************************************
** Form generated from reading UI file 'settingsForm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSFORM_H
#define UI_SETTINGSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsForm
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QCheckBox *cbSys;
    QCheckBox *cbUsr;
    QCheckBox *cbLog;
    QFrame *line;
    QCheckBox *cbCompress;
    QFrame *line_2;
    QCheckBox *cbPreserveTimeStamp;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QSpinBox *spAutomaticRetries;
    QSpacerItem *spacerItem;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QHBoxLayout *hboxLayout;
    QLabel *labelDownLoadDir;
    QLineEdit *lineEditDownLoadDir;
    QPushButton *dirButton;
    QSpacerItem *verticalSpacer;
    QFrame *line_3;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *leBackupTemplate;
    QLabel *label_8;
    QLabel *lbExample;
    QTextBrowser *textBrowser;
    QSpacerItem *spacerItem1;
    QWidget *page_3;
    QGridLayout *gridLayout1;
    QLabel *label_3;
    QLabel *label;
    QComboBox *cbLanguages;
    QLabel *label_2;
    QComboBox *cbStyle;
    QSpacerItem *spacerItem2;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem3;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *SettingsForm)
    {
        if (SettingsForm->objectName().isEmpty())
            SettingsForm->setObjectName(QStringLiteral("SettingsForm"));
        SettingsForm->resize(579, 378);
        horizontalLayout = new QHBoxLayout(SettingsForm);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listWidget = new QListWidget(SettingsForm);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget->setAlternatingRowColors(true);
        listWidget->setResizeMode(QListView::Adjust);
        listWidget->setWordWrap(true);

        horizontalLayout->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stackedWidget = new QStackedWidget(SettingsForm);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setWordWrap(true);

        verticalLayout_3->addWidget(label_4);

        cbSys = new QCheckBox(page);
        cbSys->setObjectName(QStringLiteral("cbSys"));

        verticalLayout_3->addWidget(cbSys);

        cbUsr = new QCheckBox(page);
        cbUsr->setObjectName(QStringLiteral("cbUsr"));

        verticalLayout_3->addWidget(cbUsr);

        cbLog = new QCheckBox(page);
        cbLog->setObjectName(QStringLiteral("cbLog"));

        verticalLayout_3->addWidget(cbLog);

        line = new QFrame(page);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        cbCompress = new QCheckBox(page);
        cbCompress->setObjectName(QStringLiteral("cbCompress"));

        verticalLayout_3->addWidget(cbCompress);

        line_2 = new QFrame(page);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        cbPreserveTimeStamp = new QCheckBox(page);
        cbPreserveTimeStamp->setObjectName(QStringLiteral("cbPreserveTimeStamp"));

        verticalLayout_3->addWidget(cbPreserveTimeStamp);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(page);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_7);

        spAutomaticRetries = new QSpinBox(page);
        spAutomaticRetries->setObjectName(QStringLiteral("spAutomaticRetries"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spAutomaticRetries->sizePolicy().hasHeightForWidth());
        spAutomaticRetries->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(spAutomaticRetries);


        verticalLayout_3->addLayout(horizontalLayout_2);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(spacerItem);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setWordWrap(true);

        verticalLayout_2->addWidget(label_5);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        labelDownLoadDir = new QLabel(page_2);
        labelDownLoadDir->setObjectName(QStringLiteral("labelDownLoadDir"));
        labelDownLoadDir->setWordWrap(true);

        hboxLayout->addWidget(labelDownLoadDir);

        lineEditDownLoadDir = new QLineEdit(page_2);
        lineEditDownLoadDir->setObjectName(QStringLiteral("lineEditDownLoadDir"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(2);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEditDownLoadDir->sizePolicy().hasHeightForWidth());
        lineEditDownLoadDir->setSizePolicy(sizePolicy3);
        lineEditDownLoadDir->setReadOnly(true);

        hboxLayout->addWidget(lineEditDownLoadDir);

        dirButton = new QPushButton(page_2);
        dirButton->setObjectName(QStringLiteral("dirButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(dirButton->sizePolicy().hasHeightForWidth());
        dirButton->setSizePolicy(sizePolicy4);
        dirButton->setMinimumSize(QSize(0, 0));

        hboxLayout->addWidget(dirButton);


        verticalLayout_2->addLayout(hboxLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        line_3 = new QFrame(page_2);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        leBackupTemplate = new QLineEdit(page_2);
        leBackupTemplate->setObjectName(QStringLiteral("leBackupTemplate"));

        gridLayout->addWidget(leBackupTemplate, 0, 1, 1, 1);

        label_8 = new QLabel(page_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 1, 0, 1, 1);

        lbExample = new QLabel(page_2);
        lbExample->setObjectName(QStringLiteral("lbExample"));

        gridLayout->addWidget(lbExample, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        textBrowser = new QTextBrowser(page_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy5);
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setFrameShadow(QFrame::Plain);
        textBrowser->setLineWidth(0);

        verticalLayout_2->addWidget(textBrowser);

        spacerItem1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(spacerItem1);

        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        gridLayout1 = new QGridLayout(page_3);
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setWordWrap(true);

        gridLayout1->addWidget(label_3, 0, 0, 1, 1);

        label = new QLabel(page_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout1->addWidget(label, 1, 0, 1, 1);

        cbLanguages = new QComboBox(page_3);
        cbLanguages->setObjectName(QStringLiteral("cbLanguages"));

        gridLayout1->addWidget(cbLanguages, 1, 1, 1, 1);

        label_2 = new QLabel(page_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout1->addWidget(label_2, 2, 0, 1, 1);

        cbStyle = new QComboBox(page_3);
        cbStyle->setObjectName(QStringLiteral("cbStyle"));
        cbStyle->setEnabled(false);

        gridLayout1->addWidget(cbStyle, 2, 1, 1, 1);

        spacerItem2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout1->addItem(spacerItem2, 3, 0, 1, 1);

        stackedWidget->addWidget(page_3);

        verticalLayout->addWidget(stackedWidget);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        hboxLayout1->setContentsMargins(0, 0, 0, 0);
        spacerItem3 = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout1->addItem(spacerItem3);

        okButton = new QPushButton(SettingsForm);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout1->addWidget(okButton);

        cancelButton = new QPushButton(SettingsForm);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout1->addWidget(cancelButton);


        verticalLayout->addLayout(hboxLayout1);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(SettingsForm);
        QObject::connect(okButton, SIGNAL(clicked()), SettingsForm, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), SettingsForm, SLOT(reject()));
        QObject::connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));

        listWidget->setCurrentRow(0);
        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SettingsForm);
    } // setupUi

    void retranslateUi(QDialog *SettingsForm)
    {
        SettingsForm->setWindowTitle(QApplication::translate("SettingsForm", "Preferences", Q_NULLPTR));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("SettingsForm", "Default Backup Settings", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("SettingsForm", "Backup Storage Directory", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("SettingsForm", "User Interface", Q_NULLPTR));
        listWidget->setSortingEnabled(__sortingEnabled);

        label_4->setText(QApplication::translate("SettingsForm", "If a not yet used address / host name is entered these settings are used by default.", Q_NULLPTR));
        cbSys->setText(QApplication::translate("SettingsForm", "Save /sys partition", Q_NULLPTR));
        cbUsr->setText(QApplication::translate("SettingsForm", "Save /usr partition", Q_NULLPTR));
        cbLog->setText(QApplication::translate("SettingsForm", "Save /log partition", Q_NULLPTR));
        cbCompress->setText(QApplication::translate("SettingsForm", "Compress backup after download", Q_NULLPTR));
        cbPreserveTimeStamp->setText(QApplication::translate("SettingsForm", "Preserve time stamp of saved files", Q_NULLPTR));
        label_7->setText(QApplication::translate("SettingsForm", "Number of automatic retries", Q_NULLPTR));
        label_5->setText(QApplication::translate("SettingsForm", "Backups are stored in this folder, separated by serial number and time stamp of backup creation.", Q_NULLPTR));
        labelDownLoadDir->setText(QApplication::translate("SettingsForm", "Download Folder:", Q_NULLPTR));
        dirButton->setText(QApplication::translate("SettingsForm", "...", Q_NULLPTR));
        label_6->setText(QApplication::translate("SettingsForm", "Backup name template", Q_NULLPTR));
        label_8->setText(QApplication::translate("SettingsForm", "Example:", Q_NULLPTR));
        lbExample->setText(QString());
        textBrowser->setHtml(QApplication::translate("SettingsForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Place holders for backup names:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">%SN	Serial number</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("SettingsForm", "Modification of these settings become active on next start!", Q_NULLPTR));
        label->setText(QApplication::translate("SettingsForm", "Language", Q_NULLPTR));
        label_2->setText(QApplication::translate("SettingsForm", "Style", Q_NULLPTR));
        cbStyle->clear();
        cbStyle->insertItems(0, QStringList()
         << QApplication::translate("SettingsForm", "Automatic", Q_NULLPTR)
         << QApplication::translate("SettingsForm", "Plastique", Q_NULLPTR)
         << QApplication::translate("SettingsForm", "Windows Vista", Q_NULLPTR)
         << QApplication::translate("SettingsForm", "Windows XP", Q_NULLPTR)
        );
        okButton->setText(QApplication::translate("SettingsForm", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("SettingsForm", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingsForm: public Ui_SettingsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSFORM_H
