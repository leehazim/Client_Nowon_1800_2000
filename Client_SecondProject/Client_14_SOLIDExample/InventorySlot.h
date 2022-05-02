#pragma once
#include <string>
#include "IPointerHandler.h"
class InventorySlot :
	public IPointerHandler {
private:
	std::string name;
	int Stock;

public:
	virtual POINT MouseDown();
	virtual POINT MouseUp();
	virtual POINT MouseClick(); /* 이 클래스에서 사용되지 않는 인터페이스가 있다. 이것은 인터페이스 분리 법칙에 어긋난다.*/
	virtual POINT MouseDag();

	void Pick();
	void Dragging();
	void Drop();
};