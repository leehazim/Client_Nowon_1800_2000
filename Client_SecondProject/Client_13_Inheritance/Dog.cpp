#include "Dog.h"
#include <iostream>
void Dog::Bite(Creature* Target) {
	std::cout << "개가 물었다!" << std::endl;
	Target->weight -= 10;
}
