#include <iostream>
#include <Windows.h>
#include <conio.h>


using namespace std;

struct Polinom {
	double*allNums;// ����� �����������
	int power;// ������ �������
	void inputPolinom(int power) {	
		this->power = power; //�������� �����
		allNums = new double[power];
		for (int i = power-1; i > 0; i--) {	// ������� ������ �� ����������� ������� �� 1
			cout << "������ ���������� " << i+1 << " �������: ";
			cin >> allNums[i];
		}
		cout << "������ ���������� 1 �������: ";
		cin >> allNums[0];
	}
	double getValueInPoint(double x) {	//������ �������� ������� � �����
		double res=0; //���� ��� ������
		for (int i = 0; i < power; i++) {
			res += allNums[i] * pow(x,i+1);	// ��^i
		}
		return res;
	}
	Polinom operator+(Polinom& b) {		//�������������� ��������� ��������� 
		Polinom x; x.power = this->power;
		x.allNums = new double[this->power];
		for (int i = 0; i < this->power; i++) {
			x.allNums[i] = this->allNums[i] + b.allNums[i];
		}
		return x;
	}
	Polinom operator*(Polinom& b) {	//�������������� ��������� ��������
		Polinom x;
		x.allNums = new double[this->power*b.power];//���������� ������� ����� ���'��
		int newPower=0;
		for (int i = 0; i < this->power; i++) {
			for (int j = 0; j < b.power; j++) {
				x.allNums[newPower++] = this->allNums[i] * b.allNums[j];
			}
		} 
		x.power = newPower;
		return x;
	}
	friend ostream& operator<<(ostream&o, Polinom&p) {
		//�������������� ��������� ����� ���� ��� ������� ������ � �������
		for (int i = p.power-1; i > 0; i--) {// �������� �� ����. � "�" �� �������� 
			o << " " <<p.allNums[i] << "x"<<i+1<<
				((fabs(p.allNums[i - 1])== p.allNums[i - 1])?" + ":" ");//������ + ��� �� ������� ����
		} o << p.allNums[0]<<"x";// � �������..
		return o;
	}
};
int main() {
	SetConsoleOutputCP(1251);

	Polinom a,b;
	int power;
	cout << "������ ������ �������: ";
	cin >> power;
	cout << "������ 1 ������: \n";
	a.inputPolinom(power);
	cout << "������ 2 ������: \n";
	b.inputPolinom(power);

	cout << "a + b =" << a + b<<endl;
	cout << "a * b =" << a * b << endl;
	int x;
	cout<< "������ �: ";
	cin >> x;
	
	cout << "�������� ������� � � ����� "<<x <<" = " << a.getValueInPoint(x);
	_getch();
	return 0;
}