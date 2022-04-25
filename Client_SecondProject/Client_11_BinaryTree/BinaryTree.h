#pragma once

/* ����Ʈ��
�⺻���� : ���

��Ʈ(���)	:  �ֻ��� �θ� ���, �ڽĸ��� ������ Ʈ���� ������ �Ǵ� ���.
����(���)	: ������ �ڽ� ���, �ڽ��� ���� ���� ������ �ڽĳ��.
ũ��			: ��� ����
����(����)	: ���� ���� ������ 0���̸� ��Ʈ�� �ڽ��� �ڽ��� 2��.
����			: ���� ����(��尳�� - 1).
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