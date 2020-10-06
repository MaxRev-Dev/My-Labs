#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

class Even {
	int eve;
public:
	Even(int x) {
		eve = x;
	}

	static Even* SetValue(int x) {
		if (x % 2 != 0) {
			return nullptr;
		}
		return new Even(x);
	}
	int operator/(const Even& rhs)
	{
		return this->eve / rhs.eve;
	}
	
	Even& operator*(const Even& rhs)
	{
		return *(new Even(this->eve * rhs.eve));
	}
	Even& operator+(const Even& rhs)
	{
		return *(new Even(this->eve + rhs.eve));
	}

	Even& operator-(const Even& rhs)
	{
		return *(new Even(this->eve-rhs.eve));
	}
	friend ostream& operator<<(ostream&o, Even&s) {
		return o << s.eve;
	}
};
Even* SetNum() {
	int x;
	cin >> x;
	Even*n = Even::SetValue(x);
	if (n != nullptr) {
		cout << "Число встановленно" << endl; 
		return n;
	} cout << "Число не можливо встановити об'єкту парних чисел" << endl;
	return SetNum();
}
int main() {
	SetConsoleOutputCP(1251);
	
	Even *x= SetNum();
	cout <<"x + x = " <<*x + *x << endl;
	cout << "x / x = " << *x / *x << endl;
	cout << "x - x = " << *x - *x << endl;
	cout << "x * x = " << *x * *x << endl;
	_getch();
	return 0;
}
