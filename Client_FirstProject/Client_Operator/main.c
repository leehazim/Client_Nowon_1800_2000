#include <stdio.h>

int main(void) {

	/* 대입연산자 
	연산자 기준 오른쪽의 값을 왼쪽 변수(메모리)에 대입*/
	int intResult = 0;
	double doubleResult = 0.0;

	/* 산술연산자
	+, -, *, /, % */
	intResult = 3 + 4;
	doubleResult = 3.0 + 4.0;
	printf("%d, %lf\n", intResult, doubleResult);
	
	intResult = 2 - 1;
	doubleResult = 4.0 - 3.0;

	intResult = 3 * 4;
	doubleResult = 3.0 * 4.0;

	/* 나누기 연산자 주의사항은 0으로 나누지 않도록 주의하자*/
	intResult = 3 / 4;
	doubleResult = 3.0 / 4.0;
	printf("%d\n%lf\n", intResult, doubleResult);

	/* 나머지 연산은 정수에서만 사용할 수 있다.
	나머지가 나누어떨어지면 0을 반환하지만 아니라면 나머지값을 반환하는 연산자
	무엇의 배수인지 짝수인지 홀수인지 확인하는데 사용할 수 있다.*/
	intResult = 3 % 4;
	doubleResult = 3 % 4;

	/* 부호연산자*/
	intResult = +3;
	intResult = -3;

	intResult = 0;
	/* 복합 대입연산자
	Result = Result + 값 처럼 한 변수에 값을 연산하고 다시 변수에 대입하고싶을 때 변수명을 두번써야하는 불편함이 있다
	이것을 해결하는 것이 복합 대입연산자*/
	intResult += 1;
	intResult += 1;
	printf("%d\n", intResult);


	/* ++, -- 증감연산자*/
	intResult++;
	printf("%d\n", intResult++);
	printf("%d\n", ++intResult);

	/* 관계연산자 
	>,<,>=,<= 등호는 반드시 오른쪽에 붙어야한다.*/
	

	return 0;
}