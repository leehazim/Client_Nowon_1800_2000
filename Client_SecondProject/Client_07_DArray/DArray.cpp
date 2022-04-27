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
	/* memcpy쓰지 말자*/
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
///  가장 마지막 인덱스의 값을 꺼내기
/// </summary>
int DArray::Pop_Back() {
	return Pop_At(Length);
}

/// <summary>
/// 인덱스를 제외하고 버퍼에 저장하고 값을 꺼냄 그리고 그 값을 제외하고 배열에 다시 저장
/// 그리고 값을 저장했던 변수 반환
/// </summary>
int DArray::Pop_At(int idx) {
	if (idx < 0 || idx > Length) /* 삭제요청된 인덱스가 유효범위가 아니면*/
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
/// 아이템 검색 성공시에는 인덱스 반환, 검색 실패시에는 -1인 인덱스 외값 반환
/// </summary>
int DArray::Find(int data) {
	for (int i = 0; i < Length; i++) 
		if (Arr[i] == data) return i;
	return -1;
}

/// <summary>
///  값의 존재 유무만 판별, 있으면 true 없으면 false
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
