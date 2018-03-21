#pragma once
#include "HtmlParser.h"
#include "HtmlRequest.h"
#include <algorithm>
#include <qstring.h>

#ifndef __EXTRACTARTICLETEXT_H__
#define __EXTRACTARTICLETEXT_H__


class ExtractArticleText {
public:
	ExtractArticleText(HtmlParser _html); // 按眉积己苞 悼矫俊 htmlParser 按眉 
	void loadHtmlFile(int idx);
	void titleText(); // 
	void mainText();
	void loadImage();


	HtmlParser htmlUrl;
	std::wstring title;
	QString main_txt;
	std::wstring img;
};

#endif // !__EXTRACTARTICLETEXT_H__

