#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

/* ���� ����� 
1. �ϵ��ũ�� �ִ� ������ ��ũ��Ʈ���� �����ϰų� ��ũ��Ʈ�� ������ �ϵ��ũ�� �����ϴ� ���
������ �޸𸮰� �ƴ϶� ��ũ�� �����ϴ� ����̶�� �����ϴ� �͵� ������ ����.

HDD �����͸� ������ �б�/���� �ӵ��� ���ؼ� ��ϴ����� �а��⸦ �Ѵ�.
�̶� ��ϴ����� ����ü�� ���·� ����Ѵ�.
struct FILE{
	��� ù��° �ּ�
	����
	ũ��
	�ۼ� ��¥
	�ۼ��� ��........
};�� ����Ǿ��ִ�.

���۸� ����� ����ü�� �޸𸮿� ����ϴ°� ��Ʈ���̶�� �Ѵ�.
����: �ϵ��ũ�� �ִ� ���� ������ �ӽ÷� �����ϰ� �ִ� ����(��Ȯ�ϰԴ� �޸𸮿� �ö�� �ϵ��ũ�� ���ϳ����� ����Ű�� ������
�ϵ��ũ���� �ø� ����ü == ��Ʈ��(stream) ����
���۸� ���ؼ� ���� �е� ���� ������ �ϵ� HDD�� �ǽð����� ������ �̷�� ������ �ʴ´�.
�޸𸮻󿡼� �����ɶ� ������ �̷�� ����.

�ü���� �⺻������ 3���� ��Ʈ���� �����Ѵ�.
1. stdin	:	(Ű����) �Է� ��Ʈ�� ex) scanf(�⺻���� �Լ�), getchar() �޽��� ť, 
2. stdout	:	(�����) ��� ��Ʈ�� 
3. stderr	:	���� ��Ʈ��
*/
int main(void) {
	
	/* ǥ�� ����� �Լ�
	printf, scanf, puts, _putch, gets, getch,*/

	/*
	fopen(���� ���, ���) 
	�⺻������ ���� ���α׷� ������ �ִ� �������� ������ �˻��Ѵ�.
	�ϵ��ũ�κ��� ������ �о�� File Stream�� ����ϴ� �Լ�
	fopen ��� ����(���� ���� ���)
	1. r : �б� ���� (Read Mode)
	2. w : ���� ���� (Write Mode) == �����Ͱ� NULL�� ��ȯ�Ǹ� ���� ������ ���������� ��Ÿ����.
	3. a : ���ٿ����� ���� (Append Mode)
	4. r+ : �б�/���� ���� ==> ������ ������ ����
	5. w+ : �б�/���� ���� ==> ������ ������ ����
	6. a+ : �б�/���ٿ����� ���� ==> ������ ������ ����
	7. rb : ���̳ʸ� ���� �б� ���� -- ������ ������ ���ϵ��� �о�ö� ���ȴ�.
	8. wb : ���̳ʸ� ���� ���� ����
	9. ab : ���̳ʸ� ���� ���ٿ����� ����
	fclose() 
	File Stream�� ���ۿ� ��ϵ� ������ ����.
	*/
	
	char Mes[128];
	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	FILE* pf1 = fopen("Test.txt", "r");
	if (!pf1) { /* �б��� ���� ���⿡�� �����Ͱ� NULL�̸� ������ �д� ���� �����ߴ�.(������ �������� �ʰų� �������� �Ұ����� ������ ���)*/
		puts("failed to open File");
		exit(-1);
	}
	printf("%c\n", fgetc(pf1));
	printf("%c\n", fgetc(pf1)); /*�ٽ� �ڷ� �ǵ��� ������ ����ϴ� �Լ��� ������..*/
	fclose(pf1); /* ���� ���� ������ ���õ� ���� �Ҵ�ó�� ���� ���־�� �Ѵ�. ���� ���� �Լ�.*/
	
	pf1 = fopen("test.txt", "r");
	fgets(Mes, 20, pf1);
	printf("%s\n", Mes);
	fclose(pf1);

	pf1 = fopen("test.txt", "a");
	for (int i = 0; i < 10; i++) fprintf(pf1, "%d ", ar[i]);
	fclose(pf1);

	FILE* pf2 = fopen("Test2.txt", "r");
	if (!pf2) {
		puts("Failed to Read");
		exit(-1);
	}
	char IsOverride = 'N';
	printf("Test2.txt�� ����ڽ��ϱ�? : ");
	IsOverride = getch();
	if (tolower(IsOverride) == 'n') {
		puts("Test2.txt ���α׷� ����");
		fclose(pf2);
		exit(0);
	}

	pf2 = fopen("Test2.txt", "w"); /* ������ ������ ������ �ϰ�, ������ ������ ������ ���θ� ��� ����� �۾��� �����Ѵ�.*/
	if (!pf2) {
		puts("Failed to Create File");
		exit(-2);
	}
	for (int i = 0; i < 10; i++) fprintf(pf2, "%d ", ar[i]);
	puts("File save Complete");
	fclose(pf2);
	/* ���� ���� ������ ������ �ٷ� ������ ����.*/
	char first[10] = "abc";
	char second[10] = "def";
	char temp[10];

	strcpy(temp, first);
	strncpy(first, second, 1);
	strncpy(second, temp, 1);
	printf("%s, %s\n", first, second);

	/* Append Mode : 
	������ ������ ���� �����Ѵ�. �׷��� NULL�� ��ȯ�Ѵٴ°� ���������Ѱ�*/
	FILE* pf3 = fopen("Test3.txt", "a");
	if (pf3 == NULL) {
		puts("Test3.txt ������ �����߽��ϴ�.");
		exit(-2);
	}
	fprintf(pf3, "�ȳ�");
	fclose(pf3);

	/* �پ��� ������ ���ڿ� �����*/
	FILE* pf4;
	FILE* pf5;

	char name[20] = "chulsu";
	int korean = 10, english = 20, math = 30;
	double average = (double)(korean + english + math) / 3;
	
	pf4 = fopen("Chulsu.txt", "r");
	if (!pf4) {
		puts("Chulsu���� �б� ����");
		exit(-1);
	}
	/* Chulsu.txt�� ���Ͽ� ���� ���ڿ�, ���� ���� ���� ���� �о �������� �����.*/
	fscanf(pf4, "%s %d %d %d", name, &korean, &english, &math);
	fclose(pf4);
	average = (double)(korean + english + math) / 3;
	
	pf5 = fopen("RealChulsu.txt", "w");
	if (!pf5) {
		puts("���� ���� ����");
		exit(-2);
	}
	fprintf(pf5, "%s %d %d %d %.2lf", name, korean, english, math, average);
	fclose(pf5);
	puts("����Ϸ�");

	/* ��뷮 ������ ó���ؾ��Ҷ� ������� �ӵ��� ���ؼ� rb���� ����Ѵ�. binary -> 2����
	fread�� fwrite �Լ��� ����Ѵ�.(����� �������°� �ǹ̰� ��������.) 
	2������ �ӵ��� ������������ ���� ��ü�� �������� ����Ǵ� ����� �ƴϴ�.
	������ �������� ������ ������ ��뷮���Ͽ� �����ϴ�.*/
	FILE* fp;
	fp = fopen("TestBinary.txt", "wb");
	char a[] = "adkcviekkdkkdvisd";
	fwrite(a, sizeof(a), 1, fp);
	fclose(fp);
	
	return 0;
}