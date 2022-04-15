#include "Warrior.h"
#include <iostream>
using namespace std;

Warrior* Warrior::Instance;
Warrior::Warrior() {
	Hp = 100; Def = 2; Att = 3;
}

Warrior::Warrior(int hp, int def, int att) {
	Hp = hp; Def = def; Att = att;
}

Warrior* Warrior::GetInstance() {
	if (Instance == nullptr) Instance = new Warrior();
	return Instance;
}

Warrior::~Warrior() {
	if (Instance != nullptr) delete Instance;
}

void Warrior::SetHP(int hp) { Hp = hp; }
int Warrior::GetHP() { return Hp; }

void Warrior::Attack() {
	cout << "전사 공격!" << endl;
}

void Warrior::Move(int x, int y) {
	cout << "전사( " << x << " , " << y << " )로 이동!" << endl;
}

void Warrior::PrintState() {
	cout << "체력 : " << Hp << " 공격력 : " << Att << " 방어력 : " << Def << endl;
}
