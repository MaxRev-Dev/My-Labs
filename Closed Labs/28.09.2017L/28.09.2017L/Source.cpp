#include <iostream>
#include <iterator>
#include <fstream>
#include <conio.h>
#include <Windows.h>
using namespace std;

template <typename T>
struct Node {
	Node *Next, *Prev;
	T Data;
};
template <typename T>
class List
{
	Node *Head, *Tail;
	Node *Next, *Prev;
public:
	List() :Head(NULL), Tail(NULL) {};
	~List();
	void Show();
	void DeleteAt(T);
	void IsEmpty();
	void Add(T);
	void SaveAsFile(string path);
};

template <typename T>
List::~List()
{
	while (Head)
	{
		Tail = Head->Next;
		delete Head;
		Head = Tail;
	}
}
template <typename T>
void List::DeleteAt(T i)
{
	int iter = 0;
	Node *temp = Head;

	while (true)
	{
		temp = temp->Next;
		if (iter++ == i - 1)break;
	}
	Node *prev = temp->Prev;
	Node *next = temp->Next;
	prev->Next = temp->Next;
	next->Prev = temp->Prev;
	temp = NULL;

}
template <typename T>
inline void List::IsEmpty()
{
	if (Head == NULL)
		cout << "List is Empty" << endl;
	else cout << "List is NOT empty" << endl;

}
template <typename T>
void List::Add(T x)
{
	Node *temp = new Node;
	temp->Next = NULL;
	temp->Data = x;

	if (Head != NULL)
	{
		temp->Prev = Tail;
		Tail->Next = temp;
		Tail = temp;
	}
	else
	{
		temp->Prev = NULL;
		Head = Tail = temp;
	}
}
template <typename T>
inline void List::SaveAsFile(string path)
{
	ofstream of(path, ios_base::trunc);

	Node *temp = Tail;

	while (temp != NULL)
	{
		of << temp->Data << " ";
		temp = temp->Prev;
	}
	of.close();
}
template <typename T>
void List::Show()
{
	Node *temp = Tail;

	while (temp != NULL)
	{
		cout << temp->Data << " ";
		temp = temp->Prev;
	}
	cout << "\n";


	temp = Head;
	while (temp != NULL)
	{
		cout << temp->Data << " ";
		temp = temp->Next;
	}
	cout << "\n";
}
int main()
{
	SetConsoleOutputCP(1251);
	List<int> lst;
	for (int i = 0; i < 100; i += 10) {
		lst.Add(i);
	}
	lst.Show();
	lst.DeleteAt(4);
	lst.Show();
	lst.SaveAsFile("D:\\MaxRev\\Desktop\\1.txt");
	_getch();
	return 0;
}