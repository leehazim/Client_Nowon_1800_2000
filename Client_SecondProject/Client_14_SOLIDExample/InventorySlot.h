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
	virtual POINT MouseClick(); /* �� Ŭ�������� ������ �ʴ� �������̽��� �ִ�. �̰��� �������̽� �и� ��Ģ�� ��߳���.*/
	virtual POINT MouseDag();

	void Pick();
	void Dragging();
	void Drop();
};