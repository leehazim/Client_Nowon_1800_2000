#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)
#pragma warning(disable : 6031)

#define Swap(type, a, b) do{ type t = a ; a = b; b = t;}while(0)

void func(void* Data1, void* Data2, const char* DataType) {
	
	if (!strcmp(DataType, "int")) {
		Swap(int, *(int*)Data1, *(int*)Data2);
		return;
	}
	if (!strcmp(DataType, "char")) {
		Swap(char, *(char*)Data1, *(char*)Data2); 
		return;
	}
	if (!strcmp(DataType, "double")) {
		Swap(double, *(double*)Data1, *(double*)Data2); 
		return;
	}
}

void SwapFunc(int* a, int* b) {
	int t = *a; *a = *b; *b = t;
}

int main(void) {
	int a = 1, b = 3;
	double c = 1.2, d = 3.4;
	func(&a, &b, "int");
	printf("a = %d, b = %d\n", a, b);
	func(&c, &d, "double");
	printf("c = %.2lf, d = %.2lf\n", c, d);

	return 0;
}

//int main(void) {
//
//	int c = 1, c2 = 2;
//	int* p1 = &c, * p2 = &c2;
//	sum(p1, p2, "int");
//	printf("%d\n", c);
//	
//	/* *: 간접참조 연산자
//	직접참조 : 값을 직접 참조하는 걸 직접 참조라고 한다. 변수 R value 사용
//	변수이름을 바로 가져다가 쓰는 방식
//	
//	간접참조는 메모리의 주소를 이용해서 주소로 접근하여 값을 사용하는 방식을 말한다.*/
//
//	/* * : 포인터
//	데이터형 바로 뒤에 붙어서 변수가 주소를 저장할 수 있는 변수라는 것을 표현하기 위한 구두점, 연산자가 아니다.*/
//	int* p;
//	int a = 10;
//	p = &a;
//	printf("%d\n", a);
//	printf("%d\n", sizeof(a));
//	//printf("%d\n", &a);
//	printf("%p\n", &a);
//
//	double d = 1.23;
//	double* pd;
//	pd = &d;
//	//p = &d;
//	/* 포인터도 변수 데이터형이고, 포인터 변수는 데이터형에 상관없이 4바이트를 할당받는다
//	16비트 컴퓨터는 2바이트*/
//	
//	/*printf("%d\n", sizeof(p));
//	printf("%d\n", sizeof(pd));
//	printf("%d\n", sizeof(*pd));
//	printf("%.2lf\n", *pd);
//	printf("%lf\n", *(double*)p);*/
//
//	/* 상수 지시 포인터\ 상수 포인터\ 상수 지시 상수 포인터*/
//	
//	const int* cp; /* 참조하고 있는 변수의 값을 변경할 수 없다.(상수 지시 포인터)*/
//	cp = &a;
////	*cp = 1; 오류.
//	int* const cp2 = &a; /* 포인터 변수가 다른 값을 참조하는 것이 불가능 (상수형 포인터)*/
//	
//	const int num = 1;
//	int* pNum = &num;
//	*pNum = 2; /* 메모리 자체가 상수값인가에 대한 정보를 가지고 있지 않아서 기계적으로는 가능
//			   하지만 논리적인 오류가 발생*/
//	printf("%d\n", num);
//
//
//	/* 다른 데이터형간으 포인터 참조가 가능한가?
//	가능은 하다 int* 이 double형 변수의 주소를 참조 할 수 있으나 
//	값을 읽는 방법을 모르기때문에 값을 대입하거나 읽을때 논리적인 오류가 발생한다.*/
//
//	//printf("p : %p\n", p);
//	//printf("pd : %p\n", pd);
//	//p = pd;
//	//printf("p : %p\n", p);
//	//*p = 11;
//	//printf("%d\n", *p);
//	//printf("%d\n", sizeof(*p));
//	//printf("%d\n", sizeof(*pd));
//	
//	int temp = 1;
//	int* pTemp = &temp;
//	double temp2 = 3.1f;
//	double* pTemp2 = &temp2;
//	printf("temp : %p\n", &temp);
//	printf("pTemp : %p\n", pTemp);
//	printf("temp2 : %p\n", &temp2);
//	printf("pTemp2 : %p\n", pTemp2);
//
//	pTemp = pTemp2;
//	puts("");
//	printf("temp : %p\n", &temp);
//	printf("pTemp : %p\n", pTemp);
//	printf("temp2 : %p\n", &temp2);
//	printf("pTemp2 : %p\n", pTemp2);
//	
//	*pTemp = 3;
//	puts("");
//	printf("%d\n", *pTemp);
//	printf("%lf\n", *pTemp2);
//	printf("%lf\n", temp2);
//
//	return 0;
//}