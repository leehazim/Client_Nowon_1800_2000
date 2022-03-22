#include "Player.h"

Player::Player(){
	m_x = 400;
	m_y = 320;
	/*m_shape = RECTANGLE;*/
}

void Player::Move(int key){
	
	switch (key) {
	case VK_LEFT:
		m_x = max(m_x - 10, 100);
		break;
	case VK_RIGHT:
		m_x = min(m_x + 10, 700);
		break;
	case VK_UP:
		m_y = max(m_y - 10, 10);
		break;
	case VK_DOWN:
		m_y = min(m_y + 10, 530);
		break;
	}
}

void Player::Draw(HWND hwnd){
	
	HDC hdc;
	PAINTSTRUCT ps;

	hdc = BeginPaint(hwnd, &ps);
	Rectangle(hdc, m_x, m_y, m_x + 10, m_y + 10);
	EndPaint(hwnd, &ps);
}
