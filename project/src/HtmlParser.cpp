#include"HtmlParser.h"


wstring HtmlParser::wordParsing(wstring _str)
{
	int idx = _str.find(L"\"");
	int idx2 = _str.find(L"\"", idx + 1);
	_str = _str.substr(idx + 1, idx2 - idx - 1);
	
	return _str;
}

// 검색의 결과를 파싱
void HtmlParser::resultParsing()
{
	wstring line;
	cnt = 0;

	std::locale::global(std::locale("kor")); // encoding
	wifstream ifs(L"result.html"); // 한글을 읽기 위해 wifstream 사용
	ifs.imbue(std::locale(std::locale::empty(), \
		new std::codecvt_utf8<wchar_t, 0x10ffff, \
		std::consume_header>));

	while (getline(ifs, line))
	{
		if (wordParsing(line) == L"clusterResultUL") //html 결과 링크 부분 여기서부터 뉴스
		{
			while (line != L"</script>") // 하나의 스크립트가 끝날때 까지
			{
				getline(ifs, line); // 한줄 씩 읽는다
				if (wordParsing(line) == L"wrap_tit mg_tit")
				{
					getline(ifs, line);
					if (line.find(L"daum") != -1)
					{
						wstring st = wordParsing(line);
						url[cnt] = st.substr(0, st.find(L"?"));
						cnt++;
						if (cnt == 5) break; // 기사 5개 까지만 저장
					}
				}
			}
		}
	}

	ifs.close();
}

// 검색 결과에 따른 url을 파싱
void HtmlParser::searchParsing()
{
	wstring line;
	cnt = 0;

	std::locale::global(std::locale("kor")); // encoding
	wifstream ifs(L"search.html"); // 한글을 읽기 위해 wifstream 사용
	ifs.imbue(std::locale(std::locale::empty(), \
		new std::codecvt_utf8<wchar_t, 0x10ffff, \
		std::consume_header>));

	while (getline(ifs, line))
	{
		if (line.find(L"<title>") != -1)
		{
			int idx = line.find(L">");
			int idx2 = line.find_last_of(L"<") - 1;
			wstring str = line.substr(idx + 1, idx2 - idx);
			wcout << str << endl;
			break;
		}
		else if (line.find(L"<meta property=\"og:title\"") != -1)
		{
			int idx = line.find(L"content");
			idx = line.find(L"\"", idx + 1);
			int idx2 = line.find(L"\"", idx + 1);
			wstring str = line.substr(idx + 1, idx2 - idx - 1);
			wcout << str << endl;
			break;
		}
	}
	
	ifs.close();
}


void HtmlParser::showInfo()
{
	for (int i = 0; i<cnt; i++)
	{
		std::cout << "검색 결과 "<< i << endl;
		std::wcout <<"link: " << url[i]<<endl;
		//std::wcout <<"title: " << title[i] << endl;
		//std::wcout << endl;
	}
}