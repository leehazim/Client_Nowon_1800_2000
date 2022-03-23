#include <stdio.h>

int main(void) {
	/* while : 특정 조건에 따라 내용을 반복 제어
	형태 while(조건문) {조건문이 참일때 반복할 내용} */

	/* do~ while : 은 do 안의 구문을 우선 실행하고 실행 조건문이 참이면 다시 반복을 돌리는 반복문
	do{ 반복실행할 구문}while(조건문);  */

	/* 조건이 항상 참이면 반복문을 무한루프라고 한다.*/
	/* break, continue break은 가장 가까운 반복문을 멈추고
	continue는 가장 가까운 반복문으로 돌아간다.
	가장 가까운 반복문이라고 하면 이중반복문일경우 for {for{continue}}이면 안쪽 for문으로 돌아간다.
	break이면 안쪽의 for문만 정지*/

	int sum = 0; 
	while (sum < 10) sum += 1; 
	printf("%d\n", sum);
	
	sum = 0;
	while (0) {
		printf("ahahahahah111111\n"); 
		sum++;
		if(sum == 10) break;
		continue;
		printf("ahahahahah222222\n");
	}
	printf("while statement is over\n");

	int count = 0;
	while (count < 5) {
		printf("while count : %d\n", count);
		count++;
	}
	printf("while statement is over\n");

	/* do - while*/
	do {
		puts("do while OutPut");
	} while (0);

	/* for Loop
	while문과 같이 반복문이지만 반복할 구간을 직접 설정이 가능하다. 반복 할때마다 특정 함수를 수행할 수 있는 반복문
	for(초기식;조건문;증가값) {실행할 구문} 방식으로 실행된다.
	초기식, 조건문, 증가값 자리중 어느곳이든지 생략이 가능하다, 모두 생략이 가능하다.
	*/
	
	for (int i = 0; i < 10; i++) {
		//printf("%d\n", i);
	}

	/* for문 안의 continue break*/
	for (int i = 0;;i++) {
		if (i < 5) continue;
		else printf("%d\n", i);
		if (i == 10) break;	
	}
	
	return 0;
}