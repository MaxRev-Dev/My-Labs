#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

class PositiveIns {
	bool input() {
		char *buff = new char[256];
		cin.getline(buff, 256);
		string input(buff);
		if (input == "") return false;
		for each (char var in input)
		{
			if (!isdigit(var))
			{
				cout << "\nПомилка. Число не ціле додатнє INT\n";
				return false;
			}
		}
		number=atoi(input.c_str());

		return true;
	}

	int number;
public:
	int GetNum() {
		return number;
	}
	PositiveIns() {
		cout << "\nВведіть число: ";
		while (true) if (input()) break;
	}
	PositiveIns(int num) {
		if (isPositive(num))this->number = num;
		else {
			cout << "\nЧисло змінено на протилежне: ";
			this->number = -num;
		}
		cout << " " << this->number;
	}
	
	static bool isPositive(int n) {
		if (abs(n) == n) {
			return true;
		} return false;
	};
	bool isPositiveThis() {
		if (abs(number) == number) {
			return true;
		} return false;
	};

	friend PositiveIns* operator+(PositiveIns& lft, PositiveIns& rht) {
		return new PositiveIns(lft.number + rht.number);
	}
	PositiveIns* operator-(PositiveIns& rht) {
		return new PositiveIns(this->number - rht.number);
	}
	PositiveIns* operator/(PositiveIns& rht) {
		return new PositiveIns(this->number / rht.number);
	}
	PositiveIns* operator*(PositiveIns& rht) {
		return new PositiveIns(this->number * rht.number);
	}

};
template <typename T, typename T2>
void Show(T f1, T2 f2) {
	cout << "\nЧисло " << (f2 ? "" : "не ") << "додатнє: " << "[" << f1 << "]" << (f2 ? "TRUE" : "FALSE") << endl << endl;
}
int main() {
	SetConsoleOutputCP(1251);

	PositiveIns  *x = new PositiveIns[2];

	Show(x->GetNum(), x->isPositiveThis());

	PositiveIns* addNums = *x +x[1];
	Show(42, PositiveIns::isPositive(42));
	Show(-20, PositiveIns::isPositive(-20));

	x = new  PositiveIns(20);
	cout << " " << (x->isPositiveThis() ? "TRUE" : "FALSE") << endl;
	//(*x) + (*addNums);
	_getch();
	return 0;
}