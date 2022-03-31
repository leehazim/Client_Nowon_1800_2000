#include "Enemy.h"
Enemy::Enemy(Player * pPlayer){
	exist = false;
	m_x = (rand() % 780); 
	m_y = (rand() % 630);
	m_dx = m_dy = 0;
	m_pPlayer = pPlayer;
	m_nStay = m_nFrame = (rand() % 20) + 1;

	if (m_x - m_pPlayer->GetX() > 0) m_x = 780;
	else m_x = 10;
	/*if (m_y - m_pPlayer->GetY() > 0) m_y = 630;
	else m_y = 0;*/
}

void Enemy::Move() {

	if (m_pPlayer->GetX() - m_x > 0)	m_dx = +1;
	else								m_dx = -1;

	if ((m_pPlayer->GetY() - m_y) > 0)	m_dy = +1;
	else								m_dy = -1;

	if (--m_nStay == 0) {
		m_nStay = m_nFrame;
		m_x += m_dx;
		m_y += m_dy;
	}

}
