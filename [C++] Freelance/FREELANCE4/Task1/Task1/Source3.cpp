#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include "Item.h"

using namespace std;
//Задача 3
vector<Item>* GetItems() {
	vector<Item> *v = new vector<Item>();
	while (true)
	{
		Item it;
		cout << "Введіть код факультету: ";
		cin >> it.fcode; cin.get();
		cout << "Введіть код спеціальності: ";
		cin >> it.scode; cin.get();
		cout << "Введіть курс: ";
		cin >> it.course;
		cout << "Введіть групу: ";
		cin >> it.group;
		cout << "Введіть код дисципліни: ";
		cin >> it.dpcode; cin.get();
		cout << "Введіть прізвище студента: ";
		cin >> it.nick;
		cout << "Введіть номер залікової книжки: ";
		cin >> it.gradebook_id; cin.get();
		cout << "Введіть оцінку: ";
		cin >> it.mark; cin.get();
		v->push_back(it);
		cout << endl << "Додати ще запис [1/0]: ";
		int fg;  cin >> fg;
		if (fg != 1) break;
	} return v;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	//задача 3
	auto f3 = GetItems();
	PrintAll(*f3);
	WriteItems("./data.txt", *f3);
	
	_getch();
	return 0;
}