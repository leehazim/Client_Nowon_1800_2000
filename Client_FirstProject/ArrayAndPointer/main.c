#include <stdio.h>
#pragma warning(disable: 4996)
#define MAX 5

void OutArr(int ar[], int len) {
	//int len = sizeof(ar); /* �Ű������� �ᱹ �������̴�.  �׷��� sizeof �����ڸ� ����ص� �������� ũ�Ⱑ ���û��̴�.*/
	for (int i = 0; i < len; i++) 
		printf("%d ", ar[i]);
}

int main(void) {

	int ar[MAX] = { 10, 20, 30, 40, 50 };
	int* pAr = ar, i;

	//for (i = 0; i < MAX; i++) scanf("%d", pAr+i);
	//for (i = 0; i < MAX; i++) printf("%d ", *pAr++);
	printf("%p\n", ar);
	printf("%p\n", ar + 4);
	printf("%p\n", &ar[4]);

	printf("%p\n", ar + 4); /* �迭 �ּҿ��� �������� * 4��ŭ�� ���� (�迭�� 4ĭ�� �ǳʶڰ�ó��) �� �ּҸ� ������*/
	printf("%d\n", *ar);  /* �ּҿ��� ���������� �°� ���� ������ (int)�� 4����Ʈ ����*/

	int* p1, * p2;
	p1 = &ar[4]; p2 = &ar[0];
	printf("%d\n", p1 - p2); /* ������ ���� ������ �� �����Ͱ��� �Ÿ��� ��Ÿ����. (�迭���� �λ����� �Ÿ��� ã�����ؼ� ���
							 ���� ������ ���� �������� ���̰Ÿ��� �������� �ǹ��ϴ°� ����.*/
	printf("%d\n", p1 < p2); /* �޸𸮻󿡼��� ������� �ּҸ� �� �� �ִ�.*/

	int a = 1, b = 2;
	int* q1 = &a, *q2 = &b;
	printf("%d\n", q1 - q2);

	// �������� �������� (����� ����)
	/*printf("%d\n", (*p2)++);
	printf("%d\n", *p2++);
	printf("%d\n", (*p2)++);
	printf("%d\n", *++p2);
	*/
	OutArr(ar, sizeof(ar)/sizeof(ar[0]));

	return 0;
}