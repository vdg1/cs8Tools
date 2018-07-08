/********************************************************************************
** Form generated from reading UI file 'mainForm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Quit;
    QAction *action_About;
    QAction *action_About_Qt;
    QAction *action_Preferences;
    QAction *actionRescan_Updates;
    QAction *actionReport_a_bug;
    QAction *actionCheck_for_Updates;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *hboxLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *leUserName;
    QLabel *label_4;
    QLineEdit *lePassword;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QToolButton *btUpdate;
    QLabel *lbScannerStatus;
    QSpacerItem *horizontalSpacer;
    QTableView *tableViewDetectedControllers;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *leIPAddress;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *rbCompleteSystem;
    QRadioButton *rbPartitions;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout1;
    QCheckBox *checkBoxSys;
    QLabel *label_2;
    QCheckBox *checkBoxUsr;
    QLabel *label_7;
    QCheckBox *checkBoxLog;
    QLabel *label_8;
    QRadioButton *rbConfigs;
    QFrame *line;
    QCheckBox *checkBoxCompress;
    QFrame *line_2;
    QSpacerItem *verticalSpacer;
    QLabel *label_6;
    QHBoxLayout *hboxLayout1;
    QLineEdit *leDownloadDir;
    QToolButton *btSelectDownloadDir;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonExplore;
    QCommandLinkButton *btDownload;
    QWidget *tab_2;
    QVBoxLayout *vboxLayout;
    QListWidget *fileList;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menu_Settings;
    QMenu *menu_Help;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1004, 581);
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName(QStringLiteral("action_Quit"));
        action_About = new QAction(MainWindow);
        action_About->setObjectName(QStringLiteral("action_About"));
        action_About_Qt = new QAction(MainWindow);
        action_About_Qt->setObjectName(QStringLiteral("action_About_Qt"));
        action_Preferences = new QAction(MainWindow);
        action_Preferences->setObjectName(QStringLiteral("action_Preferences"));
        actionRescan_Updates = new QAction(MainWindow);
        actionRescan_Updates->setObjectName(QStringLiteral("actionRescan_Updates"));
        actionReport_a_bug = new QAction(MainWindow);
        actionReport_a_bug->setObjectName(QStringLiteral("actionReport_a_bug"));
        actionCheck_for_Updates = new QAction(MainWindow);
        actionCheck_for_Updates->setObjectName(QStringLiteral("actionCheck_for_Updates"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFlat(true);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        leUserName = new QLineEdit(groupBox_2);
        leUserName->setObjectName(QStringLiteral("leUserName"));

        gridLayout->addWidget(leUserName, 1, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        lePassword = new QLineEdit(groupBox_2);
        lePassword->setObjectName(QStringLiteral("lePassword"));
        lePassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lePassword, 2, 1, 1, 1);

        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFlat(false);
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout->addWidget(label_9);

        btUpdate = new QToolButton(groupBox_3);
        btUpdate->setObjectName(QStringLiteral("btUpdate"));

        horizontalLayout->addWidget(btUpdate);

        lbScannerStatus = new QLabel(groupBox_3);
        lbScannerStatus->setObjectName(QStringLiteral("lbScannerStatus"));
        lbScannerStatus->setPixmap(QPixmap(QString::fromUtf8(":/res/loading19.gif")));

        horizontalLayout->addWidget(lbScannerStatus);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableViewDetectedControllers = new QTableView(groupBox_3);
        tableViewDetectedControllers->setObjectName(QStringLiteral("tableViewDetectedControllers"));
        tableViewDetectedControllers->setEnabled(false);
        tableViewDetectedControllers->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableViewDetectedControllers->setAlternatingRowColors(true);
        tableViewDetectedControllers->setSelectionMode(QAbstractItemView::SingleSelection);
        tableViewDetectedControllers->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableViewDetectedControllers->setShowGrid(false);
        tableViewDetectedControllers->setGridStyle(Qt::NoPen);
        tableViewDetectedControllers->setSortingEnabled(true);
        tableViewDetectedControllers->horizontalHeader()->setDefaultSectionSize(150);
        tableViewDetectedControllers->horizontalHeader()->setStretchLastSection(true);
        tableViewDetectedControllers->verticalHeader()->setVisible(false);
        tableViewDetectedControllers->verticalHeader()->setCascadingSectionResizes(true);

        verticalLayout->addWidget(tableViewDetectedControllers);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setWordWrap(false);
        label->setIndent(-1);

        horizontalLayout_2->addWidget(label);

        leIPAddress = new QComboBox(groupBox_3);
        leIPAddress->setObjectName(QStringLiteral("leIPAddress"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leIPAddress->sizePolicy().hasHeightForWidth());
        leIPAddress->setSizePolicy(sizePolicy1);
        leIPAddress->setMinimumSize(QSize(120, 0));
        leIPAddress->setEditable(true);
        leIPAddress->setMaxCount(10);
        leIPAddress->setInsertPolicy(QComboBox::NoInsert);

        horizontalLayout_2->addWidget(leIPAddress);


        verticalLayout->addLayout(horizontalLayout_2);


        gridLayout->addWidget(groupBox_3, 0, 0, 1, 2);


        hboxLayout->addWidget(groupBox_2);


        horizontalLayout_3->addLayout(hboxLayout);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFlat(true);
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        rbCompleteSystem = new QRadioButton(groupBox);
        rbCompleteSystem->setObjectName(QStringLiteral("rbCompleteSystem"));

        verticalLayout_5->addWidget(rbCompleteSystem);

        rbPartitions = new QRadioButton(groupBox);
        rbPartitions->setObjectName(QStringLiteral("rbPartitions"));
        rbPartitions->setChecked(true);

        verticalLayout_5->addWidget(rbPartitions);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        groupBox_4->setCheckable(false);
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout1 = new QGridLayout();
        gridLayout1->setObjectName(QStringLiteral("gridLayout1"));
        gridLayout1->setHorizontalSpacing(26);
        checkBoxSys = new QCheckBox(groupBox_4);
        checkBoxSys->setObjectName(QStringLiteral("checkBoxSys"));

        gridLayout1->addWidget(checkBoxSys, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setWordWrap(true);

        gridLayout1->addWidget(label_2, 0, 1, 1, 1);

        checkBoxUsr = new QCheckBox(groupBox_4);
        checkBoxUsr->setObjectName(QStringLiteral("checkBoxUsr"));

        gridLayout1->addWidget(checkBoxUsr, 1, 0, 1, 1);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);
        label_7->setWordWrap(true);

        gridLayout1->addWidget(label_7, 1, 1, 1, 1);

        checkBoxLog = new QCheckBox(groupBox_4);
        checkBoxLog->setObjectName(QStringLiteral("checkBoxLog"));

        gridLayout1->addWidget(checkBoxLog, 2, 0, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy3.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy3);
        label_8->setWordWrap(true);

        gridLayout1->addWidget(label_8, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout1);


        verticalLayout_5->addWidget(groupBox_4);

        rbConfigs = new QRadioButton(groupBox);
        rbConfigs->setObjectName(QStringLiteral("rbConfigs"));

        verticalLayout_5->addWidget(rbConfigs);

        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line);

        checkBoxCompress = new QCheckBox(groupBox);
        checkBoxCompress->setObjectName(QStringLiteral("checkBoxCompress"));
        checkBoxCompress->setEnabled(true);

        verticalLayout_5->addWidget(checkBoxCompress);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_2);

        verticalSpacer = new QSpacerItem(20, 264, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_5->addWidget(label_6);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName(QStringLiteral("hboxLayout1"));
        leDownloadDir = new QLineEdit(groupBox);
        leDownloadDir->setObjectName(QStringLiteral("leDownloadDir"));
        leDownloadDir->setFrame(true);
        leDownloadDir->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        leDownloadDir->setReadOnly(true);

        hboxLayout1->addWidget(leDownloadDir);

        btSelectDownloadDir = new QToolButton(groupBox);
        btSelectDownloadDir->setObjectName(QStringLiteral("btSelectDownloadDir"));

        hboxLayout1->addWidget(btSelectDownloadDir);


        verticalLayout_5->addLayout(hboxLayout1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pushButtonExplore = new QPushButton(groupBox);
        pushButtonExplore->setObjectName(QStringLiteral("pushButtonExplore"));

        horizontalLayout_4->addWidget(pushButtonExplore);


        verticalLayout_5->addLayout(horizontalLayout_4);


        horizontalLayout_3->addWidget(groupBox);


        verticalLayout_4->addLayout(horizontalLayout_3);

        btDownload = new QCommandLinkButton(tab);
        btDownload->setObjectName(QStringLiteral("btDownload"));

        verticalLayout_4->addWidget(btDownload);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        vboxLayout = new QVBoxLayout(tab_2);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        fileList = new QListWidget(tab_2);
        fileList->setObjectName(QStringLiteral("fileList"));

        vboxLayout->addWidget(fileList);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_3->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1004, 21));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Settings = new QMenu(menubar);
        menu_Settings->setObjectName(QStringLiteral("menu_Settings"));
        menu_Help = new QMenu(menubar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        menu_Help->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
#ifndef QT_NO_SHORTCUT
        label_4->setBuddy(lePassword);
        label->setBuddy(leIPAddress);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(btUpdate, tableViewDetectedControllers);
        QWidget::setTabOrder(tableViewDetectedControllers, leIPAddress);
        QWidget::setTabOrder(leIPAddress, leUserName);
        QWidget::setTabOrder(leUserName, lePassword);
        QWidget::setTabOrder(lePassword, btDownload);
        QWidget::setTabOrder(btDownload, rbPartitions);
        QWidget::setTabOrder(rbPartitions, checkBoxSys);
        QWidget::setTabOrder(checkBoxSys, checkBoxUsr);
        QWidget::setTabOrder(checkBoxUsr, checkBoxLog);
        QWidget::setTabOrder(checkBoxLog, rbConfigs);
        QWidget::setTabOrder(rbConfigs, checkBoxCompress);
        QWidget::setTabOrder(checkBoxCompress, leDownloadDir);
        QWidget::setTabOrder(leDownloadDir, btSelectDownloadDir);
        QWidget::setTabOrder(btSelectDownloadDir, pushButtonExplore);
        QWidget::setTabOrder(pushButtonExplore, fileList);
        QWidget::setTabOrder(fileList, tabWidget);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menu_Settings->menuAction());
        menubar->addAction(menu_Help->menuAction());
        menu_File->addAction(action_Quit);
        menu_Settings->addAction(action_Preferences);
        menu_Settings->addAction(actionRescan_Updates);
        menu_Help->addAction(actionCheck_for_Updates);
        menu_Help->addAction(action_About);
        menu_Help->addAction(action_About_Qt);

        retranslateUi(MainWindow);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(rbPartitions, SIGNAL(toggled(bool)), groupBox_4, SLOT(setEnabled(bool)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CS8 Backup", Q_NULLPTR));
        action_Quit->setText(QApplication::translate("MainWindow", "&Quit", Q_NULLPTR));
        action_About->setText(QApplication::translate("MainWindow", "&About", Q_NULLPTR));
        action_About_Qt->setText(QApplication::translate("MainWindow", "About Qt", Q_NULLPTR));
        action_Preferences->setText(QApplication::translate("MainWindow", "&Preferences", Q_NULLPTR));
        actionRescan_Updates->setText(QApplication::translate("MainWindow", "Rescan Backup Storage", Q_NULLPTR));
        actionReport_a_bug->setText(QApplication::translate("MainWindow", "Report a bug ...", Q_NULLPTR));
        actionCheck_for_Updates->setText(QApplication::translate("MainWindow", "Check for Updates", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Connection Settings", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "User name:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Password:", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Controller:", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "List of automatically detected controllers:", Q_NULLPTR));
        btUpdate->setText(QApplication::translate("MainWindow", "Update", Q_NULLPTR));
        lbScannerStatus->setText(QString());
#ifndef QT_NO_TOOLTIP
        tableViewDetectedControllers->setToolTip(QApplication::translate("MainWindow", "Double click on an entry to select it.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "&IP Address:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        leIPAddress->setToolTip(QApplication::translate("MainWindow", "Please enter the IP address of the controller here, if no controller were detected automatically.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QApplication::translate("MainWindow", "Backup Settings", Q_NULLPTR));
        rbCompleteSystem->setText(QApplication::translate("MainWindow", "Complete System Backup", Q_NULLPTR));
        rbPartitions->setText(QApplication::translate("MainWindow", "Backup Partitions:", Q_NULLPTR));
        groupBox_4->setTitle(QString());
        checkBoxSys->setText(QApplication::translate("MainWindow", "/sys", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">The </span><span style=\" font-size:8pt; font-weight:600;\">/sys</span><span style=\" font-size:8pt;\"> partition contains the operating system and system specific configuration files.</span></p></body></html>", Q_NULLPTR));
        checkBoxUsr->setText(QApplication::translate("MainWindow", "/usr", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">The </span><span style=\" font-size:8pt; font-weight:600;\">/usr</span><span style=\" font-size:8pt;\"> partition contains all user programs, user configuration files and arm specific data.</span></p></body></html>", Q_NULLPTR));
        checkBoxLog->setText(QApplication::translate("MainWindow", "/log", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">The </span><span style=\" font-size:8pt; font-weight:600;\">/log</span><span style=\" font-size:8pt;\"> partition contains the system log files.</span></p></body></html>", Q_NULLPTR));
        rbConfigs->setText(QApplication::translate("MainWindow", "Backup /sys/configs and /usr/configs", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        checkBoxCompress->setToolTip(QApplication::translate("MainWindow", "Compress the backup folder after download.", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        checkBoxCompress->setText(QApplication::translate("MainWindow", "Compress backup after download", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Download folder:", Q_NULLPTR));
        btSelectDownloadDir->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        pushButtonExplore->setText(QApplication::translate("MainWindow", "&Explore", Q_NULLPTR));
        btDownload->setText(QApplication::translate("MainWindow", "Start Backup", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "File list", Q_NULLPTR));
        menu_File->setTitle(QApplication::translate("MainWindow", "&Action", Q_NULLPTR));
        menu_Settings->setTitle(QApplication::translate("MainWindow", "&Edit", Q_NULLPTR));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
