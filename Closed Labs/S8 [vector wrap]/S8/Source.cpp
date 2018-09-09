#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>

using namespace std;
struct Item {
	int x, y;
	string name;
	friend ostream& operator<<(ostream&o,Item&x) {
		return o << x.name.c_str()<< " x:" << x.x << " y:" << x.y << endl;
	}
};
template <typename T>
class MBase {
	vector<T> *base;
public:
	MBase() {
		base = new vector<T>();
	}
	void Add(T x) {
		base->push_back(x);
	}
	void RemoveAt(int pos) {
		base->erase(base->begin() + pos);
	}
	void Insert(int pos, T x) {
		base->insert(base->begin() + pos, x);
	}
	friend ostream&  operator<<(ostream&o,const  MBase<T> &x) {
		for (auto it = x.base->begin(); it != x.base->end(); it++) {
			o<< *it;
		} return o;
	}
};
int main() {
	SetConsoleOutputCP(1251);
	MBase<int> *bx = new MBase<int>();
	bx->Add(1);
	cout << *bx << endl;
	bx->Add(2);
	cout << *bx << endl;
	bx->Insert(0, 0);
	bx->RemoveAt(1);
	cout << *bx << endl;

	MBase<Item> *bxs = new MBase<Item>();
	Item f;
	f.name = "NameX";
	f.x = 20;
	f.y = 40;
	bxs->Add(f);
	cout << *bxs;
	_getch();
	return 0;
}

