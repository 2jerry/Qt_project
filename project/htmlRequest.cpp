#include "HtmlRequest.h"

HtmlRequest::HtmlRequest()
{

}

HtmlRequest::HtmlRequest(std::wstring  _tag)
{
	tag =_tag;

}

void HtmlRequest::htmlGet(std::string _filename,std::wstring _url ,int _type)
{
	std::locale::global(std::locale("kor")); // encoding
	string_t t = utility::conversions::to_string_t(tag);
	auto fileStream = std::make_shared<ostream>();
	pplx::task<void> requestTask =
		fstream::open_ostream(utility::conversions::to_string_t(_filename)).then([=](ostream outFile)
	{
		*fileStream = outFile;

		http_client_config conf;
		conf.set_timeout(seconds(5));

		/* --- my code --- */
		http_client client(utility::conversions::to_string_t(_url));
		
		if (_type == SEARCH)
		{
			uri_builder builder(U("/search"));
			//builder.set_query(uri::encode_uri(t));
			builder.append_query(U("q"),t);
			builder.append_query(U("w"), U("news"));//builder.append_query(U("q"), uri::encode_uri(utility::conversions::to_string_t(tt)));
			builder.append_query(U("enc"), U("utf8"));	
			
			return client.request(methods::GET, builder.to_string());
		}
		else
		{
			uri_builder builder(U(""));
			return client.request(methods::GET, builder.to_string());
		}
	
		
		
 	}).then([=](http_response response)
	{
		//printf("Receive response status code:%u\n", response.status_code());

		return response.body().read_to_end(fileStream->streambuf());
	}).then([=](size_t nVal)
	{
		printf("Size is %u\n", nVal);

		return fileStream->close();
	});

	try
	{
		requestTask.wait();
	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}
}