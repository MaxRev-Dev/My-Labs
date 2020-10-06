#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <sstream>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	double a,b;
	cout << "Р’РІРµРґС–С‚СЊ С‡РёСЃРµР»СЊРЅРёРє РґСЂРѕР±Сѓ: ";
	cin >> a;
	cout << "Р’РІРµРґС–С‚СЊ Р·РЅР°РјРµРЅРЅРёРє РґСЂРѕР±Сѓ: ";
	cin >> b;

	double d = a / b;

	std::ostringstream sstream;
	sstream << d;
	string str = sstream.str();	// РєРѕРЅРІРµСЂС‚СѓРІР°РЅРЅСЏ double to string (C++03)

	string last = str.substr(str.find_first_of('.')+1, str.length());
	for (int i = 1; i < last.length(); i++) {
		if (last.substr(0, i) == last.substr(i, i)) {
			last = last.substr(0, i);
		}
	}
	cout << "Р РµР·СѓР»СЊС‚Р°С‚: " << str<<endl;
	cout << "РџРµСЂС–РѕРґ РґСЂРѕР±Сѓ  = "<<last;

	_getch();
	return 0;
}