#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include "BinaryTree.h"

using namespace std;
void gen_random(char *s, const int len) {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i) {
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	s[len] = 0;
}
int main(int argc, char **argv) {
	SetConsoleOutputCP(1251);
	while (true) {
		char *buff = new char[500];
		int nparam, toFind = 12345, toFind2 = 54321;//Values for search
		string strparam;
		cout << "Enter data: \nNumber XXXX and line as offences";
		cout << "\nNumber >> "; cin >> nparam; cin.get(); 
		cout << "\nOffences [500 symbols max]>> "; cin.getline(buff, 500);
		cout << "\n\nADDING MORE RANDOM DATA\n";
		BinaryTree *tree = new BinaryTree();
		tree->root = newTreeNode(1000 + rand() % 8999, "FIRST");
		insertTreeNode(tree->root, nparam, buff);
		for (int i = 0; i < 40; i++) {
			gen_random(buff, 30); //Genarating random offences)
			if (i == 4) {
				insertTreeNode(tree->root, toFind, buff);
			}
			else if (i == 5)
			{
				insertTreeNode(tree->root, 54321, buff);
			}
			else {
				insertTreeNode(tree->root, 1000 + rand() % 8999, buff);
			}
		}
		cout << "\n\nAll data:\n";
		tree->printTreeInOrder(tree->root);
		cout << "\nENDOF All data\n\n";
		tree->FindAndPrintNode(tree->root, toFind);//Searching first number
		tree->FindAndPrintNode(tree->root, toFind2);//and second
		tree->FindAndPrintNode(tree->root, 0000000); // AND Default (notfound)

		while (true) {
			int sparam;
			cout << "\nEnter number to search: ";
			cin >> sparam;
			cin.get();

			tree->FindAndPrintNode(tree->root, sparam);
			buff = new char[20];
			cout << "\nSearch more?? [y/n] >> ";

			cin.getline(buff, 20);
			string inp(buff);
			if (inp == "yes" || inp == "YES" || inp == "Y" || inp == "y") continue;
			else break;
		}

		cout << "Start over?? [y/n] >> ";
		buff = new char[20];
		cin.getline(buff, 20);
		string inp(buff);
		if (inp == "yes" || inp == "YES" || inp == "Y" || inp == "y") {
			cout << endl << endl;
			continue;
		} break;
	}
	return 0;
}

