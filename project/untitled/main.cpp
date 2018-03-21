#include "mainwindow.h"
#include <QApplication>
#include <QVBoxLayout>
#include<QLabel>
#include <QScrollBar>
#include <QScrollArea>
#include <QInputDialog>
int main(int argc, char *argv[])
{
/* QApplication a(argc, argv);
MainWindow w;
w.show();
*/

    QWidget *window = new QWidget; // 새로운 위젯 생성

    QLabel *titleLabel = new QLabel();
    QLabel *mainLabel = new QLabel();
    QLabel *imageLabel = new QLabel();
    QScrollArea *scrollArea = new QScrollArea(window);
    QWidget *scrollAreaWidgetContents;

    QFont titleFont;
    QFont mainFont;
    window->resize(700, 700);


    titleLabel->setGeometry(QRect(70, 10, 290, 40));
    titleFont.setBold(true);
    titleFont.setPointSize(11);
    //titleLabel->setText(QString::fromStdWString(img[idx]));
    titleLabel->setText("title[idx]");
    titleLabel->setFont(titleFont);

    //imageLabel->setGeometry(QRect(20, 70, buf.width() / 2, buf.height() / 2));
   // imageLabel->setPixmap(buf);
//    imageLabel->setPixmap(buf.scaled(imageLabel->size()));
    //imageLabel->resize(buf.width() / 100, buf.height() / 100);
    mainLabel->setGeometry(QRect(20, 230, 100, 200));
    mainFont.setPointSize(9);
    mainLabel->setText("mainTxt[idx]");
    mainLabel->setFont(mainFont);

    scrollArea->setWidgetResizable(true);
    scrollArea->setWidgetResizable(true);
    scrollAreaWidgetContents = new QWidget();
    scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
    scrollAreaWidgetContents->setGeometry(QRect(0, 0, 308, 149));
    scrollArea->setWidget(scrollAreaWidgetContents);


    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(titleLabel);
   // layout->addWidget(imageLabel);
    layout->addWidget(mainLabel);
    layout->addWidget(scrollArea);

    window->setLayout(layout);
    window->show();
    return 0;
}
