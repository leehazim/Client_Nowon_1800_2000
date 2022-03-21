#include <stdio.h>
#pragma warning (disable : 4996)

int main(void) {
	
	int number;
	char temp[50];
	scanf("%d", &number);
	/* scanf는 콘솔에서 사용자로부터 데이터를 입력받기 위해서 사용하는 C언어에서 제공하는 함수다.
	printf와 비슷하게 ("입력될 포멧", 1:1 대응 &변수) 방식으로 사용된다.
	변수앞에 &를 붙여서 포인터를 넘겨서 주소에 접근할 수 있도록 사용한다.*/
	printf("값 : %d, 변수주소 : 0x%X\n", number, &number);
	
	/* sizeof 키워드 sizeof(데이터형) 방식으로 사용한다. 
	그 자료형이 메모리에서 할당받게될 크기를 바이트단위로 리턴받는다.*/
	scanf("%s", temp);
	printf("%s\n", temp);

	/* 오버플로우에 대응하기 위해서 사이즈를 입력받아서 입력이 안되는 것을 방지하는 것인데
	C++에서 오버플로우 방지를 어떻게 하고 있더라.
	*/
	return 0;
}