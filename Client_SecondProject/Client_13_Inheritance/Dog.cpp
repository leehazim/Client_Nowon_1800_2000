#include "Dog.h"
#include <iostream>
void Dog::Bite(Creature* Target) {
	std::cout << "���� ������!" << std::endl;
	Target->weight -= 10;
}

void Dog::Grow() {
	height += 1;
	weight += 1;
}