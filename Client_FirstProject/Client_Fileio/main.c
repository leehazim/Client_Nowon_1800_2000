#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

/* 파일 입출력 
1. 하드디스크에 있는 파일을 스크립트에서 참조하거나 스크립트의 내용을 하드디스크에 저장하는 방법
변수를 메모리가 아니라 디스크에 저장하는 방법이라고 생각하는 것도 좋을거 같다.

HDD 데이터를 읽을때 읽기/쓰기 속도를 위해서 블록단위로 읽고쓰기를 한다.
이때 블록단위를 구조체의 형태로 사용한다.
struct FILE{
	블록 첫번째 주소
	내용
	크기
	작성 날짜
	작성자 등........
};가 선언되어있다.

버퍼를 만들고 구조체를 메모리에 등록하는게 스트림이라고 한다.
버퍼: 하드디스크에 있던 파일 내용을 임시로 저장하고 있는 공간(정확하게는 메모리에 올라온 하드디스크의 파일내용을 가르키는 포인터
하드디스크에서 올린 구조체 == 스트림(stream) 파일
버퍼를 통해서 값을 읽든 쓰든 수정을 하든 HDD에 실시간으로 수정이 이루어 지지는 않는다.
메모리상에서 해제될때 저장이 이루어 진다.

운영체제는 기본적으로 3개의 스트림을 생성한다.
1. stdin	:	(키보드) 입력 스트림 ex) scanf(기본적인 함수), getchar() 메시지 큐, 
2. stdout	:	(모니터) 출력 스트림 
3. stderr	:	에러 스트림
*/
int main(void) {
	
	/* 표준 입출력 함수
	printf, scanf, puts, _putch, gets, getch,*/

	/*
	fopen(파일 경로, 모드) 
	기본적으로 현재 프로그램 파일이 있는 폴더에서 파일을 검색한다.
	하드디스크로부터 파일을 읽어들어서 File Stream에 등록하는 함수
	fopen 모드 종류(파일 개방 모드)
	1. r : 읽기 전용 (Read Mode)
	2. w : 쓰기 전용 (Write Mode) == 포인터가 NULL로 반환되면 파일 생성에 실패했음을 나타낸다.
	3. a : 덧붙여쓰기 전용 (Append Mode)
	4. r+ : 읽기/쓰기 가능 ==> 파일이 없으면 에러
	5. w+ : 읽기/쓰기 가능 ==> 파일이 없으면 생성
	6. a+ : 읽기/덧붙여쓰기 가능 ==> 파일이 없으면 에러
	7. rb : 바이너리 파일 읽기 전용 -- 이진수 형태의 파일들을 읽어올때 사용된다.
	8. wb : 바이너리 파일 쓰기 전용
	9. ab : 바이너리 파일 덧붙여쓰기 전용
	fclose() 
	File Stream의 버퍼에 등록된 파일을 해제.
	*/
	
	char Mes[128];
	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	FILE* pf1 = fopen("Test.txt", "r");
	if (!pf1) { /* 읽기모드 파일 열기에서 포인터가 NULL이면 파일을 읽는 것이 실패했다.(파일이 존재하지 않거나 엑세스에 불가능한 파일인 경우)*/
		puts("failed to open File");
		exit(-1);
	}
	printf("%c\n", fgetc(pf1));
	printf("%c\n", fgetc(pf1)); /*다시 뒤로 되돌아 가려면 써야하는 함수가 뭐더라..*/
	fclose(pf1); /* 파일 버퍼 포인터 역시도 동적 할당처럼 해제 해주어야 한다. 파일 해제 함수.*/
	
	pf1 = fopen("test.txt", "r");
	fgets(Mes, 20, pf1);
	printf("%s\n", Mes);
	fclose(pf1);

	pf1 = fopen("test.txt", "a");
	for (int i = 0; i < 10; i++) fprintf(pf1, "%d ", ar[i]);
	fclose(pf1);

	FILE* pf2 = fopen("Test2.txt", "r");
	if (!pf2) {
		puts("Failed to Read");
		exit(-1);
	}
	char IsOverride = 'N';
	printf("Test2.txt를 덮어쓰겠습니까? : ");
	IsOverride = getch();
	if (tolower(IsOverride) == 'n') {
		puts("Test2.txt 프로그램 종료");
		fclose(pf2);
		exit(0);
	}

	pf2 = fopen("Test2.txt", "w"); /* 파일이 없으면 생성을 하고, 파일이 있으면 파일의 내부를 모두 지우고 작업을 시작한다.*/
	if (!pf2) {
		puts("Failed to Create File");
		exit(-2);
	}
	for (int i = 0; i < 10; i++) fprintf(pf2, "%d ", ar[i]);
	puts("File save Complete");
	fclose(pf2);
	/* 쓰기 모드는 수정이 끝나면 바로 파일을 닫자.*/
	char first[10] = "abc";
	char second[10] = "def";
	char temp[10];

	strcpy(temp, first);
	strncpy(first, second, 1);
	strncpy(second, temp, 1);
	printf("%s, %s\n", first, second);

	/* Append Mode : 
	파일이 없으면 새로 생성한다. 그래서 NULL을 반환한다는건 생성실패한것*/
	FILE* pf3 = fopen("Test3.txt", "a");
	if (pf3 == NULL) {
		puts("Test3.txt 생성에 실패했습니다.");
		exit(-2);
	}
	fprintf(pf3, "안녕");
	fclose(pf3);

	/* 다양한 형태의 문자열 입출력*/
	FILE* pf4;
	FILE* pf5;

	char name[20] = "chulsu";
	int korean = 10, english = 20, math = 30;
	double average = (double)(korean + english + math) / 3;
	
	pf4 = fopen("Chulsu.txt", "r");
	if (!pf4) {
		puts("Chulsu파일 읽기 실패");
		exit(-1);
	}
	/* Chulsu.txt의 파일에 적인 문자열, 정수 정수 정수 값을 읽어서 변수들이 변경됨.*/
	fscanf(pf4, "%s %d %d %d", name, &korean, &english, &math);
	fclose(pf4);
	average = (double)(korean + english + math) / 3;
	
	pf5 = fopen("RealChulsu.txt", "w");
	if (!pf5) {
		puts("파일 생성 실패");
		exit(-2);
	}
	fprintf(pf5, "%s %d %d %d %.2lf", name, korean, english, math, average);
	fclose(pf5);
	puts("저장완료");

	/* 대용량 파일을 처리해야할때 입출력의 속도를 위해서 rb등을 사용한다. binary -> 2진수
	fread나 fwrite 함수를 사용한다.(기계어라서 포멧형태가 의미가 없어진다.) 
	2진수로 속도가 빨랐을뿐이지 내용 자체가 이진수로 저장되는 방식은 아니다.
	하지만 이진수라서 빠르기 때문에 대용량파일에 적합하다.*/
	FILE* fp;
	fp = fopen("TestBinary.txt", "wb");
	char a[] = "adkcviekkdkkdvisd";
	fwrite(a, sizeof(a), 1, fp);
	fclose(fp);
	
	return 0;
}