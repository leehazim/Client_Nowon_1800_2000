#pragma once
#include <iostream>

template <typename __type>
class PriorityQueue {
public:
	void EnQueue(const __type& aData);
	__type& DeQueue();
	void PrintData();

	PriorityQueue();
	PriorityQueue(int aCapacity);
	~PriorityQueue();

private:
	static const int __InitSize;

	__type* _Heap;
	int _Size;
	int _Capacity;
};

template <typename __type>
const int PriorityQueue<__type>::__InitSize = 10;

template<typename __type>
inline void PriorityQueue<__type>::EnQueue(const __type& aData) {
	if (_Size >= _Capacity) {
		_Capacity *= 2;
		__type* tmpHeap = new __type[_Capacity];
		for (int i = 0; i < _Size; i++) {
			tmpHeap[i] = _Heap[i];
		}
		delete[] _Heap;
		_Heap = new __type[_Capacity];
		for (int i = 0; i < _Size; i++) {
			_Heap[i] = tmpHeap[i];
		}
		delete[] tmpHeap;
	}
	_Heap[_Size] = aData;

	int parent = _Size / 2;
	int child = _Size;

	// Bottom-Up 정렬 방식
	while (_Heap[parent] < _Heap[child]) {
		__type tmpData = _Heap[parent];
		_Heap[parent] = _Heap[child];
		_Heap[child] = tmpData;

		child = parent;
		parent = child / 2;
	}
	_Size++;
}

template<typename __type>
inline __type& PriorityQueue<__type>::DeQueue() {
	__type top = _Heap[0];
	_Heap[0] = _Heap[_Size - 1];
	int parent = 0;
	int child = parent * 2 + 1;
	bool doSwap = false;

	// Top-Down 정렬 방식
	while (child < _Size - 1) {
		
		if (child + 1 < _Size-1 &&
			_Heap[child] < _Heap[child + 1]) {
			child++;
		}

		if (_Heap[parent] < _Heap[child]) {
			doSwap = true;
		}
		/*if (_Heap[parent] < _Heap[child + 1]) {
			doSwap = true;
			child++;
		}*/
		if (doSwap) {
			__type tmpData = _Heap[parent];
			_Heap[parent] = _Heap[child];
			_Heap[child] = tmpData;
			doSwap = false;

			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}

	_Size--;
	return top;
}

template<typename __type>
inline void PriorityQueue<__type>::PrintData() {
	std::cout << "Priority Queue Elements: ";
	for (int i = 0; i < _Size; i++)
		std::cout << _Heap[i] << " ";
	std::cout << std::endl;
}

template<typename __type>
inline PriorityQueue<__type>::PriorityQueue() 
	: _Capacity(__InitSize) {
	_Heap = new __type[_Capacity];
	_Size = 0;
}

template<typename __type>
inline PriorityQueue<__type>::PriorityQueue(int aCapacity) : _Capacity(aCapacity) {
	_Heap = new __type[_Capacity];
	_Size = 0;
}

template<typename __type>
inline PriorityQueue<__type>::~PriorityQueue() {
	delete[] _Heap;
}
