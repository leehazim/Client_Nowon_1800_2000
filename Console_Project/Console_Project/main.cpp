#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <Time.h>
#pragma warning (disable : 4996)

#define MAXENEMY 10
#define TRUE 1
#define FALSE 0

typedef struct tag_Player {
	int x, y;
	int dx, dy;
	char Shape;
}Player;

typedef struct tag_enemy {
	int exist;
	int x, y;
	int dx, dy;
	int nStay, nFrame;
	char Shape;
}Enemy;

void SetCursorXY(int x, int y) {
	COORD Position;
	Position.X = x;
	Position.Y = y;

	SetConsoleCursorPosition(, Position);
}

int main(void) {

	char key;
	Enemy Enemies[MAXENEMY];
	Player P;

	srand(time(NULL));
	P.x = 40;	P.y = 12; P.Shape = '@';
	SetCursorXY(10, 10);
	_putch('A');
	//for (; 1;) {
	//	system("cls");
	//	
	//	/* 게임 초기화 */
	//	for (int i = 0; i < MAXENEMY; i++) {
	//		Enemies[i].exist = TRUE;
	//		Enemies[i].x = rand() % 79 + 1;
	//		Enemies[i].y = rand() % 23 + 1;
	//		Enemies[i].Shape = 65 + (rand()% 24);
	//		Enemies[i].dx = (Enemies[i].x - P.x > 0) ? -1 : 1;
	//		Enemies[i].dy = (Enemies[i].y - P.y > 0) ? -1 : 1;
	//		Enemies[i].nStay = Enemies[i].nFrame = rand() % 15 + 5;
	//	}
	//	
	//	for (; 2;) {
	//		/* 적군 움직임*/
	//		/* 캐릭터 움직임*/
	//		/* 캐릭터와 적군 충돌 감지*/
	//	}

	//	Sleep(1000);
	//}
}