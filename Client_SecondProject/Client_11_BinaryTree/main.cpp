/* 이진트리의 장점 :
모든 요소를 순회하지않아도 되는 빠른 검색*/
#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main(void) {

	BinaryTree bt;
	bt.Insert(20);
	bt.Insert(11);
	bt.Insert(15);
	bt.Insert(5);
	bt.Insert(13);
	bt.Insert(18);
	bt.Insert(16);
	bt.Insert(17);
	
	cout << bt.Find(11).m_Right->m_Data << endl;
	cout << bt.Find(11).m_Right->m_Left->m_Data << endl;
	cout << bt.Find(11).m_Right->m_Right->m_Data << endl;
	cout << bt.Find(11).m_Right->m_Right->m_Left->m_Data << endl;
	bt.Remove(15);
	cout << endl;
	cout << bt.Find(11).m_Right->m_Data << endl;
	cout << bt.Find(11).m_Right->m_Left->m_Data << endl;
	cout << bt.Find(11).m_Right->m_Right->m_Data << endl;
	cout << bt.Find(11).m_Right->m_Right->m_Left->m_Data << endl;

	return 0;
}