#include <stdio.h>

int main(void) {

	printf("%d\n", 1);
	printf("%c\n", 65);
	printf("0x%X\n", 'A');
	printf("%.10f\n", 1.123456789F);
	printf("%.10lf\n", 1.123456789);
	printf("%s\n", "�ȳ��ϼ���.");
	printf("0x%X\n", 0xfaed);

	/* ���Ĺ���
	 ���ڿ� ���� ���Ĺ��ڸ� ����ؼ� ���ڸ� ǥ���� �� �ֵ���
	 �ش� ���� ��ġ�� ���� ������ �� �ִ�.
	 printf("format", argu, argu); format => "���� = %d, �̸� = %s, Ű =  %.2f \n" 
	 ���� %�� �����ϴ� �͵�.*/

	/* ����� || Ư������ 
	\ : BackSlash (������ ������� ���ĵ��� ������ �� ���) \n, \t, \a, \0, \\, \"��...
	n : NewLine �ٹٲٱ�
	r : Carriage return Ŀ���� �ش��� ���� ������ �ű�
	b : BackSpace Ŀ����ġ�� ��ĭ �������� �̵�
	t : tab��ŭ ����
	a : Beep, �߼Ҹ����� */

	return 0;
}