#include <stdio.h>
#include <stdlib.h> /* �����Ҵ��� �ϱ����� ���ԵǴ� ������� �̰� �ܿ�� �� �ȿ� �������� �Լ�������*/
#pragma warning(disable : 4996)

/* ���� �޸� �Ҵ� (HEAP������ �޸𸮸� �Ҵ�)
�����߿� �ʿ��� ������ ���������� �Ҵ��ϱ����� ����

���� �޸� �Ҵ��� ���� �Լ��� 
malloc(size), calloc(count, data_size), realloc(ptr, size) 
malloc�� �������� �Ҵ� �� �ʱ�ȭ�� ������ �ʾƼ� �����Ⱚ�� ������������
calloc�� �������� �Ҵ� �� 0���� �ʱ�ȭ�� ���ش�. 
realloc�� �������� �̹� �Ҵ�� �޸𸮸� ���ϴ� ������� �ٽ� �Ҵ����ش�.
malloc, calloc, realloc���� ��� void*�� �����ؼ� ������ ������ �������� ĳ�����ؾ���

�迭�� ũ��� ������� �پ��� ������ ���� �Ҵ�Ǿ�� �Ҷ�,
��, �����Ͻÿ� �迭�� ũ�⸦ ���� �� ������ ����ϴ� ��

realloc :
ũ�⸦ �����ϰ������ �� �� �ּ� ���� �����Ͱ��� �����ϰ������
*/

int main(void) {
	int* a = (int*)malloc(sizeof(int));
	free(a);
	a = (int*)calloc(1, sizeof(int));
	*a = 3; printf("%d\n", *a);

	free(a);/* �����Ҵ�� �޸𸮴� ���� ���������������� ���α׷� �����Ŀ��� �� �޸𸮰����� �ü������ �ݳ������ʴ´�*/
			/* �׷��� �����Ҵ� ���� ������ �����ͷ� �����Լ��� ȣ��*/

	//a = (int*)malloc(count * sizeof(int));
	int count = 16;
	a = (int*)calloc(count, sizeof(int));
	for (int i = 0; i < count; i++) a[i] = i + 1;

	a = (int*)realloc(a, 20 * sizeof(int));
	for (int i = count; i < 20; i++) a[i] = i + 1;
	for (int i = 0; i < 20; i++) printf("%d ", a[i]);
 	free(a);

	return 0;
}