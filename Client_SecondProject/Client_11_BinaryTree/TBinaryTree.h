#pragma once
#include <iostream>

template <typename T>
struct Node {
	T Data;
	Node* Left;
	Node* Right;
};

template <typename T>
class TBinaryTree {
private:
	Node<T>* Root;

public:
	TBinaryTree();
	~TBinaryTree();

	bool Add(Node<T>& start, T data);
	Node<T>& Find(T data);
	bool Remove(T data);
	void PrintLDR();
};

template<typename T>
TBinaryTree<T>::TBinaryTree() {
	Root = nullptr;
}

template<typename T>
TBinaryTree<T>::~TBinaryTree() {}

template<typename T>
bool TBinaryTree<T>::Add(Node<T>& start, T data) {

}

template<typename T>
inline Node<T>& TBinaryTree<T>::Find(T data) {
	// TODO: 여기에 return 문을 삽입합니다.
}



template<typename T>
bool TBinaryTree<T>::Remove(T data) {
	return false;
}

template<typename T>
void TBinaryTree<T>::PrintLDR() {}
