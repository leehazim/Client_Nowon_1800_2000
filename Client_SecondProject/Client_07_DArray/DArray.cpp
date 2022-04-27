#include "DArray.h"
#include <iostream>

DArray::DArray() : DEFAULT_SIZE(1) {
	Length = 0;
	Capacity = DEFAULT_SIZE;
	Arr = new int[Capacity];
}
	
DArray::DArray(int size) : DEFAULT_SIZE(10) {
	Length = 0;
	Capacity = size;
	Arr = new int[size];
}

DArray::DArray(const DArray& Other) : DEFAULT_SIZE(10) {
	Arr = new int[Other.Length];
	for (int i = 0; i < Other.Length; i++) Arr[i] = Other.Arr[i];
	Capacity = Other.Capacity;
	Length = Other.Length;
}

DArray::~DArray() { 
	delete[] Arr;
}

void DArray::Push_Back(int data) {
	/* memcpy���� ����*/
	if (Capacity <= Length) {
		Capacity *= 2; 
		int* tmp = new int[Capacity];
		for (int i = 0; i < Length; i++) tmp[i] = Arr[i]; 
		delete[] Arr; 
		Arr = new int[Capacity];
		for (int i = 0; i < Length; i++) Arr[i] = tmp[i];
		delete[] tmp;
	}
	Arr[Length] = data;
	Length++;
}

/// <summary>
///  ���� ������ �ε����� ���� ������
/// </summary>
int DArray::Pop_Back() {
	return Pop_At(Length);
}

/// <summary>
/// �ε����� �����ϰ� ���ۿ� �����ϰ� ���� ���� �׸��� �� ���� �����ϰ� �迭�� �ٽ� ����
/// �׸��� ���� �����ߴ� ���� ��ȯ
/// </summary>
int DArray::Pop_At(int idx) {
	if (idx < 0 || idx > Length) /* ������û�� �ε����� ��ȿ������ �ƴϸ�*/
		return -99999999;
	if (idx == Length) idx--;
	int a = Arr[idx];
	for (int i = idx; i < Length - 1; i++) Arr[i] = Arr[i + 1];
	Length--;
	return a;
}

int DArray::Pop_Data(int data) {
	int idx = Find(data);
	Pop_At(idx);
	return 0;
}

/// <summary>
/// ������ �˻� �����ÿ��� �ε��� ��ȯ, �˻� ���нÿ��� -1�� �ε��� �ܰ� ��ȯ
/// </summary>
int DArray::Find(int data) {
	for (int i = 0; i < Length; i++) 
		if (Arr[i] == data) return i;
	return -1;
}

/// <summary>
///  ���� ���� ������ �Ǻ�, ������ true ������ false
/// </summary>
bool DArray::IsExist(int data) {
	for (int i = 0; i < Length; i++)
		if (Arr[i] == data) return true;
	return false;
}

void DArray::Print() {
	for (int i = 0; i < Length; i++) std::cout << Arr[i] << " ";
	std::cout << std::endl;
}
