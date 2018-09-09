#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <stack>
using namespace std;
template<typename T>
ostream& operator<<(ostream&o, stack<T>xs) {
	stack<T> s = xs; cout << "stack: ";
	while(!s.empty()){
	 o << s.top()<<" "; s.pop(); 
	}return o;
}
int main() {
	SetConsoleOutputCP(1251);

	stack<int> *s = new stack<int>();
	for (int i = 0; i < 30; i++) {
		s->push(i);
	}cout << endl;
	cout << *s<<endl;
	for (int i = 0; i < 15; i++) {
		s->pop();
	}
	cout << *s;
	_getch();
	return 0;
}
