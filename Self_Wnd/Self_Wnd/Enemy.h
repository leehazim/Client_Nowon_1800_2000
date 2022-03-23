#pragma once
#include "Player.h"
class Enemy{
protected:
	int m_x, m_y;
	int m_dx, m_dy;
	const Player* m_pPlayer;
	
public:
	Enemy(Player* pPlayer);
	
	int GetX() const { return m_x; }
	int GetY() const { return m_y; }
	void Move();
};

