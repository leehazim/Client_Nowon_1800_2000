#pragma once

template <typename __type>
class PriorityQueue {
public:
	void EnQueue(const __type& aData);
	__type& DeQueue();

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

//template<typename __type>
//inline void PriorityQueue<__type>::EnQueue(const __type& aData) {
//	if (_Size >= _Capacity) {
//		__type* tmp = new __type[_Capacity];
//		for (int i = 0; i < _Size; i++) {
//			tmp[i] = _Heap[i];
//		}
//		_Capacity *= 2;
//		delete[] _Heap;
//		_Heap = new __type[_Capacity];
//		for (int i = 0; i < _Size; i++) {
//			_Heap[i] = tmp[i];
//		}
//	}
//	_Heap[_Size] = aData;
//}

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
	// TODO: 여기에 return 문을 삽입합니다.
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
