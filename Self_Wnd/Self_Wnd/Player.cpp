#include "Player.h"

Player::Player(){
	m_x = 400;
	m_y = 320;
	m_shape = RECTANGLE;
}

void Player::Move(int key){
	
	switch (key) {
	case VK_LEFT:
		m_x = min(m_x + 10, 700);
		break;
	case VK_RIGHT:
		m_x = max(m_x - 10, 10);
		break;
	case VK_UP:
		m_y = min(m_y - 10, 10);
		break;
	case VK_DOWN:
		m_y = max(m_y + 10, 700);
		break;
	}
}

void Player::Draw(HWND hwnd){
	
	HDC hdc;
	PAINTSTRUCT ps;

	hdc = BeginPaint(hwnd, &ps);
	switch (m_shape) {
	case RECTANGLE:
		Rectangle(hdc, m_x, m_y, m_x + 10, m_y + 10);
		break;
	case ELLIPSE:
		break;
	case TRIANGLE:
		break;
	}
	EndPaint(hwnd, &ps);
}
