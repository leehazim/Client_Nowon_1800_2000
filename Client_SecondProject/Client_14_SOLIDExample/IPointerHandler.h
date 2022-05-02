#pragma once
#include <Windows.h>

class IPointerHandler {
public:
	virtual POINT MouseDown() = 0;
	virtual POINT MouseUp() = 0;
	virtual POINT MouseClick() = 0;
	virtual POINT MouseDag() = 0;
};