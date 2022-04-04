#include <stdio.h>
#pragma warning(disable : 4996)

/* FSM(Finite State Machine)
유한 상태 머신 */

/* enum : 열거형 사용자지정의 자료형을 만기위함*/

enum tag_Subject { KOREAN, ENGLISH, MATH, MAXSUBJECT };

/* 플레이어 상태가 열러가지일때
1. 아무것도 안할때
2. 걷기 
3. 달리기
4. 공격하기 
5. 점프하기 등이 있을때
이런 상태들을 정수만으로 기억하면 기억하기 불편해서 이름을 주고 싶을때 사용하는 경우가 많다.*/
enum Player_State {
	Wait = 1, Walk, Run, Attack, Jump, 
};
enum Jump_State {
	Idle, PrepareJump, InFlight, Falling, OnGround, 
	/* 대기 점프준비 점프중 떨어지는중 땅에 떨어짐 순으로 순회하는 동작에 이름 붙여서 상태 체킹 도구 만들기 좋음*/
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
		case Wait:		printf("대기상태...\n"); break;
		case Walk:		printf("걷는 중...\n"); break;
		case Run:		printf("달리는 중...\n"); break;
		case Attack:	printf("공격!\n"); break;
		case Jump:		printf("점프!\n"); break;
		default:		printf("무슨 행동인지 캐릭터가 이해하지 못했습니다.\n"); break;
		}
	}

	return 0;
}