#include "Creature.h"
#include <iostream>

void Creature::Breath() {	
	std::cout << "������! ";
	age++;
	Grow();
}

void Creature::Grow() { 
	std::cout << "�����Ѵ�! ";
	height += 10;
	weight += 5;
}
