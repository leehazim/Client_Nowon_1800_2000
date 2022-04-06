#include <stdio.h>
#include "OperationFuctions.h"

int opCount;
int count;
/* 헤더파일에서 선언된 전역변수를 소스에서 함수내부가 아닌 곳에서 사용하려고 하면 오류발생 중복정의 선언만 하는 것은 상관이 없지만 이미 초기화가 된 전역변수의
값은 겉드려서는 안된다.*/
/* static (정적) 키워드 메모리 동적 할당이 불가능한 키워드 인스턴스화가 불가능하게 하는 키워드
정적 전역 변수 = 다른 소스파일에서 참조할 수 없는 변수 
*/

int main(void) {
	printf("1 + 2 = %d\n", sumInt(1, 2));
	printf("2 - 1 = %d\n", subInt(2, 1));
	printf("opCount = %d\n", opCount);
	
	printf("%d\n", count);
	return 0;
}