#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include "Item.h"

using namespace std;

//Задача 4
void CorrectPrint(const Item p) {
	cout <<
		"\n| [1]" << setw(5) << p.fcode << setw(5) << "| [2]" << setw(5) <<
		setw(5) << p.scode << setw(5) << "| [3]" << setw(5) <<
		setw(5) << p.course << setw(5) << "| [4]" << setw(5) <<
		setw(10) << p.group << setw(5) << "| [5]" << setw(5) <<
		setw(5) << p.dpcode << setw(5) << "| [6]" << setw(5) <<
		setw(10) << p.nick << setw(5) << "| [7]" << setw(5) <<
		setw(5) << p.gradebook_id << setw(5) << "| [8]" << setw(5) <<
		setw(5) << p.mark << "|" << endl;
}
void CorrectItems(vector<Item> *v) {
	while (true)
	{
		PrintAll(*v);
		cout << "Введіть номер запису для коригування (-1 відміна): ";
		int x, y;  cin >> x; cin.get();
		if (x == -1) break;
		Item tmp = v->at(x - 1);
		while (true)
		{
			cout << "Введіть номер поля для коригування (-1 відміна): ";
			CorrectPrint(tmp);
			cin >> y; cin.get();
			if (x == -1) break;
			cout << ">> Редагуємо ";
			switch (y)
			{
			case 1: {
				cout << "код факультету: "; cin >> tmp.fcode; cin.get();
				break;
			}
			case 2: {
				cout << "код спеціальності: "; cin >> tmp.scode; cin.get();
				break;
			}
			case 3: {
				cout << "курс: "; cin >> tmp.course;
				break;
			}
			case 4: {
				cout << "групу: "; cin >> tmp.group;
				break;
			}
			case 5: {
				cout << "код дисципліни: "; cin >> tmp.dpcode; cin.get();
				break;
			}
			case 6: {
				cout << "прізвище студента: "; cin >> tmp.nick;
				break;
			}
			case 7: {
				cout << "номер зал.кн.: "; cin >> tmp.gradebook_id; cin.get();
				break;
			}
			case 8: {
				cout << "оцінку: "; cin >> tmp.mark; cin.get();
				break;
			}
			default:
				break;
			}
			CorrectPrint(tmp);
			cout << endl << "Скорегувати ще поле [1/0]: ";
			int fg;  cin >> fg;	if (fg != 1) break;

		}

		v->at(x - 1) = tmp;
		cout << endl << "Скорегувати ще запис [1/0]: ";
		int fg;  cin >> fg;	if (fg != 1) break;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//задача 4
	auto f4 = ReadFile("./data.txt");
	CorrectItems(f4);
	WriteItems("./data.txt", *f4);

	_getch();
	return 0;
}