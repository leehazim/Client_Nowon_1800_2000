#include <stdio.h>
#include "OperationFuctions.h"

int opCount;
int count;
/* ������Ͽ��� ����� ���������� �ҽ����� �Լ����ΰ� �ƴ� ������ ����Ϸ��� �ϸ� �����߻� �ߺ����� ���� �ϴ� ���� ����� ������ �̹� �ʱ�ȭ�� �� ����������
���� �ѵ������ �ȵȴ�.*/
/* static (����) Ű���� �޸� ���� �Ҵ��� �Ұ����� Ű���� �ν��Ͻ�ȭ�� �Ұ����ϰ� �ϴ� Ű����
���� ���� ���� = �ٸ� �ҽ����Ͽ��� ������ �� ���� ���� 
*/

int main(void) {
	printf("1 + 2 = %d\n", sumInt(1, 2));
	printf("2 - 1 = %d\n", subInt(2, 1));
	printf("opCount = %d\n", opCount);
	
	printf("%d\n", count);
	return 0;
}