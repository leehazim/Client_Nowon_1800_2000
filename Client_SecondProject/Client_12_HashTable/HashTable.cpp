#include "HashTable.h"

HashTable::HashTable() 
	: DEFAULT_SIZE(100) {
	*_bucket = new TLinkedList<string>[DEFAULT_SIZE];
	_tmpHash = 0;
}

void HashTable::Add(string data) {
	_tmpHash = MakeHash(data);
	if (_bucket[_tmpHash] == nullptr) 
		_bucket[_tmpHash] = new TLinkedList<string>;
	_bucket[_tmpHash]->AddLast(data);
}

bool HashTable::ContainsKey(string value) {
	return false;
}

bool HashTable::ContainsKey(int key) {
	return false;
}

bool HashTable::ContainsValue(string value) {
	return false;
}

bool HashTable::RemoveKey(string data) {
	return false;
}

bool HashTable::RemoveKey(int key) {
	return false;
}

bool HashTable::RemoveValue(string data) {
	return false;
}

void HashTable::Clear() {}

void HashTable::Delete() {}

int HashTable::MakeHash(string data) {
	_tmpHash = 0;
	for (int i = 0; i < data.length(); i++) _tmpHash += data[i];
	_tmpHash %= DEFAULT_SIZE;
	return _tmpHash;
}
