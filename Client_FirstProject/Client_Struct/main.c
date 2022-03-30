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
	//char Name[20];
	double Average;
	int Korean, English, Math;
};

int main(void) {
	
	/* 구조체 변수에서 구조체의 멤버에 접근하기 위한 연산자 멤버연산자(도트 연산자) : . 
	구조체변수.멤버변수
	*/
	struct tag_Coord Coord1;
	struct tag_Coord Coord2;

	Coord1.x = 10;
	Coord1.y = 20;
	Coord2 = Coord1; /* 배열은 불가능 했지만 구조체는 변수끼리의 대입이 가능하다.*/
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
	return 0;
}