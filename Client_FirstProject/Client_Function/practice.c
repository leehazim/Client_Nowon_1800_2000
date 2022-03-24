#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 4996)

int sum(int, int);
int sub(int, int);
int div1(int, int);
int mul(int, int);
int mod(int, int);
int OperationCount;

int Factorial(int num) {
	if (num == 1)	return 1;
	else			return num * Factorial(num - 1);
}

int main(void) {
	int a, b;
	char str[5];
	int result = 0;
	
	for (;1;) {

		printf("정수입력 >> ");
		scanf("%d", &a);
		printf("정수입력 >> ");
		scanf("%d", &b);
		printf("호출하실 함수를 입력해주세요 : ");
		scanf("%s", str);
		
		if (!strcmp(str, "sum"))		{ result = sum(a, b);	}
		else if (!strcmp(str, "sub"))	{ result = sub(a, b);	}
		else if (!strcmp(str, "div"))	{ result = div1(a, b);	}
		else if (!strcmp(str, "mul"))	{ result = mul(a, b);	}
		else if (!strcmp(str, "mod"))	{ result = mod(a, b);	}
		else if (!strcmp(str, "end"))	{ break;				}

		printf("%d\n", result);
		printf("%d\n", OperationCount);
		
	}

	result = 1;
	for (a = 5; a > 0; a--) result *= a;
	printf("%d\n", result);

	return 0;
}

int sum(int a, int b) {
	OperationCount++;
	return a + b;
}

int sub(int a, int b) {
	OperationCount++;
	return a - b;
}

int div1(int a, int b) {
	OperationCount++;
	if (b == 0) return 0;
	return a / b;
}

int mul(int a, int b) {
	OperationCount++;
	return a * b;
}

int mod(int a, int b) {
	OperationCount++;
	if (b == 0) return a;
	else return a % b;
}