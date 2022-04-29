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

void Human::Dothing() {
	std::cout << "뭐하지" << std::endl;
}

void Human::Print() {
	std::cout << "사람 나이:" << age << " 사람 키:" << height << " 사람 무게:" << weight << std::endl;
}

void Human::Grow() {
	height += 2;
	weight += 2;
}

void Human::Walk() {
	std::cout << "사람이 두발로 걷는다" << std::endl;
}
