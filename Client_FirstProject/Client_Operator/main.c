#include <stdio.h>

int main(void) {

	/* ���Կ����� 
	������ ���� �������� ���� ���� ����(�޸�)�� ����*/
	int intResult = 0;
	double doubleResult = 0.0;

	/* ���������
	+, -, *, /, % */
	intResult = 3 + 4;
	doubleResult = 3.0 + 4.0;
	printf("%d, %lf\n", intResult, doubleResult);
	
	intResult = 2 - 1;
	doubleResult = 4.0 - 3.0;

	intResult = 3 * 4;
	doubleResult = 3.0 * 4.0;

	/* ������ ������ ���ǻ����� 0���� ������ �ʵ��� ��������*/
	intResult = 3 / 4;
	doubleResult = 3.0 / 4.0;
	printf("%d\n%lf\n", intResult, doubleResult);

	/* ������ ������ ���������� ����� �� �ִ�.
	�������� ����������� 0�� ��ȯ������ �ƴ϶�� ���������� ��ȯ�ϴ� ������
	������ ������� ¦������ Ȧ������ Ȯ���ϴµ� ����� �� �ִ�.*/
	intResult = 3 % 4;
	doubleResult = 3 % 4;

	/* ��ȣ������*/
	intResult = +3;
	intResult = -3;

	intResult = 0;
	/* ���� ���Կ�����
	Result = Result + �� ó�� �� ������ ���� �����ϰ� �ٽ� ������ �����ϰ���� �� �������� �ι�����ϴ� �������� �ִ�
	�̰��� �ذ��ϴ� ���� ���� ���Կ�����*/
	intResult += 1;
	intResult += 1;
	printf("%d\n", intResult);


	/* ++, -- ����������*/
	intResult++;
	printf("%d\n", intResult++);
	printf("%d\n", ++intResult);

	/* ���迬���� 
	>,<,>=,<= ��ȣ�� �ݵ�� �����ʿ� �پ���Ѵ�.*/
	

	return 0;
}