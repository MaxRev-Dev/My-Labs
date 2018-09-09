#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <limits>
#include <string>
#include <algorithm>
using namespace std;



class ODD {
	int num;

	void input() {
		char *buff = new char[256];
		cin.getline(buff, 256);
		if (!ValueInRange(string(buff), MININT, 0)) {
			input();
		}
	}
	bool ValueInRange(const std::string& input, int min, int max)
	{	
		if (input == "") return false;
		for each (char var in input)
		{
			if (!isdigit(var) && var != '-')
			{
				cout << "\nПомилка. Це не число. Спробуйте ще раз\n";
				return false;
			}
		}
		int value = atoi(input.c_str());
		num = value;
		if (value < max && value > min) {
			return true;
		} cout << "\nПомилка. Число не від'ємне\n";
		return false;
		

	}

public:
	ODD() {
		cout << "\nВведіть число: ";
		input();
	}
	ODD(int num) {
		this->num = num;
	}

	bool isNegative(int n) {
		if (abs(n) != n) {
			return true;
		} return false;
	};
	bool isNegativeThis() {
		if (abs(num) != num) {
			return true;
		} return false;
	};

	bool isOdd() {
		return num % 2 != 0;
	}
};
int main() {
	SetConsoleOutputCP(1251);

	ODD  *x = new ODD();

	cout <<(x->isOdd()?"TRUE":"FALSE");

	_getch();
	return 0;
}