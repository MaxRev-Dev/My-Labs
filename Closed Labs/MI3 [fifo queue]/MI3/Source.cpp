#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "List2links.h"
using namespace std;

/*
����� �� ����� �����'������ ������
�������: FIFO(First In First Out)	
���������� ������: Head(NULL) <- node ->|<- node -> Tail(NULL)*/
template <typename T>	
class Queue : private List<T> { 
private:
	List<T> *ins; /* ������ - ���� �����'������ ������
							���������� � ���� List2Linked*/
public:
	Queue<T>() {
		ins = new List<T>();
	}
	void Enqueue(T x) {
		ins->Add<T>(x); // ������ � ������� �����
	}
	void Dequeue() {
		ins->DeleteAt<T>(0); //��������� ������ �������
	}
	void ShowQueue() {
		cout << endl;
		ins->Show<T>();
		cout << endl;
	}
	bool IsEmpty() {
		return ins->IsEmpty<T>();
	}
};
int main() {
	SetConsoleOutputCP(1251);

	Queue<int> *q = new Queue<int>(); //����������� � ����� int
	for (int i = 0; i < 20; i++) {
		q->Enqueue(1 + rand() % 100); // ���������� �����
	}
	q->ShowQueue();
	for (int i = 0; i < 20; i++) {
		q->Dequeue();			// ³�������� ������� � ����
		q->Enqueue(1 + rand() % 100); // ϳ�������� ����� ����� (������ ���� � �����)
		q->ShowQueue();				// ���� ����� � �������
	}

	for (int i = 0; i < 20; i++) { // ³�������� ���
		q->Dequeue(); q->ShowQueue();
		if (q->IsEmpty()) {
			cout << "����� �����!";
		}
	}

	_getch();
	return 0;
}