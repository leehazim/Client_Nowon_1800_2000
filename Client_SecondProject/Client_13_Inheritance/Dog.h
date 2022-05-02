#pragma once
#include "Creature.h"
#include "Human.h"
class Dog
	:public Creature{
	/* friendŰ����� ����� Ŭ������ �Լ����� friend�� ������ Ŭ������ private���������� ������� ������ ����
	�ڵ� Ŀ�ø��� ���ؼ� �̿��̸� �Ⱦ��°� ����.*/
	friend class Human;
private:
	std::string who;
public:
	int tailLength;
public:
	void Bite(Creature* Target);
	virtual void Grow();
};