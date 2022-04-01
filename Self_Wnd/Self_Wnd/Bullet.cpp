#include "Bullet.h"

void Bullet::Move(int key) {
	switch (key) {
	case VK_LEFT:  m_dx = -1; m_dy = 0; break;
	case VK_RIGHT: m_dx = +1; m_dy = 0; break;
	case VK_UP:	   m_dx = 0; m_dy = -1; break;
	case VK_DOWN:  m_dx = 0; m_dy = +1; break;
	}
	
	m_x += m_dx;
	m_y += m_dy;
	count++;
	if (count == m_range) {
		exist = false;
		count = 0;
	}
}
