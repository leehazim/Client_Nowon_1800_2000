#pragma once
#include <iostream>

template <typename T>
struct tag_node {
	T data;
	tag_node* next;
	tag_node* prev;
};
	
template<typename T>
class TLinkedList {
private:
	tag_node<T>* head;
	tag_node<T>* tail;

public:

	TLinkedList();
	~TLinkedList();

	bool AddFirst(T data);
	bool AddLast(T data);
	bool AddBefore(tag_node<T>* node, T data);
	bool AddAfter(tag_node<T>* node, T data);

	tag_node<T>* First();
	tag_node<T>* Last();
	tag_node<T>* Find(T data);
	tag_node<T>* FindLast(T data);
	bool Remove(T data);
	void Print();
	void PrintData(int data);
};

template<typename T>
inline TLinkedList<T>::TLinkedList() {
	tail = head = new tag_node<T>;
	head->next = nullptr;
	tail->next = nullptr;
}

template<typename T>
inline TLinkedList<T>::~TLinkedList() { delete head; delete tail; }

template<typename T>
bool TLinkedList<T>::AddFirst(T data) {
	tag_node<T>* tmp = new tag_node<T>;
	if (tmp == nullptr) return false;

	tmp->data = data;
	if (head != nullptr) {
		tmp->next = head->next;
		tmp->prev = head;
	}

	if (tail == nullptr) {
		tail = tmp;
	}
	head = tmp;
	if (head == nullptr) { tmp->next = nullptr; tmp->prev = head; }
	//head = tmp;
	tmp->data = data;

	tmp->next = head->next;
	head->next = tmp;
	tmp->prev = head;
	if (tail == head) tail = tmp;
	else while (tmp->next) {
		tail = tmp;
		tmp = tmp->next;
	}
	return true;
}

template<typename T>
bool TLinkedList<T>::AddLast(T data) {
	tag_node<T>* tmp = new tag_node<T>;
	if (tmp == nullptr) return false;

	tmp->data = data;
	tail->next = tmp;
	tmp->prev = tail;
	tmp->next = nullptr;
	tail = tmp;
	
	return true;
}

template<typename T>
inline bool TLinkedList<T>::AddBefore(tag_node<T>* node, T data) {
	tag_node<T>* tmp = new tag_node<T>;
	tag_node<T>* tmp2 = node->prev;
	if (tmp == nullptr) return false;
	
	//tmp2->next = tmp; 
	//tmp->prev = tmp2;
	//tmp->next = node;
	//node->prev = tmp;

	tmp->data = data;
	node->prev->next = tmp;
	tmp->prev = node->prev;
	node->prev = tmp;
	tmp->next = node;
	
	return true;
}

template<typename T>
inline bool TLinkedList<T>::AddAfter(tag_node<T>* node, T data) {
	return false;
}

template<typename T>
inline tag_node<T>* TLinkedList<T>::First() {
	// TODO: 여기에 return 문을 삽입합니다.
}

template<typename T>
inline tag_node<T>* TLinkedList<T>::Last() {
	// TODO: 여기에 return 문을 삽입합니다.
}

template<typename T>
inline tag_node<T>* TLinkedList<T>::Find(T data) {
	tag_node<T>* tmp = head;
	while (tmp) {
		if (tmp->data == data) return tmp;
		tmp = tmp->next;
	}
	return nullptr;
}

template<typename T>
inline tag_node<T>* TLinkedList<T>::FindLast(T data) {
	tag_node<T>* tmp = tail;
	while (tmp) {
		if (tmp->data == data) return tmp;
		tmp = tmp->prev;
	}
	return nullptr;
}

template<typename T>
inline bool TLinkedList<T>::Remove(T data) {
	
	tag_node<T>* tmp = head;
	while (tmp) {
		if (tmp->data == data) break;
		tmp = tmp->next;
	}

	if (tmp == nullptr) return false;

	if (tmp == head) {
		tmp = head->next;
		delete head;
		head = tmp;
		return true;
	}

	if (tmp == tail) {
		tmp = tail->prev;
		tail->prev->next = nullptr;
		delete tail;
		tail = tmp;
	}

	tag_node<T>* tmp2 = tmp->prev;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp2;
	delete tmp;
	return true;
}

template<typename T>
inline void TLinkedList<T>::Print() {
	tag_node<T>* tmp = head->next;
	while (tmp) {
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}

template<typename T>
inline void TLinkedList<T>::PrintData(int data) {
	tag_node<T>* tmp = FindLast(data);
	if (tmp == nullptr) return;
	std::cout << tmp->data << std::endl;
}
