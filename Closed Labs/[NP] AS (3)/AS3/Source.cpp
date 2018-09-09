#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
using namespace std;
template <typename T>
class Array {
public:
	vector<T> arr;

	Array() {

	}
	Array& GetData() {
		return *this;
	}

	void Insert(size_t where,T x) {
		arr.insert(arr.begin()+where,x);
	}
	void RemoveAt(int x) {
		for (int i = x; i < arr.size()-1; i++) {
			arr[i] = arr[i + 1];
		}
	}
	T operator[](size_t x){
		return arr.at(x);
	}

friend std::ostream& operator<<(ostream&out, const Array<T>&a) {
		for (int i = 0; i < a.arr.size(); i++) {
			out << a.arr.at(i) << " ";
		}
		return out;
	}

};


int main() {
	SetConsoleOutputCP(1251);

	Array<int> *a = new Array<int>();
	a->Insert(0, 234);
	cout << *a<<endl;
	a->GetData();
	a->Insert(0, 43543); cout << *a<<endl;
	a->Insert(0, 34590); cout << *a<<endl;
	a->Insert(0, 347); cout << *a<<endl;
	a->RemoveAt(2);
	cout << *a << endl;


	_getch();
	return 0;
}