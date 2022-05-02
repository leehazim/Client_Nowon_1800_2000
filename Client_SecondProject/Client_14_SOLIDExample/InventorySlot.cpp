#include"InventorySlot.h"

POINT InventorySlot::MouseDown() {
	Pick();
	return { 1, 1 };
}

POINT InventorySlot::MouseClick() {
	return POINT();
}

POINT InventorySlot::MouseDag() {
	Dragging();
	return { 1, 1 };
}

void InventorySlot::Pick() {}

void InventorySlot::Dragging() {}

void InventorySlot::Drop() {}

POINT InventorySlot::MouseUp() {
	Drop();
	return { 1, 1 };
}
