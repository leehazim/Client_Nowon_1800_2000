#pragma once
#include "Enemy.h"

class Bullet 
	:public AutoMove{
private:
	int m_range;
	int count;
	Player& pPlayer;

public:
	Bullet(Player& apPlayer) : AutoMove(apPlayer.GetX(), apPlayer.GetY()), pPlayer(apPlayer) {
		m_range = 100;
		count = 0;
	}
	void Make(int key, int, Player& P);
	virtual void Move(Player& p, int idx = 0);
	void Draw(HDC hdc);
	void SetExist(bool data) { exist = data; }
	void IsCrash(Enemy* E);
	bool getExist() const { return exist; }
	int GetRange() const { return m_range; }
	int GetX() { return m_x; }
	int GetY() { return m_y; }
};

