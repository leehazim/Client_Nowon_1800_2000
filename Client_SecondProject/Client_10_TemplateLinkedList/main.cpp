#include "TLinkedList.h"
#include <iostream>


int main(void) {

	TLinkedList<int> list;
	list.AddFirst(10);
	list.AddFirst(11);
	list.AddFirst(12);
	list.AddLast(111);
	list.AddLast(12);
	list.AddLast(13);
	list.Print();
	//list.PrintData(11);
	list.Remove(111);
	list.Print();
	tag_node<int>* tmp = list.Find(10);
	list.AddBefore(tmp, 15);
	list.Print();
	delete tmp;
	return 0;
}