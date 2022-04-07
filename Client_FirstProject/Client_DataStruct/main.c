#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define TRUE 1
#define FALSE 0

typedef struct tag_DArray {
	int* ar;
	int num;
	int size;
}DArray;

DArray* arr;

void InitArray(int aSize) {
	arr->size = aSize;
	arr->ar = (int*)malloc(arr->size * sizeof(int));
	arr->num = 0;
}

void Add(int Data); /* 데이터 추가 함수*/
int Remove(int Data), RemoveAt(int idx); /* 데이터 삭제, 인덱스 삭제함수*/
void Clear(); /* 배열 해제 함수*/
void Print();
int IsExist(int Data);


int* Arr;
int size; /* 현재 저장된 데이터 개수*/
int capacity; /* 현재 할당한 메모리 양*/
const int growby = 10; /* 데이터공간 부족시 데이터를 증가시킬 양*/
int* tmp;

int main(void) {
	for (int i = 1; i <= 10; i++) Add(i);
	printf("size = %d, capacity = %d\n", size, capacity);
	Print();
	Remove(11); Print();
	RemoveAt(4); Print();
	
	Clear();
	return 0;
}

void Add(int Data) {
	if (0 == capacity) {
		capacity += growby;
		Arr = (int*)malloc(sizeof(int) * capacity);
	}
	else if (size + 1 > capacity) {
		/*capacity += growby;
		Arr = (int*)realloc(Arr, sizeof(int) * capacity);*/
		// realloc의 구조를 보기위해 풀어쓴 알고리즘
		capacity += growby;
		tmp = (int*)malloc(sizeof(int) * (size+growby));
		for (int i = 0; i < size; i++) 	tmp[i] = Arr[i];
		free(Arr);
		Arr = (int*)malloc(sizeof(int) * (size+growby));
		for (int i = 0; i < size; i++) Arr[i] = tmp[i];
		free(tmp);
	}
	Arr[size] = Data;
	size++;
}
int Remove(int Data) {
	int idx = IsExist(Data);
	if (RemoveAt(idx) == TRUE) return TRUE;
	return FALSE;
}

int RemoveAt(int idx){
	if (capacity == 0) return FALSE;
	if (idx > size || idx < 0) return FALSE;
	for (int i = idx; i < size - 1; i++) Arr[i] = Arr[i + 1];
	size--;
	return TRUE;
}

int IsExist(int Data) {
	for (int i = 0; i < size; i++) 
		if (Arr[i] == Data) return i;
	
	return -1;
}

void Clear() {
	free(Arr);
	size = 0;
	capacity = 0;
}

void Print() {
	for (int i = 0; i < size; i++) { printf("%d ", Arr[i]); }
	printf("\n");
}