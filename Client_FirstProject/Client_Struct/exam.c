/* 구조체 스왑함수 만들기*/
#include <stdio.h>

typedef struct tag_Position {
	int x, y;
}Pos, *LPPos;

void SwapStudent(LPPos,LPPos);
void VoidSwap(void*, void*, const char*);

int main(void) {

	Pos P1 = { 10,10 }, P2 = { 20,20 };
	printf("Before Position : ");
	printf("P1: x = %d, y = %d ", P1.x, P1.y);
	printf("P2: x = %d, y = %d\n", P2.x, P2.y);
	Swap(&P1, &P2);
	printf("After Position : ");
	printf("P1: x = %d, y = %d ", P1.x, P1.y);
	printf("P2: x = %d, y = %d\n", P2.x, P2.y);

	return 0;
}

void SwapStudent(LPPos P1, LPPos P2) {
	Pos temp = *P1; *P1 = *P2; *P2 = temp;
}

