#pragma once
#ifndef __HTMLREQUEST_h__
#define __HTMLREQUEST_h__

#include <cpprest\http_client.h>
#include <cpprest\filestream.h>
#include <string>

#define SEARCH 1


using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

class HtmlRequest {
public:
	HtmlRequest(std::wstring _tag); // »ý¼ºÀÚ
	HtmlRequest();
	void htmlGet(std::string _filename, std::wstring _url,int _type);

	std::wstring tag;
	
};

#endif // __HTMLREQUEST_h__
