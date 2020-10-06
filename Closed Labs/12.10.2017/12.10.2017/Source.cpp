#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

class NegativeInt {
	

	bool input() {
		char *buff = new char[256];
		cin.getline(buff, 256);
		string input(buff);
		if (input == "") return false;
		for each (char var in input)
		{
			if (!isdigit(var) && var != '-')
			{
				cout << "\nПомилка. Число не ціле від'ємне\n";
				return false;
			}
		}
		int value = atoi(input.c_str());
		num = value;
		
		if (value < 0 && value > MININT32) {
			return true;
		} cout << "\nПомилка. Число не від'ємне\n";
		return false;
	}

int num;
public:
	int GetNum() {
		return num;
	}
	NegativeInt() {
		cout << "\nВведіть число: ";
		while (true) if (input()) break;
	}
	NegativeInt(int num) {
		if (isNegative(num))this->num = num;
		else
			cout << "\nЧисло змінено на протилежне: ";
			this->num = -num;
			cout <<" "<< this->num;
	}
	static bool isNegative(int n) {
		if (abs(n) != n) {
			return true;
		} return false;
	};
	bool isNegativeThis() {
		if (abs(num) != num) {
			return true;
		} return false;
	};

};
template <typename T, typename T2>
void PrettyPrint(T f1, T2 f2) {
	cout << "Число "<<(f2 ? "" : "не ") << "від'ємне: " << "[" << f1 << "]" << (f2 ? "TRUE" : "FALSE") << endl<<endl;
}
int main() {
	SetConsoleOutputCP(1251);

	NegativeInt  *x = new NegativeInt();
	
	PrettyPrint(x->GetNum(), x->isNegativeThis());


	cout << endl << "Other tests.." << endl;
	PrettyPrint(20,NegativeInt::isNegative(20));
	PrettyPrint(-20, NegativeInt::isNegative(-20));

	x = new  NegativeInt(20);
	cout << " "<<(x->isNegativeThis() ? "TRUE" : "FALSE") << endl;

	_getch();
	return 0;
}