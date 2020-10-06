#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include "Item.h"

using namespace std;

//������ 4
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
		cout << "������ ����� ������ ��� ����������� (-1 �����): ";
		int x, y;  cin >> x; cin.get();
		if (x == -1) break;
		Item tmp = v->at(x - 1);
		while (true)
		{
			cout << "������ ����� ���� ��� ����������� (-1 �����): ";
			CorrectPrint(tmp);
			cin >> y; cin.get();
			if (x == -1) break;
			cout << ">> �������� ";
			switch (y)
			{
			case 1: {
				cout << "��� ����������: "; cin >> tmp.fcode; cin.get();
				break;
			}
			case 2: {
				cout << "��� ������������: "; cin >> tmp.scode; cin.get();
				break;
			}
			case 3: {
				cout << "����: "; cin >> tmp.course;
				break;
			}
			case 4: {
				cout << "�����: "; cin >> tmp.group;
				break;
			}
			case 5: {
				cout << "��� ���������: "; cin >> tmp.dpcode; cin.get();
				break;
			}
			case 6: {
				cout << "������� ��������: "; cin >> tmp.nick;
				break;
			}
			case 7: {
				cout << "����� ���.��.: "; cin >> tmp.gradebook_id; cin.get();
				break;
			}
			case 8: {
				cout << "������: "; cin >> tmp.mark; cin.get();
				break;
			}
			default:
				break;
			}
			CorrectPrint(tmp);
			cout << endl << "����������� �� ���� [1/0]: ";
			int fg;  cin >> fg;	if (fg != 1) break;

		}

		v->at(x - 1) = tmp;
		cout << endl << "����������� �� ����� [1/0]: ";
		int fg;  cin >> fg;	if (fg != 1) break;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//������ 4
	auto f4 = ReadFile("./data.txt");
	CorrectItems(f4);
	WriteItems("./data.txt", *f4);

	_getch();
	return 0;
}