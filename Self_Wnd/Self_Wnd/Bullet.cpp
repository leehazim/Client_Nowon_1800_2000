#include "Bullet.h"

void Bullet::Make(int key, int playerkey) {
	switch (key) {
	case VK_SPACE: exist = true; break;
	}
	
	switch (playerkey) {
	case VK_LEFT: m_dx = -1; m_dy = 0; break;
	case VK_RIGHT: m_dx = +1; m_dy = 0; break;
	case VK_UP: m_dx = 0; m_dy = -1; break;
	case VK_DOWN: m_dx = 0; m_dy = +1; break;
	}
}

void Bullet::Move() {
	if (--m_nStay == 0) {
		m_nStay = m_nFrame;
		m_x += m_dx;
		m_y += m_dy;
		count++;
	}
	if (count == m_range) {
		exist = false;
		m_x = pPlayer->GetX();
		m_y = pPlayer->GetY();
		count = 0;
	}
}
