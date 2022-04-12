#pragma once
class AutoMove {
protected:
	bool exist;
	int m_x, m_y;
	int m_dx, m_dy;
public:
	AutoMove(int x, int y) : m_x(x), m_y(y) { exist = false; m_dx = m_dy = 0; }
	virtual void Move() {};
};

