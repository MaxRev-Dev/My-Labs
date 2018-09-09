#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <set>
using namespace std;

int main() {

	SetConsoleOutputCP(1251);
	set<string> *st = new set<string>();
	for (int i = 0; i < 20; i++) {		
		st->insert("3");
	}
	for (auto i = st->begin(); i != st->end(); i++) {
		string f = *i;
		cout<<f.c_str();
	}
	_getch();
	return 0;
}



