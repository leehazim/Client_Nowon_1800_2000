#pragma once
#include <windows.h>
class Player{
private:
	int m_x, m_y;
	/*tag_shape m_shape;*/

public:
	Player();
	void Move(int key);
	void Draw(HWND hwnd);
};

