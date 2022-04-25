#pragma once

/* 이진트리
기본단위 : 노드

루트(노드)	:  최상위 부모 노드, 자식만을 가지는 트리의 시작이 되는 노드.
리프(노드)	: 최하위 자식 노드, 자식이 없는 가장 마지막 자식노드.
크기			: 노드 개수
깊이(높이)	: 층의 개수 루프가 0층이면 루트의 자식의 자식은 2층.
차수			: 간선 개수(노드개수 - 1).
*/

struct Node {
	int m_Data;
	Node* m_Left;
	Node* m_Right;
	
};
enum { LEFT = 1, RIGHT };

class BinaryTree {
private:
	Node* m_Root, *m_Tmp, *m_PTmp;

	Node& FindLeftLeaf(Node* start);

public:
	BinaryTree();
	~BinaryTree();
	
	Node& Find(int Value);
	bool Insert(int Value);
	bool Remove(int Value);
};