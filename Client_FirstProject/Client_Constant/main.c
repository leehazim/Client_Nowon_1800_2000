#include <stdio.h>

int main(void) {

	printf("%d\n", 1);
	printf("%c\n", 65);
	printf("0x%X\n", 'A');
	printf("%.10f\n", 1.123456789F);
	printf("%.10lf\n", 1.123456789);
	printf("%s\n", "안녕하세요.");
	printf("0x%X\n", 0xfaed);

	/* 서식문자
	 문자열 내에 서식문자를 사용해서 인자를 표현할 수 있도록
	 해당 인자 위치에 값을 삽입할 수 있다.
	 printf("format", argu, argu); format => "나이 = %d, 이름 = %s, 키 =  %.2f \n" 
	 에서 %로 시작하는 것들.*/

	/* 제어문자 || 특수문자 
	\ : BackSlash (보통의 띄어쓰기등의 형식들을 지정할 때 사용) \n, \t, \a, \0, \\, \"등...
	n : NewLine 줄바꾸기
	r : Carriage return 커서를 해당줄 가장 앞으로 옮김
	b : BackSpace 커서위치를 한칸 왼쪽으로 이동
	t : tab만큼 띄어쓰기
	a : Beep, 삐소리내는 */

	return 0;
}