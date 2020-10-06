#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
class Matrix {
private:
	struct MatrixObj {
		int colls;
		int rows;
		vector<vector<int>> obj;
	} matrix;
	bool isMaxtrixSet;
	
public:
	Matrix() { this->isMaxtrixSet = false; };
	void setMatrix(vector<vector<int>> x) {
		matrix.obj = x;
		matrix.colls = x.size();
		matrix.rows = x[0].size();
		isMaxtrixSet = true;
	};
	void setMatrix(int rows, int colls) {
		vector<vector<int>> retVal(colls, vector<int>(rows));
		for (int i = 0; i < colls; i++) {			
			cout << "Рядок " << (i == colls-1 ? "останній" : static_cast<ostringstream*>(&(ostringstream() << i+1))->str())<<":" << endl;
			for (int j = 0; j < rows; j++) {
				cin >> retVal[i][j];
			}
		}
		matrix.obj = retVal;
		matrix.colls = colls;
		matrix.rows = rows;
		isMaxtrixSet = true;
	}
	void printMatrix() {
		if (this->isMaxtrixSet) {
			string str = "\n";
			for (int i = 0; i < matrix.colls; i++) {
				for (int j = 0; j < matrix.rows; j++) {
					stringstream ss;
					ss << matrix.obj[i][j];
					str += ss.str();
					str += " ";
				}
				str += "\n\n";
			}
			cout << str;
		}
		else {
			cout << endl << "Matrix is not set" << endl;
		}
	};
	static vector<vector<int>> getQuadIdentity(int sizeX) {
		vector<vector<int>> retVal(sizeX,vector<int>(sizeX));
		for (int i = 0; i < sizeX; i++) {
			for (int j = 0; j < sizeX; j++) {
				if (i == j) {
					retVal[i][j] = 1;
				}
				else {
					retVal[i][j] = 0;
				}
			}
		}
		return retVal;
	}
	bool isIdentity() {
		if (this->isMaxtrixSet) {
			for (int i = 0; i < matrix.colls; i++) {
				for (int j = 0; j < matrix.rows; j++) {
					if (i == j) {
						if (matrix.obj[i][j] != 1) {
							return false;
						}
					}
					else {
						if (matrix.obj[i][j] != 0) {
							return false;
						}
					}
				}
			}
			return true;
		}
		else {
			cout << endl << "Matrix is not set" << endl;
			return false;
		}
	};
	bool isQuad() {
		return matrix.colls == matrix.rows;
	};
	
	friend Matrix operator +(const Matrix& left,const Matrix& right) {
		vector<vector<int>> r(max( left.matrix.colls,right.matrix.colls), vector<int>(max(left.matrix.rows,right.matrix.rows)));
		for (int i = 0; i < min(left.matrix.colls, right.matrix.colls); i++) {
			for (int j = 0; j <min(left.matrix.rows, right.matrix.rows); j++)
			{
				r[i][j] = left.matrix.obj[i][j] + right.matrix.obj[i][j];
			}
		}
		Matrix x = left; x.matrix.obj = r;
		return x;
	}
	friend Matrix operator *(const Matrix& left, const Matrix& right) {
		Matrix x;
		if (left.matrix.colls == right.matrix.rows) {
			vector<vector<int>> C(max(left.matrix.colls, right.matrix.colls), vector<int>(max(left.matrix.rows, right.matrix.rows)));

			for (int i = 0; i <min(left.matrix.rows, right.matrix.rows); i++)
				for (int j = 0; j < min(left.matrix.colls, right.matrix.colls); j++)
				{
					C[i][j] = 0;
					for (int k = 0; k <min(left.matrix.rows, right.matrix.rows); k++)
						C[i][j] += left.matrix.obj[i][k] * right.matrix.obj[k][j];
				}
			x = left; x.matrix.obj = C;
			return x;
		}
		else {
			cout << "\nПомилка: Кількість стовпців А != кількості рядків В !!!\n";
			x.setMatrix(Matrix::getQuadIdentity(1));
			return x;
		}
	}
		
};

void PrettyPrintQuad(Matrix *x,int id) {
	if (x[id].isQuad()) {
		cout << "-------\nМатриця квадратна" << endl;
	//x.printMatrix();
		cout << "-------\n";
	}
	else {
		cout << "Матриця не квадратна" << endl;
	}
}
void PrettyPrintIndent(Matrix*x, int id){
	if (x[id].isIdentity()) {
		cout << "-------\nМатриця одинична" << endl;
		//x.printMatrix();
		cout << "-------\n";
	}
	else {
		cout << "Матриця не одинична" << endl;
	}
}
void PrettyPrintMatrix(Matrix *x, int id) {
	cout << "-------\nМатриця:" << endl;
	x[id].printMatrix();
	cout << "-------\n";
}
int main()
{
	SetConsoleOutputCP(1251);
	Matrix *x = new Matrix[3];
	x->setMatrix(Matrix::getQuadIdentity(3));

	PrettyPrintMatrix(x,0);
	PrettyPrintQuad(x,0);
	PrettyPrintIndent(x,0);
	int colls, rows;
	cout << "\n\nВведіть кількість стовпців та рядків А:\n";
	cin >> colls>>rows ;
	x[0].setMatrix(colls,rows);
	PrettyPrintMatrix(x, 0);
	PrettyPrintQuad(x, 0);
	PrettyPrintIndent(x, 0);

	cout << "\n\nВведіть кількість стовпців та рядків B:\n";
	cin >> colls >> rows;
	x[1].setMatrix(colls, rows);
	PrettyPrintMatrix(x,1);
	PrettyPrintQuad(x,1);
	PrettyPrintIndent(x,1);

	x[2] = x[0]*x[1];
	cout << "\nМноження А * В:\n";
	PrettyPrintMatrix(x,2);
	PrettyPrintQuad(x,2);
	PrettyPrintIndent(x,2);

	x[2] = x[0]+x[1];
	cout << "\nДодавання А + В:\n";
	PrettyPrintMatrix(x,2);
	PrettyPrintQuad(x,2);
	PrettyPrintIndent(x,2);

	_getch();
	return 0;
}
