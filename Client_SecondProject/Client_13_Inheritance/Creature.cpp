#include "Creature.h"
#include <iostream>

void Creature::Breath() {	
	std::cout << "¼û½®´Ù! ";
	age++;
	Grow();
}

void Creature::Grow() { 
	std::cout << "¼ºÀåÇÑ´Ù! ";
	height += 10;
	weight += 5;
}
