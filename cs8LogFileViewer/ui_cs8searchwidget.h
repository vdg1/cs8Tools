/********************************************************************************
** Form generated from reading UI file 'cs8searchwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CS8SEARCHWIDGET_H
#define UI_CS8SEARCHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cs8SearchWidgetClass
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditSearchText;
    QToolButton *toolButtonClear;
    QHBoxLayout *horizontalLayout;
    QCheckBox *cbRegularExpression;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLabel *labelHits;
    QTableView *listViewResults;

    void setupUi(QWidget *cs8SearchWidgetClass)
    {
        if (cs8SearchWidgetClass->objectName().isEmpty())
            cs8SearchWidgetClass->setObjectName(QStringLiteral("cs8SearchWidgetClass"));
        cs8SearchWidgetClass->resize(400, 300);
        verticalLayout = new QVBoxLayout(cs8SearchWidgetClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(cs8SearchWidgetClass);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEditSearchText = new QLineEdit(cs8SearchWidgetClass);
        lineEditSearchText->setObjectName(QStringLiteral("lineEditSearchText"));

        horizontalLayout_2->addWidget(lineEditSearchText);

        toolButtonClear = new QToolButton(cs8SearchWidgetClass);
        toolButtonClear->setObjectName(QStringLiteral("toolButtonClear"));

        horizontalLayout_2->addWidget(toolButtonClear);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cbRegularExpression = new QCheckBox(cs8SearchWidgetClass);
        cbRegularExpression->setObjectName(QStringLiteral("cbRegularExpression"));
        cbRegularExpression->setCheckable(true);

        horizontalLayout->addWidget(cbRegularExpression);

        horizontalSpacer = new QSpacerItem(38, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(cs8SearchWidgetClass);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        labelHits = new QLabel(cs8SearchWidgetClass);
        labelHits->setObjectName(QStringLiteral("labelHits"));

        horizontalLayout->addWidget(labelHits);


        verticalLayout->addLayout(horizontalLayout);

        listViewResults = new QTableView(cs8SearchWidgetClass);
        listViewResults->setObjectName(QStringLiteral("listViewResults"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listViewResults->sizePolicy().hasHeightForWidth());
        listViewResults->setSizePolicy(sizePolicy);
        listViewResults->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listViewResults->setAlternatingRowColors(true);
        listViewResults->setSelectionMode(QAbstractItemView::SingleSelection);
        listViewResults->setSelectionBehavior(QAbstractItemView::SelectRows);
        listViewResults->setShowGrid(false);
        listViewResults->setWordWrap(false);

        verticalLayout->addWidget(listViewResults);


        retranslateUi(cs8SearchWidgetClass);

        QMetaObject::connectSlotsByName(cs8SearchWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *cs8SearchWidgetClass)
    {
        cs8SearchWidgetClass->setWindowTitle(QApplication::translate("cs8SearchWidgetClass", "cs8SearchWidget", Q_NULLPTR));
        label->setText(QApplication::translate("cs8SearchWidgetClass", "Search for:", Q_NULLPTR));
        toolButtonClear->setText(QApplication::translate("cs8SearchWidgetClass", "&Clear", Q_NULLPTR));
        cbRegularExpression->setText(QApplication::translate("cs8SearchWidgetClass", "Regular expression", Q_NULLPTR));
        label_2->setText(QApplication::translate("cs8SearchWidgetClass", "Number of hits:", Q_NULLPTR));
        labelHits->setText(QApplication::translate("cs8SearchWidgetClass", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class cs8SearchWidgetClass: public Ui_cs8SearchWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CS8SEARCHWIDGET_H
