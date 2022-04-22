#include "BinaryTree.h"
#include <iostream>

Node& BinaryTree::FindLeaf(Node* start) {
	Node* leaf = start;
	while (leaf->m_Left != nullptr) {
		leaf = leaf->m_Left;
	}
	if (leaf->m_Right != nullptr) leaf = &FindLeaf(leaf->m_Right);
	
	return *leaf;
}

BinaryTree::BinaryTree() {
	m_Root = nullptr;
	m_Tmp = nullptr;
	m_PTmp = nullptr;
}

BinaryTree::~BinaryTree() {}

Node& BinaryTree::Find(int Value) {
	if (m_Root == nullptr) return *m_Root;
	m_Tmp = m_Root;
	while (m_Tmp != nullptr) {
		if (m_Tmp->m_Data == Value)	return *m_Tmp;
		if (m_Tmp->m_Data > Value)	m_Tmp = m_Tmp->m_Left;
		else						m_Tmp = m_Tmp->m_Right;
	}
	return *m_Tmp;
}

bool BinaryTree::Insert(int Value) {
	if (m_Root == nullptr) {
		m_Tmp = new Node;
		m_Root = m_Tmp;
		m_Tmp->m_Data = Value;
		m_Tmp->m_Left = nullptr;
		m_Tmp->m_Right = nullptr;
		return true;
	}

	try {
		m_Tmp = m_Root;
		while (m_Tmp != nullptr) {
			if (m_Tmp->m_Data > Value) { 
				if (m_Tmp->m_Left != nullptr) m_Tmp = m_Tmp->m_Left; 
				else {
					m_Tmp->m_Left = new Node;
					m_Tmp->m_Left->m_Data = Value;
					m_Tmp->m_Left->m_Left = nullptr;
					m_Tmp->m_Left->m_Right = nullptr;
					return true;
				}
			}
			else if (m_Tmp->m_Data < Value) {
				if (m_Tmp->m_Right != nullptr) m_Tmp = m_Tmp->m_Right;
				else {
					m_Tmp->m_Right = new Node;
					m_Tmp->m_Right->m_Data = Value;
					m_Tmp->m_Right->m_Left = nullptr;
					m_Tmp->m_Right->m_Right = nullptr;
					return true;
				}
			}
			else throw "해당노드가 이미 존재함";
		}
	}
	catch (const char* tmp) { std::cout << tmp << std::endl; }
	
	return false;
}

bool BinaryTree::Remove(int Value) {

	int dir = 0;

	/* 삭제할 대상 노드를 찾기*/
	m_Tmp = m_Root;
	while (m_Tmp != nullptr) {
		if (m_Tmp->m_Data == Value)	break;
		if (m_Tmp->m_Data > Value)	{
			dir = LEFT;
			m_PTmp = m_Tmp;
			m_Tmp = m_Tmp->m_Left;
		}
		else { 
			dir = RIGHT;
			m_PTmp = m_Tmp;
			m_Tmp = m_Tmp->m_Right;
		}
	}
	if (m_Tmp == nullptr) { return false; }

	/* 삭제할 대상 노드가 자식이 없는 경우*/
	if ((m_Tmp->m_Left == nullptr) && (m_Tmp->m_Right == nullptr)) {
		if (m_PTmp != nullptr) {
			if (dir == LEFT)	m_PTmp->m_Left = nullptr;
			if (dir == RIGHT)	m_PTmp->m_Right = nullptr;
		}
		delete m_Tmp; m_Tmp = nullptr; return true;
	}
	else if (m_Tmp->m_Left == nullptr) {
		if (dir == LEFT)	m_PTmp->m_Left = m_Tmp->m_Right;
		else				m_PTmp->m_Right = m_Tmp->m_Right;
		delete m_Tmp; m_Tmp = nullptr; return true;
	}
	else if(m_Tmp->m_Right == nullptr) {
		if (dir == LEFT)	m_PTmp->m_Left = m_Tmp->m_Left;
		else				m_PTmp->m_Right = m_Tmp->m_Left;
		delete m_Tmp; m_Tmp = nullptr; return true;
	}
	else {
		Node* Leaf = m_Tmp->m_Right;
		if(Leaf->m_Left == nullptr)

	}
}
