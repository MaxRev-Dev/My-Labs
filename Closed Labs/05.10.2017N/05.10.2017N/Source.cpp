#include "externalModule.h"

using namespace std;
int main() {
	SetConsoleOutputCP(1251);

	Test<string> *d = new Test<string>[1];
	string str;
	cin >> str;
	d->SetValue(str);
	d->TestAll();
	_getch();

	return 0;
}