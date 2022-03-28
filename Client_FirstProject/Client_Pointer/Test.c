#include <stdio.h>
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

int main(void) {
	
	double* pd1, * pd2, d1, d2;
	double d;
	double* pd = &d;
	
	d1 = 2.0; d2 = 4.0; /* 값초기화*/
	pd1 = &d1; pd2 = &d2; /* 포인터 링크*/

	/* 이 상황에서 대입연산자 없이 *pd1, *pd2, d1, d2의 조합으로 6을 출력할 수 있는 4가지 경우
	각 변수는 연산에 한번씩만 사용 가능*/

	// 1
	printf("%.1lf\n", d1 + d2);
	
	// 2
	printf("%.1lf\n", d2 + *pd1);

	// 3 
	printf("%.1lf\n", d1 + *pd2);

	// 4
	printf("%.1lf\n", *pd1 + *pd2);

	/* 포인터 변수 pd가 있을때 값을 출력할때와 입력받을때의 방법*/
	scanf("%lf", pd);
	printf("%lf\n", *pd);
	/*printf("%lf\n", *&pd);*/

	return 0;
}