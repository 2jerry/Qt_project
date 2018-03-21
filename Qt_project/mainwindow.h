#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <locale>
#include <string>
#include <thread>
#include <QThread>
#include <iostream>
#include <QtWidgets\qlistwidget.h>

#include "ui_mainwindow.h"
#include "ExtractArticleText.h"
#include "Control.h"

namespace Ui {
	class MainWindow;
}

class MainWindow :public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_pushButton_clicked();
	void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
	void on_thread_finish(const int value);
public:
	void showInfo(int idx);
	QLineEdit *lineEdit;
	
private:
	Ui::MainWindow *ui;
	Control* info_thread;
	
};

#endif // MAINWINDOW_H