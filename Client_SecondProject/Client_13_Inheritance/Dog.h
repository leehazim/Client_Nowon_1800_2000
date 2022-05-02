#pragma once
#include "Creature.h"
#include "Human.h"
class Dog
	:public Creature{
	/* friend키워드로 선언된 클래스나 함수들은 friend를 선언한 클래스의 private접근제한자 멤버여도 접근이 가능
	코드 커플링이 심해서 이왕이면 안쓰는게 좋다.*/
	friend class Human;
private:
	std::string who;
public:
	int tailLength;
public:
	void Bite(Creature* Target);
	virtual void Grow();
};