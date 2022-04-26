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
	void Add(string data); /* 해쉬키를 만들어서 데이터를 추가함*/
	bool ContainsKey(string value); /* 값을 받아서 그값의 해쉬를 계산한 수 그 계산된 해쉬를 찾아가는것*/
	bool ContainsKey(int key);		/* 키를 받아서 그 키에 해당하는 해쉬가 이미 존재하는지 확인*/
	bool ContainsValue(string value);
	bool RemoveKey(string data); /* 값을 입력받아서 해쉬함수로 해쉬를 구해 해당 해쉬를 모두 지우기*/
	bool RemoveKey(int key);	 /* 키를 받아서 해당하는 키값을 모두 지우기*/
	bool RemoveValue(string data);
	void Clear(); /*모든 버켓을 삭제*/
	void Delete(); /* HashTable을 제거하는 메소드*/
	void PrintKey(string data);

private:
	int MakeHash(string data); /* 해쉬키를 만드는 함수*/
};