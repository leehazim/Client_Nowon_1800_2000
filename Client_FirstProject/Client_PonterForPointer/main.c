#include <stdio.h>

void FindMinMax(int ar[], int size, int** max, int** min) {
	int i;
	*max = ar;
	*min = ar;
	for (i = 0; i < size; i++) {
		if (**max < *(ar + i)) *max = ar + i;
		if (**min > *(ar + i)) *min = ar + i;
	}
}

int main(void) {
	/* ����������(�������� ������)*/
	int a = 3;
	int* p = &a;
	int** pp = &p;

	/* �ּ� ����غ���*/
	printf("%p\n", p);
	printf("%p\n", pp);
	printf("%p\n", *pp);
	printf("%p\n", &pp);

	/* �� ����غ���*/
	printf("%d\n", *p);
	printf("%d\n", **pp);

	int* maxPtr;
	int* minPtr;
	int ar[5] = { 3, 2, 4, 2, 6 };
	/* maxPtr(�迭�ִ밪)�� minPtr(�迭�ּڰ�)�� ��ũ�ϴ� �Լ� �����*/
	FindMinMax(ar, sizeof(ar)/sizeof(ar[0]), &maxPtr, &minPtr);
	printf("�ִ� : %d, �ּڰ� : %d\n", *maxPtr, *minPtr);
	
	return 0;
}