#include <stdio.h>
#pragma warning(disable : 4996)
#pragma warning(disable : 6031)

int main(void) {
	
	double* pd1, * pd2, d1, d2;
	double d;
	double* pd = &d;
	
	d1 = 2.0; d2 = 4.0; /* ���ʱ�ȭ*/
	pd1 = &d1; pd2 = &d2; /* ������ ��ũ*/

	/* �� ��Ȳ���� ���Կ����� ���� *pd1, *pd2, d1, d2�� �������� 6�� ����� �� �ִ� 4���� ���
	�� ������ ���꿡 �ѹ����� ��� ����*/

	// 1
	printf("%.1lf\n", d1 + d2);
	
	// 2
	printf("%.1lf\n", d2 + *pd1);

	// 3 
	printf("%.1lf\n", d1 + *pd2);

	// 4
	printf("%.1lf\n", *pd1 + *pd2);

	/* ������ ���� pd�� ������ ���� ����Ҷ��� �Է¹������� ���*/
	scanf("%lf", pd);
	printf("%lf\n", *pd);
	/*printf("%lf\n", *&pd);*/

	return 0;
}