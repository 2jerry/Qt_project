#include "mainwindow.h"

#include <QInputDialog>
#include <qlabel.h>
#include <QVBoxLayout>
#include <qgridlayout.h>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	lineEdit = new QLineEdit();
	ui->comboBox->setLineEdit(lineEdit);
	ui->comboBox->setInsertPolicy(QComboBox::NoInsert); // 

	info_thread = new Control(this);
	connect(info_thread, SIGNAL(FinishCount(int)), this, SLOT(on_thread_finish(int)));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::showInfo(int idx)
{
	QWidget *window = new QWidget; // 새로운 위젯 생성
	QGridLayout *gridLayout;
	QScrollArea *scrollArea;
	QWidget *scrollAreadWidget;
	QGridLayout *gridLayout_2;
	QImage *img = new QImage();
	QPixmap *buf = new QPixmap();


	QLabel *titleLabel ;
	QLabel *mainLabel;
	QLabel *imageLabel ;
	
	QFont titleFont;
	QFont mainFont;

	titleFont.setFamily(QString::fromUtf8("\353\247\221\354\235\200 \352\263\240\353\224\225"));
	mainFont.setFamily(QString::fromUtf8("\353\247\221\354\235\200 \352\263\240\353\224\225"));

	window->setWindowTitle(QApplication::translate("window", "article", nullptr));
	window->resize(800, 600);
	window->setStyleSheet("background:rgb(255,255,255)");

	gridLayout = new QGridLayout(window);
	gridLayout->setSpacing(6);
	gridLayout->setContentsMargins(11, 11, 11, 11);
	gridLayout->setObjectName(QStringLiteral("gridLayout"));

	scrollArea = new QScrollArea(window);
	scrollArea->setObjectName(QStringLiteral("scrollArea"));
	scrollArea->setFrameShape(QFrame::NoFrame);
	scrollArea->setWidgetResizable(true);

	scrollAreadWidget = new QWidget();
	scrollAreadWidget->setObjectName(QStringLiteral("scrollAreadWidget"));
	scrollAreadWidget->setGeometry(QRect(0, 0, 535, 555));

	gridLayout_2 = new QGridLayout(scrollAreadWidget);
	gridLayout_2->setSpacing(6);
	gridLayout_2->setContentsMargins(11, 11, 11, 11);
	gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
	
	titleLabel = new QLabel(scrollAreadWidget);
	titleFont.setBold(true);
	titleFont.setPointSize(16);
	titleLabel->setFont(titleFont);
	//titleLabel->setAlignment(Qt::AlignCenter);
	titleLabel->setText(info_thread->title[idx]);
	
	
	imageLabel = new QLabel(scrollAreadWidget);
	//imageLabel->setAlignment(Qt::AlignCenter);

	if (img->load("image.jpg"))
	{
		*buf = QPixmap::fromImage(*img);
		if (img->width() >= 1000 )
			*buf = buf->scaled(img->width()/4, img->height()/4);
		
		imageLabel->setPixmap(*buf);
		
		imageLabel->resize(buf->width(), buf->height());
		
	}
	else
		imageLabel->setText("Image load Error");


	mainLabel = new QLabel(scrollAreadWidget);
	mainFont.setPointSize(11);
	mainLabel->setFont(mainFont);
	mainLabel->setAlignment(Qt::AlignLeft);
	mainLabel->setText(info_thread->mainTxt[idx]);

	gridLayout_2->addWidget(titleLabel, 0, 0, 1, 1);
	gridLayout_2->addWidget(imageLabel,1, 0, 1, 1);
	gridLayout_2->addWidget(mainLabel, 2, 0, 1, 1);

	scrollArea->setWidget(scrollAreadWidget);
	gridLayout->addWidget(scrollArea, 0, 0, 1, 1);
	
	window->setLayout(gridLayout);
	window->show();
}

/* --- Event 함수 ----*/
void MainWindow::on_pushButton_clicked()
{
	ui->listWidget->clear();
	ui->pushButton->setEnabled(false);
	ui->listWidget->addItem("loading.."); // loading 표시

	std::locale::global(std::locale("kor")); // encoding
	QString str = lineEdit->text(); // 검색어 가져오기
	ui->comboBox->addItem(str);

	info_thread->tag = str.toStdWString(); // 검색어 저장
	info_thread->start(); // 쓰레드 시작

}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
	QString idx = item->text().section(" ", 0, 0);
	int index = idx.toInt()-1;
	HtmlRequest html;
	html.htmlGet("image.jpg", info_thread->img[index], -1);
	showInfo(index);
}

void MainWindow::on_thread_finish(const int cnt)
{
	if (info_thread->isFinished() == false)
		return;
	if (info_thread->isRunning() == true)
		return;
	ui->pushButton->setEnabled(true);
	ui->listWidget->clear();
	for (int i = 0; i <cnt; i++)
	{
		ui->listWidget->addItem(QString("%1 " + info_thread->title[i]).arg(i+1));
	}

	//ui->pushButton->setEnabled(true);

}

