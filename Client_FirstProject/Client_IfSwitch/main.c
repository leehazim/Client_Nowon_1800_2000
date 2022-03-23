#include <stdio.h>
#pragma warning (disable:4996)

int main(void) {

	/* 코드의 흐름을 제어하는 문법
	1. 조건문 (if, switch)
	2. 반복문 (for, while, do_while)
	3. 분기문 (goto)*/

	/* if문
	특정 조건의 참/거짓 여부에 따라 흐름을 제어
	형태 : if(조건문1) { 조건이 참일때 실행문 } else if(조건문2) {} else {}  */
	char ch;
	ch = getch();
	if (ch == '1')	printf("%d\n", ch - '0');
	else			printf("False\n");

	int num = 0;
	if (num == 1) printf("%d\n", num);
	else if (num == 2) printf("%d\n", num);
	else if (num == 3) printf("%d\n", num);
	else printf("%d\n", num);

	switch (num) {
	case 1: puts("this is 1"); break;
	case 2:	puts("this is 2"); break;
	case 3: puts("this is 3"); break;
	default: puts("I don't know this number"); break;
	}

	/* n부터 10까지 더하기*/
	int n = 3;
	int sumResult = 0;
	switch (n) {
	case 1:	sumResult += 1; case 2:	 sumResult += 2;
	case 3:	sumResult += 3; case 4:	 sumResult += 4;
	case 5:	sumResult += 5; case 6:	 sumResult += 6;
	case 7:	sumResult += 7; case 8:	 sumResult += 8;
	case 9:	sumResult += 9; case 10: sumResult += 10;
	}
	printf("%d\n", sumResult);

	// 알파벳 부르기
	char character = 'A';
	switch (character) {
	case 'A': printf("%c : I am in rable 'A'\n", character); break;
	case 'B': printf("%c : I am in rable 'B'\n", character); break;
	case 'C': printf("%c : I am in rable 'C'\n", character); break;
	case 'D': printf("%c : I am in rable 'D'\n", character); break;
	default : printf("Who are you\n"); break;
	}
	
	return 0;
}