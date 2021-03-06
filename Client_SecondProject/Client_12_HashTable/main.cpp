/* 적당한 크기와 적당한 충돌로 구성되는것이 가장 바람직하다. 사이즈가 너무 크면 빈 공간이 많아질 수 있고
작은 사이즈로 만들 수록 해시값의 중복이 많아져서 불안정하다.
해시값이 같을때 일어나는 충돌을 처리하는 작업도 필요하다.*/

/* 충돌 해결방법
1. 체이닝(Chainning) : 모든 Value를 LinkedList나 동적배열로 관리하는 방법
2. 오픈 어드레싱(Open Addressing) : 	해시키값 충돌시 다시 해시값을 생성하는 방식
									ex) 철수해쉬 35, 영희해쉬 35일때 영희 해쉬 135로 재생성 하고 해시테이블의 크기를 변경
*/

/* 해쉬 생성방법
1. 모듈러 방식 사용
*/
#include <iostream>
#include "HashTable.h"
using namespace std;

int main(void) {
	HashTable* HT = new HashTable();
	HT->Add("joshua");
	HT->Add("mose");
	HT->Add("ojshua");
	cout << HT->ContainsValue("joshua") << endl;
	HT->PrintKey("joshua");
	HT->PrintKey("mose");
	return 0;
}