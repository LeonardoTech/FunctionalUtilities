/********************************************************************************
** Form generated from reading UI file 'treestructure.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREESTRUCTURE_H
#define UI_TREESTRUCTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TreeStructureClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuLoad;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QTabWidget *tabWidget;
    QWidget *floor;
    QTreeWidget *treeWidget;
    QWidget *tab_2;
    QTreeWidget *treeWidget_2;

    void setupUi(QMainWindow *TreeStructureClass)
    {
        if (TreeStructureClass->objectName().isEmpty())
            TreeStructureClass->setObjectName(QStringLiteral("TreeStructureClass"));
        TreeStructureClass->resize(736, 412);
        centralWidget = new QWidget(TreeStructureClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TreeStructureClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TreeStructureClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 736, 23));
        menuLoad = new QMenu(menuBar);
        menuLoad->setObjectName(QStringLiteral("menuLoad"));
        TreeStructureClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TreeStructureClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TreeStructureClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TreeStructureClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TreeStructureClass->setStatusBar(statusBar);
        dockWidget = new QDockWidget(TreeStructureClass);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        tabWidget = new QTabWidget(dockWidgetContents);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 199, 339));
        floor = new QWidget();
        floor->setObjectName(QStringLiteral("floor"));
        treeWidget = new QTreeWidget(floor);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(10, 20, 161, 281));
        treeWidget->setLayoutDirection(Qt::LeftToRight);
        treeWidget->setColumnCount(0);
        tabWidget->addTab(floor, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        treeWidget_2 = new QTreeWidget(tab_2);
        treeWidget_2->setObjectName(QStringLiteral("treeWidget_2"));
        treeWidget_2->setGeometry(QRect(10, 20, 171, 271));
        treeWidget_2->setLayoutDirection(Qt::LeftToRight);
        treeWidget_2->setColumnCount(0);
        tabWidget->addTab(tab_2, QString());
        dockWidget->setWidget(dockWidgetContents);
        TreeStructureClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        menuBar->addAction(menuLoad->menuAction());

        retranslateUi(TreeStructureClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TreeStructureClass);
    } // setupUi

    void retranslateUi(QMainWindow *TreeStructureClass)
    {
        TreeStructureClass->setWindowTitle(QApplication::translate("TreeStructureClass", "TreeStructure", 0));
        menuLoad->setTitle(QApplication::translate("TreeStructureClass", "Load", 0));
        tabWidget->setTabText(tabWidget->indexOf(floor), QApplication::translate("TreeStructureClass", "\346\245\274\345\261\202", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("TreeStructureClass", "\346\236\204\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class TreeStructureClass: public Ui_TreeStructureClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREESTRUCTURE_H
