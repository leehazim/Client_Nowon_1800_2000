#pragma once
template <typename T>
class TDArray {
	friend void PrintArray(TDArray& Other);
private:
	T* Arr;
	int Size;
	int Capacity;
	const int DEFAULT_SIZE;
	
public:
	TDArray();
	TDArray(int);
	TDArray(const TDArray& Other);
	~TDArray();
	
	bool PushBack(T data);
	bool RemoveBack();
	bool RemoveIndex(int index);
	int FindIndex(T data);
	bool IsExist(T data);

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
inline TDArray<T>::~TDArray() { delete[] Arr; }

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