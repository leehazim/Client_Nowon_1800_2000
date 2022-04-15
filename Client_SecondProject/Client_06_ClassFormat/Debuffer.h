#pragma once
/* ������ �÷��̾� ü���� ��� ������� ȿ��*/
#include "Warrior.h"
class Debuffer {
public:
	int Damage;
	char* Name;

public:
	Debuffer();
	Debuffer(const char* name);
	Debuffer(Warrior& target);
	Debuffer(const Debuffer& Other);
	~Debuffer();
	Debuffer& operator =(const Debuffer& Other);
	void DecreaseHP(Warrior& target);
	void DecreaseHP();
};

