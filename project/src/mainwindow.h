#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ExtractArticleText.h"
#include <locale>
#include <string>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	
private slots:
	void on_pushButton_clicked();
	void on_commandLinkButton_clicked();
	void on_commandLinkButton_2_clicked();
	void on_commandLinkButton_3_clicked();
	void on_commandLinkButton_4_clicked();
	void on_commandLinkButton_5_clicked();


public:
	/* --- my code --- */
	void saveInfo(int idx);
	void showInfo(int idx);

	QString title[5];
	QString main[5];
	wstring img[5];

	HtmlRequest html;

	/* end */

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
