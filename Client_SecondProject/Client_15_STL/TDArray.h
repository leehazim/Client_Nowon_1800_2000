#pragma once
#include <cassert>
template <typename T>
class TDArray {
	friend void PrintArray(TDArray& Other);
private:
	T* Arr;
	int Size;
	int Capacity;
	const int DEFAULT_SIZE;
	
public:
	class Iterator {
	private:
		TDArray<T>* p_DA;
		T* p_Data;
		int idx;

	public:
		T& operator *() { return p_Data[idx]; }
		Iterator& operator ++() { 
			/*전위 증감 연산자*/
			if ((p_DA == nullptr) || (p_DA->Arr != p_Data) || (idx < 0)) {
				assert(nullptr);
			}

			if (idx < p_DA->Size - 1) idx++;
			else idx = -1;

			return *this;
		}
		Iterator& operator ++(int) { 
			/* 후위 증감 연산자*/
			TDArray<T>::Iterator tmp = *this;
			++(*this);

			return tmp;
		}
		bool operator !=(const TDArray<T>::Iterator& Other) {
			return Other.idx != idx;
		}
		bool operator ==(const TDArray<T>::Iterator& Other) {
			return !(Other != *this);
		}

		bool operator <(const TDArray<T>::Iterator& Other) {
			if (idx < 0) return false;
			if (Other.idx < 0) return true;
			if (idx < Other.idx) return true;
			return false;
		}
		Iterator() : p_DA(nullptr), p_Data(nullptr), idx(-1) {}
		Iterator(TDArray<T>* arr,T* data, int index) : p_DA(arr), p_Data(data), idx(index) {
			/*if (TDArray<T>::Arr == NULL) idx = -1;*/
		}
	};
	TDArray<T>::Iterator Begin();
	TDArray<T>::Iterator End();

	TDArray();
	TDArray(int);
	TDArray(const TDArray& Other);
	~TDArray();
	
	bool PushBack(T data);
	bool RemoveBack();
	bool RemoveIndex(int index);
	int FindIndex(T data);
	bool IsExist(T data);
	T* GetData(int idx) { return &Arr[idx]; }

	TDArray& operator =(const TDArray& Other) {
		Size = Other.Size;
		Capacity = Other.Capacity;
		if (Arr != nullptr) delete[] Arr;
		Arr = new T[Other.Capacity];
		for (int i = 0; i < Size; i++) Arr[i] = Other.Arr[i];
		return *this;
	}
};

template<typename T>
typename TDArray<T>::Iterator TDArray<T>::Begin() {
	return TDArray<T>::Iterator(this, Arr, 0);
}

template<typename T>
typename TDArray<T>::Iterator TDArray<T>::End() {
	return TDArray<T>::Iterator(this, Arr, -1);
}

template<typename T>
inline TDArray<T>::TDArray() : DEFAULT_SIZE(1) {
	Size = 0;
	Capacity = DEFAULT_SIZE;
	Arr = new T[DEFAULT_SIZE];
}

template<typename T>
inline TDArray<T>::TDArray(int size) {
	Size = 0;
	Capacity = size;
	Arr = new T[size];
}

template<typename T>
inline TDArray<T>::TDArray(const TDArray& Other) : DEFAULT_SIZE(1) {
	*this = Other;
}

template<typename T>
inline TDArray<T>::~TDArray() {
	delete[] Arr; 
}

template<typename T>
inline bool TDArray<T>::PushBack(T data) {
	if (Size + 1 > Capacity) {
		Capacity *= 2;
		T* tmp = new T[Capacity];
		for (int i = 0; i < Size; i++) tmp[i] = Arr[i]; delete[] Arr;
		Arr = new T[Capacity];
		for (int i = 0; i < Size; i++) Arr[i] = tmp[i]; delete[] tmp;
		if (Arr == nullptr) return false;
	}
	Arr[Size] = data;
	Size++;
	return true; 
}

template<typename T>
inline bool TDArray<T>::RemoveBack() {
	return false;
}

template<typename T>
inline bool TDArray<T>::RemoveIndex(int index) {
	return false;
}

template<typename T>
inline int TDArray<T>::FindIndex(T data) {
	for (int i = 0; i < Size; i++) if (Arr[i] == data) return i;
	return -1;
}

template<typename T>
inline bool TDArray<T>::IsExist(T data) {
	for (int i = 0; i < Size; i++) if (Arr[i] == data) return true;
	return false;
}