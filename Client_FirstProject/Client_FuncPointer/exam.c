/* ������� �Է¿� ���� �����ͷ� ����ȣ���ϴ� �Լ� �����*/
#include <stdio.h>
#include <string.h>
#include "Functions.h"
#pragma warning(disable: 4996)

int main(void) {

	char op[10];
	double num1, num2;
	double (*pF)(double, double) = NULL;

	printf("�� �Ǽ��� �Է��� �ּ��� : "); 
	scanf("%lf %lf", &num1, &num2);
	do {
		printf("�����ڸ� �Է����ּ��� : ");   
		scanf("%s", op);
	
		if (!strcmp(op, "sum")) pF = sum;
		else if (!strcmp(op, "sub")) pF = sub;
		else if (!strcmp(op, "mul")) pF = mul;
		else if (!strcmp(op, "div")) pF = div;
		else if (!strcmp(op, "mod")) pF = mod;
		else { puts("�߸��� �����ڸ� �Է��ϼ̽��ϴ�."); pF = NULL; }
	} while (pF == NULL);
	printf("���� ��� = %.2lf\n", pF(num1, num2));
	
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
