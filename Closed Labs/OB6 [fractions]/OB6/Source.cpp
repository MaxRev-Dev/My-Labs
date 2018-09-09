#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <algorithm>

using namespace std;
class Fractions {
private:
	/*Рахуємо НСД(greatest common divisor) за алгоритмом Евкліда
	(обидва аргументи мають бути додатні)*/
	long long gcd(long long a, long long b) {
		while (a != b) {
			if (a > b) {
				a -= b;
			}
			else {
				b -= a;
			}
		}
		return a;
	}
public:
	long long numerator, denominator;

	Fractions() { //випадковий дріб
		numerator = 0 + rand() % 10;
		denominator = 1 + rand() % 10;
	}

	/*Fractions() {
		numerator = 0;
		denominator = 1;
	}*/

	Fractions(long long n, long long d) {
		if (d == 0) {
			cerr << "Знаменник не може бути 0" << endl;
			exit(0);
		}
		else if (n == 0) {
			numerator = 0;
			denominator = 1;
		}
		else {
			int sign = 1;
			if (n < 0) {
				sign *= -1;
				n *= -1;
			}
			if (d < 0) {
				sign *= -1;
				d *= -1;
			}

			long long tmp = gcd(n, d);
			numerator = n / tmp*sign;
			denominator = d / tmp;
		}
	}

	//зміна типу
	operator int() { return (static_cast<int>((numerator) / denominator)); }
	operator float() { return ((float)numerator) / denominator; }
	operator double() { return ((double)numerator) / denominator; }
};

/*Перевантаження майже всіх загальних операторів*/
#pragma region OperatorOverloads
/*Перевантаження оператора додавання*/
Fractions operator+(const Fractions& lhs, const Fractions& rhs) {
	return *(new Fractions(lhs.numerator*rhs.denominator
		+ rhs.numerator*lhs.denominator,
		lhs.denominator*rhs.denominator));
}
/*Перевантаження оператора додавання з присвоєнням*/
Fractions operator+=(Fractions& lhs, const Fractions& rhs) {
	return lhs = *(new Fractions(lhs.numerator*rhs.denominator
		+ rhs.numerator*lhs.denominator,
		lhs.denominator*rhs.denominator));
}
/*Перевантаження оператора віднімання*/
Fractions operator-(const Fractions& lhs, const Fractions& rhs) {
	return *(new Fractions(lhs.numerator*rhs.denominator
		- rhs.numerator*lhs.denominator,
		lhs.denominator*rhs.denominator));
}
/*Перевантаження оператора віднімання з присвоєнням */
Fractions operator-=(Fractions& lhs, const Fractions& rhs) {
	return lhs = *(new Fractions(lhs.numerator*rhs.denominator
		- rhs.numerator*lhs.denominator,
		lhs.denominator*rhs.denominator));
}
/*Перевантаження оператора множення*/
Fractions operator*(const Fractions& lhs, const Fractions& rhs) {
	return *(new Fractions(lhs.numerator*rhs.numerator,
		lhs.denominator*rhs.denominator));
}
/*Перевантаження оператора множення з присвоєнням*/
Fractions operator*=(Fractions& lhs, const Fractions& rhs) {
	return lhs = *(new Fractions(lhs.numerator*rhs.numerator,
		lhs.denominator*rhs.denominator));
}
/*Перевантаження оператора множення цілого числа на дріб*/
Fractions operator*(int lhs, const Fractions& rhs) {
	return *(new Fractions(lhs*rhs.numerator, rhs.denominator));
}
/*Перевантаження оператора множення дробу на ціле число*/
Fractions operator*(const Fractions& rhs, int lhs) {
	return *(new Fractions(lhs*rhs.numerator, rhs.denominator));
}
/*Перевантаження оператора ділення*/
Fractions operator/(const Fractions& lhs, const Fractions& rhs) {
	return *(new Fractions(lhs.numerator*rhs.denominator,
		lhs.denominator*rhs.numerator));
}
/*Перевантаження оператора для поміщення
об'єкту в потік через форматований ввід*/
std::ostream& operator<<(std::ostream &strm, const Fractions &a) {
	return (a.denominator == 1) ? strm << a.numerator :
		strm << a.numerator << "/" << a.denominator;

}
#pragma endregion

/*Допоміжна функція для ініціалізації масиву об'єктів дробів*/
Fractions GetFraction(string x) {
	string str, n = "", d = "";
	cout << x;
	getline(cin, str); int i = 0;
	while (true) {
		if (!str[i] || str[i] == '/' || str[i] == '\\' || str[i] == '|')break;
		n += str[i];
		i++;
	}
	if (strchr(str.c_str(), '/') != nullptr ||
		strchr(str.c_str(), '\\') != nullptr ||
		strchr(str.c_str(), '|') != nullptr) while (str[++i])d += str[i]; else d = "1";
	return Fractions(atoll(n.c_str()), atoll(d.c_str()));
}

int main() {
	SetConsoleOutputCP(1251);

	Fractions *n = new Fractions[2];
	cout << "Випадкові дроби: \n";
	cout << "1) = " << n[0] << " \n2) = " << n[1] << endl << endl;
	cout << n[0] << " - " << n[1] << " = " << n[0] - n[1] << endl;
	cout << n[0] << " + " << n[1] << " = " << n[0] + n[1] << endl;
	cout << n[0] << " * " << n[1] << " = " << n[0] * n[1] << endl;
	cout << n[0] << " / " << n[1] << " = " << n[0] / n[1] << endl;
	delete n; // збираємо непотріб
	while (true) { // для повторного введення
		n = new Fractions[2]{
			GetFraction("Введіть перший дріб у форматі XX/YY або ціле число:"),
			GetFraction("Введіть другий дріб у форматі XX/YY або ціле число:") // ініцілізуємо динам. масив через функцію
		}; 
		//Обробка операції		
		cout << "Виконати операцію [ * , / , + , - ] : ";
		char buff; cin >> buff;	cin.get(); // flush buffer
		switch (buff) {
			case '*': {
				cout << n[0] << " * " << n[1] << " = " << n[0] * n[1] << endl;
				break;
			}
			case '/': {
				cout << n[0] << " / " << n[1] << " = " << n[0] / n[1] << endl;
				break;
			}
			case '+': {
				cout << n[0] << " + " << n[1] << " = " << n[0] + n[1] << endl;
				break;
			}
			case '-': {
				cout << n[0] << " - " << n[1] << " = " << n[0] - n[1] << endl;
				break;
			}
			default:
				break;
		}
		_getch();
	}
	return 0;
}