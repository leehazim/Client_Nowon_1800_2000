#include <stdio.h>
#pragma warning (disable : 4996)

/* ����� ���� �������� �����*/
typedef int INT;
typedef int* POINT, PINT;

int main(void) {

	int num = 10;
	POINT pNum = &num;
	PINT pNum2 = &num;

	printf("%d\n", *pNum);
	return 0;
}
