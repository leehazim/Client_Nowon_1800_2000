#include "Debuffer.h"
#include <string>
#pragma warning(disable : 4996)

Debuffer::Debuffer() 
	: Damage(10) { Name = new char[20]; }

Debuffer::Debuffer(const char* name) 
	: Damage(10) { 
	Name = new char[strlen(name) + 1];
	strcpy(Name, name);
}

Debuffer::Debuffer(Warrior& target) 
	: Damage(10) {	DecreaseHP(target); }

Debuffer::Debuffer(const Debuffer& Other) {
	*this = Other;
}

Debuffer::~Debuffer() { delete[] Name; }

Debuffer& Debuffer::operator=(const Debuffer& Other) {
	Damage = Other.Damage;
	Name = new char[strlen(Other.Name) + 1];
	strcpy(Name, Other.Name);
	return *this;
}

void Debuffer::DecreaseHP(Warrior& target) { 
	target.SetHP(target.GetHP() - Damage); 
}

void Debuffer::DecreaseHP() { 
	DecreaseHP(*Warrior::GetInstance()); 
}
