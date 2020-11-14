/********************************************************************************
** Form generated from reading UI file 'mymainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYMAINWINDOW_H
#define UI_MYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myMainWindow
{
public:
    QAction *action_N;
    QWidget *centralwidget;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *myMainWindow)
    {
        if (myMainWindow->objectName().isEmpty())
            myMainWindow->setObjectName(QString::fromUtf8("myMainWindow"));
        myMainWindow->resize(531, 518);
        action_N = new QAction(myMainWindow);
        action_N->setObjectName(QString::fromUtf8("action_N"));
        centralwidget = new QWidget(myMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        myMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(myMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        myMainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(myMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 531, 26));
        myMainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(myMainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        myMainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(myMainWindow);

        QMetaObject::connectSlotsByName(myMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *myMainWindow)
    {
        myMainWindow->setWindowTitle(QCoreApplication::translate("myMainWindow", "myMainWindow", nullptr));
        action_N->setText(QCoreApplication::translate("myMainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266(&N)", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("myMainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myMainWindow: public Ui_myMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYMAINWINDOW_H
