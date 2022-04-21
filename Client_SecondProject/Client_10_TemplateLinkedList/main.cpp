#include "TLinkedList.h"
#include <iostream>


int main(void) {

	TLinkedList<int> list;
	list.AddLast(1);
	list.AddLast(2);
	list.AddLast(5);
	list.AddLast(3);
	list.AddLast(4);
	list.AddLast(5);
	list.AddLast(3);
	list.AddLast(2);
	list.AddLast(1);
	list.Print();
	list.Remove(5);
	list.Print();
	return 0;
}