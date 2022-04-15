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
	cout << "���� ����!" << endl;
}

void Warrior::Move(int x, int y) {
	cout << "����( " << x << " , " << y << " )�� �̵�!" << endl;
}

void Warrior::PrintState() {
	cout << "ü�� : " << Hp << " ���ݷ� : " << Att << " ���� : " << Def << endl;
}
