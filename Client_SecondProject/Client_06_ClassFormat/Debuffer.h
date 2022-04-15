#pragma once
/* 생성시 플레이어 체력을 깍고 사라지는 효과*/
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

