#include"PriorityQueue.h"

int main(void) {
	PriorityQueue<int> Queue;
	Queue.EnQueue(3);
	Queue.EnQueue(7);
	Queue.EnQueue(2);
	Queue.EnQueue(8);
	Queue.EnQueue(5);
	Queue.EnQueue(6);
	Queue.EnQueue(9);
	
	Queue.PrintData();
	int tmp = Queue.DeQueue();
	std::cout << "DeQueue : " << tmp << std::endl;
	Queue.PrintData();
	tmp = Queue.DeQueue();
	std::cout << "DeQueue : " << tmp << std::endl;
	Queue.PrintData();
	tmp = Queue.DeQueue();
	std::cout << "DeQueue : " << tmp << std::endl;
	Queue.PrintData();
	tmp = Queue.DeQueue();
	std::cout << "DeQueue : " << tmp << std::endl;
	Queue.PrintData();
	tmp = Queue.DeQueue();
	std::cout << "DeQueue : " << tmp << std::endl;
	Queue.PrintData();


	return 0;
}

//Heap Sort (������)
// 
// Heapify �ڷḦ �� �ڷᱸ���� ��ȯ�ϴ� ����
// 
//