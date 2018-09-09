#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

class FileObject {
	FILE *_file;
public:
	FileObject(char* filepath,char* mode) {
		_file = fopen(filepath, mode);
	}
	FileObject(FILE *file) {
		_file = file;
	}
	string ReadAll() {
		if (_file != nullptr) {
			string ret;
			char * buff = new char[256];
			buff[0] = '\0';
			while (buff != nullptr) {
				fgets(buff, 256, _file);
				if (strlen(buff) > 0) { ret += buff; buff[0] = '\0'; }
				else break;
			} if (ret == "") cout << "\nFile is empty\n";
			return ret;
		} 
		return "";
	}
	bool Write(char *content) {
		if (fputs(content, _file) < 0) return false;
		return true;
	}
	void Close() {
		fclose(_file);
	}
	~FileObject() {
		this->Close();
	}
};

int main() {
	SetConsoleOutputCP(1251);

	FileObject *file = new FileObject("./text.txt", "a+");

	cout <<"FILE CONTENT :\n "<<(*file).ReadAll()<<"\nEND\n";

	(*file).Write("sample text to be writen\nnext line\n");
	(*file).Close();

	_getch();
	return 0;
}