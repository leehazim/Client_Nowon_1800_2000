#include <iostream>
#include "TDArray.h"

int main(void) {
	TDArray<int> id;
	
	for(int i = 0; i< 10; i++)
		id.PushBack(i+1);
	PrintArray(id);
	
	TDArray<int> id2 = id;

	PrintArray(id2);
	return 0;
}

void PrintArray(TDArray<int>& Other) {
	for (int i = 0; i < Other.Size; i++)
		std::cout << Other.Arr[i] << " ";
	std::cout << std::endl;
}
