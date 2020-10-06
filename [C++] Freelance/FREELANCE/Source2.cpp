#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <math.h>

using namespace std;

struct Point
{
	double X, Y;
	Point(int x, int y) //����������� �����
	{
		X = x;
		Y = y;
	}
	Point()
	{//����� ��� ��������� 0
		X = Y = 0;
	}
};

struct Triangle
{
	Point A, B, C; // 3 ����� ����������
	Triangle(const Point& a, const Point& b, const Point& c) //����������� ��� ��������� ����������
	{
		A = a;
		B = b;
		C = c;
	}
	void rotate(double t)
	{
		Point cent = get_center();
		rotatePoint(A, cent, t);
		rotatePoint(B, cent, t);
		rotatePoint(C, cent, t);
	}

	Point get_center()
	{
		Point temp;
		temp.Y = (A.Y + B.Y + C.Y) / 3; //�����
		temp.X = (A.X + B.X + C.X) / 3;
		return temp;
	}
	void scale(double factor) {
		A.X *= factor;
		A.Y *= factor; // �� ��� ������� ������
		B.X *= factor;
		B.Y *= factor;
		C.X *= factor;
		C.Y *= factor;
	}
private: 
	//���������� ����� ����� �� ������ ������ � ����������� ������
	void rotatePoint(Point &point,const Point cent,double deg) {
		point.X = cent.X + (A.X - cent.X)*cos(deg) - (A.Y - cent.Y)*sin(deg);
		point.Y = cent.Y + (A.Y - cent.Y)*cos(deg) + (A.X - cent.X)*sin(deg);
	}
};

int main() {
	SetConsoleOutputCP(1251);
	int x, y, deg;
	cout << "������ ��������� ����� �����: \n";
	cout << "X = ";	cin >> x; cout << "Y = "; cin >> y;
	Point a(x, y);

	cout << "������ ��������� ����� �����: \n";
	cout << "X = ";	cin >> x; cout << "Y = "; cin >> y;
	Point b(x, y);

	cout << "������ ��������� ������ �����: \n";
	cout << "X = ";	cin >> x; cout << "Y = "; cin >> y;
	Point c(x, y);

	Triangle tr(a, b, c);
	Point cn = tr.get_center();
	cout << "�����:  X=" << cn.X <<" Y=" <<cn.Y << endl;
	cout << "��� ��������: ";
	cin >> deg;
	tr.rotate(deg); //�������

	cout << "X1: "<<tr.A.X << " Y1: "<<tr.A.Y<<endl;
	cout << "X2: " << tr.B.X << " Y2: " << tr.B.Y<<endl;
	cout << "X3: " << tr.C.X << " Y3: " << tr.C.Y<<endl;


	cout << "���������� ������������ ~1~: ";
	cin >> deg;//����������� ��� ����� ��� ��������
	tr.scale(deg);//������������

	cout << "X1: " << tr.A.X << " Y1: " << tr.A.Y << endl;
	cout << "X2: " << tr.B.X << " Y2: " << tr.B.Y << endl;
	cout << "X3: " << tr.C.X << " Y3: " << tr.C.Y << endl;

	_getch();
	return 0;
}