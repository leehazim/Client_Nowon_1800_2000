#include "HashTable.h"

HashTable::HashTable() 
	: DEFAULT_SIZE(10) {
	_bucket = new TLinkedList<string>*[DEFAULT_SIZE];
	for (int i = 0; i < DEFAULT_SIZE; i++) 
		_bucket[i] = nullptr;
	_tmpHash = 0;
}

HashTable::~HashTable() {
	Delete();
}

void HashTable::Add(string data) {
	_tmpHash = MakeHash(data);
	if (_bucket[_tmpHash] == nullptr) /* _bucket[_tmpHash] == *(_bucket+_tmpHash)  */
		_bucket[_tmpHash] = new TLinkedList<string>;
	_bucket[_tmpHash]->AddLast(data);
}

bool HashTable::ContainsKey(string value) {
	return ContainsKey(MakeHash(value));
}

bool HashTable::ContainsKey(int key) {
	if (_bucket[key] == nullptr || key >= DEFAULT_SIZE) 
		return false;
	else return true;
}

bool HashTable::ContainsValue(string value) {
	_tmpHash = MakeHash(value);
	if (_bucket[_tmpHash] != nullptr) {
		return _bucket[_tmpHash]->Find(value) != nullptr ? true : false;
	}
	return false;
}

bool HashTable::RemoveKey(string data) {
	return RemoveKey(MakeHash(data));
}

bool HashTable::RemoveKey(int key) {
	if (_bucket[key] != nullptr) {
		_bucket[key]->Delete();
		delete _bucket[key];
		return true;
	}
	return false;
}

bool HashTable::RemoveValue(string data) {
	_tmpHash = MakeHash(data);
	if (_bucket[_tmpHash] != nullptr) {
		bool isRemoved = _bucket[_tmpHash]->RemoveLast(data);
		if (isRemoved && _bucket[_tmpHash]->Count() == 0)
			delete _bucket[_tmpHash];
		return isRemoved;
	}
	return false;
}

void HashTable::Clear() {
	for (int i = 0; i < DEFAULT_SIZE; i++) {
		if (_bucket[i] != nullptr) {
			_bucket[i]->Delete();
			delete _bucket[i];
		}
	}
}

void HashTable::Delete() {
	Clear();
	delete _bucket;
}

void HashTable::PrintKey(string data) {
	_tmpHash = MakeHash(data);
	if (_bucket[_tmpHash] != nullptr) {
		_bucket[_tmpHash]->Print();
	}
}

int HashTable::MakeHash(string data) {
	_tmpHash = 0;
	/*_tmpHash = atoi(data.c_str());*/
	for (int i = 0; i < data.length(); i++) _tmpHash += data[i];
	_tmpHash %= DEFAULT_SIZE;
	return _tmpHash;
}
