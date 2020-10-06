#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>

using namespace std;

bool checkIn(string s1) {
	string base = "0123456789";
	for (size_t i = 0; i < s1.length(); i++) {
		if (s1[i] != base[i]) {
			cout << "РўРµРєС‚ РЅРµ СЃРїС–РІРїР°РґР°С” Р· РІС–РґСЂС–Р·РєРѕРј - РЅР° С–РЅРґРµРєСЃС– [" << i << "]\n";
			return false;
		}
	}
	return true;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true) {
		string  input;
		cout << "Р’РІРµРґС–С‚СЊ С‚РµРєСЃС‚: ";
		getline(cin, input);

		if (checkIn(input)) {
			cout << "РўРµРєСЃС‚ С” РїРѕС‡Р°С‚РєРѕРј РІС–РґСЂС–Р·РєСѓ\n";
		}
		_getch();
	}
	return 0;
}

#include <vector>

vector<int> Fibo(int n) {
	int t1 = 0, t2 = 1, next = 0;
	vector<int> ret;
	ret.push_back(t1); ret.push_back(t2);

	next = t1 + t2;

	while (next <= n)
	{
		ret.push_back(next);
		t1 = t2;
		t2 = next;
		next = t1 + t2;
	}
	return ret;
}

vector<string> split(string inp) {
	size_t pos = 0;
	string token;
	vector<string> ret;
	while ((pos = inp.find(' ')) != std::string::npos) {
		token = inp.substr(0, pos);
		if (pos != inp.length() - 1&& token !="") ret.push_back(token);
		inp.erase(0, pos + 1);
	}
	return ret;
}

int main2() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string inp;
	cout << "Р’РІРµРґС–С‚СЊ РїРѕСЃР»С–РґРѕРІРЅС–СЃС‚СЊ С‡РµСЂРµР· РїСЂРѕР±С–Р» С– Р·Р°РІРµСЂС€С–С‚СЊ РЅСѓР»РµРј\n";
	getline(cin, inp);

	vector<string> sx = split(inp);
	vector<int> v = Fibo(sx.size()-1);
	cout << "Р’РІРµРґРµРЅС– С‡РёСЃР»Р°: \n";
	for (size_t i = 0; i < sx.size(); i++) {
		cout << "[" << i + 1 << "]" << sx[i] << endl;
	}cout << "\n\n";
	int sum = 0;
	for (size_t i = 0; i < v.size(); i++) {
		cout << "CСѓРјСѓС”РјРѕ С–РЅРґРµРєСЃ " << v[i] << endl;
		sum += atoi(sx[v[i]].c_str());
	}
	cout << "РЎСѓРјР° = "<< sum;
	_getch();
	return 0;
}