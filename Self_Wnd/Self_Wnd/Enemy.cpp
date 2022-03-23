#include "Enemy.h"
Enemy::Enemy(Player * pPlayer){
	m_x = (rand() % 780) + 10;
	m_y = (rand()% 630) + 10;
	m_dx = m_dy = 0;
	m_pPlayer = pPlayer;
}

void Enemy::Move(){

	double distance = 1.0f;
	if (distance < 10.0 /*&& distance > 0*/) {
		if (m_pPlayer->GetX() - m_x > 0)	m_dx = +1;
		else								m_dx = -1;

		if ((m_pPlayer->GetY() - m_y) > 0)	m_dy = +1;
		else								m_dy = -1;

		m_x += m_dx;
		m_y += m_dy;
	}
}
