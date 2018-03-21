#include "Control.h"

Control::Control(QObject *parent) :
	QThread(parent)
{

}
void Control::run()
{
	title->clear();
	mainTxt->clear();
	img->clear();

	cnt = 0;
	HtmlRequest html;
	html.tag = tag;
	// 검색 결과 페이지 파싱
	html.htmlGet("result.html", L"https://search.daum.net/", SEARCH);

	HtmlParser htmlparser; // 
	cnt = htmlparser.resultParsing();
	for (int idx = 0; idx < cnt; idx++)
	{
		if (idx >= 0)
		{
			ExtractArticleText article(htmlparser);

			article.loadHtmlFile(idx);
			article.titleText();
			article.mainText();
			article.loadImage();

			mainTxt[idx] =article.main_txt;
			/*mainTxt[idx].replace("&middot;", ",");
			mainTxt[idx].replace("&quot;", "\"");
			mainTxt[idx].replace("&nbsp;", " ");
			mainTxt[idx].replace("&lt;", "<");
			mainTxt[idx].replace("&gt;", ">");*/

			title[idx] = QString::fromStdWString(article.title);
			title[idx].replace("&middot;", ",");
			title[idx].replace("&quot;", "\"");
			title[idx].replace("&nbsp;", " ");
			title[idx].replace("&lt;", "<");
			title[idx].replace("&gt;", ">");

			img[idx] = article.img;
		}
	}
	emit FinishCount(cnt);
}

