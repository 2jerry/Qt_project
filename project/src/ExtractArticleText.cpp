#include "ExtractArticleText.h"


ExtractArticleText::ExtractArticleText(HtmlParser _html)
{
	htmlUrl = _html; // url ������ �Ѱ� �޴´�.
}

// search.html �� ����..
void ExtractArticleText::loadHtmlFile(int idx)
{
	HtmlRequest request;
	request.htmlGet("search.html", htmlUrl.url[idx], 0); // html ���� ����
	//htmlUrl.searchParsing();
}

void ExtractArticleText::titleText()
{
	wstring line;
	std::locale::global(std::locale("kor")); // encoding
	wifstream ifs(L"search.html"); // �ѱ��� �б� ���� wifstream ���
	ifs.imbue(std::locale(std::locale::empty(), \
		new std::codecvt_utf8<wchar_t, 0x10ffff, \
		std::consume_header>));
	title = L"";

	while (getline(ifs, line))
	{
		if (line.find(L"<title>") != -1) // ��� ���� �Ľ�
		{
			//line.replace("&middot;", "��");
			int idx = line.find(L">");
			int idx2 = line.find_last_of(L"<") - 1;
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
	wifstream ifs(L"search.html"); // �ѱ��� �б� ���� wifstream ���
	ifs.imbue(std::locale(std::locale::empty(), \
		new std::codecvt_utf8<wchar_t, 0x10ffff, \
		std::consume_header>));
	int dot = 0;

	while (getline(ifs, line))
	{
		if (line.find(L"<p dmcf-pid") != -1) // ���� �Ľ�
		{
			dot++;
			if (line.find(L"</section>") == -1)
			{
				int idx = line.find(L">");
				int idx2 = line.find_last_of(L"<");

				wstring str = line.substr(idx + 1, idx2 - idx - 1);

				main_txt += str;

			}
		}
	}

	for (int i = 1; i < main_txt.length(); i++)
	{
		if (i % 70 == 0)
			main_txt.insert(i, L"\n");
	}
	//wcout << main << endl;
}

void ExtractArticleText::loadImage()
{
	wstring line;
	std::locale::global(std::locale("kor")); // encoding
	wifstream ifs(L"search.html"); // �ѱ��� �б� ���� wifstream ���
	ifs.imbue(std::locale(std::locale::empty(), \
		new std::codecvt_utf8<wchar_t, 0x10ffff, \
		std::consume_header>));
	while (getline(ifs, line))
	{
		if (int i = line.find(L"<meta property=\"og:image\"") != -1) // ���� �Ľ�
		{
			int idx = line.find(L"content=")+9;
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
	cout << "��� ����: ";
	wcout << title << endl;
	cout << "����>> \n ";
	wcout << main_txt << endl;
	cout << endl;
}*/