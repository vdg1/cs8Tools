/********************************************************************************
** Form generated from reading UI file 'dialoghighlightconfiguration.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGHIGHLIGHTCONFIGURATION_H
#define UI_DIALOGHIGHLIGHTCONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "cs8colorlabel.h"

QT_BEGIN_NAMESPACE

class Ui_DialogHighLightConfiguration
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QListView *listView;
    QVBoxLayout *verticalLayout;
    QPushButton *pbAddItem;
    QPushButton *pdRemoveItem;
    QSpacerItem *verticalSpacer;
    QPushButton *pdMoveUp;
    QPushButton *pdMoveDown;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    cs8ColorLabel *lbBackgroundColor;
    cs8ColorLabel *lbForegroundColor;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *cbIgnoreCase;
    QCheckBox *cbBold;
    QCheckBox *cbItalic;
    QCheckBox *cbHighLight;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_4;
    QFrame *line;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *leSearchString;
    QCheckBox *cbRegExp;
    QLabel *label_5;
    QComboBox *cbLevel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogHighLightConfiguration)
    {
        if (DialogHighLightConfiguration->objectName().isEmpty())
            DialogHighLightConfiguration->setObjectName(QStringLiteral("DialogHighLightConfiguration"));
        DialogHighLightConfiguration->setWindowModality(Qt::ApplicationModal);
        DialogHighLightConfiguration->resize(369, 559);
        DialogHighLightConfiguration->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(DialogHighLightConfiguration);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        listView = new QListView(DialogHighLightConfiguration);
        listView->setObjectName(QStringLiteral("listView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        font.setPointSize(10);
        listView->setFont(font);
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setProperty("showDropIndicator", QVariant(false));
        listView->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout->addWidget(listView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pbAddItem = new QPushButton(DialogHighLightConfiguration);
        pbAddItem->setObjectName(QStringLiteral("pbAddItem"));
        pbAddItem->setStyleSheet(QLatin1String("QPushButton {\n"
"            text-align:left;\n"
"            }"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/32x32/32x32/actions/list-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbAddItem->setIcon(icon);

        verticalLayout->addWidget(pbAddItem);

        pdRemoveItem = new QPushButton(DialogHighLightConfiguration);
        pdRemoveItem->setObjectName(QStringLiteral("pdRemoveItem"));
        pdRemoveItem->setStyleSheet(QLatin1String("QPushButton {\n"
"            text-align:left;\n"
"            }"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/32x32/32x32/actions/list-remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdRemoveItem->setIcon(icon1);

        verticalLayout->addWidget(pdRemoveItem);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        verticalLayout->addItem(verticalSpacer);

        pdMoveUp = new QPushButton(DialogHighLightConfiguration);
        pdMoveUp->setObjectName(QStringLiteral("pdMoveUp"));
        pdMoveUp->setStyleSheet(QLatin1String("QPushButton {\n"
"            text-align:left;\n"
"            }"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/32x32/32x32/actions/arrow-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdMoveUp->setIcon(icon2);

        verticalLayout->addWidget(pdMoveUp);

        pdMoveDown = new QPushButton(DialogHighLightConfiguration);
        pdMoveDown->setObjectName(QStringLiteral("pdMoveDown"));
        pdMoveDown->setStyleSheet(QLatin1String("QPushButton {\n"
"            text-align:left;\n"
"            }"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/32x32/32x32/actions/arrow-down.png"), QSize(), QIcon::Normal, QIcon::Off);
        pdMoveDown->setIcon(icon3);

        verticalLayout->addWidget(pdMoveDown);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        groupBox = new QGroupBox(DialogHighLightConfiguration);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(false);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        lbBackgroundColor = new cs8ColorLabel(groupBox);
        lbBackgroundColor->setObjectName(QStringLiteral("lbBackgroundColor"));
        lbBackgroundColor->setReadOnly(true);

        gridLayout->addWidget(lbBackgroundColor, 1, 1, 1, 1);

        lbForegroundColor = new cs8ColorLabel(groupBox);
        lbForegroundColor->setObjectName(QStringLiteral("lbForegroundColor"));
        lbForegroundColor->setReadOnly(true);

        gridLayout->addWidget(lbForegroundColor, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cbIgnoreCase = new QCheckBox(groupBox);
        cbIgnoreCase->setObjectName(QStringLiteral("cbIgnoreCase"));

        horizontalLayout_2->addWidget(cbIgnoreCase);

        cbBold = new QCheckBox(groupBox);
        cbBold->setObjectName(QStringLiteral("cbBold"));

        horizontalLayout_2->addWidget(cbBold);

        cbItalic = new QCheckBox(groupBox);
        cbItalic->setObjectName(QStringLiteral("cbItalic"));

        horizontalLayout_2->addWidget(cbItalic);

        cbHighLight = new QCheckBox(groupBox);
        cbHighLight->setObjectName(QStringLiteral("cbHighLight"));

        horizontalLayout_2->addWidget(cbHighLight);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(5, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        leSearchString = new QLineEdit(groupBox);
        leSearchString->setObjectName(QStringLiteral("leSearchString"));

        horizontalLayout_3->addWidget(leSearchString);

        cbRegExp = new QCheckBox(groupBox);
        cbRegExp->setObjectName(QStringLiteral("cbRegExp"));

        horizontalLayout_3->addWidget(cbRegExp);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        cbLevel = new QComboBox(groupBox);
        cbLevel->setObjectName(QStringLiteral("cbLevel"));

        verticalLayout_2->addWidget(cbLevel);


        verticalLayout_3->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(DialogHighLightConfiguration);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(DialogHighLightConfiguration);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogHighLightConfiguration, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogHighLightConfiguration, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogHighLightConfiguration);
    } // setupUi

    void retranslateUi(QDialog *DialogHighLightConfiguration)
    {
        DialogHighLightConfiguration->setWindowTitle(QApplication::translate("DialogHighLightConfiguration", "Highlighting", Q_NULLPTR));
        pbAddItem->setText(QApplication::translate("DialogHighLightConfiguration", "Add", Q_NULLPTR));
        pdRemoveItem->setText(QApplication::translate("DialogHighLightConfiguration", "Remove", Q_NULLPTR));
        pdMoveUp->setText(QApplication::translate("DialogHighLightConfiguration", "Up", Q_NULLPTR));
        pdMoveDown->setText(QApplication::translate("DialogHighLightConfiguration", "Down", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("DialogHighLightConfiguration", "Foreground Color:", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogHighLightConfiguration", "Background Color:", Q_NULLPTR));
        cbIgnoreCase->setText(QApplication::translate("DialogHighLightConfiguration", "Ignore Case", Q_NULLPTR));
        cbBold->setText(QApplication::translate("DialogHighLightConfiguration", "Bold", Q_NULLPTR));
        cbItalic->setText(QApplication::translate("DialogHighLightConfiguration", "Italic", Q_NULLPTR));
        cbHighLight->setText(QApplication::translate("DialogHighLightConfiguration", "Highlight in Scrollbar", Q_NULLPTR));
        label_4->setText(QApplication::translate("DialogHighLightConfiguration", "Search Criteria:", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogHighLightConfiguration", "String:", Q_NULLPTR));
        leSearchString->setText(QString());
        cbRegExp->setText(QApplication::translate("DialogHighLightConfiguration", "Regular Expression", Q_NULLPTR));
        label_5->setText(QApplication::translate("DialogHighLightConfiguration", "Level:", Q_NULLPTR));
        cbLevel->clear();
        cbLevel->insertItems(0, QStringList()
         << QApplication::translate("DialogHighLightConfiguration", "Any", Q_NULLPTR)
         << QApplication::translate("DialogHighLightConfiguration", "Information", Q_NULLPTR)
         << QApplication::translate("DialogHighLightConfiguration", "Warning", Q_NULLPTR)
         << QApplication::translate("DialogHighLightConfiguration", "Error", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class DialogHighLightConfiguration: public Ui_DialogHighLightConfiguration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGHIGHLIGHTCONFIGURATION_H
