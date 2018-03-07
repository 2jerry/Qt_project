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
    w.show();
	

    /* 버튼 예제 */
    /*QPushButton *btn = new QPushButton("검색색",0);
    btn->show();

    QObject::connect(btn,SIGNAL(clicked()),&a,SLOT(quit()));*/

    /* 입력 예제 */


    return a.exec();
}
