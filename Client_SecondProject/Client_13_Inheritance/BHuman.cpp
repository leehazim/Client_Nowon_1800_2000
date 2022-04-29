#include "BHuman.h"
#include <iostream>
void BHuman::GotoGym() {
	std::cout << "ÈæÀÎ! Ã¼À°°ü¿¡ °£´Ù." << std::endl;
}

void BHuman::Breath() {
	age++;
	Grow();
}

void BHuman::Grow() {
	height += 100;
	weight += 20;
}

void BHuman::Dothing() {
	std::cout << "ÈæÀÎ! Ã¼À°°ü¿¡ °£´Ù." << std::endl;
}
void BHuman::Print() {
	std::cout << "ÈæÀÎ ³ªÀÌ:" << age << " ÈæÀÎ Å°:" << height << " ÈæÀÎ ¹«°Ô:" << weight << std::endl;
}
