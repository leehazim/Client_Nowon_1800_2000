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
public:
	tag_node<T>* head;
	tag_node<T>* tail;

public:

	TLinkedList();
	~TLinkedList();

	bool AddFirst(T data);
	bool AddLast(T data);
	/*bool AddBefore(tag_node<T>* node, T data);*/
	/*bool AddAfter(tag_node<T>* node, T data);*/
	bool AddBefore(T target, T item);
	bool AddAfter(T target, T data);
	bool AddBefore(tag_node<T>& target, T item);
	bool AddAfter(tag_node<T>& target, T data);

	tag_node<T>* Find(T data);
	tag_node<T>* FindLast(T data);
	bool Remove(T data);
	bool RemoveLast(T data);
	void Print();
	void PrintData(T data);
	int Count();
	void Delete();
	/*bool operator==(void * tmp) { return head == tmp; }*/
};

template<typename T>
inline TLinkedList<T>::TLinkedList() {
	tail = head = new tag_node<T>;
	head->next = nullptr;
	tail->next = nullptr;
}

template<typename T>
inline TLinkedList<T>::~TLinkedList() { 
	while (head) {
		tag_node<T>* tmp = head;
		head = head->next;
		delete tmp;
	}
}

template<typename T>
bool TLinkedList<T>::AddFirst(T data) {
	tag_node<T>* tmp = new tag_node<T>;
	if (tmp == nullptr) return false; /* 동적할당에 실패하면 false리턴*/

	if (head->next == nullptr) tmp->prev = head;
	else {
		head->next->prev = tmp;
		tmp->prev = head;
	}
	tmp->next = head->next;
	head->next = tmp;
	tmp->data = data; /* 노드에 데이터 삽입*/
	
	if (head == tail) tail = tmp;
	tmp = head;
	while (tmp->next) {	tmp = tmp->next; }
	tail = tmp;
	return true;
}

template<typename T>
bool TLinkedList<T>::AddLast(T data) {
	tag_node<T>* tmp = new tag_node<T>;
	if (tmp == nullptr) return false;
	if (tail == head) {
		AddFirst(data);
		return true;
	}

	tmp->data = data;
	tail->next = tmp;
	tmp->prev = tail;
	tmp->next = nullptr;
	tail = tmp;
	
	return true;
}

template<typename T>
inline bool TLinkedList<T>::AddBefore(T target, T item) {
	tag_node<T>* tmp = Find(target);
	if (tmp == nullptr) return false;
	tag_node<T>* tmp2 = new tag_node<T>;

	if (tmp->prev == nullptr) {
		AddFirst(item);
		delete tmp2;
		return true;
	}

	tmp2->data = item;
	tmp2->next = tmp;
	tmp2->prev = tmp->prev;
	tmp->prev->next = tmp2;
	tmp->prev = tmp2;

	return true;
}

template<typename T>
inline bool TLinkedList<T>::AddAfter(T target, T data) {
	tag_node<T>* tmp = Find(target);
	if (tmp == nullptr) return false;
	tag_node<T>* tmp2 = new tag_node<T>;

	if (tmp->next == nullptr) {
		AddLast(data);
		delete tmp2;
		return true;
	}

	tmp->next->prev = tmp2;
	tmp2->next = tmp->next;
	tmp->next = tmp2;
	tmp2->prev = tmp;
	tmp2->data = data;
	
	return true;
}

template<typename T>
inline bool TLinkedList<T>::AddBefore(tag_node<T>& target, T item) {
	if (AddBefore(target.data, item)) return true;
	return false;
}

template<typename T>
inline bool TLinkedList<T>::AddAfter(tag_node<T>& target, T data) {
	if(AddAfter(target.data, data)) return true; 
	return false;
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
	
	tag_node<T>* tmp = Find(data);
	if (tmp == nullptr) return false;

	if(tmp->prev != nullptr) tmp->prev->next = tmp->next;
	if(tmp->next != nullptr) tmp->next->prev = tmp->prev;
	delete tmp;
	return true;
}

template<typename T>
inline bool TLinkedList<T>::RemoveLast(T data) {
	tag_node<T>* tmp = FindLast(data);
	if (tmp == nullptr) return false;

	if (tmp->prev != nullptr) tmp->prev->next = tmp->next;
	if (tmp->next != nullptr) tmp->next->prev = tmp->prev;
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
inline void TLinkedList<T>::PrintData(T data) {
	tag_node<T>* tmp = FindLast(data);
	if (tmp == nullptr) return;
	std::cout << tmp->data << std::endl;
}

template<typename T>
inline int TLinkedList<T>::Count() {
	int count = 0;
	tag_node<T>* tmp = head;
	while (tmp != nullptr) {
		tmp = tmp->next;
		count++;
	}
	return count;
}

template<typename T>
inline void TLinkedList<T>::Delete() {
	while (head) {
		tag_node<T>* tmp = head;
		head = head->next;
		delete tmp;
	}
}
