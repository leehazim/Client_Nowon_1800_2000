#include <stdio.h>
#pragma warning(disable: 4996)
#define MAX 5

void OutArr(int ar[], int len) {
	//int len = sizeof(ar); /* 매개변수는 결국 포인터이다.  그래서 sizeof 연산자를 사용해도 포인터의 크기가 나올뿐이다.*/
	for (int i = 0; i < len; i++) 
		printf("%d ", ar[i]);
}

int main(void) {

	int ar[MAX] = { 10, 20, 30, 40, 50 };
	int* pAr = ar, i;

	//for (i = 0; i < MAX; i++) scanf("%d", pAr+i);
	//for (i = 0; i < MAX; i++) printf("%d ", *pAr++);
	printf("%p\n", ar);
	printf("%p\n", ar + 4);
	printf("%p\n", &ar[4]);

	printf("%p\n", ar + 4); /* 배열 주소에서 데이터형 * 4만큼을 더함 (배열의 4칸을 건너뛴것처럼) 그 주소를 가져옴*/
	printf("%d\n", *ar);  /* 주소에서 데이터형에 맞게 값을 참조함 (int)라서 4바이트 참조*/

	int* p1, * p2;
	p1 = &ar[4]; p2 = &ar[0];
	printf("%d\n", p1 - p2); /* 포인터 간의 뺄셈은 두 포인터간의 거리를 나타낸다. (배열에서 두사이의 거리를 찾기위해서 사용
							 서로 연관이 없는 값끼리의 사이거리는 논리적으로 의미하는게 없다.*/
	printf("%d\n", p1 < p2); /* 메모리상에서의 상대적인 주소를 알 수 있다.*/

	int a = 1, b = 2;
	int* q1 = &a, *q2 = &b;
	printf("%d\n", q1 - q2);

	// 포인터의 덧셈연산 (상수나 증감)
	/*printf("%d\n", (*p2)++);
	printf("%d\n", *p2++);
	printf("%d\n", (*p2)++);
	printf("%d\n", *++p2);
	*/
	OutArr(ar, sizeof(ar)/sizeof(ar[0]));

	return 0;
}