#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <math.h>

using namespace std;

struct Polinom { //������������� ��� ������������ ��������
	double*allNums;// ����� �����������
	int power;
	int c;// ������ ������� + �

	void inputPolinom(int powerX) {
		this->power = powerX; //�������� �����
		allNums = new double[this->power];
		for (int i = this->power - 1; i > 0; i--) {	// ������� ������ �� ����������� ������� �� 1
			cout << "������ ���������� " << i + 1 << " �������: ";
			cin >> allNums[i];
		}
		cout << "������ ���������� 1 �������: ";
		cin >> allNums[0];
		cout << "������ �(������ ����): ";
		cin >> this->c;
	}
	double getValueInPoint(double x) {	//������ �������� ������� � �����
		double res = 0; //���� ��� ������
		for (int i = 0; i < this->power; i++) {
			res += allNums[i] * pow(x, i + 1);	// ��^i
		}
		return res;
	}
	static Polinom powerTo(Polinom a,int powerSt) {		
		if (powerSt == 1)
			return a;
		return powerTo(a*a,powerSt-1);
	}

	Polinom operator*(Polinom& b) {	//�������������� ��������� ��������
		Polinom x;
		x.allNums = new double[this->power*b.power+b.power];//���������� ������� ����� ���'��
		int newPower = 0;
		for (int i = 0; i < this->power; i++) {
			for (int j = 0; j < b.power; j++) {
				x.allNums[newPower++] = this->allNums[i] * b.allNums[j];
			}
		}
		for (int j = 0; j < b.power; j++) {
			x.allNums[newPower++] = c * b.allNums[j];
		}
		x.power = newPower; x.c = this->c*b.c;
		return x;
	}
};
ostream& operator<<(ostream&o, Polinom&p) {
	//�������������� ��������� ����� ���� ��� ������� ������ � �������
	for (int i = p.power - 1; i > 0; i--) {// �������� �� ����. � "�" �� �������� 
		o << " " << p.allNums[i] << "x" << i + 1 <<
			((fabs(p.allNums[i - 1]) == p.allNums[i - 1]) ? " + " : " ");//������ + ��� �� ������� ����
	} o << p.allNums[0] << "x" << ((abs(p.c) == p.c) ? " + " : " ") << p.c << endl;// � ������..
	return o;
}
int main() {
	SetConsoleOutputCP(1251);

	Polinom a, b;
	int power;
	cout << "������ ������: \n";
	a.inputPolinom(2);
	cout << "������ ������: \n";
	cin>> power;
	Polinom p = Polinom::powerTo(a, power);
	cout << p; // ������������� �������� ������� ��� ��������� ������ ��'����
	_getch();
	return 0;
}