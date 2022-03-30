#include <stdio.h>
#include <windows.h>
#pragma warning(disable : 4996)
/* ����ü:
 �������� ���������� ��� ������ �� �ִ� ����� ���� ������
 �迭���� �ٸ��� ���� �ٸ� Ÿ���� �����͵��� ���� �� �ִ� ���� �ٸ���
 ������:
 struct �±� �̸�{ ��������� } ������;
 C++������ �±��̸��� �ڰ��� ����ؼ� �ٷ� ���������� ���� �� �ִ�. C�� �ȵ�*/

typedef struct tag_Player {
	char Name[64];
	int Hp, Mp, Int, Dex, Luk, Str;
	double Att, Def;
	double Exp;
}Player;

struct tag_Coord {
	int x, y;
};

struct tag_Student {
	//char Name[20];
	double Average;
	int Korean, English, Math;
};

int main(void) {
	
	/* ����ü �������� ����ü�� ����� �����ϱ� ���� ������ ���������(��Ʈ ������) : . 
	����ü����.�������
	*/
	struct tag_Coord Coord1;
	struct tag_Coord Coord2;

	Coord1.x = 10;
	Coord1.y = 20;
	Coord2 = Coord1; /* �迭�� �Ұ��� ������ ����ü�� ���������� ������ �����ϴ�.*/
					 /* ����ü�� �������� ����Ѵ�. �迭�̸��� �����Ϳ����� ����ü�� ��쿡�� �׷��� �ʴ�.
					  ����ü�� �����͸� �̿��ؼ� ������ ���������� ����ü ��ü�� ���� �ҷ��ö��� �ּ����������� �ƴϴ�.*/
	Coord2.x = 1;
	Coord2.y = 2;
	/* ������ ������� ������ ���̾����� Coord2�� ����� Coord1�� ����Ǿ�����Ѵ�. ������ ������� �ʾҴ�.
	���� �ٷ��д� ����̱� �����̴�.*/
	printf("��ǥ1 : (%d,%d)\n", Coord1.x, Coord1.y);
	printf("��ǥ2 : (%d,%d)\n", Coord2.x, Coord2.y);

	printf("Coord ����ü�� ����Ʈ = %d\n", sizeof(struct tag_Coord));
	printf("Player ����ü�� ����Ʈ = %d\n", sizeof(Player));
	printf("Student ����ü�� ����Ʈ = %d\n", sizeof(struct tag_Student));
	return 0;
}