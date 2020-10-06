#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "List2links.h"
using namespace std;

/*
Черга на основі двозв'язного списку
Принцип: FIFO(First In First Out)	
Двозвязний список: Head(NULL) <- node ->|<- node -> Tail(NULL)*/
template <typename T>	
class Queue : private List<T> { 
private:
	List<T> *ins; /* Основа - клас двозв'язного списку
							визначений в файлі List2Linked*/
public:
	Queue<T>() {
		ins = new List<T>();
	}
	void Enqueue(T x) {
		ins->Add<T>(x); // Додаємо в елемент кінець
	}
	void Dequeue() {
		ins->DeleteAt<T>(0); //Видаляємо перший елемент
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

	Queue<int> *q = new Queue<int>(); //Ініціалізація з типом int
	for (int i = 0; i < 20; i++) {
		q->Enqueue(1 + rand() % 100); // Заповнюємо чергу
	}
	q->ShowQueue();
	for (int i = 0; i < 20; i++) {
		q->Dequeue();			// Відпускаємо першого в черзі
		q->Enqueue(1 + rand() % 100); // Підтримуємо рівень черги (додаємо щось в кінець)
		q->ShowQueue();				// Вивід черги в консоль
	}

	for (int i = 0; i < 20; i++) { // Відпускаємо всіх
		q->Dequeue(); q->ShowQueue();
		if (q->IsEmpty()) {
			cout << "Черга пуста!";
		}
	}

	_getch();
	return 0;
}