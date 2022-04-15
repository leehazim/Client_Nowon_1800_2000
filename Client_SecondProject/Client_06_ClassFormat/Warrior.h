#pragma once
class Warrior {
private: static Warrior* Instance; 
	   /* ��ü���� ���� �������� ����ʹ� �ٸ��� ��ü���� �������� �����ϴ� ����. (��ü�� ���� �ƴ� Ŭ������ ���̴�.)*/
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