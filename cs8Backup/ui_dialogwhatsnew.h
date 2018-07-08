/********************************************************************************
** Form generated from reading UI file 'dialogwhatsnew.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGWHATSNEW_H
#define UI_DIALOGWHATSNEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogWhatsNew
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *textEditChangelog;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogWhatsNew)
    {
        if (DialogWhatsNew->objectName().isEmpty())
            DialogWhatsNew->setObjectName(QStringLiteral("DialogWhatsNew"));
        DialogWhatsNew->resize(400, 300);
        verticalLayout = new QVBoxLayout(DialogWhatsNew);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(DialogWhatsNew);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        textEditChangelog = new QTextEdit(DialogWhatsNew);
        textEditChangelog->setObjectName(QStringLiteral("textEditChangelog"));
        textEditChangelog->setReadOnly(true);

        verticalLayout->addWidget(textEditChangelog);

        buttonBox = new QDialogButtonBox(DialogWhatsNew);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogWhatsNew);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogWhatsNew, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogWhatsNew, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogWhatsNew);
    } // setupUi

    void retranslateUi(QDialog *DialogWhatsNew)
    {
        DialogWhatsNew->setWindowTitle(QApplication::translate("DialogWhatsNew", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DialogWhatsNew", "What''s New:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogWhatsNew: public Ui_DialogWhatsNew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGWHATSNEW_H
