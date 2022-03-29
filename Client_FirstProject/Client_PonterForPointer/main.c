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
	/* 이중포인터(포인터의 포인터)*/
	int a = 3;
	int* p = &a;
	int** pp = &p;

	/* 주소 출력해보기*/
	printf("%p\n", p);
	printf("%p\n", pp);
	printf("%p\n", *pp);
	printf("%p\n", &pp);

	/* 값 출력해보기*/
	printf("%d\n", *p);
	printf("%d\n", **pp);

	int* maxPtr;
	int* minPtr;
	int ar[5] = { 3, 2, 4, 2, 6 };
	/* maxPtr(배열최대값)과 minPtr(배열최솟값)을 링크하는 함수 만들기*/
	FindMinMax(ar, sizeof(ar)/sizeof(ar[0]), &maxPtr, &minPtr);
	printf("최댓값 : %d, 최솟값 : %d\n", *maxPtr, *minPtr);
	
	return 0;
}