/* ----- Qt header ----- */
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>
#include "mainwindow.h"
#include <qlabel.h>

/* ----- Html Header ----- */
#include "ExtractArticleText.h"
#include <locale>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow w;

	remove("image.jpg");
	remove("result.html");
	remove("search.html");

    w.show();
	

    return a.exec();
}
