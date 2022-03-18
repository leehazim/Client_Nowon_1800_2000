#include <stdio.h>
#include <stdlib.h>

int main(void) {

	/* 배열 (Array)
	1 3 2 1  3 2 5 3 2 
	처럼 같은 타입의 자료들이 나열된 것
	
	324332353 
	324332353 
	처럼 두줄로 나열되기도 하는 2차원 배열도 있다.
	
	===========================================
	프로그램에서 배열의 크기는 제한은 없다.
	1. 1차원 배열 
	하나의 선으로만 데이터가 저장되는 것
	
	*/

	int ar1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; /* '데이터형' '배열이름'['배열크기']*/
	int ar2[3] = {1,2};
	printf("%d\n", ar2[2]);

	/* 배열초기화 방법
	*  초기값을 다 안주더라도 초기값이 전달되지 않았을경우 0 으로 초기화됨
	* 하지만 하나라도 초기화를 하지 않으면 쓰래기 값이 들어있다.
	int ar[3] = {1,2,3};
	int ar[3] = {0,};
	int ar[3] = {0};
	int ar[3];
	ar[0] = 1;
	ar[1] = 2;
	ar[2] = 3; */

	/* 배열의 인덱스
	배열에 들어있는 값을 꺼내기 위한 첨자로 0부터 시작한다
	그래서 크기가 3 인 배열은 0~2까지의 인덱스만 가진다.*/
	/* 2차원 배열 */
	short arr2x_1[][3] = { {1,2,3},
							{4,5,6},};
	/* 위와같이 코드를 작성할 수 있는 이유는 C 컴파일러가 프리포멧을 지원하기 때문이다.
	 세미콜론(;)이라는 구두점이 있다보니까 세미콜론을 기준으로 어디까지가 한 문장인지 찾을 수 있다.*/
	
	/* 배열은 열의 크기가 중요하다 따라서
	int arr[][3] 선언이 가능하다.
	하지만 두번째 첨자를 기준으로 나누어지기 때문에
	int arr[2][]; 은 오류를 발생시킨다.
	*/

	/* '데이터형' 배열이름[열 인덱스][행 인덱스]*/
	
	printf("%d\n", arr2x_1[0][2]);

	/* 문자열은 배열의 확장으로 보면 된다.
	문자열은 문자형데이터를 배열화 하면 된다.
	문자열 : 배열 마지막에 NULL문자가 붙는다.
	char String[10] = "abcd\0"; \0은 자동으로 붙는다.
	그 널문자도 배열의 자리를 하나 차지하기때문에 널문자가 들어올 자리도 생각해서 글자수 +1 만큼의 배열 공간을
	확보해 주어야한다. 
	문자열의 크기를 널문자를 뺀 값으로 선언해도 바로 에러를 반환하지는 않는다.
	다만 그 문자열을 사용할때 에러가 발생한다.*/\

	char name[128] = "C Programming Is Good at Speed and...";

	char str1[20] = "hello";
	char str2[6] = "Hello";
	char str3[] = "Hello";
//	char str4[3] = "hello";
	char str5[] = "hello";
	char str6[6] = { 'h', 'e', 'l', 'l', 'o', '\0'};
	
	printf("%s\n", name);
	printf("%c\n", str6[0]);
	printf("%s\n", str6);

	strcpy(str3, "HI");
	printf("%s\n", str3);

	/* 문자열 내장함수
	strcpy(), strcmp(), strlen(), strncpy()*/

	return 0;
}