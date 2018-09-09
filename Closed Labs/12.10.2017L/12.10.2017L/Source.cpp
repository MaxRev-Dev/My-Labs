#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

template <typename T>
struct Node {
	Node *Next, *Prev;
	int Data;
	T val;
	Node(const T& t = T()) : val(t) {}
};
template <typename T>
struct node_iter {
	Node<T>& current;
	node_iter(Node<T>* current) : current(current) {}

	const node_iter& operator++() { current = current->next; return *this; }
	node_iter operator++(int) {
		node_iter result = this->current->Next; return result;
	}
	T& operator*() { return current->Data; }
};

class List : public std::iterator<bidirectional_iterator_tag,int>
{
	Node<int> *Head, *Tail;
	Node<int> *Next, *Prev;
	
public:
	List() :Head(NULL), Tail(NULL) {};
	~List();
	void Show();
	void DeleteAt(int);
	void IsEmpty();
	void Add(int);
	Node<int> At(int);
	size_t ssize;
	size_t size() { return ssize; };
	size_t csize() const { return ssize; };

	//forward
	typedef Node<int>* iterator;
	typedef const Node<int>* const_iterator;
	iterator  List::begin() { return Head; }
	const_iterator  List::begin() const { return Head; }
	iterator  List::end() { return begin() + csize();
	}
	iterator List::operator++() {
		Node<int>*tmp =this->Next->Prev;
		operator++();
		return tmp;
	}
	iterator List::operator++(int x) {
		Node<int>*tmp = this->Next->Prev;
		operator++();
		return tmp;
	}
	const_iterator  List::end() const { return begin() + csize(); }
	const_iterator  List::cbegin() const { return begin(); }
	const_iterator  List::cend() const { return end(); }
	
	//reverse
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
	reverse_iterator  List::rbegin() { return reverse_iterator(end()); }
	reverse_iterator  List::rend() { return reverse_iterator(begin()); }
	const_reverse_iterator  List::rbegin() const { return const_reverse_iterator(end()); }
	const_reverse_iterator  List::rend() const { return const_reverse_iterator(begin()); }
	const_reverse_iterator  List::crbegin() const { return rbegin(); }
	const_reverse_iterator  List::crend() const { return rend(); }
	
};

Node<int> List::At(int x) {

	int iter = 0;
	Node<int> *temp = Head;
	if (x == 0) return *temp;
	while (true)
	{
		temp = temp->Next;
		if (++iter == x)break;
	}
	return  *temp;
}
List::~List()
{
	while (Head)
	{
		Tail = Head->Next;
		delete Head;
		Head = Tail;
	}
}

void List::DeleteAt(int i)
{
	int iter = 0;
	Node<int> *temp = Head;

	while (true)
	{
		temp = temp->Next;
		if (iter++ == i-1)break;
	}
	Node<int> *prev = temp->Prev;
	Node<int> *next = temp->Next;
	prev->Next = temp->Next;
	next->Prev = temp->Prev;
	temp = NULL;
}

inline void List::IsEmpty()
{
	if (Head == NULL)
		cout << "List is Empty" << endl;
	else cout << "List is NOT empty" << endl;

}

void List::Add(int x)
{
	//if (Head != NULL) {
	//	Tail->Next = new Node<int>;
	//	Tail->Data = x;

	//	Tail->Next->Prev = Tail;

	//	Tail = Tail->Next;
	//	Tail->Next = NULL;
	//}
	//else {
	//	Node<int> *temp = new Node<int>;
	//	temp->Next = NULL;
	//	temp->Data = x;	
	//	temp->Prev = NULL;
	//	Head = Tail = temp;
	//}
	Node<int> *temp = new Node<int>;
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
	ssize++;
}

void List::Show()
{
	Node<int> *temp = Tail;

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
	List lst;

	for (int i = 0; i < 100; i += 10) {
		lst.Add(i);
	}
	cout << "Added" << endl;

	for (auto i = lst.begin(); i != lst.end();i++) {
		cout << (*i).Data <<endl;
	}
	cout << "\nReady\n";
	
	_getch();
	return 0;
}