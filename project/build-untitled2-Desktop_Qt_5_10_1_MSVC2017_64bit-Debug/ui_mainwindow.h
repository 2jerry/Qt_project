/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:

    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QSplitter *splitter_3;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QCommandLinkButton *commandLinkButton;
    QCommandLinkButton *commandLinkButton_2;
    QCommandLinkButton *commandLinkButton_3;
    QCommandLinkButton *commandLinkButton_4;
    QCommandLinkButton *commandLinkButton_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(435, 335);
        centralWidget = new QWidget(MainWindow);
		//
	
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 10, 261, 31));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 10, 51, 31));
        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(10, 50, 600, 205));
        splitter_3->setOrientation(Qt::Vertical);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        QFont font;
        font.setPointSize(8);
        splitter->setFont(font);
        splitter->setOrientation(Qt::Vertical);
        splitter_2->addWidget(splitter);
        splitter_3->addWidget(splitter_2);
        commandLinkButton = new QCommandLinkButton(splitter_3);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI"));
        font1.setPointSize(8);
        commandLinkButton->setFont(font1);
        commandLinkButton->setIconSize(QSize(50, 20));
        splitter_3->addWidget(commandLinkButton);
        commandLinkButton_2 = new QCommandLinkButton(splitter_3);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));
        commandLinkButton_2->setFont(font1);
        commandLinkButton_2->setIconSize(QSize(20, 20));
        splitter_3->addWidget(commandLinkButton_2);
        commandLinkButton_3 = new QCommandLinkButton(splitter_3);
        commandLinkButton_3->setObjectName(QStringLiteral("commandLinkButton_3"));
        commandLinkButton_3->setFont(font1);
        commandLinkButton_3->setIconSize(QSize(20, 20));
        splitter_3->addWidget(commandLinkButton_3);
        commandLinkButton_4 = new QCommandLinkButton(splitter_3);
        commandLinkButton_4->setObjectName(QStringLiteral("commandLinkButton_4"));
        commandLinkButton_4->setFont(font1);
        commandLinkButton_4->setIconSize(QSize(20, 20));
        splitter_3->addWidget(commandLinkButton_4);
        commandLinkButton_5 = new QCommandLinkButton(splitter_3);
        commandLinkButton_5->setObjectName(QStringLiteral("commandLinkButton_5"));
        commandLinkButton_5->setFont(font1);
        commandLinkButton_5->setIconSize(QSize(20, 20));
        splitter_3->addWidget(commandLinkButton_5);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 382, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "\352\262\200\354\203\211", nullptr));
        commandLinkButton->setText(QString());
        commandLinkButton_2->setText(QString());
        commandLinkButton_3->setText(QString());
        commandLinkButton_4->setText(QString());
        commandLinkButton_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
