#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

/* ������ �迭�� �迭�� �������� ����� ����*/
/* �Ű������� ������ main�Լ� 
 C\: > �������� �̸�.exe
 �ܼ� ������ ������ Ư���� ����̳� �ɼ��� �ο��Ҷ� ���ڸ� �ش�.
 C\:>�������� �̸�.exe ���ڿ� ���ڿ�
��� ���ڿ��� �����Ҵ��� �Ŀ� main �Լ� ���ڷ� �Ѱ��ش�. */
int main(int argc, char** argv) {

	/*argc == argument count ���ڿ� ����
	argv == argument vector ���ڿ� �迭, ������ NULL�߰�*/
	
	for (int i = 0; i < argc; i++) 
		printf("argv[%d] = %s\n", argc, argv[i]);
	
	while (*argv) printf("%s\n", *argv++);

	char input[100];
	int count = 3;
	char** spp;
	
	spp = (char**)malloc(count * sizeof(char*));
	if (spp == NULL) exit(-1);

	for (int i = 0; i < count; i++) {
		scanf("%s", input);
		spp[i] = (char*)malloc(strlen(input) + 1);
		strcpy(spp[i], input);
	}

	for (int i = 0; i < count; i++) {
		printf("%s\n", spp[i]);
		free(spp[i]);
	}
	
	free(spp);
	return 0;
}