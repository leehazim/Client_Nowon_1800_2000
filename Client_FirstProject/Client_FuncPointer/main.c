#include <stdio.h>

int Sum(int, int);
int GetFactorial(int, int); /* �迭�� ���������� �Լ��� �̸����� ����ϸ� �Լ��� �����ϰ� �ִ� �޸𸮸� ����Ű�� �������̴�.*/
int Factorial(int, int);

int main(void) {

	int arr[3]; /* �迭�̸����� ����ϸ� �迭�� �ּҸ� ����Ű�� ������*/

	int (*p)(int, int);
	p = Sum; 
	printf("%d\n",p(1, 2));

	p = GetFactorial;
	printf("%d\n", p(5, 0));

	p = Factorial;
	printf("%d\n", p(5, 0));

	/* void�� ������*/
	void* vp;
	/* ��Ȳ�� ���� �������� Ÿ���� �����͸� �޾ƾ��� �� ����Ѵ�. �⺻������ ��� Ÿ���� �����͸� �޴� ���� 
	�����ϴ�. ������ ���������� �д� ����� ���� ���� ���� ���� ����.
	������, ĳ�����ؼ� ����ϸ� ��� Ÿ���� �������� �����͸� ��ũ�� �� �ִ� ������ �ȴ�.
	�����ڰ� �Ű��� ���̽Ἥ ����ؾ� �Ѵ�.*/

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