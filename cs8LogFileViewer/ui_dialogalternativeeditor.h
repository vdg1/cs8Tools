/********************************************************************************
** Form generated from reading UI file 'dialogalternativeeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGALTERNATIVEEDITOR_H
#define UI_DIALOGALTERNATIVEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogAlternativeEditor
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QLabel *labelIcon;
    QLineEdit *leEditorFilePath;
    QPushButton *pbSelect;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogAlternativeEditor)
    {
        if (DialogAlternativeEditor->objectName().isEmpty())
            DialogAlternativeEditor->setObjectName(QStringLiteral("DialogAlternativeEditor"));
        DialogAlternativeEditor->resize(424, 183);
        verticalLayout = new QVBoxLayout(DialogAlternativeEditor);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DialogAlternativeEditor);
        label->setObjectName(QStringLiteral("label"));
        label->setTextFormat(Qt::AutoText);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        line = new QFrame(DialogAlternativeEditor);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelIcon = new QLabel(DialogAlternativeEditor);
        labelIcon->setObjectName(QStringLiteral("labelIcon"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelIcon->sizePolicy().hasHeightForWidth());
        labelIcon->setSizePolicy(sizePolicy);
        labelIcon->setMinimumSize(QSize(16, 0));
        labelIcon->setMaximumSize(QSize(64, 16777215));

        horizontalLayout->addWidget(labelIcon);

        leEditorFilePath = new QLineEdit(DialogAlternativeEditor);
        leEditorFilePath->setObjectName(QStringLiteral("leEditorFilePath"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leEditorFilePath->sizePolicy().hasHeightForWidth());
        leEditorFilePath->setSizePolicy(sizePolicy1);
        leEditorFilePath->setReadOnly(true);

        horizontalLayout->addWidget(leEditorFilePath);

        pbSelect = new QPushButton(DialogAlternativeEditor);
        pbSelect->setObjectName(QStringLiteral("pbSelect"));

        horizontalLayout->addWidget(pbSelect);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 11, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(DialogAlternativeEditor);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::No|QDialogButtonBox::Yes);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogAlternativeEditor);

        QMetaObject::connectSlotsByName(DialogAlternativeEditor);
    } // setupUi

    void retranslateUi(QDialog *DialogAlternativeEditor)
    {
        DialogAlternativeEditor->setWindowTitle(QApplication::translate("DialogAlternativeEditor", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DialogAlternativeEditor", "<html><head/><body><p align=\"center\">The log file </p><p align=\"center\"><span style=\" font-weight:600;\">%1</span></p><p align=\"center\"> does not appear to be a valid CS8 log file. Do you want to open the file in an alternative editor instead?</p></body></html>", Q_NULLPTR));
        labelIcon->setText(QString());
        pbSelect->setText(QApplication::translate("DialogAlternativeEditor", "Select", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogAlternativeEditor: public Ui_DialogAlternativeEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGALTERNATIVEEDITOR_H
