#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

class Repeater {
	ifstream ifs;
public:
	void OpenFile(string name) {
		ifs.open(name, ios::in);
	}
	friend void operator<<(ofstream &s2, Repeater &s) {
		while (!s.ifs.eof()) {
			string so;
			getline(s.ifs, so);
			 s2 << so<<endl;
		}
	}
	~Repeater() {
		ifs.close();
	}
};
int main() {
	SetConsoleOutputCP(1251);
	ofstream out("test_in.txt", ios::out);
	out << "sample text\nendof sample text";
	out.close();
	Repeater * rp = new Repeater();
	rp->OpenFile("test_in.txt");
	
	ofstream ofs("test_out.txt", ios::out);
	ofs << *rp;

	delete rp;
	_getch();

	return 0;
}
