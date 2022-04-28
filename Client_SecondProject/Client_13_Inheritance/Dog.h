#pragma once
#include "Creature.h"
class Dog
	:public Creature{
public:
	int tailLength;
public:
	void Bite(Creature* Target);
};

