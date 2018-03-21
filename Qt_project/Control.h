#pragma once
#ifndef __CONTROLL_H__
#define __CONTROLL_H__

#include <QThread>
#include <string>
#include <qstring.h>

#include "HtmlParser.h"
#include "HtmlRequest.h"
#include "ExtractArticleText.h"


using namespace std;

class Control :public QThread {
	Q_OBJECT
public:
	explicit Control(QObject *parent = 0);

private:
	void run();
	
signals:
	void FinishCount(int cnt);

public:
	wstring tag;
	QString title[20];
	QString mainTxt[20];
	wstring img[20];
	int cnt;
	int idx;
};


#endif // !__CONTROLL_H__

