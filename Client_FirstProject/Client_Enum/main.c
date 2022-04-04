#include <stdio.h>
#pragma warning(disable : 4996)

/* FSM(Finite State Machine)
���� ���� �ӽ� */

/* enum : ������ ����������� �ڷ����� ��������*/

enum tag_Subject { KOREAN, ENGLISH, MATH, MAXSUBJECT };

/* �÷��̾� ���°� ���������϶�
1. �ƹ��͵� ���Ҷ�
2. �ȱ� 
3. �޸���
4. �����ϱ� 
5. �����ϱ� ���� ������
�̷� ���µ��� ���������� ����ϸ� ����ϱ� �����ؼ� �̸��� �ְ� ������ ����ϴ� ��찡 ����.*/
enum Player_State {
	Wait = 1, Walk, Run, Attack, Jump, 
};
enum Jump_State {
	Idle, PrepareJump, InFlight, Falling, OnGround, 
	/* ��� �����غ� ������ ���������� ���� ������ ������ ��ȸ�ϴ� ���ۿ� �̸� �ٿ��� ���� üŷ ���� ����� ����*/
};
int playerState;
int main(void) {
	int Subject[MAXSUBJECT];
	Subject[KOREAN] = 100;
	Subject[ENGLISH] = 80;
	Subject[MATH] = 88;

	for (;;) {
		scanf("%d", &playerState);

		if (playerState == -1) break;

		switch (playerState) {
		case Wait:		printf("������...\n"); break;
		case Walk:		printf("�ȴ� ��...\n"); break;
		case Run:		printf("�޸��� ��...\n"); break;
		case Attack:	printf("����!\n"); break;
		case Jump:		printf("����!\n"); break;
		default:		printf("���� �ൿ���� ĳ���Ͱ� �������� ���߽��ϴ�.\n"); break;
		}
	}

	return 0;
}