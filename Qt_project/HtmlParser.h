#pragma once
#ifndef __HTMLPARSER_H__
#define __HTMLPARSER_H__

#include <fstream>
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
using namespace std;

class HtmlParser {
public:
	wstring url[20];
	int cnt;

	void searchParsing();
	int resultParsing();
	void showInfo();
	wstring wordParsing(wstring _str);

};


#endif // !__HTMLPARSER_H__

