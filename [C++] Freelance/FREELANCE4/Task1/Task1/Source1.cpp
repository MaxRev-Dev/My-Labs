#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include "Item.h"

using namespace std;
bool contains(const vector<int> v, int s) {
	for (size_t i = 0; i < v.size(); i++)
		if (v[i] == s) return true;
	return false;
}

void Calc(vector<Item> v) {
	vector<int> made;
	vector<Item> sum, res = v;
	made.push_back(v.back().fcode);
	cout << "|\t\t   |   Питома вага   |" << endl;
	cout << "| Факультет\t" << "   |  2   3   4   5  |" << endl;
	for (size_t i = 0; i < v.size(); i++) {
		int lsum = 0, cnt = 0, resf;
		int *wmark = new int[6];
		for (int i = 2; i <= 5; i++) wmark[i] = 0;
		for (size_t i = 0; i < v.size(); i++) {
			if (!contains(made, v[i].fcode)) continue;
			if (v[i].fcode == made.back()) {
				lsum += v[i].mark; // aver mark
				cnt++;

				//weight
				++wmark[v[i].mark];
			}
		}
		cout << "| Факультет: " << setw(5) << made.back();
		for (int i = 2; i <= 5; i++) {
			if (wmark[i] != 0) {
				cout << " | " << setw(1) << setprecision(2) << (1.0*wmark[i] / cnt * 100);
			}
			else cout << " | " << 0;
		}
		cout << " | Середній бал: " << lsum / cnt << endl;

		resf = v.back().fcode;
		while (contains(made, resf)) {
			if (v.size() > 0) {
				v.pop_back();
				if (v.size() > 0)
					resf = v.back().fcode;
			}
			else break;
		}
		if (v.size() > 0)
			made.push_back(v.back().fcode);
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//задача 1
	auto f1 = ReadFile("./data.txt");
	Calc(*f1);
	_getch();
	return 0;
}