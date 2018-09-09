#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <algorithm>
using namespace std;

string changeOA(string s) {
	string vovels = "aeuyio", consonants = "bcdfghjklmnpqrstvwxz";
	int iter = 0;
	string finalize = "";
	for (size_t i = 0; i < s.size(); i++)
	{
		char sym = s.at(i);
		string consonantsToUpper = consonants;
		transform(consonants.begin(),consonants.end(), consonantsToUpper.begin() ,toupper);
		if (consonants.find(sym) != s.npos || consonantsToUpper.find(toupper(sym)) != s.npos) {
			finalize += vovels.at(iter++);

			finalize += "\n";
		}		
		else {
			finalize += "\\x";
			finalize += to_string(int(sym));
			finalize += " ";

			finalize += "\n";
		}
		if (iter == vovels.size()) iter = 0;
	}
	return finalize;
}


int main() {
	SetConsoleOutputCP(1251);

	string str;

	cin >> str;
    str = changeOA(str);
	cout << str;

	_getch();
	return 0;

}