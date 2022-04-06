#include <stdio.h>
#include <stdlib.h>

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

void Add(int Data); /* ������ �߰� �Լ�*/
int Remove(int Data), RemoveAt(int idx); /* ������ ����, �ε��� �����Լ�*/
void Clear(); /* �迭 ���� �Լ�*/

int* Arr;
int size; /* ���� ����� ������ ����*/
int capacity; /* ���� �Ҵ��� �޸� ��*/
const int growby = 10; /* �����Ͱ��� ������ �����͸� ������ų ��*/
int* tmp;

int main(void) {
	for (int i = 0; i < 11; i++) Add(i);
	printf("size = %d, capacity = %d\n", size, capacity);
	for (int i = 0; i < size; i++) {
		printf("%d ", Arr[i]);
	}
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
		// realloc�� ������ �������� Ǯ� �˰���
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
int Remove(int Data) {}
int RemoveAt(int idx){}