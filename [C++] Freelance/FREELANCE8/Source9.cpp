#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <math.h>
using namespace std;

int main() {
	SetConsoleOutputCP(1251);

	double xmin = 1,
		xmax = 2,
		ymin = 2,
		ymax = 5,
		q1 = 0.2,
		q2 = 0.5,
		b = -0.5;

	cout << setw(3) << setfill('-') << "X" << setw(8) << "Y" <<setw(8)<< "Z"<<endl;
	for (double x = xmin; x <= xmax; x += q1) {
		for (double y = ymin; y <= ymax; y += q2) {
			double z = pow(x, -sqrt(y))*tan(x*b + 1.7);
			cout << setfill(' ')<< setw(3) << x 
				<< setw(3) << "|"
				<< setw(5) << y 
				<< setw(3) << "|"
				<< setprecision(4) <<z << endl;
		}
	}

	_getch();
	return 0;
}