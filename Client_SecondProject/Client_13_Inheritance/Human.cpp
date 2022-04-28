#include "Human.h"

void PrintArray(TDArray<std::string>& Other) {
	for (int i = 0; i < Other.Size; i++) std::cout << Other.Arr[i] << " ";
	std::cout << std::endl;
}

void Human::WearCloth(std::string cloth) {
	clothes.PushBack(cloth);
}

void Human::PrintAllClothes() {
	PrintArray(clothes);
}
