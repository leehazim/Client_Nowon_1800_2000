#include "SumFunctions.h"
extern opCount; 
/* 다른 소스파일에서 선언된 전역변수를 이 소스파일에서 사용하고 싶을때 사용하는 키워드 extern
데이터 영역에 해당 인덱스 이름으로 선언된 변수가 있으면 해당 변수를 참조
공간 할당을 하는 게 아닌 해당 전역변수의 주소를 링크한다고 생각해도 좋음*/

int sumInt(int a, int b) { opCount++; return a + b; }
double sumDouble(double a, double b) { opCount++; return a + b; }