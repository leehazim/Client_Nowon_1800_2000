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
	char Name[20];
	double Average;
	int Korean, English, Math;
};

/* ����ü�� �����ϴ� ����ü*/
struct tag_StuList {
	struct tag_Student Students[3];
	int CntStudent;
};

struct tag_StuList Student_List = { 
	{/* ����ü �迭 �ʱ�ȭ*/
	{"Lim", 100, 100, 100, (double)(100 + 100 + 100) / 3},
	{"joshua", 80, 90, 20, (double)(80 + 90 + 20) / 3}, 
	{"Lee", 70, 60, 30, (double)(70 + 60 + 30) / 3},
	},
	3 /* ������ ���� �ʱ�ȭ*/
};

/* ��Ʈ �ʵ� ����ü 
�޸� ���� ���̱� ���� ������� �޸� ������� ��Ʈ�� �Ҵ��Ѵ�.
��, ���� �ش� ��Ʈ���� �Ѿ�� �Ǹ� �����÷ο� �߻��Ѵ�. �������� ���ǰ� �ʿ��ϴ�.*/
struct tag_Time {
	unsigned short sec : 6;	/* LSB���� bit 5������ �Ҵ��*/
	unsigned short min : 6;	/* bit 6 ~ 11�� ���� �Ҵ��*/
	unsigned short hour : 4;	/* bit 12 ~ 15���� �Ҵ��*/
};
/* ��Ʈ ����ü�� �ʵ�� �����ͷ� ������ �� ����. */\
/* ��Ʈ ����ü�� �⺻���� ������ ũ�� ��ŭ �켱 �Ҵ� ����, �� ��Ʈ�� �߶� ����Ѵ�.*/
int main(void) {
	
	/* ����ü �������� ����ü�� ����� �����ϱ� ���� ������ ���������(��Ʈ ������) : . 
	����ü����.�������*/
	struct tag_Coord Coord1;
	struct tag_Coord Coord2;
	struct tag_Time STime;

	Coord1.x = 10;
	Coord1.y = 20;
	Coord2 = Coord1; /* == Coord2.x = Coord1.x; Coord2.y = Coord1.y;*/
	/* �迭�� �Ұ��� ������ ����ü�� ���������� ������ �����ϴ�.*/
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

	/* ����ü ������*/
	struct tag_Student Student_A;
	struct tag_Student* pStudent;
	struct tag_Student Student_B = { "Lim", 100, 80, 50, (double)(100 + 80 + 50) / 3 };
	
	strcpy(Student_A.Name, "Lee");
	Student_A.English = 80;
	Student_A.Korean = 60;
	Student_A.Math = 40;
	Student_A.Average = (double)(Student_A.English + Student_A.Korean + Student_A.Math) / 3;

	printf("%s\n", Student_A.Name);
	printf("%lf\n", Student_A.Average);

	/* -> : ����ü ������ ��� ���� ������ (����ü ������)->������ ������ ��ũ�� ����ü�� ���.(���� ��� ������)*/
	pStudent = &Student_A;
	printf("%s\n", pStudent->Name);
	printf("%lf\n", pStudent->Average);
	
	pStudent->English = 10;
	printf("%d\n", pStudent->English);
	printf("%d\n", Student_A.English);
	
	printf("%d\n", sizeof(STime));
	STime.hour = 5;
	STime.min = 59;
	STime.sec = 59;
	printf("%d:%d:%d\n", STime.hour, STime.min, STime.sec);

	struct tag_Student StudentA;
	struct tag_Student StudentB;
	struct tag_Student StudentC;
	StudentA = Student_List.Students[0];
	StudentB = Student_List.Students[1];
	StudentC = Student_List.Students[2];

	for(int i = 3; i > 0; i--) printf("Number = %d Student Name = %s, Average = %lf\n",
		Student_List.CntStudent - i, Student_List.Students[3 - i].Name, Student_List.Students[3-i].Average);

	printf("%d\n", sizeof(struct tag_Time));

	return 0;
}