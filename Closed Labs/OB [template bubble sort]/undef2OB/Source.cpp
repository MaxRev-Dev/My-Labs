#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;

//Звичайне сортування "бульбашкою"
template <typename T>
void sortCust(T*a,int  size) {
	for (int i = 0; i <size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (a[j]>a[j + 1])
			{
				T temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

//Визначення для стрічок з методом size()
template <typename T>
void sortCustS(T*a, int  size) {
	for (int i = 0; i <size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (a[j].size()>a[j + 1].size())
			{
				T temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

//Форматований вивід через розділювач endline
template <typename T>
void sortAndPrint(T *arr, int size, char endline) {
	sortCust(arr, size-1);
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endline;
	}cout << endl;
}

//Стрічки виводимо через метод с_str()
template <typename T>
void sortAndPrintS(T *arr, int size, char endline) {
	sortCustS(arr, size - 1);
	for (int i = 0; i < size; i++) {
		cout << arr[i].c_str() << endline;
	}cout << endl;
}

//Визначення виводу для класу XTypePoint
template <typename T>
void sortAndPrintXTP(T *arr, int size) {
	sortCust(arr, size - 1);
	for (int i = 0; i < size; i++) {
		cout <<"Point["<<i+1<<"] "<< arr[i].x<<" " <<arr[i].y<<endl;
	}cout << endl;
}

/*Свій клас який визначає положення
	точки на екрані наприклад
Сортування визначає найбільшу суму координат 
*/
class XTypePoint {
private:
	int x, y;
public:
	template <typename T> friend void sortAndPrintXTP(T *,int);

	XTypePoint(int X,int Y) {
		x = X;
		y = Y;
	}
	// Визначення оператора порівняння
	bool operator>(XTypePoint&rt) {
		return (this->x+this->y)/2 > (rt.x + rt.y)/2;
	}
};


int main() {
	SetConsoleOutputCP(1251);

	int *s = new int[9]{ 13,26,6,4,26,67,8,28,542 };
	sortAndPrint(s, 9, ' ');
	double *s1 = new double[9]{ 1.530,2.35,6.345,4.345,2.457,66.7,8.68,2.678,1.678 };
	sortAndPrint(s1, 9, ' ');
	char *s2 = new char[9]{ 'd','e','g','s','h','o','u','p','t' };
	sortAndPrint(s2, 9, ' ');

	string *s3 = new string[4]{ "xr5","y5jmczer6","z4egerg50","pe56" };
	sortAndPrintS(s3, 4, '\n');

	XTypePoint *pArr = 
		new XTypePoint[5]{
		XTypePoint(7,3),
		XTypePoint(8,9),
		XTypePoint(2,8),
		XTypePoint(9,2),
		XTypePoint(3,1) 
	};
	sortAndPrintXTP(pArr, 5);

	_getch();
	return 0;
}