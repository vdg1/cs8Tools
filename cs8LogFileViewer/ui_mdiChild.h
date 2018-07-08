/********************************************************************************
** Form generated from reading UI file 'mdiChild.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MDICHILD_H
#define UI_MDICHILD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "logfiledetailedinformationform.h"

QT_BEGIN_NAMESPACE

class Ui_mdiChild
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *gpInformation;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    logFileDetailedInformationForm *widgetInformation;
    QGridLayout *gridLayout;
    QTableView *view;

    void setupUi(QWidget *mdiChild)
    {
        if (mdiChild->objectName().isEmpty())
            mdiChild->setObjectName(QStringLiteral("mdiChild"));
        mdiChild->resize(716, 389);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mdiChild->sizePolicy().hasHeightForWidth());
        mdiChild->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/32x32/32x32/actions/archive-insert-directory.png"), QSize(), QIcon::Normal, QIcon::Off);
        mdiChild->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(mdiChild);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        gpInformation = new QGroupBox(mdiChild);
        gpInformation->setObjectName(QStringLiteral("gpInformation"));
        gridLayout_2 = new QGridLayout(gpInformation);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(0);
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(gpInformation);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        widgetInformation = new logFileDetailedInformationForm(gpInformation);
        widgetInformation->setObjectName(QStringLiteral("widgetInformation"));
        gridLayout = new QGridLayout(widgetInformation);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        gridLayout_2->addWidget(widgetInformation, 0, 0, 1, 1);


        verticalLayout->addWidget(gpInformation);

        view = new QTableView(mdiChild);
        view->setObjectName(QStringLiteral("view"));
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        font.setPointSize(10);
        view->setFont(font);
        view->setSelectionMode(QAbstractItemView::ContiguousSelection);
        view->setSelectionBehavior(QAbstractItemView::SelectRows);
        view->setShowGrid(false);
        view->setSortingEnabled(false);
        view->horizontalHeader()->setDefaultSectionSize(150);
        view->horizontalHeader()->setStretchLastSection(true);

        verticalLayout->addWidget(view);


        retranslateUi(mdiChild);

        QMetaObject::connectSlotsByName(mdiChild);
    } // setupUi

    void retranslateUi(QWidget *mdiChild)
    {
        mdiChild->setWindowTitle(QApplication::translate("mdiChild", "Form", Q_NULLPTR));
        gpInformation->setTitle(QApplication::translate("mdiChild", "Information", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pushButton->setToolTip(QApplication::translate("mdiChild", "Hide / Show Information", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("mdiChild", "Hide", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mdiChild: public Ui_mdiChild {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MDICHILD_H
