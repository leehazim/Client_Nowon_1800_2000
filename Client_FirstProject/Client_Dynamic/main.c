#include <stdio.h>
#include <stdlib.h> /* 동적할당을 하기위해 포함되는 헤더파일 이거 외에어도 이 안에 여러가지 함수들있음*/
#pragma warning(disable : 4996)

/* 동적 메모리 할당 (HEAP영역에 메모리를 할당)
실행중에 필요한 데이터 변수공간을 할당하기위한 문법

동적 메모리 할당을 위한 함수는 
malloc(size), calloc(count, data_size), realloc(ptr, size) 
malloc은 동적으로 할당 후 초기화를 해주지 않아서 쓰래기값을 가지고있지만
calloc은 동적으로 할당 후 0으로 초기화를 해준다. 
realloc은 동적으로 이미 할당된 메모리를 원하는 사이즈로 다시 할당해준다.
malloc, calloc, realloc들은 모두 void*을 리턴해서 포인터 변수에 담으려면 캐스팅해야함

배열의 크기와 같은경우 다양한 종류나 값이 할당되어야 할때,
즉, 컴파일시에 배열의 크기를 정할 수 없을때 사용하는 것

realloc :
크기를 변경하고싶을때 밑 그 주소 안의 데이터값을 유지하고싶을때
*/

int main(void) {
	int* a = (int*)malloc(sizeof(int));
	free(a);
	a = (int*)calloc(1, sizeof(int));
	*a = 3; printf("%d\n", *a);

	free(a);/* 동적할당된 메모리는 직접 헤재해주지않으면 프로그램 종료후에도 그 메모리공간은 운영체제에게 반납되지않는다*/
			/* 그래서 동적할당 받은 공간의 포인터로 해제함수를 호출*/

	//a = (int*)malloc(count * sizeof(int));
	int count = 16;
	a = (int*)calloc(count, sizeof(int));
	for (int i = 0; i < count; i++) a[i] = i + 1;

	a = (int*)realloc(a, 20 * sizeof(int));
	for (int i = count; i < 20; i++) a[i] = i + 1;
	for (int i = 0; i < 20; i++) printf("%d ", a[i]);
 	free(a);

	return 0;
}