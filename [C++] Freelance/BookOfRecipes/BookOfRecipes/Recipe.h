#ifndef RCP_HEAD
#define RCP_HEAD
#include <string>

using namespace std;

struct Recipe {
	wstring Title;
	wstring ImageUrl;
	wstring Tags;
	wstring Content;
	wstring ContentIntro;
	wstring ImageLocal;
	wstring Url;
};
#endif