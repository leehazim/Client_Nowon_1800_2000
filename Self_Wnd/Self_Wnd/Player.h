#pragma once
#include <windows.h>
class Player{
private:
	int m_x, m_y;
	/*tag_shape m_shape;*/

public:
	Player();

	int GetX() const;
	int GetY() const;
	void Move(int key);
	void Draw(HWND hwnd);
};

