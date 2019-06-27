#include <vector>
#include <string.h>
#include "Recipe.h"
#pragma once

using namespace std;
 
class RecipeFetch
{
private:
	vector<Recipe> list;
public:
	RecipeFetch();
	void FetchRoot();
	void GetRecipeFull(Recipe & recipe);
	vector<Recipe> GetList();
	~RecipeFetch();
};

