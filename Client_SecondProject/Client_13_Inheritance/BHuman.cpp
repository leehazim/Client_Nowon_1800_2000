#include "BHuman.h"
#include <iostream>
void BHuman::GotoGym() {
	std::cout << "����! ü������ ����." << std::endl;
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
	std::cout << "����! ü������ ����." << std::endl;
}
void BHuman::Print() {
	std::cout << "���� ����:" << age << " ���� Ű:" << height << " ���� ����:" << weight << std::endl;
}
