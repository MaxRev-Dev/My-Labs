#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

int size; //Глобальна змінна для постійного розміру

class Matrix {
private:
	int **m;	// Матриця 
	Matrix(int x) { // Допоміжний конструктор для створення 
						//готової матриці з одним числом
		m = new int*[::size];
		for (int i = 0; i < ::size; i++) {
			m[i] = new int[::size];
			for (int j = 0; j < ::size; j++) {
				this->m[i][j] = x;
			}
		}
	}
public:
	Matrix() { //Загальний конструктор з генератором випадкових чисел
		m = new int*[::size];
		for (int i = 0; i < ::size; i++) {
			m[i] = new int[::size];
			for (int j = 0; j < ::size; j++) {
				m[i][j] = 1 + rand() % 9;
			}
		}
	}
	friend Matrix& operator*(Matrix&a, Matrix&b) { 
		//Перевантаження оператора множення
		Matrix *r = new Matrix(0);
		for (int i = 0; i < ::size; i++) {
			for (int j = 0; j < ::size; j++) {
				for (int k = 0; k < ::size; k++) {
					r->m[i][j] += a.m[i][k] * b.m[k][j];
				}
			}
		}
		return *r;
	}
	friend Matrix& operator+(Matrix&a, Matrix&b) {
		//Перевантаження оператора додавання
		Matrix *r = new Matrix(0);
		for (int i = 0; i < ::size; i++) {
			for (int j = 0; j < ::size; j++) {
				r->m[i][j] += a.m[i][j] + b.m[i][j];
			}
		}
		return *r;
	}
	bool operator==(Matrix&b) {  // Оператор порівняння
		if (this->m == nullptr) return false; // Якщо матриця то вони не рівні 
		for (int i = 0; i < ::size; i++) {
			for (int j = 0; j < ::size; j++) {
				if (this->m[i][j] != b.m[i][j]) return false;
			}
		}
		return true;
	}
	void ShowMatrix() { //Вивід матриці
		if (m == nullptr) return;
		cout << endl;
		for (int i = 0; i < ::size; i++) {
			for (int j = 0; j < ::size; j++) {
				cout << m[i][j]<<" ";
			}cout << endl;
		}
		cout << endl;
	}
};

bool Distribute(Matrix&a, Matrix&b,Matrix&c) {
	cout << "За законом дистрибутивності:\n\t A*(B+C) == A*C+B*C"<<endl;
	return (a*(b + c)) == (a*b) + (a*c);
}
int main() {
	SetConsoleOutputCP(1251);

	cout << "Введіть розмір матриць: ";
	cin >> ::size; cin.get();

	Matrix *x = new Matrix[3];
	x[0].ShowMatrix(); 
	x[1].ShowMatrix();
	x[2].ShowMatrix();
	cout << "Закон дистрибутивності " <<
		(Distribute(x[0], x[1], x[2])?"виконується":"не виконується");	

	_getch();
	return 0;
}