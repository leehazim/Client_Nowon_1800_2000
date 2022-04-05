#pragma once
#include "Enemy.h"
class Bullet {
private:
	bool exist;
	int m_x, m_y;
	int m_dx, m_dy;
	int m_range;
	int m_nStay, m_nFrame;
	int count;
	Player& pPlayer;

public:
	Bullet(Player& apPlayer) : pPlayer(apPlayer) {
		exist = false;
		m_x = pPlayer.GetX();
		m_y = pPlayer.GetY();
		m_range = 1000;
		m_dx = m_dy = 0;
		count = 0;
		m_nStay = m_nFrame = rand() % 5 + 5;
	}
	void Make(int key, int, Player& P);
	void Move(Player& p);
	void SetExist(bool data) { exist = data; }
	void IsCrash(Enemy* E);
	bool getExist() const { return exist; }
	int GetRange() const { return m_range; }

	int GetX() { return m_x; }
	int GetY() { return m_y; }
};

