#pragma once
#include <vector>
#include "Recipe.h"
#include <string>

using std::vector;

class RecipeHtmlParser
{
private: 
	vector<Recipe> list;
	wstring baseHost;
public:
	RecipeHtmlParser();
	RecipeHtmlParser(wstring url);

	vector<Recipe> ParsePage(wstring html);

	~RecipeHtmlParser();
};

