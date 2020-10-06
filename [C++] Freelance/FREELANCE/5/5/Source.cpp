#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	double a,b;
	cout << "Ð â€™Ð Ð†Ð ÂµÐ Ò‘Ð¡â€“Ð¡â€šÐ¡ÐŠ Ð¡â€¡Ð Ñ‘Ð¡ÐƒÐ ÂµÐ Â»Ð¡ÐŠÐ Ð…Ð Ñ‘Ð Ñ” Ð Ò‘Ð¡Ð‚Ð Ñ•Ð Â±Ð¡Ñ“: ";
	cin >> a;
	cout << "Ð â€™Ð Ð†Ð ÂµÐ Ò‘Ð¡â€“Ð¡â€šÐ¡ÐŠ Ð Â·Ð Ð…Ð Â°Ð Ñ˜Ð ÂµÐ Ð…Ð Ð…Ð Ñ‘Ð Ñ” Ð Ò‘Ð¡Ð‚Ð Ñ•Ð Â±Ð¡Ñ“: ";
	cin >> b;

	double d = a / b;

	string str(to_string(d));
	string last = str.substr(str.find_first_of('.')+1, str.length());
	for (int i = 1; i < last.length(); i++) {
		if (last.substr(0, i) == last.substr(i, i)) {
			last = last.substr(0, i);
		}
	}
	cout << "Ð Â Ð ÂµÐ Â·Ð¡Ñ“Ð Â»Ð¡ÐŠÐ¡â€šÐ Â°Ð¡â€š: " << str<<endl;
	cout << "Ð ÑŸÐ ÂµÐ¡Ð‚Ð¡â€“Ð Ñ•Ð Ò‘ Ð Ò‘Ð¡Ð‚Ð Ñ•Ð Â±Ð¡Ñ“  = "<<last;

	_getch();
	return 0;
}