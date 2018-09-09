#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <algorithm>

using namespace std;
class Fractions {
private:
	/*������ ���(greatest common divisor) �� ���������� ������
	(������ ��������� ����� ���� ������)*/
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

	Fractions() { //���������� ���
		numerator = 0 + rand() % 10;
		denominator = 1 + rand() % 10;
	}

	/*Fractions() {
		numerator = 0;
		denominator = 1;
	}*/

	Fractions(long long n, long long d) {
		if (d == 0) {
			cerr << "��������� �� ���� ���� 0" << endl;
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

	//���� ����
	operator int() { return (static_cast<int>((numerator) / denominator)); }
	operator float() { return ((float)numerator) / denominator; }
	operator double() { return ((double)numerator) / denominator; }
};

/*�������������� ����� ��� ��������� ���������*/
#pragma region OperatorOverloads
/*�������������� ��������� ���������*/
Fractions operator+(const Fractions& lhs, const Fractions& rhs) {
	return *(new Fractions(lhs.numerator*rhs.denominator
		+ rhs.numerator*lhs.denominator,
		lhs.denominator*rhs.denominator));
}
/*�������������� ��������� ��������� � ����������*/
Fractions operator+=(Fractions& lhs, const Fractions& rhs) {
	return lhs = *(new Fractions(lhs.numerator*rhs.denominator
		+ rhs.numerator*lhs.denominator,
		lhs.denominator*rhs.denominator));
}
/*�������������� ��������� ��������*/
Fractions operator-(const Fractions& lhs, const Fractions& rhs) {
	return *(new Fractions(lhs.numerator*rhs.denominator
		- rhs.numerator*lhs.denominator,
		lhs.denominator*rhs.denominator));
}
/*�������������� ��������� �������� � ���������� */
Fractions operator-=(Fractions& lhs, const Fractions& rhs) {
	return lhs = *(new Fractions(lhs.numerator*rhs.denominator
		- rhs.numerator*lhs.denominator,
		lhs.denominator*rhs.denominator));
}
/*�������������� ��������� ��������*/
Fractions operator*(const Fractions& lhs, const Fractions& rhs) {
	return *(new Fractions(lhs.numerator*rhs.numerator,
		lhs.denominator*rhs.denominator));
}
/*�������������� ��������� �������� � ����������*/
Fractions operator*=(Fractions& lhs, const Fractions& rhs) {
	return lhs = *(new Fractions(lhs.numerator*rhs.numerator,
		lhs.denominator*rhs.denominator));
}
/*�������������� ��������� �������� ������ ����� �� ���*/
Fractions operator*(int lhs, const Fractions& rhs) {
	return *(new Fractions(lhs*rhs.numerator, rhs.denominator));
}
/*�������������� ��������� �������� ����� �� ���� �����*/
Fractions operator*(const Fractions& rhs, int lhs) {
	return *(new Fractions(lhs*rhs.numerator, rhs.denominator));
}
/*�������������� ��������� ������*/
Fractions operator/(const Fractions& lhs, const Fractions& rhs) {
	return *(new Fractions(lhs.numerator*rhs.denominator,
		lhs.denominator*rhs.numerator));
}
/*�������������� ��������� ��� ��������
��'���� � ���� ����� ������������ ���*/
std::ostream& operator<<(std::ostream &strm, const Fractions &a) {
	return (a.denominator == 1) ? strm << a.numerator :
		strm << a.numerator << "/" << a.denominator;

}
#pragma endregion

/*�������� ������� ��� ����������� ������ ��'���� �����*/
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
	cout << "�������� �����: \n";
	cout << "1) = " << n[0] << " \n2) = " << n[1] << endl << endl;
	cout << n[0] << " - " << n[1] << " = " << n[0] - n[1] << endl;
	cout << n[0] << " + " << n[1] << " = " << n[0] + n[1] << endl;
	cout << n[0] << " * " << n[1] << " = " << n[0] * n[1] << endl;
	cout << n[0] << " / " << n[1] << " = " << n[0] / n[1] << endl;
	delete n; // ������� �������
	while (true) { // ��� ���������� ��������
		n = new Fractions[2]{
			GetFraction("������ ������ ��� � ������ XX/YY ��� ���� �����:"),
			GetFraction("������ ������ ��� � ������ XX/YY ��� ���� �����:") // ��������� �����. ����� ����� �������
		}; 
		//������� ��������		
		cout << "�������� �������� [ * , / , + , - ] : ";
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