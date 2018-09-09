#include <iostream>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include "Item.h"

using namespace std;

//������ 2
void RemoveItems(vector<Item> *v) {
	while (true) {
		PrintAll(*v);
		cout << endl << "����� ������ ��� ��������� (-1 �����): " << endl;
		int x; cin >> x; cin.get();
		if (x == -1) break;
		v->erase(v->begin() + x - 1);
		cout << endl << "�������� �� ����� [1/0]: ";
		int fg;  cin >> fg;
		if (fg != 1) break;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//������ 2
	auto f2 = ReadFile("./data.txt");
	RemoveItems(f2);
	WriteItems("./data.txt", *f2);

	_getch();
	return 0;
}