#include "Define.h"
#pragma warning (disable : 4996)


int main(void) {

	char key;
	Enemy Enemies[MAXENEMY];
	Player P;

	srand(time(NULL));
	P.x = 40;	P.y = 12; P.Shape = '@';
	SetCursorXY(10, 10);
	
	system("cls");
	for (int i = 0; i < MAXENEMY; i++) Enemies[i].exist = FALSE;
		for (int i = 0; i < MAXENEMY; i++) {
			
				Enemies[i].exist = TRUE;
				Enemies[i].x = rand() % 79 + 1;
				Enemies[i].y = rand() % 15 + 1;
				Enemies[i].Shape = 65 + (rand() % 24);
				Enemies[i].dx = /*(Enemies[i].x - P.x > 0) ? -1 : 1*/0;
				Enemies[i].dy = /*(Enemies[i].y - P.y > 0) ? -1 : 1*/1;
				Enemies[i].nStay = Enemies[i].nFrame = rand() % 15 + 5;
				Enemies[i].Range = rand() % 15 + 1;
			
		}
		
	for (; 1;) {
		
		/* 게임 초기화 */
		for (; 2;) {
			/* 적군 움직임*/
			for (int i = 0; i < MAXENEMY; i++) {
				if (Enemies[i].exist == FALSE) continue;
				if (--Enemies[i].nStay == 0) {
					Enemies[i].nStay = Enemies[i].nFrame;
					SetCursorXY(Enemies[i].x, Enemies[i].y); _putch(' ');
					Enemies[i].x += Enemies[i].dx;
					Enemies[i].y += Enemies[i].dy;
					SetCursorXY(Enemies[i].x, Enemies[i].y); _putch(Enemies[i].Shape);
				}
				/*if (--Enemies[i].Range < 0) Enemies[i].exist = FALSE;*/
			}
			break;
			/* 캐릭터 움직임*/
			/* 캐릭터와 적군 충돌 감지*/
		}

		Sleep(10);
	}
}

void SetCursorXY(int x, int y) {
	COORD Position;
	Position.X = x;
	Position.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);
}