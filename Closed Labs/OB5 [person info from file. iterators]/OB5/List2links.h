#pragma once

#include <iostream>
#include <string>
#include <fstream>

/*	
		Linked List
	Copyright © MaxRev 2017
	  All rights reserved
*/
template< typename T >
class List {
private:
	struct Node {
		Node() : m_next(NULL) { }

		Node(const T& t) : m_t(t), m_next(NULL) { }

		T m_t;

		Node* m_next;
	};
	Node* m_head;
public:

	class Iterator {
	public:
		Iterator(Node* node) : m_node(node) { }

		bool operator==(const Iterator& other) const {
			if (this == &other) {
				return true;
			}
			return m_node == other.m_node;
		}

		bool operator!=(const Iterator& other) const {
			return !operator==(other);
		}

		T operator*() const {
			if (m_node) {
				return m_node->m_t;
			} 		return T();
		}

		void operator++() {
			if (m_node) {
				m_node = m_node->m_next;
			}
		}

		Node* m_node;
	};

public:
	List();
	~List();
	void append(const T& t) {
		if (Node* node = new Node(t)) {
			node->m_next = m_head;

			m_head = node;
		}
	}
	void remove() {
		if (m_head) {
			Node* newHead = m_head->m_next;

			delete m_head;

			m_head = newHead;
		}
	}
	
	template< typename T >
	Iterator begin()  {
		return Iterator(m_head);
	}

	template< typename T >
	Iterator end()  {
		return Iterator(NULL);
	}

	template< typename T >
	size_t size()  {
		size_t s = 0;
		for (Iterator it = begin(); it != end(); ++it) {
			++s;
		}
		return s;
	}
};

template< typename T >
List< T >::List() : m_head(NULL) {
}
template< typename T >
List< T >::~List() {
	while (m_head) {
		remove();
	}
}

/*
	Copyright © MaxRev 2017
	  All rights reserved
*/