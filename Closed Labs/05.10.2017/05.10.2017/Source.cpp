#include <iostream>
#include <cstdio>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;
void GetMatrixAtAA(long long **mas, long long **p, int i, int j, int m) {
	long long mI, mJ, nI, nJ;
	nI = 0;
	for (mI = 0; mI<m - 1; mI++) { //check row
		if (mI == i) nI = 1;
		nJ = 0;
		for (mJ = 0; mJ<m - 1; mJ++) {//check coll
			if (mJ == j) nJ = 1;
			p[mI][mJ] = mas[mI + nI][mJ + nJ];
		}
	}
}
long long Determinant(long long **mas, int m) {
	int f,a; long long l, o, r ;
	
	long long **p;
	p = new long long*[m];
	for (f = 0; f<m; f++)
		p[f] = new long long[m];
	l = 0; o = 0;
	r = 1;
	a = m - 1;
	if (m<1) cout << "UNABLE TO COUNT DETERMINANT";
	if (m == 1) {
		o = mas[0][0];
		return(o);
	}
	if (m == 2) {
		o = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
		return(o);
	}
	if (m>2) {
		for (f = 0; f<m; f++) {
			GetMatrixAtAA(mas, p, f, 0, m);
			o = o + r * mas[f][0] * Determinant(p, a);
			r = -r;
		}
	}
	return o;
}

int main() {
	SetConsoleOutputCP(1251);
	string inpath = "E:\\MaxRev\\Desktop\\test.in.txt", 
			outpath = "E:\\MaxRev\\Desktop\\test.out.txt";
	FILE*in,*out;
	fopen_s(&in, inpath.c_str(), "r");
	char* buff = new char[256];	int sizeOfMatrix_NxN = 0;
	long long **matrix = new long long*[20];
	for (int i = 0; i < 20; i++)
	{
		matrix[i] = new long long[20];
	}

	if (in != nullptr) {
		while (true) {
			if (fgets(buff, 256, in) != nullptr) {
				string str = string(buff); int num = 0, n = 1;
				for (size_t i = 0; i < str.size(); i++) {
					if (str.at(i) != ' ' && str.at(i) != '\n') {
						int tmp = atoi(&(str.at(i)));
						matrix[sizeOfMatrix_NxN][num++] = tmp; i++;
					}
				}
				sizeOfMatrix_NxN++; num = 0;
			}
			else break;
		}
	}
	fclose(in);
	for (int i = 0; i < sizeOfMatrix_NxN; i++) {
		for (int j = 0; j < sizeOfMatrix_NxN; j++) {
			cout << matrix[i][j] << " ";
		}cout << endl;
	}
	long long finalize = Determinant(matrix, sizeOfMatrix_NxN);
	cout << "Determinant is: " << finalize;
	fopen_s(&out, outpath.c_str(), "w");
	fputs(to_string(finalize).c_str(), out);
	fclose(out);
	_getch();
	return 0;
}