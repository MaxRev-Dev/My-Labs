#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>

using namespace std;
class FileObj {
private:
	FILE * pFile;
	fpos_t pos;
public :
	FileObj(const char* name,const char*mode) {
		pFile = fopen(name,mode);
	}
	void WriteToFile(string content) {
		fgetpos(pFile, &pos);
		fputs(content.c_str(), pFile); return;
	if (pFile == NULL)fputs("\nError writing to file\n", stdout);
		//fflush(pFile);
	}
	void ReadFromFile() {
		char *buffer = new char[100];
		if (pFile == NULL) perror("Error opening file");
		else
		{
			fsetpos(pFile,0);
			while (!feof(pFile))
			{
				if (fgets (buffer, 100, pFile) == NULL) break;
				fputs(buffer, stdout);
			}
			fclose(pFile);
		}
	}
	void Close() {
		fclose(pFile);
	}
	~FileObj() {
		this->Close();
	}
};
int main() {
	SetConsoleOutputCP(1251);

	FileObj *file = new FileObj("./test.txt","w+");
	file->WriteToFile("SAMPLE content\n\n\nEnd of content");
	file->Close();
	delete file;
	file = new FileObj("./test.txt","r");
	file->ReadFromFile();
	_getch();
	return 0;
}
