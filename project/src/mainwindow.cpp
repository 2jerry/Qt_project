#include "mainwindow.h"
#include "build-untitled2-Desktop_Qt_5_10_1_MSVC2017_64bit-Debug\ui_mainwindow.h"
#include <QInputDialog>
#include <qlabel.h>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::saveInfo(int idx)
{
	std::locale::global(std::locale("kor")); // encoding

	QString str = ui->lineEdit->text(); // text 창 결과
	wstring tag = str.toStdWString();

	html.tag = tag;
	// 검색 결과 페이지 파싱
	html.htmlGet("result.html", L"https://search.daum.net/", SEARCH);

	HtmlParser htmlparser; // 
	htmlparser.resultParsing();

	ExtractArticleText article(htmlparser);

	article.loadHtmlFile(idx);
	article.titleText();
	article.mainText();
	article.loadImage();

	main[idx] = QString::fromStdWString(article.main_txt);
	main[idx].replace("&middot;", ",");
	main[idx].replace("&quot;", "\"");
	main[idx].replace("&nbsp;", " ");

	title[idx] = QString::fromStdWString(article.title);
	title[idx].replace("&middot;", ",");
	title[idx].replace("&quot;", "\"");
	title[idx].replace("&nbsp;", " ");

	img[idx] = article.img;


}

void MainWindow::showInfo(int idx)
{
	QString filename = "image.jpg"; //  이미지 파일 이름 불러오기
	QImage img(filename);
	QPixmap buf = QPixmap::fromImage(img);

	QWidget *window = new QWidget; // 새로운 위젯 생성
	QLabel *titleLabel = new QLabel();
	QLabel *mainLabel = new QLabel();
	QLabel *imageLabel = new QLabel();
	QFont titleFont;
	QFont mainFont;
	//window->resize(500, 500);

	
	titleLabel->setGeometry(QRect(70, 10, 290, 40));
	titleFont.setBold(true);
	titleFont.setPointSize(11);
	titleLabel->setText(title[idx]);
	titleLabel->setFont(titleFont);

	imageLabel->setGeometry(QRect(20, 70, 300,300));
	imageLabel->setPixmap(buf);
	//imageLabel->setPixmap(buf.scaled(imageLabel->size()));
	imageLabel->resize(buf.width() / 2, buf.height() / 2);
	mainLabel->setGeometry(QRect(20, 230, 100, 200));
	mainFont.setPointSize(9);
	mainLabel->setText(main[idx]);
	mainLabel->setFont(mainFont);


	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(titleLabel);
	layout->addWidget(imageLabel);
	layout->addWidget(mainLabel);
	

	window->setLayout(layout);
	window->show();
}

/* --- Event 함수 ----*/
void MainWindow::on_pushButton_clicked()
{
	saveInfo(0);
	ui->commandLinkButton->setText(title[0]);

	saveInfo(1);
	ui->commandLinkButton_2->setText(title[1]);

	saveInfo(2);
	ui->commandLinkButton_3->setText(title[2]);

	saveInfo(3);
	ui->commandLinkButton_4->setText(title[3]);

	saveInfo(4);
	ui->commandLinkButton_5->setText(title[4]);
}

void MainWindow::on_commandLinkButton_clicked()
{
	html.htmlGet("image.jpg", img[0], 0); // html 파일 생성
	showInfo(0);
}

void MainWindow::on_commandLinkButton_2_clicked()
{
	html.htmlGet("image.jpg", img[1], 0); // html 파일 생성
	showInfo(1);
}

void MainWindow::on_commandLinkButton_3_clicked()
{
	html.htmlGet("image.jpg", img[2], 0);
	showInfo(2);
}

void MainWindow::on_commandLinkButton_4_clicked()
{
	html.htmlGet("image.jpg", img[3], 0);
	showInfo(3);
}

void MainWindow::on_commandLinkButton_5_clicked()
{
	html.htmlGet("image.jpg", img[4], 0);
	showInfo(4);
}