#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)
#pragma warning(disable : 6031)

#define Swap(type, a, b) do{ type t = a ; a = b; b = t;}while(0)

void func(void* Data1, void* Data2, const char* DataType) {
	
	if (!strcmp(DataType, "int")) {
		Swap(int, *(int*)Data1, *(int*)Data2);
		return;
	}
	if (!strcmp(DataType, "char")) {
		Swap(char, *(char*)Data1, *(char*)Data2); 
		return;
	}
	if (!strcmp(DataType, "double")) {
		Swap(double, *(double*)Data1, *(double*)Data2); 
		return;
	}
}

void SwapFunc(int* a, int* b) {
	int t = *a; *a = *b; *b = t;
}

int main(void) {
	int a = 1, b = 3;
	double c = 1.2, d = 3.4;
	func(&a, &b, "int");
	printf("a = %d, b = %d\n", a, b);
	func(&c, &d, "double");
	printf("c = %.2lf, d = %.2lf\n", c, d);

	return 0;
}

//int main(void) {
//
//	int c = 1, c2 = 2;
//	int* p1 = &c, * p2 = &c2;
//	sum(p1, p2, "int");
//	printf("%d\n", c);
//	
//	/* *: �������� ������
//	�������� : ���� ���� �����ϴ� �� ���� ������� �Ѵ�. ���� R value ���
//	�����̸��� �ٷ� �����ٰ� ���� ���
//	
//	���������� �޸��� �ּҸ� �̿��ؼ� �ּҷ� �����Ͽ� ���� ����ϴ� ����� ���Ѵ�.*/
//
//	/* * : ������
//	�������� �ٷ� �ڿ� �پ ������ �ּҸ� ������ �� �ִ� ������� ���� ǥ���ϱ� ���� ������, �����ڰ� �ƴϴ�.*/
//	int* p;
//	int a = 10;
//	p = &a;
//	printf("%d\n", a);
//	printf("%d\n", sizeof(a));
//	//printf("%d\n", &a);
//	printf("%p\n", &a);
//
//	double d = 1.23;
//	double* pd;
//	pd = &d;
//	//p = &d;
//	/* �����͵� ���� ���������̰�, ������ ������ ���������� ������� 4����Ʈ�� �Ҵ�޴´�
//	16��Ʈ ��ǻ�ʹ� 2����Ʈ*/
//	
//	/*printf("%d\n", sizeof(p));
//	printf("%d\n", sizeof(pd));
//	printf("%d\n", sizeof(*pd));
//	printf("%.2lf\n", *pd);
//	printf("%lf\n", *(double*)p);*/
//
//	/* ��� ���� ������\ ��� ������\ ��� ���� ��� ������*/
//	
//	const int* cp; /* �����ϰ� �ִ� ������ ���� ������ �� ����.(��� ���� ������)*/
//	cp = &a;
////	*cp = 1; ����.
//	int* const cp2 = &a; /* ������ ������ �ٸ� ���� �����ϴ� ���� �Ұ��� (����� ������)*/
//	
//	const int num = 1;
//	int* pNum = &num;
//	*pNum = 2; /* �޸� ��ü�� ������ΰ��� ���� ������ ������ ���� �ʾƼ� ��������δ� ����
//			   ������ ������ ������ �߻�*/
//	printf("%d\n", num);
//
//
//	/* �ٸ� ������������ ������ ������ �����Ѱ�?
//	������ �ϴ� int* �� double�� ������ �ּҸ� ���� �� �� ������ 
//	���� �д� ����� �𸣱⶧���� ���� �����ϰų� ������ ������ ������ �߻��Ѵ�.*/
//
//	//printf("p : %p\n", p);
//	//printf("pd : %p\n", pd);
//	//p = pd;
//	//printf("p : %p\n", p);
//	//*p = 11;
//	//printf("%d\n", *p);
//	//printf("%d\n", sizeof(*p));
//	//printf("%d\n", sizeof(*pd));
//	
//	int temp = 1;
//	int* pTemp = &temp;
//	double temp2 = 3.1f;
//	double* pTemp2 = &temp2;
//	printf("temp : %p\n", &temp);
//	printf("pTemp : %p\n", pTemp);
//	printf("temp2 : %p\n", &temp2);
//	printf("pTemp2 : %p\n", pTemp2);
//
//	pTemp = pTemp2;
//	puts("");
//	printf("temp : %p\n", &temp);
//	printf("pTemp : %p\n", pTemp);
//	printf("temp2 : %p\n", &temp2);
//	printf("pTemp2 : %p\n", pTemp2);
//	
//	*pTemp = 3;
//	puts("");
//	printf("%d\n", *pTemp);
//	printf("%lf\n", *pTemp2);
//	printf("%lf\n", temp2);
//
//	return 0;
//}