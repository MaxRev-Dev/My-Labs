#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "List2links.h"
using namespace std;

/*
Р§РµСЂРіР° РЅР° РѕСЃРЅРѕРІС– РґРІРѕР·РІ'СЏР·РЅРѕРіРѕ СЃРїРёСЃРєСѓ
РџСЂРёРЅС†РёРї: FIFO(First In First Out)	
Р”РІРѕР·РІСЏР·РЅРёР№ СЃРїРёСЃРѕРє: Head(NULL) <- node ->|<- node -> Tail(NULL)*/
template <typename T>	
class Queue : private List<T> { 
private:
	List<T> *ins; /* РћСЃРЅРѕРІР° - РєР»Р°СЃ РґРІРѕР·РІ'СЏР·РЅРѕРіРѕ СЃРїРёСЃРєСѓ
							РІРёР·РЅР°С‡РµРЅРёР№ РІ С„Р°Р№Р»С– List2Linked*/
public:
	Queue<T>() {
		ins = new List<T>();
	}
	void Enqueue(T x) {
		ins->Add<T>(x); // Р”РѕРґР°С”РјРѕ РІ РµР»РµРјРµРЅС‚ РєС–РЅРµС†СЊ
	}
	void Dequeue() {
		ins->DeleteAt<T>(0); //Р’РёРґР°Р»СЏС”РјРѕ РїРµСЂС€РёР№ РµР»РµРјРµРЅС‚
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

	Queue<int> *q = new Queue<int>(); //Р†РЅС–С†С–Р°Р»С–Р·Р°С†С–СЏ Р· С‚РёРїРѕРј int
	for (int i = 0; i < 20; i++) {
		q->Enqueue(1 + rand() % 100); // Р—Р°РїРѕРІРЅСЋС”РјРѕ С‡РµСЂРіСѓ
	}
	q->ShowQueue();
	for (int i = 0; i < 20; i++) {
		q->Dequeue();			// Р’С–РґРїСѓСЃРєР°С”РјРѕ РїРµСЂС€РѕРіРѕ РІ С‡РµСЂР·С–
		q->Enqueue(1 + rand() % 100); // РџС–РґС‚СЂРёРјСѓС”РјРѕ СЂС–РІРµРЅСЊ С‡РµСЂРіРё (РґРѕРґР°С”РјРѕ С‰РѕСЃСЊ РІ РєС–РЅРµС†СЊ)
		q->ShowQueue();				// Р’РёРІС–Рґ С‡РµСЂРіРё РІ РєРѕРЅСЃРѕР»СЊ
	}

	for (int i = 0; i < 20; i++) { // Р’С–РґРїСѓСЃРєР°С”РјРѕ РІСЃС–С…
		q->Dequeue(); q->ShowQueue();
		if (q->IsEmpty()) {
			cout << "Р§РµСЂРіР° РїСѓСЃС‚Р°!";
		}
	}

	_getch();
	return 0;
}