/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionClose;
    QAction *actionReport_bug;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *cbEnableSync;
    QCheckBox *cbAvoidVpn;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *leRemotePath;
    QPushButton *pbRemotePathBrowse;
    QSpacerItem *verticalSpacer_3;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout;
    QCheckBox *cbEnableCatalogueImport;
    QFrame *frame;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout;
    QLineEdit *leMaintainer;
    QLabel *label_5;
    QPushButton *pbCatalogueFileBrowse;
    QPushButton *pbConfigureImport;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QLineEdit *leCatalogueFile;
    QLabel *label_6;
    QLineEdit *leCatalogue_URL;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *cbAutoStart;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;
    QMenuBar *menuBar;
    QMenu *menu_ACtion;
    QMenu *menu_Help;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(614, 274);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionReport_bug = new QAction(MainWindow);
        actionReport_bug->setObjectName(QStringLiteral("actionReport_bug"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        cbEnableSync = new QCheckBox(tab);
        cbEnableSync->setObjectName(QStringLiteral("cbEnableSync"));

        verticalLayout_3->addWidget(cbEnableSync);

        cbAvoidVpn = new QCheckBox(tab);
        cbAvoidVpn->setObjectName(QStringLiteral("cbAvoidVpn"));

        verticalLayout_3->addWidget(cbAvoidVpn);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        leRemotePath = new QLineEdit(tab);
        leRemotePath->setObjectName(QStringLiteral("leRemotePath"));

        horizontalLayout->addWidget(leRemotePath);

        pbRemotePathBrowse = new QPushButton(tab);
        pbRemotePathBrowse->setObjectName(QStringLiteral("pbRemotePathBrowse"));

        horizontalLayout->addWidget(pbRemotePathBrowse);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout = new QVBoxLayout(tab_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        cbEnableCatalogueImport = new QCheckBox(tab_2);
        cbEnableCatalogueImport->setObjectName(QStringLiteral("cbEnableCatalogueImport"));

        verticalLayout->addWidget(cbEnableCatalogueImport);

        frame = new QFrame(tab_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        leMaintainer = new QLineEdit(frame);
        leMaintainer->setObjectName(QStringLiteral("leMaintainer"));

        gridLayout->addWidget(leMaintainer, 2, 2, 1, 3);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 2);

        pbCatalogueFileBrowse = new QPushButton(frame);
        pbCatalogueFileBrowse->setObjectName(QStringLiteral("pbCatalogueFileBrowse"));

        gridLayout->addWidget(pbCatalogueFileBrowse, 1, 4, 1, 1);

        pbConfigureImport = new QPushButton(frame);
        pbConfigureImport->setObjectName(QStringLiteral("pbConfigureImport"));

        gridLayout->addWidget(pbConfigureImport, 3, 0, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 2, 1, 3);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        leCatalogueFile = new QLineEdit(frame);
        leCatalogueFile->setObjectName(QStringLiteral("leCatalogueFile"));

        gridLayout->addWidget(leCatalogueFile, 1, 1, 1, 3);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        leCatalogue_URL = new QLineEdit(frame);
        leCatalogue_URL->setObjectName(QStringLiteral("leCatalogue_URL"));

        gridLayout->addWidget(leCatalogue_URL, 0, 1, 1, 4);


        verticalLayout_5->addLayout(gridLayout);


        verticalLayout->addWidget(frame);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_2 = new QVBoxLayout(tab_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        cbAutoStart = new QCheckBox(tab_3);
        cbAutoStart->setObjectName(QStringLiteral("cbAutoStart"));

        verticalLayout_2->addWidget(cbAutoStart);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_4->addWidget(tabWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(centralWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout_4->addWidget(buttonBox);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 614, 21));
        menu_ACtion = new QMenu(menuBar);
        menu_ACtion->setObjectName(QStringLiteral("menu_ACtion"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_ACtion->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_ACtion->addAction(actionClose);
        menu_Help->addAction(actionAbout);
        menu_Help->addAction(actionAbout_Qt);

        retranslateUi(MainWindow);
        QObject::connect(buttonBox, SIGNAL(rejected()), MainWindow, SLOT(close()));
        QObject::connect(actionClose, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(cbEnableCatalogueImport, SIGNAL(toggled(bool)), frame, SLOT(setEnabled(bool)));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CS8Backup Sync", Q_NULLPTR));
        actionClose->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        actionReport_bug->setText(QApplication::translate("MainWindow", "Report bug ...", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", Q_NULLPTR));
        cbEnableSync->setText(QApplication::translate("MainWindow", "Enable syncronization", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cbAvoidVpn->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>To safe network bandwith syncronisation of backups is disabled when your computer is connected via a VPN connection to the office lan.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        cbAvoidVpn->setText(QApplication::translate("MainWindow", "Do not synchronize when connected via VPN", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Remote path:", Q_NULLPTR));
        leRemotePath->setPlaceholderText(QApplication::translate("MainWindow", "Shared folder on file server where backups are copied to ", Q_NULLPTR));
        pbRemotePathBrowse->setText(QApplication::translate("MainWindow", "Browse", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Synchronization Settings", Q_NULLPTR));
        cbEnableCatalogueImport->setText(QApplication::translate("MainWindow", "Enable machine catalogue import", Q_NULLPTR));
        leMaintainer->setPlaceholderText(QApplication::translate("MainWindow", "Email adress of machine catalogue maintainer", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Catalogue Maintainer", Q_NULLPTR));
        pbCatalogueFileBrowse->setText(QApplication::translate("MainWindow", "Browse", Q_NULLPTR));
        pbConfigureImport->setText(QApplication::translate("MainWindow", "Configure Import", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Import Catalogue File", Q_NULLPTR));
        leCatalogueFile->setPlaceholderText(QApplication::translate("MainWindow", "Path to the import XLS file", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Online Catalogue URL", Q_NULLPTR));
        leCatalogue_URL->setPlaceholderText(QApplication::translate("MainWindow", "Base URL to the online machine catalogue", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Machine Catalogue", Q_NULLPTR));
        cbAutoStart->setText(QApplication::translate("MainWindow", "Automatic start of program", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "General", Q_NULLPTR));
        menu_ACtion->setTitle(QApplication::translate("MainWindow", "&Action", Q_NULLPTR));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
