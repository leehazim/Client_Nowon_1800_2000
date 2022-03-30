/* 사용자의 입력에 따라 포인터로 간접호출하는 함수 만들기*/
#include <stdio.h>
#include <string.h>
#include "Functions.h"
#pragma warning(disable: 4996)

int main(void) {

	char op[10];
	double num1, num2;
	double (*pF)(double, double) = NULL;

	printf("두 실수를 입력해 주세요 : "); 
	scanf("%lf %lf", &num1, &num2);
	do {
		printf("연산자를 입력해주세요 : ");   
		scanf("%s", op);
	
		if (!strcmp(op, "sum")) pF = sum;
		else if (!strcmp(op, "sub")) pF = sub;
		else if (!strcmp(op, "mul")) pF = mul;
		else if (!strcmp(op, "div")) pF = div;
		else if (!strcmp(op, "mod")) pF = mod;
		else { puts("잘못된 연산자를 입력하셨습니다."); pF = NULL; }
	} while (pF == NULL);
	printf("연산 결과 = %.2lf\n", pF(num1, num2));
	
	return 0;
}

double sum(double a, double b){return a + b;}
double sub(double a, double b){return a - b;}
double mul(double a, double b){return a * b;}

double div(double a, double b) {
	if (b == 0.0) return 0.0;
	return a / b;
}

double mod(double a, double b) {
	int tmp1 = (int)a, tmp2 = (int)b;
	if (tmp2 == 0) return 0.0;
	return (double)(tmp1 % tmp2);
}
