#include "WHuman.h"
#include <iostream>
void WHuman::GoToTravle() {
	std::cout << "백인은 여행을 간다!" << std::endl;
}

void WHuman::Grow() {
	height += 20;
	weight += 7;
}

/* 크리처에 있던 메소드를 덮어쓰는 함수오버라이딩 */
void WHuman::Breath() {
	age++;
	Grow();
}

void WHuman::Dothing() {
	std::cout << "백인은 여행을 간다!" << std::endl;
}

void WHuman::Print() {
	std::cout << "백인 나이:" << age << " 백인 키:" << height << " 백인 무게:" << weight << std::endl;
}
