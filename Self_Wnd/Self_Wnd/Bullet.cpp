#include "Bullet.h"

void Bullet::Make(int key, int playerkey, Player& P) {
	switch (key) {
	case VK_SPACE: 
		exist = true;
		m_x = P.GetX();
		m_y = P.GetY();
		break;
	}
	
	switch (playerkey) {
	case VK_LEFT: m_dx = -1; m_dy = 0; break;
	case VK_RIGHT: m_dx = +1; m_dy = 0; break;
	case VK_UP: m_dx = 0; m_dy = -1; break;
	case VK_DOWN: m_dx = 0; m_dy = +1; break;
	}
}

void Bullet::Move(Player& p) {
	if (--m_nStay == 0) {
		m_nStay = m_nFrame;
		m_x += m_dx;
		m_y += m_dy;
		count++;
	}

	if (count == m_range) {
		exist = false;
		count = 0;
	}
}

void Bullet::IsCrash(Enemy* E) {
	int x_range = E->GetX() - m_x; x_range = (x_range > 0) ? x_range : -x_range;
	int y_range = E->GetY() - m_y; y_range = (y_range > 0) ? y_range : -y_range;
	if (x_range  < 3 && y_range < 3) {
		this->exist = false;
		E->SetExist(false);
	}
}
