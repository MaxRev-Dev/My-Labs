#pragma once

#include <iostream>
#include <string>
#include <fstream>

/*	
		2 Linked List
	Copyright © MaxRev 2017
	  All rights reserved
*/
template <typename T>
struct Node {
	Node *Next, *Prev;
	T Data;
};

template <typename T>
class List
{
	Node<T> *Head, *Tail;
	Node<T> *Next, *Prev;
public:
	List<T>():Head(NULL), Tail(NULL) {};

	template <typename T> void Show() {
		Node<T> *temp = Tail;

		while (temp != NULL)
		{
			std::cout << temp->Data << " ";
			temp = temp->Prev;
		}
		std::cout << "\n";

	}
	template <typename T> int Size() {
		Node<T> *temp = Tail;
		int i=0;
		while (temp != NULL) {
			++i;
			temp = temp->Prev;
		}
		return i;
	}
	template <typename T> void DeleteAt(int i) {
		int iter = 0;
		Node<T> *current = Head;
		while (current != NULL)
		{
			if (i == iter++ || current->Next==NULL) break;
			current = current->Next;
		}
		if (current != NULL) {
			if (current->Prev == NULL) { //First in list
				if (current->Next == NULL) {
					Head = NULL; Tail = Head;
				}
				else {
					Head = current->Next;
					if (current->Next != NULL) {
						current->Next->Prev = NULL;
					}
				}
			}
			else if (current->Next == NULL) { //Last in list
				if (current->Prev == NULL) {
					Head = NULL; Tail = Head;
				}
				else {
					Tail = current->Prev;
					if (current->Prev != NULL) {
						current->Prev->Next = NULL;
					}
				}
			}
			else { // Somewhere else in list
				current->Prev->Next = current->Next;
				current->Next->Prev = current->Prev;
			}

		}
		current = NULL;

	}
	template <typename T> bool IsEmpty() {
		return (Head == NULL);
	}
	template <typename T> void Add(T x) {
		Node<T> *temp = new Node<T>;
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
	template <typename T> void SaveAsFile(std::string path) {
		std::ofstream of(path, std::ios_base::trunc);

		Node<T> *temp = Tail;

		while (temp != NULL)
		{
			of << temp->Data << " ";
			temp = temp->Prev;
		}
		of.close();
	}
	~List() {
		while (Head)
		{
			Tail = Head->Next;
			delete Head;
			Head = Tail;
		}
	}
};

/*
	Copyright © MaxRev 2017
	  All rights reserved
*/