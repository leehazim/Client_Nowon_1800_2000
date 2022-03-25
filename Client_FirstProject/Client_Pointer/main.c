#include <stdio.h>
#pragma warning (disable : 4996)

int main(void) {
	
	/* *: 간접참조 연산자
	직접참조 : 값을 직접 참조하는 걸 직접 참조라고 한다. 변수 R value 사용
	변수이름을 바로 가져다가 쓰는 방식
	
	간접참조는 메모리의 주소를 이용해서 주소로 접근하여 값을 사용하는 방식을 말한다.*/

	/* * : 포인터
	데이터형 바로 뒤에 붙어서 변수가 주소를 저장할 수 있는 변수라는 것을 표현하기 위한 구두점 연산자가 아니다.
	*/
	int* p;
	int a = 10;
	p = &a;
	printf("%d\n", p);
	
	double d = 1.23;
	double* pd;
	pd = &d;

	/* 포인터도 변수 데이터형이고, 포인터 변수는 데이터형에 상관없이 4바이트를 할당받는다
	16비트 컴퓨터는 2바이트*/
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(pd));
	printf("%d\n", sizeof(*pd));
	printf("%lf\n", *pd);
	
	return 0;
}