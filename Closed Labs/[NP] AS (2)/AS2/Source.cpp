#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
using namespace std;
class xstring : string {
public:

	std::string m_string;
public:
	explicit xstring(const std::string& str)
		: m_string(str)
	{
	}
	
};

xstring& operator*(xstring&x, xstring&y) {
		string f = "";
		for (auto c : x.m_string) {
			if (y.m_string.find(c) != string::npos) f += c;
		}
		return *(new xstring(f));
	}
ostream&  operator<<(ostream& out,xstring&s) {
	return out << s.m_string;
}

int main() {
	SetConsoleOutputCP(1251);

	string a, b;
	cout << "Введіть перший рядок: ";
	getline(cin, a);
	cout << "Введіть другий рядок: ";
	getline(cin, b);
	xstring p = xstring(a)*xstring(b);
	cout << "Однакові символи: " << p << endl;
	_getch();

	return 0;
}