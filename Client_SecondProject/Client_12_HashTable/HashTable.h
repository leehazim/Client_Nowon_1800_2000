#pragma once
#include "TLinkedList.h"
#include <string>
using namespace std;

class HashTable {
private:
	const int DEFAULT_SIZE;
	TLinkedList<string>** _bucket;
	int _tmpHash;

public:
	HashTable();
	~HashTable();
	void Add(string data); /* �ؽ�Ű�� ���� �����͸� �߰���*/
	bool ContainsKey(string value); /* ���� �޾Ƽ� �װ��� �ؽ��� ����� �� �� ���� �ؽ��� ã�ư��°�*/
	bool ContainsKey(int key);		/* Ű�� �޾Ƽ� �� Ű�� �ش��ϴ� �ؽ��� �̹� �����ϴ��� Ȯ��*/
	bool ContainsValue(string value);
	bool RemoveKey(string data); /* ���� �Է¹޾Ƽ� �ؽ��Լ��� �ؽ��� ���� �ش� �ؽ��� ��� �����*/
	bool RemoveKey(int key);	 /* Ű�� �޾Ƽ� �ش��ϴ� Ű���� ��� �����*/
	bool RemoveValue(string data);
	void Clear(); /*��� ������ ����*/
	void Delete(); /* HashTable�� �����ϴ� �޼ҵ�*/
	void PrintKey(string data);

private:
	int MakeHash(string data); /* �ؽ�Ű�� ����� �Լ�*/
};