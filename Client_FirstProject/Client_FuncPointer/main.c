#include <stdio.h>

int Sum(int, int);
int GetFactorial(int, int); /* 배열과 마찬가지로 함수의 이름만을 사용하면 함수가 차지하고 있는 메모리를 가르키는 포인터이다.*/
int Factorial(int, int);

int main(void) {

	int arr[3]; /* 배열이름만을 사용하면 배열의 주소를 가르키는 포인터*/

	int (*p)(int, int);
	p = Sum; 
	printf("%d\n",p(1, 2));

	p = GetFactorial;
	printf("%d\n", p(5, 0));

	p = Factorial;
	printf("%d\n", p(5, 0));

	/* void형 포인터*/
	void* vp;
	/* 상황에 따라 여러가지 타입의 포인터를 받아야할 때 사용한다. 기본적으로 모든 타입의 포인터를 받는 것이 
	가능하다. 하지만 데이터형을 읽는 방법을 몰라서 값을 읽을 수는 없다.
	하지만, 캐스팅해서 사용하면 모든 타입의 데이터의 포인터를 링크할 수 있는 변수가 된다.
	개발자가 신경을 많이써서 사용해야 한다.*/

	return 0;
}

int Sum(int a, int b) {
	return a + b;
}

int GetFactorial(int num, int n) {
	if (num == 1) return 1;
	else return num * GetFactorial(num - 1, 0);
}

int Factorial(int num, int temp) {
	int fact = 1;
	for (int i = 1; i <= num; i++) fact *= i;
	return fact;
}