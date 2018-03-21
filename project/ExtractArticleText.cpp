#include "ExtractArticleText.h"



ExtractArticleText::ExtractArticleText(HtmlParser _html)
{
	htmlUrl = _html; // url 정보를 넘겨 받는다.
}

// search.html 을 저장..
void ExtractArticleText::loadHtmlFile(int idx)
{
	HtmlRequest request;
	request.htmlGet("search.html", htmlUrl.url[idx], 0); // html 파일 생성
														 //htmlUrl.searchParsing();
}

void ExtractArticleText::titleText()
{
	wstring line;
	std::locale::global(std::locale("kor")); // encoding
	wifstream ifs(L"search.html"); // 한글을 읽기 위해 wifstream 사용
	ifs.imbue(std::locale(std::locale::empty(), \
		new std::codecvt_utf8<wchar_t, 0x10ffff, \
		std::consume_header>));
	title = L"";

	while (getline(ifs, line))
	{
		if (line.find(L"<title>") != -1) // 기사 제목 파싱
		{
			//line.replace("&middot;", "·");
			int idx = line.find(L">");
			int idx2 = line.find_last_of(L"|") - 1;
			title += line.substr(idx + 1, idx2 - idx);

			break;
		}
	}

	ifs.close();
}

void ExtractArticleText::mainText()
{
	wstring line;
	std::locale::global(std::locale("kor")); // encoding
	wifstream ifs(L"search.html"); // 한글을 읽기 위해 wifstream 사용
	ifs.imbue(std::locale(std::locale::empty(), \
		new std::codecvt_utf8<wchar_t, 0x10ffff, \
		std::consume_header>));
	int dot = 0;

	while (getline(ifs, line))
	{
		if (line.find(L"<p dmcf-pid") != -1 && line.find(L"</section>") == -1) // 본문 파싱
		{

			int idx = line.find(L">");
			int idx2 = line.find_last_of(L"<");

			wstring tmp_str = line.substr(idx + 1, idx2 - idx - 1);
			QString str = QString::fromStdWString(tmp_str);

			str.replace("&middot;", ",");
			str.replace("&quot;", "\"");
			str.replace("&nbsp;", " ");
			str.replace( "&lt;", "<");
			str.replace("&gt;", ">");

			if (str.length() >=60 && line.find(L"<br / >")==-1)
			{
				for (int i = 60; i <= str.length(); i = i + 60)
				{
					if (i % 60 == 0)
						str.insert(i, "<br />");
				}
			}


			main_txt += "<br /><br />"+ str;
			

		}
	}

}

void ExtractArticleText::loadImage()
{
	wstring line;
	std::locale::global(std::locale("kor")); // encoding
	wifstream ifs(L"search.html"); // 한글을 읽기 위해 wifstream 사용
	ifs.imbue(std::locale(std::locale::empty(), \
		new std::codecvt_utf8<wchar_t, 0x10ffff, \
		std::consume_header>));

	while (getline(ifs, line))
	{
		if (int i = line.find(L"<meta property=\"twitter:image\"") != -1) // 본문 파싱
		{
			int idx = line.find(L"content=") + 9;
			int idx2 = line.find_last_of(L"\"");
			wstring str = line.substr(idx, idx2 - idx);
			img = str;
			break;
		}
	}
}


/*
void ExtractArticleText::printArticle()
{
titleText();
mainText();
cout << "기사 제목: ";
wcout << title << endl;
cout << "본문>> \n ";
wcout << main_txt << endl;
cout << endl;
}*/