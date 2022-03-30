#include <stdio.h>
#pragma warning (disable : 4996)

/* 사용자 정의 데이터형 만들기*/
typedef int INT;
typedef int* POINT, PINT;

int main(void) {

	int num = 10;
	POINT pNum = &num;
	PINT pNum2 = &num;

	printf("%d\n", *pNum);
	return 0;
}
