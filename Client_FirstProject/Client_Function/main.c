#include <stdio.h>

	/* ��ȯ�� �Լ��̸�(�Ű����� ���)*/

void HowCanDoThis();
int IsOkay(int);
int sum(int, int);
void doSomeThing();
/* �������� ��������
 ���������� ���� �̸��� ���������� ���� ���������� �켱���� ������.
 ���������� ���ÿ� �Ҵ������
 ���������� �����͸޸𸮿����� �ٸ��� �־ �� ������ ����ִ� �ֱⰡ �ٸ���.*/

/* �׷��� ���������� �ڽ��� ���� ����ϰ� �־���ϴ� ��찡 �ִ�. ���������� ���輺�� ���������� �Ѱ踦 �غ��� ����
���������� ���� �������� ����� ���������� �ٽ� �� ������ ȣ��ɶ� ���� ȣ����� ���� ����ϰ��ִ�.
static �������� ������*/
int GlobalCount;


/* ��� �Լ�
�Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ�*/

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

	static int Count = 1  /* ����� �ʱ�ȭ�� ���� �ʾƵ� 0���� �ʱ�ȭ �ȴ�. �ʱⰪ�� �ڵ����� �൵ �ʱ�ȭ�� �� �ѹ��� �̷������ ������ �������.*/;
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