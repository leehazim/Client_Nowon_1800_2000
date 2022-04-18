#pragma once
class DArray {
private:
	int* Arr;
	int Length;
	int Capacity;
	const int DEFAULT_SIZE;

public:
	DArray();
	DArray(int);
	DArray(const DArray& Other);
	~DArray();

	void Push_Back(int data);
	int Pop_Back();
	int Pop_At(int);
	int Pop_Data(int);
	int Find(int data);
	bool IsExist(int data);
	void Print();
};

