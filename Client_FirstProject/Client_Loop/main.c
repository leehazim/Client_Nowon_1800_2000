#include <stdio.h>

int main(void) {
	/* while : Ư�� ���ǿ� ���� ������ �ݺ� ����
	���� while(���ǹ�) {���ǹ��� ���϶� �ݺ��� ����} */

	/* do~ while : �� do ���� ������ �켱 �����ϰ� ���� ���ǹ��� ���̸� �ٽ� �ݺ��� ������ �ݺ���
	do{ �ݺ������� ����}while(���ǹ�);  */

	/* ������ �׻� ���̸� �ݺ����� ���ѷ������ �Ѵ�.*/
	/* break, continue break�� ���� ����� �ݺ����� ���߰�
	continue�� ���� ����� �ݺ������� ���ư���.
	���� ����� �ݺ����̶�� �ϸ� ���߹ݺ����ϰ�� for {for{continue}}�̸� ���� for������ ���ư���.
	break�̸� ������ for���� ����*/

	int sum = 0; 
	while (sum < 10) sum += 1; 
	printf("%d\n", sum);
	
	sum = 0;
	while (0) {
		printf("ahahahahah111111\n"); 
		sum++;
		if(sum == 10) break;
		continue;
		printf("ahahahahah222222\n");
	}
	printf("while statement is over\n");

	int count = 0;
	while (count < 5) {
		printf("while count : %d\n", count);
		count++;
	}
	printf("while statement is over\n");

	/* do - while*/
	do {
		puts("do while OutPut");
	} while (0);

	/* for Loop
	while���� ���� �ݺ��������� �ݺ��� ������ ���� ������ �����ϴ�. �ݺ� �Ҷ����� Ư�� �Լ��� ������ �� �ִ� �ݺ���
	for(�ʱ��;���ǹ�;������) {������ ����} ������� ����ȴ�.
	�ʱ��, ���ǹ�, ������ �ڸ��� ������̵��� ������ �����ϴ�, ��� ������ �����ϴ�.
	*/
	
	for (int i = 0; i < 10; i++) {
		//printf("%d\n", i);
	}

	/* for�� ���� continue break*/
	for (int i = 0;;i++) {
		if (i < 5) continue;
		else printf("%d\n", i);
		if (i == 10) break;	
	}
	
	return 0;
}