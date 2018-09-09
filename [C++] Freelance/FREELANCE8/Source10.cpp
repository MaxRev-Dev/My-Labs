#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;
//������� ���������� ������
double Discount(double x, double perc) {
	return x * (100 - perc) / 100.0;
}
void Prog1() {

	cout << "������� ������������������ ����� ����� ������ � ��������� 0" << endl;
	int n, even = 0, odd = 0;
	while (true) { //���� �� �� ������� ����
		cin >> n;
		if (n == 0)break; //����� ������������������
		if (n % 2 == 1) odd++; // ������ �� ������� = 1, ����� ��������
		else even++; //
	}
	cout << "׸����: " << even << "\n" << "��������: " << odd;

	_getch();
}
void Prog2() {

	int N; //���������� ����� 
	cout << "������� ���������� �����: " << endl;
	cin >> N;//������ ���������� �����
	double i;
	double sum_pow_b = 0, sum_pow_a = 0, sum_sqrt_b = 0, sum_sqrt_a = 0;//���������� ���������� 
	while (N > 0) {//������ �����
		cout << "������� �����: ";
		cin >> i;//������ �����
		if (i < 0) {//���� ����� < 0
			sum_pow_b += i;//����� �������� ����� < 0
			sum_pow_a += pow(i, 2);//����� ����� � ��������
		}
		else {//�����
			sum_sqrt_b += i;//����� �������� ����� > 0
			sum_sqrt_a += sqrt(i);//����� ������ �����
		}
		N--;//������� ����������� �� 0
	}
	cout << "����� �������� ����� ";
	if (sum_sqrt_b + sum_pow_b > sum_pow_a + sum_sqrt_a) //���������� ����� �������� ����� � ���������� �����
		cout << "������";
	else
		cout << "������";
	cout << " ��� ����� ���������� �����";
	_getch();
}
void Prog3() {
	double xmin = 1,
		xmax = 2,
		ymin = 2,
		ymax = 5,
		q1 = 0.2,
		q2 = 0.5,
		b = -0.5;

	cout << setw(3) << setfill('-') << "X" << setw(8) << "Y" << setw(8) << "Z" << endl;
	for (double x = xmin; x <= xmax; x += q1) {
		for (double y = ymin; y <= ymax; y += q2) {
			double z = pow(x, -sqrt(y))*tan(x*b + 1.7);
			cout << setfill(' ') << setw(3) << x
				<< setw(3) << "|"
				<< setw(5) << y
				<< setw(3) << "|"
				<< setprecision(4) << z << endl;
		}
	}

	_getch();
}

int main() {
	SetConsoleOutputCP(1251);
	int choise = -1;
	cout << "�������� ��������:";
	cout << "[0] - ���10 - ������ �� �����"<<endl;
	cout << "[1] - ���7" << endl;
	cout << "[2] - ���8" << endl;
	cout << "[3] - ���9" << endl;
	cin >> choise;
	switch (choise) { //��������� ����
	case 0: {
		break; 
	}
	case 1: {
		Prog1(); 
		return 0; // ������ ����� �� ��������
	}
	case 2: {
		Prog2();
		return 0;
	}
	case 3: {
		Prog3();
		return 0;
	}
	default:break;
	}

	double discount, price;
	cout << "������� ��������� ������: ";
	cin >> price;
	cout << "������� ������ ������ %: ";
	cin >> discount;
	price = Discount(price, discount);
	cout << "���� �� ����� ����� 1 ������: " << setprecision(2) << fixed << price << endl;
	cout << "������� ������ ������ %: ";
	cin >> discount;
	price = Discount(price, discount);
	cout << "���� �� ����� ����� 2 ������: " << price;
	_getch();
	return 0;
}