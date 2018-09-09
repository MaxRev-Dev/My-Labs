#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

class XString {
private:
	char* data;
	int size = 20;
	XString(char* str, int size) {
		data = str;
		this->size = size;
	}
public:
	XString() {
		data = new char[size];
	}
	XString(char* str) {
		data = str; size = 0;
		while (str[size++] != '\0'); size--;
	}
	XString(char a, int count) {
		data = new char[count];

		for (int i = 0; i < count; i++) {
			data[i] = a;
		}data[count] = '\0';
		size = count;
	}
	friend XString* operator +(XString& lft, XString&rhx) {
		int all = lft.size + rhx.size;
		char*tmp = new char[all];
		memcpy_s(tmp, all, lft.data, lft.size);
		tmp[lft.size] = '\0';
		strcat(tmp, rhx.data);
		return new XString(tmp, all);
	}
	XString* operator +=(XString&rhx) {
		if (rhx.data != nullptr) {
			int all = this->size + rhx.size;
			char*tmp = new char[all];
			memcpy_s(tmp, all, this->data, this->size);
			tmp[this->size] = '\0';
			strcat(tmp, rhx.data);
			this->data = tmp;
			this->size = all;

		} return this;
	}
	int Size() {
		return size;
	}
	char*ToString() {
		if (data == nullptr) {
			cout << "\nThis string is empty!\n";
			return "";
		}
		return data;
	}
	void Clear() {
		data = nullptr;
	}
	~XString() {
		delete data;
	}
};

int main() {
	SetConsoleOutputCP(1251);
	XString *str = new XString("sample text");
	XString *str1 = new XString('x', 10);
	str->ToString();
	*str += *str1;
	cout << str->Size() << endl;
	cout << str->ToString() << endl;
	cout << (*str + *str1)->ToString() << endl;
	str->Clear();
	cout << str->ToString();
	_getch();
	return 0;
}
