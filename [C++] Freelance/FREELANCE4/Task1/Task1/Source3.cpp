#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include "Item.h"

using namespace std;
//������ 3
vector<Item>* GetItems() {
	vector<Item> *v = new vector<Item>();
	while (true)
	{
		Item it;
		cout << "������ ��� ����������: ";
		cin >> it.fcode; cin.get();
		cout << "������ ��� ������������: ";
		cin >> it.scode; cin.get();
		cout << "������ ����: ";
		cin >> it.course;
		cout << "������ �����: ";
		cin >> it.group;
		cout << "������ ��� ���������: ";
		cin >> it.dpcode; cin.get();
		cout << "������ ������� ��������: ";
		cin >> it.nick;
		cout << "������ ����� ������� ������: ";
		cin >> it.gradebook_id; cin.get();
		cout << "������ ������: ";
		cin >> it.mark; cin.get();
		v->push_back(it);
		cout << endl << "������ �� ����� [1/0]: ";
		int fg;  cin >> fg;
		if (fg != 1) break;
	} return v;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	//������ 3
	auto f3 = GetItems();
	PrintAll(*f3);
	WriteItems("./data.txt", *f3);
	
	_getch();
	return 0;
}