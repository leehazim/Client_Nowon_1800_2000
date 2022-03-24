#include <stdio.h>

	/* 반환형 함수이름(매개변수 목록)*/

void HowCanDoThis();
int IsOkay(int);
int sum(int, int);
void doSomeThing();
/* 지역변수 전역변수
 전역변수와 같은 이름의 지역변수를 사용시 지역변수가 우선권을 가진다.
 지역변수는 스택에 할당되지만
 전역변수는 데이터메모리영역이 다르게 있어서 두 변수의 살아있는 주기가 다르다.*/

/* 그런데 지역변수가 자신의 값을 기억하고 있어야하는 경우가 있다. 전역변수의 위험성과 지역변수의 한계를 극복한 변수
지역변수라서 구문 내에서만 사용이 가능하지만 다시 그 구문이 호출될때 전에 호출시의 값을 기억하고있다.
static 데이터형 변수값*/
int GlobalCount;


/* 재귀 함수
함수가 자기 자신을 호출하는 함수*/

int Factorial(int n) {
	
	if (n == 1) return 1;
	else		return n * Factorial(n - 1);
	
}
int main(void) {
	
	printf("%d\n", Factorial(5));
	for (int i = 0; i < 5; i++)
		doSomeThing();
	sum(1, 2);
	HowCanDoThis();
	return 0;
}
void doSomeThing() {

	static int Count = 1  /* 선언시 초기화를 하지 않아도 0으로 초기화 된다. 초기값을 자동으로 줘도 초기화는 단 한번만 이루어지기 때문에 상관없다.*/;
	//int GlobalCount = 0;
	GlobalCount++;
	printf("doSomeThing has been called : %d Time, %d is static\n", GlobalCount, Count);
	Count++;
}

int sum(int a, int b) {
	
	int tmpValue = a + b;
	printf("%d\n", tmpValue);
	return tmpValue;
}

void HowCanDoThis() {
	int i;
	i = IsOkay(1);
	printf("is not defined = %d\n", i);
}

int IsOkay(int num) {
	if (num) printf("Ok\n");
	else printf("Not Ok!\n");
	return num;
}