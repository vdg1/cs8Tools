/********************************************************************************
** Form generated from reading UI file 'bugreportdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUGREPORTDIALOG_H
#define UI_BUGREPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_bugReportDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *subject;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *severity;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *type;
    QLabel *label_3;
    QPlainTextEdit *description;
    QLabel *label_5;
    QTextEdit *reproduce;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *bugReportDialog)
    {
        if (bugReportDialog->objectName().isEmpty())
            bugReportDialog->setObjectName(QStringLiteral("bugReportDialog"));
        bugReportDialog->resize(484, 537);
        verticalLayout = new QVBoxLayout(bugReportDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(bugReportDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setWordWrap(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        subject = new QLineEdit(bugReportDialog);
        subject->setObjectName(QStringLiteral("subject"));

        formLayout->setWidget(0, QFormLayout::FieldRole, subject);

        label = new QLabel(bugReportDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setWordWrap(true);

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        severity = new QComboBox(bugReportDialog);
        severity->setObjectName(QStringLiteral("severity"));

        horizontalLayout_3->addWidget(severity);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        type = new QComboBox(bugReportDialog);
        type->setObjectName(QStringLiteral("type"));

        horizontalLayout->addWidget(type);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout);

        label_3 = new QLabel(bugReportDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setWordWrap(true);

        formLayout->setWidget(8, QFormLayout::LabelRole, label_3);

        description = new QPlainTextEdit(bugReportDialog);
        description->setObjectName(QStringLiteral("description"));
        description->setBackgroundVisible(false);

        formLayout->setWidget(8, QFormLayout::FieldRole, description);

        label_5 = new QLabel(bugReportDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setWordWrap(true);

        formLayout->setWidget(10, QFormLayout::LabelRole, label_5);

        reproduce = new QTextEdit(bugReportDialog);
        reproduce->setObjectName(QStringLiteral("reproduce"));

        formLayout->setWidget(10, QFormLayout::FieldRole, reproduce);

        label_4 = new QLabel(bugReportDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setWordWrap(true);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_4);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(bugReportDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(bugReportDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(bugReportDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), bugReportDialog, SLOT(reject()));

        severity->setCurrentIndex(0);
        type->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(bugReportDialog);
    } // setupUi

    void retranslateUi(QDialog *bugReportDialog)
    {
        bugReportDialog->setWindowTitle(QApplication::translate("bugReportDialog", "Submit a bug report", Q_NULLPTR));
        label_2->setText(QApplication::translate("bugReportDialog", "Subject:", Q_NULLPTR));
        subject->setPlaceholderText(QApplication::translate("bugReportDialog", "Enter a title of the issue", Q_NULLPTR));
        label->setText(QApplication::translate("bugReportDialog", "Severity:", Q_NULLPTR));
        severity->clear();
        severity->insertItems(0, QStringList()
         << QApplication::translate("bugReportDialog", "Low", Q_NULLPTR)
         << QApplication::translate("bugReportDialog", "Medium", Q_NULLPTR)
         << QApplication::translate("bugReportDialog", "High", Q_NULLPTR)
         << QApplication::translate("bugReportDialog", "Critical", Q_NULLPTR)
        );
        type->clear();
        type->insertItems(0, QStringList()
         << QApplication::translate("bugReportDialog", "Design", Q_NULLPTR)
         << QApplication::translate("bugReportDialog", "Functional", Q_NULLPTR)
         << QApplication::translate("bugReportDialog", "Usability", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("bugReportDialog", "Description of problem:", Q_NULLPTR));
        label_5->setText(QApplication::translate("bugReportDialog", "How to reproduce:", Q_NULLPTR));
        label_4->setText(QApplication::translate("bugReportDialog", "Type of Issue:", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("bugReportDialog", "Submit", Q_NULLPTR));
        pushButton->setText(QApplication::translate("bugReportDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class bugReportDialog: public Ui_bugReportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUGREPORTDIALOG_H
