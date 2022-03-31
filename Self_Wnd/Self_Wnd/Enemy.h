#pragma once
#include "Player.h"
class Enemy{
protected:
	bool exist;
	int m_x, m_y;
	int m_dx, m_dy;
	int m_nStay, m_nFrame;
	const Player* m_pPlayer;
	
public:
	Enemy(Player* pPlayer);

	void SetExist(bool Data) { exist = Data; }
	bool GetExist() { return exist; }
	int GetX() const { return m_x; }
	int GetY() const { return m_y; }
	void Move();
};

