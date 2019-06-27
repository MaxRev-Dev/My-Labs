#include "stdafx.h"
#include "RecipeFetch.h"
#include "netfetch.h"
#include <string>
#include <iostream>  
#include "RecipeHtmlParser.h" 
#include "tools.h" 
using namespace tools::extractors;
using std::string;
using convert_type = std::codecvt_utf8<wchar_t>;

RecipeFetch::RecipeFetch()
{
}

wstring FetchHtmlFrom(wstring url) {

	NetFetch*f = new NetFetch();
	string pageRaw;

	pageRaw = f->Get(tools::str::WstrToUtf8Str(url));
	if (pageRaw == "")
		return L"";

	int size = MultiByteToWideChar(CP_ACP, MB_COMPOSITE, pageRaw.c_str(),
		(int)pageRaw.length(), nullptr, 0);
	std::wstring utf16_str(size, '\0');
	MultiByteToWideChar(CP_ACP, MB_COMPOSITE, pageRaw.c_str(),
		(int)pageRaw.length(), &utf16_str[0], size);

	//  converter (.to_bytes: wstr->str, .from_bytes: str->wstr) 
	std::wstring_convert<convert_type, wchar_t> converter;
	return utf16_str;
}

void RecipeFetch::FetchRoot()
{
	wstring whost = L"www.stravy.net/ukrainska.html";
	auto rhp = new RecipeHtmlParser(L"www.stravy.net"); 
	auto  page = FetchHtmlFrom(whost);
	if (page != L"")
		list = rhp->ParsePage(page);
}
void RecipeFetch::GetRecipeFull(Recipe &recipe) {
	auto html = FetchHtmlFrom(recipe.Url.c_str());

	auto content = extract(html, L"<div class=\"entry-content clearfix\">");
	auto iframe = extract(content, L"<video");
	if (iframe != L"")
	{
		wstring pat = L"\"src\": \"";
		auto lf = iframe.substr(iframe.find(pat) + pat.length());
		int i = 0;
		while (lf[i] != '"')i++;
		lf = lf.substr(0, i);
		auto id = lf.substr(lf.find(L"v=")+2);// Creating YouTube embed video initializer sctipt
		iframe =
			L"var player = new YT.Player('ytplayer', {"\
			"     videoId: '" + id + L"'"\
			"  });";
		recipe.Content = iframe;

		return;
	}
	auto pure = RemoveBrackets(content);
	recipe.Content = pure;
}


vector<Recipe> RecipeFetch::GetList()
{
	return list;
}


RecipeFetch::~RecipeFetch()
{
	list.clear();
}
