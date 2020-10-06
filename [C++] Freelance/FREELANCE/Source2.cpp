#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <math.h>

using namespace std;

struct Point
{
	double X, Y;
	Point(int x, int y) //РєРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ С‚РѕС‡РєРё
	{
		X = x;
		Y = y;
	}
	Point()
	{//С‚РѕС‡РєР° Р±РµР· РїР°СЂР°РјРµС‚СЂС–РІ 0
		X = Y = 0;
	}
};

struct Triangle
{
	Point A, B, C; // 3 С‚РѕС‡РєРё С‚СЂРёРєСѓС‚РЅРёРєР°
	Triangle(const Point& a, const Point& b, const Point& c) //РєРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ РґР»СЏ СЃС‚РІРѕСЂРµРЅРЅСЏ С‚СЂРёРєСѓС‚РЅРёРєР°
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
		temp.Y = (A.Y + B.Y + C.Y) / 3; //С†РµРЅС‚СЂ
		temp.X = (A.X + B.X + C.X) / 3;
		return temp;
	}
	void scale(double factor) {
		A.X *= factor;
		A.Y *= factor; // РЅСѓ С‚СѓС‚ РјРЅРѕР¶РёРјРѕ РїСЂРѕСЃС‚Рѕ
		B.X *= factor;
		B.Y *= factor;
		C.X *= factor;
		C.Y *= factor;
	}
private: 
	//Р РѕР·РІРµСЂС‚Р°С”РјРѕ РєРѕР¶РЅСѓ С‚РѕС‡РєСѓ РЅР° РґРµСЏРєРёР№ РіСЂР°РґСѓСЃ Р· СѓСЂР°С…СѓРІР°РЅРЅСЏРј С†РµРЅС‚СЂСѓ
	void rotatePoint(Point &point,const Point cent,double deg) {
		point.X = cent.X + (A.X - cent.X)*cos(deg) - (A.Y - cent.Y)*sin(deg);
		point.Y = cent.Y + (A.Y - cent.Y)*cos(deg) + (A.X - cent.X)*sin(deg);
	}
};

int main() {
	SetConsoleOutputCP(1251);
	int x, y, deg;
	cout << "Р’РІРµРґС–С‚СЊ РєРѕСЂРґРёРЅР°С‚Рё РїРµСЂС€РѕС— С‚РѕС‡РєРё: \n";
	cout << "X = ";	cin >> x; cout << "Y = "; cin >> y;
	Point a(x, y);

	cout << "Р’РІРµРґС–С‚СЊ РєРѕСЂРґРёРЅР°С‚Рё РґСЂСѓРіРѕС— С‚РѕС‡РєРё: \n";
	cout << "X = ";	cin >> x; cout << "Y = "; cin >> y;
	Point b(x, y);

	cout << "Р’РІРµРґС–С‚СЊ РєРѕСЂРґРёРЅР°С‚Рё С‚СЂРµС‚СЊРѕС— С‚РѕС‡РєРё: \n";
	cout << "X = ";	cin >> x; cout << "Y = "; cin >> y;
	Point c(x, y);

	Triangle tr(a, b, c);
	Point cn = tr.get_center();
	cout << "Р¦РµРЅС‚СЂ:  X=" << cn.X <<" Y=" <<cn.Y << endl;
	cout << "РљСѓС‚ РїРѕРІРѕСЂРѕС‚Сѓ: ";
	cin >> deg;
	tr.rotate(deg); //РїРѕРІРѕСЂРѕС‚

	cout << "X1: "<<tr.A.X << " Y1: "<<tr.A.Y<<endl;
	cout << "X2: " << tr.B.X << " Y2: " << tr.B.Y<<endl;
	cout << "X3: " << tr.C.X << " Y3: " << tr.C.Y<<endl;


	cout << "РљРѕРµС„С–С†С–С”РЅС‚ РјР°С€С‚Р°Р±СѓРІР°РЅРЅСЏ ~1~: ";
	cin >> deg;//РІРёРєРѕСЂРёСЃС‚Р°РЅР° С‚Р°Р¶ Р·РјС–РЅРЅР° РґР»СЏ РІРІРµРґРµРЅРЅСЏ
	tr.scale(deg);//РјР°С€С‚Р°Р±СѓРІР°РЅРЅСЏ

	cout << "X1: " << tr.A.X << " Y1: " << tr.A.Y << endl;
	cout << "X2: " << tr.B.X << " Y2: " << tr.B.Y << endl;
	cout << "X3: " << tr.C.X << " Y3: " << tr.C.Y << endl;

	_getch();
	return 0;
}