#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

/* 문자형 배열의 배열을 동적으로 만드는 예제*/
/* 매개변수를 가지는 main함수 
 C\: > 실행파일 이름.exe
 단순 실행이 되지만 특별한 기능이나 옵션을 부여할때 인자를 준다.
 C\:>실행파일 이름.exe 문자열 문자열
모든 문자열을 동적할당한 후에 main 함수 인자로 넘겨준다. */
int main(int argc, char** argv) {

	/*argc == argument count 문자열 개수
	argv == argument vector 문자열 배열, 끝에는 NULL추가*/
	
	for (int i = 0; i < argc; i++) 
		printf("argv[%d] = %s\n", argc, argv[i]);
	
	while (*argv) printf("%s\n", *argv++);

	char input[100];
	int count = 3;
	char** spp;
	
	spp = (char**)malloc(count * sizeof(char*));
	if (spp == NULL) exit(-1);

	for (int i = 0; i < count; i++) {
		scanf("%s", input);
		spp[i] = (char*)malloc(strlen(input) + 1);
		strcpy(spp[i], input);
	}

	for (int i = 0; i < count; i++) {
		printf("%s\n", spp[i]);
		free(spp[i]);
	}
	
	free(spp);
	return 0;
}