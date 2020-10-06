Ð Â Ð’Â Ð â€™Ð’Â Ð Â Ð²Ð‚â„¢Ð â€™Ð’Â Ð Â Ð’Â Ð Â Ð â€¹Ð Â Ð â€ Ð Â Ð²Ð‚Ñ™Ð Ð†Ð â€šÐ¡ÑšÐ Â Ð’Â Ð â€™Ð’Â Ð Â Ð â€ Ð Â Ð²Ð‚Ñ™Ð Ð†Ð²Ð‚Ñ›Ð¡Ñ›Ð Â Ð’Â Ð Ð†Ð â€šÐ²â€žÑžÐ Â Ð²Ð‚â„¢Ð â€™Ð’Â»Ð Â Ð’Â Ð â€™Ð’Â Ð Â Ð’Â Ð Â Ð²Ð‚â„–Ð Â Ð’Â Ð Â Ð²Ð‚Â Ð Â Ð’Â Ð Ð†Ð â€šÐ¡â„¢Ð Â Ð â€ Ð Â Ð²Ð‚Ñ™Ð ÐŽÐ¡Ñ™#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <locale> 
#include <codecvt>
#include "RecipeHtmlParser.h" 
#include "Recipe.h" 
#include "tools.h"
using std::regex;
using std::string;
using namespace tools::extractors;


RecipeHtmlParser::RecipeHtmlParser()
{
}
RecipeHtmlParser::RecipeHtmlParser(wstring url)
{
	baseHost = url;
}

vector<Recipe> RecipeHtmlParser::ParsePage(wstring html)
{
	int *offset = new int{ 0 };
	auto cardHtml = extract(html, L"<div class=\"recipes-list\">", offset);
	offset = new int{ 0 }; 
	while (true) {
		auto recipe = ExtractCard(baseHost, cardHtml, offset);
		if (recipe.Title == L"")
			break; 
		list.push_back(recipe);
	}

	return list;
}


RecipeHtmlParser::~RecipeHtmlParser()
{
	list.clear();
}
