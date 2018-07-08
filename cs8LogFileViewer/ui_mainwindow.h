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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "cs8searchwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actOpen;
    QAction *actCopy;
    QAction *actExit;
    QAction *actHide_USR_messages;
    QAction *actionHighlighting;
    QAction *actionNext_System_Start;
    QAction *actionPrevious_System_Start;
    QAction *actionHide_Swap_File_Messages;
    QAction *actionReverse_Order;
    QAction *actionOnline;
    QAction *actionUse_Computer_Time;
    QAction *actionSend_selected_lines_to;
    QAction *actionSave_as;
    QAction *actionOpen_Machine_File;
    QAction *actionScroll_to_Bottom;
    QAction *actionReset_Dialog_Options;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menu_File;
    QMenu *menuEdit;
    QMenu *menu_Window;
    QMenu *menuTools;
    QMenu *menuNavigate;
    QStatusBar *statusbar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QTreeView *treeViewSystemConfigurations;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_3;
    cs8SearchWidget *widgetSearch;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actOpen = new QAction(MainWindow);
        actOpen->setObjectName(QStringLiteral("actOpen"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/32x32/32x32/actions/document-open-folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actOpen->setIcon(icon);
        actCopy = new QAction(MainWindow);
        actCopy->setObjectName(QStringLiteral("actCopy"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/32x32/32x32/actions/edit-copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actCopy->setIcon(icon1);
        actExit = new QAction(MainWindow);
        actExit->setObjectName(QStringLiteral("actExit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/32x32/32x32/actions/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actExit->setIcon(icon2);
        actHide_USR_messages = new QAction(MainWindow);
        actHide_USR_messages->setObjectName(QStringLiteral("actHide_USR_messages"));
        actHide_USR_messages->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/32x32/32x32/actions/view-filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        actHide_USR_messages->setIcon(icon3);
        actionHighlighting = new QAction(MainWindow);
        actionHighlighting->setObjectName(QStringLiteral("actionHighlighting"));
        actionNext_System_Start = new QAction(MainWindow);
        actionNext_System_Start->setObjectName(QStringLiteral("actionNext_System_Start"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/32x32/32x32/actions/arrow-right-double.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNext_System_Start->setIcon(icon4);
        actionPrevious_System_Start = new QAction(MainWindow);
        actionPrevious_System_Start->setObjectName(QStringLiteral("actionPrevious_System_Start"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/32x32/32x32/actions/arrow-left-double.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrevious_System_Start->setIcon(icon5);
        actionHide_Swap_File_Messages = new QAction(MainWindow);
        actionHide_Swap_File_Messages->setObjectName(QStringLiteral("actionHide_Swap_File_Messages"));
        actionHide_Swap_File_Messages->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/icons/32x32/32x32/actions/run-build-clean.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHide_Swap_File_Messages->setIcon(icon6);
        actionReverse_Order = new QAction(MainWindow);
        actionReverse_Order->setObjectName(QStringLiteral("actionReverse_Order"));
        actionReverse_Order->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/icons/32x32/32x32/actions/view-sort-descending.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReverse_Order->setIcon(icon7);
        actionOnline = new QAction(MainWindow);
        actionOnline->setObjectName(QStringLiteral("actionOnline"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/icons/32x32/32x32/actions/network-connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOnline->setIcon(icon8);
        actionUse_Computer_Time = new QAction(MainWindow);
        actionUse_Computer_Time->setObjectName(QStringLiteral("actionUse_Computer_Time"));
        actionUse_Computer_Time->setCheckable(true);
        actionSend_selected_lines_to = new QAction(MainWindow);
        actionSend_selected_lines_to->setObjectName(QStringLiteral("actionSend_selected_lines_to"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/icons/32x32/32x32/actions/mail-forwarded.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSend_selected_lines_to->setIcon(icon9);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/icons/32x32/32x32/actions/document-save-as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_as->setIcon(icon10);
        actionOpen_Machine_File = new QAction(MainWindow);
        actionOpen_Machine_File->setObjectName(QStringLiteral("actionOpen_Machine_File"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/icons/32x32/32x32/actions/view-pim-tasks.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_Machine_File->setIcon(icon11);
        actionScroll_to_Bottom = new QAction(MainWindow);
        actionScroll_to_Bottom->setObjectName(QStringLiteral("actionScroll_to_Bottom"));
        actionScroll_to_Bottom->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/icons/32x32/32x32/actions/view-sort-ascending.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScroll_to_Bottom->setIcon(icon12);
        actionReset_Dialog_Options = new QAction(MainWindow);
        actionReset_Dialog_Options->setObjectName(QStringLiteral("actionReset_Dialog_Options"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setViewMode(QMdiArea::TabbedView);
        mdiArea->setDocumentMode(true);
        mdiArea->setTabsClosable(true);
        mdiArea->setTabsMovable(true);

        verticalLayout->addWidget(mdiArea);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menu_Window = new QMenu(menubar);
        menu_Window->setObjectName(QStringLiteral("menu_Window"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuNavigate = new QMenu(menubar);
        menuNavigate->setObjectName(QStringLiteral("menuNavigate"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        treeViewSystemConfigurations = new QTreeView(dockWidgetContents);
        treeViewSystemConfigurations->setObjectName(QStringLiteral("treeViewSystemConfigurations"));
        treeViewSystemConfigurations->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeViewSystemConfigurations->setProperty("showDropIndicator", QVariant(false));
        treeViewSystemConfigurations->setAlternatingRowColors(true);
        treeViewSystemConfigurations->setAnimated(true);
        treeViewSystemConfigurations->header()->setVisible(false);

        verticalLayout_2->addWidget(treeViewSystemConfigurations);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        widgetSearch = new cs8SearchWidget(dockWidgetContents_2);
        widgetSearch->setObjectName(QStringLiteral("widgetSearch"));

        verticalLayout_3->addWidget(widgetSearch);

        dockWidget_2->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_2);

        menubar->addAction(menu_File->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuNavigate->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menu_Window->menuAction());
        menu_File->addAction(actOpen);
        menu_File->addAction(actionOnline);
        menu_File->addAction(actionSave_as);
        menu_File->addSeparator();
        menu_File->addAction(actExit);
        menuEdit->addAction(actCopy);
        menuEdit->addAction(actionSend_selected_lines_to);
        menuTools->addAction(actHide_USR_messages);
        menuTools->addAction(actionHide_Swap_File_Messages);
        menuTools->addAction(actionReverse_Order);
        menuTools->addAction(actionOpen_Machine_File);
        menuTools->addAction(actionUse_Computer_Time);
        menuTools->addAction(actionHighlighting);
        menuTools->addAction(actionReset_Dialog_Options);
        menuNavigate->addAction(actionNext_System_Start);
        menuNavigate->addAction(actionPrevious_System_Start);
        toolBar->addAction(actOpen);
        toolBar->addAction(actionOnline);
        toolBar_2->addAction(actCopy);
        toolBar_2->addAction(actHide_USR_messages);
        toolBar_2->addAction(actionHide_Swap_File_Messages);
        toolBar_2->addAction(actionReverse_Order);
        toolBar_2->addSeparator();
        toolBar_2->addAction(actionPrevious_System_Start);
        toolBar_2->addAction(actionNext_System_Start);
        toolBar_2->addAction(actionScroll_to_Bottom);
        toolBar_2->addAction(actionOpen_Machine_File);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actOpen->setText(QApplication::translate("MainWindow", "&Open...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actOpen->setToolTip(QApplication::translate("MainWindow", "Open a log file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", Q_NULLPTR));
        actCopy->setText(QApplication::translate("MainWindow", "Copy", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actCopy->setToolTip(QApplication::translate("MainWindow", "Copy current selection", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", Q_NULLPTR));
        actExit->setText(QApplication::translate("MainWindow", "&Exit", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actExit->setToolTip(QApplication::translate("MainWindow", "Exit CS8 Log File Viewer", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", Q_NULLPTR));
        actHide_USR_messages->setText(QApplication::translate("MainWindow", "Hide USR: messages", Q_NULLPTR));
        actionHighlighting->setText(QApplication::translate("MainWindow", "Highlighting", Q_NULLPTR));
        actionNext_System_Start->setText(QApplication::translate("MainWindow", "Next System Start", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionNext_System_Start->setToolTip(QApplication::translate("MainWindow", "Jump to next system start", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionPrevious_System_Start->setText(QApplication::translate("MainWindow", "Previous System Start", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionPrevious_System_Start->setToolTip(QApplication::translate("MainWindow", "Jump to previous system start", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionHide_Swap_File_Messages->setText(QApplication::translate("MainWindow", "Hide Swap File Messages", Q_NULLPTR));
        actionReverse_Order->setText(QApplication::translate("MainWindow", "Reverse Order", Q_NULLPTR));
        actionOnline->setText(QApplication::translate("MainWindow", "Online...", Q_NULLPTR));
        actionUse_Computer_Time->setText(QApplication::translate("MainWindow", "Use Computer Time", Q_NULLPTR));
        actionSend_selected_lines_to->setText(QApplication::translate("MainWindow", "Send selected lines to ...", Q_NULLPTR));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as...", Q_NULLPTR));
        actionOpen_Machine_File->setText(QApplication::translate("MainWindow", "Open Machine File", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionOpen_Machine_File->setToolTip(QApplication::translate("MainWindow", "Open Machine File", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionScroll_to_Bottom->setText(QApplication::translate("MainWindow", "Scroll to Bottom", Q_NULLPTR));
        actionReset_Dialog_Options->setText(QApplication::translate("MainWindow", "Reset Dialog Options", Q_NULLPTR));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", Q_NULLPTR));
        menu_Window->setTitle(QApplication::translate("MainWindow", "&Window", Q_NULLPTR));
        menuTools->setTitle(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        menuNavigate->setTitle(QApplication::translate("MainWindow", "Navigate", Q_NULLPTR));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "System Configurations", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
