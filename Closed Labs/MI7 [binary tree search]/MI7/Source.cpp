#include "BinaryTree.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
char* gen_random(bool withAlfa, const int len) {
	char* alphanum = ((!withAlfa) ?
		"0123456789" : "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	char* s = new char[len];
	for (int i = 0; i < len; ++i) {
		s[i] = alphanum[rand() % (strlen(alphanum) - 1)];
	}
	s[len] = 0;
	return s;
}
int main() {
	SetConsoleOutputCP(1251);

	BinaryTree *t = new BinaryTree();
	Item *item = new Item;
	item->id = 1;
	item->name = gen_random(true, 20);
	item->tel = gen_random(false, 10);
	t->root = newTreeNode(*item);
	for (int i = 2; i < 50; i++) {
		Item *item = new Item;
		item->id = i;
		item->name = gen_random(true, 20);
		item->tel = gen_random(false, 10);
		t->root = insertTreeNode(t->root, *item);
		delete item;
	}
	cout << "Згенерованна база: \n";
	t->printTreeInOrder(t->root);

	cout << "Введіть номер запису для пошуку: ";
	string str; getline(cin, str);
	int x = atoi(str.c_str());
	t->FindAndPrintNode(t->root, x);
	cout << "Введіть номер запису для редагування: ";
	cin >> x; cin.get();
	Tree * s = t->lookUp(t->root, --x);
	if (s == NULL) {
		cout << "Не знайдено такого" << endl;
	}
	else {
		cout << "Введіть ім'я: "; getline(cin, s->data.name);
		cout << "Введіть телефон: "; getline(cin, s->data.tel);
	}
	t->printTreePreOrder(t->root);
	_getch();
	return 0;
}