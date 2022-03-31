#include <stdio.h>
#include <windows.h>
#pragma warning(disable : 4996)
/* 구조체:
 여러가직 데이터형을 묶어서 관리할 수 있는 사용자 정의 데이터
 배열과는 다르게 서로 다른 타입의 데이터들을 가질 수 있는 것이 다르다
 선언방법:
 struct 태그 이름{ 멤버변수들 } 변수명;
 C++에서는 태그이름의 자격이 상승해서 바로 데이터형을 만들 수 있다. C는 안됨*/

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

/* 구조체를 포함하는 구조체*/
struct tag_StuList {
	struct tag_Student Students[3];
	int CntStudent;
};

struct tag_StuList Student_List = { 
	{/* 구조체 배열 초기화*/
	{"Lim", 100, 100, 100, (double)(100 + 100 + 100) / 3},
	{"joshua", 80, 90, 20, (double)(80 + 90 + 20) / 3}, 
	{"Lee", 70, 60, 30, (double)(70 + 60 + 30) / 3},
	},
	3 /* 정수형 변수 초기화*/
};

/* 비트 필드 구조체 
메모리 낭비를 줄이기 위한 방법으로 메모리 순서대로 비트를 할당한다.
단, 값이 해당 비트수를 넘어가게 되면 오버플로우 발생한다. 개발자의 주의가 필요하다.*/
struct tag_Time {
	unsigned short sec : 6;	/* LSB부터 bit 5번까지 할당됨*/
	unsigned short min : 6;	/* bit 6 ~ 11번 까지 할당됨*/
	unsigned short hour : 4;	/* bit 12 ~ 15까지 할당됨*/
};
/* 비트 구조체의 필드는 포인터로 참조할 수 없다. */\
/* 비트 구조체는 기본형의 데이터 크기 만큼 우선 할당 이후, 그 비트를 잘라서 사용한다.*/
int main(void) {
	
	/* 구조체 변수에서 구조체의 멤버에 접근하기 위한 연산자 멤버연산자(도트 연산자) : . 
	구조체변수.멤버변수*/
	struct tag_Coord Coord1;
	struct tag_Coord Coord2;
	struct tag_Time STime;

	Coord1.x = 10;
	Coord1.y = 20;
	Coord2 = Coord1; /* == Coord2.x = Coord1.x; Coord2.y = Coord1.y;*/
	/* 배열은 불가능 했지만 구조체는 변수끼리의 대입이 가능하다.*/
	/* 구조체는 값참조를 사용한다. 배열이름은 포인터였지만 구조체의 경우에는 그렇지 않다.
	구조체도 포인터를 이용해서 접근은 가능하지만 구조체 자체가 값을 불러올때는 주소참조연산이 아니다.*/
	Coord2.x = 1;
	Coord2.y = 2;
	/* 포인터 방식으로 접근한 것이었으면 Coord2를 변경시 Coord1도 변경되었어야한다. 하지만 변경되지 않았다.
	값을 바로읽는 방식이기 때문이다.*/
	printf("좌표1 : (%d,%d)\n", Coord1.x, Coord1.y);
	printf("좌표2 : (%d,%d)\n", Coord2.x, Coord2.y);

	printf("Coord 구조체의 바이트 = %d\n", sizeof(struct tag_Coord));
	printf("Player 구조체의 바이트 = %d\n", sizeof(Player));
	printf("Student 구조체의 바이트 = %d\n", sizeof(struct tag_Student));

	/* 구조체 포인터*/
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

	/* -> : 구조체 포인터 멤버 참조 연산자 (구조체 포인터)->포인터 변수에 링크된 구조체의 멤버.(간접 멤버 연산자)*/
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