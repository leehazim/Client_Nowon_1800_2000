#include "WHuman.h"
#include <iostream>
void WHuman::GoToTravle() {
	std::cout << "������ ������ ����!" << std::endl;
}

void WHuman::Grow() {
	height += 20;
	weight += 7;
}

/* ũ��ó�� �ִ� �޼ҵ带 ����� �Լ��������̵� */
void WHuman::Breath() {
	age++;
	Grow();
}

void WHuman::Dothing() {
	std::cout << "������ ������ ����!" << std::endl;
}

void WHuman::Print() {
	std::cout << "���� ����:" << age << " ���� Ű:" << height << " ���� ����:" << weight << std::endl;
}
