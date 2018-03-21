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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QComboBox>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
	QWidget * centralWidget;
//	QLineEdit *lineEdit;
	QComboBox *comboBox;
	QPushButton *pushButton;
	QListWidget *listWidget;
	QMenuBar *menuBar;
	QToolBar *mainToolBar;
	QStatusBar *statusBar;

	void setupUi(QMainWindow *MainWindow)
	{
		if (MainWindow->objectName().isEmpty())
			MainWindow->setObjectName(QStringLiteral("MainWindow"));
		MainWindow->resize(530, 330);
		centralWidget = new QWidget(MainWindow);
		centralWidget->setObjectName(QStringLiteral("centralWidget"));
		comboBox = new QComboBox(centralWidget);
		comboBox->setObjectName(QStringLiteral("comboBox"));
		comboBox->setGeometry(QRect(20, 10, 261, 31));
		QFont font; 
		font.setPointSize(11);
		comboBox->setFont(font);
		pushButton = new QPushButton(centralWidget);
		pushButton->setObjectName(QStringLiteral("pushButton"));
		pushButton->setGeometry(QRect(290, 10, 51, 31));
		listWidget = new QListWidget(centralWidget);
		listWidget->setObjectName(QStringLiteral("listWidget"));
		listWidget->setGeometry(QRect(20, 50, 481, 241));
		font.setPointSize(12);
		listWidget->setFont(font);
		MainWindow->setCentralWidget(centralWidget);
		menuBar = new QMenuBar(MainWindow);
		menuBar->setObjectName(QStringLiteral("menuBar"));
		menuBar->setGeometry(QRect(0, 0, 441, 26));
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
		MainWindow->setWindowTitle(QApplication::translate("MainWindow", "News Search Program", nullptr));
		//lineEdit->setText(QString());
		pushButton->setText(QApplication::translate("MainWindow", "\352\262\200\354\203\211", nullptr));
	} // retranslateUi

};

namespace Ui {
	class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H