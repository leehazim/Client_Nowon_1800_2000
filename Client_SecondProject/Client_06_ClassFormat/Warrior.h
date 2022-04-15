#pragma once
class Warrior {
private: static Warrior* Instance; 
	   /* 객체들이 각자 가져가는 멤버와는 다르게 객체들이 공통으로 공유하는 변수. (객체의 것이 아닌 클래스의 것이다.)*/
private:
	int Hp;
	int Def;
	int Att;

public:
	Warrior();
	Warrior(int hp, int def, int att);
	~Warrior();

	static Warrior* GetInstance();

	void SetHP(int hp);
	int GetHP();

	void Attack();
	void Move(int x, int y);
	void PrintState();
};