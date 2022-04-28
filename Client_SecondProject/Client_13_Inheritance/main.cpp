#include <iostream>
#include <Windows.h>
#include "Dog.h"
#include "Human.h"

int main(void) {
	Creature* creature1 = new Creature();
	Dog* dog1 = new Dog();
	Human* man = new Human;
	int elapsedTime = 0;
	int wearCloth = 0;

	man->WearCloth("청바지");
	man->WearCloth("셔츠");
	man->WearCloth("야구모자");
	man->WearCloth("니트");
	man->WearCloth("장갑");

	while (true) {
		// 생물 숨쉬기
		creature1->Breath();
		std::cout	<< "크리처 나이 : "		<< creature1->age 
					<< " 크리처 높이 : "		<< creature1->height 
					<< " 크리처 무게 : "		<< creature1->weight 
					<< std::endl;
		
		// 개 숨쉬기
		dog1->Breath();
		std::cout	<< "개 나이 : "		<< dog1->age 
					<< " 개 높이 : "		<< dog1->height
					<< " 개 무게 : "		<< dog1->weight 
					<< std::endl;

		man->Breath();
		std::cout	<< "사람 나이 : "		<< man->age
					<< " 사람 높이 : "		<< man->height
					<< " 사람 무게 : "		<< man->weight
					<< std::endl;

		// 3초마다 물기
		if (++elapsedTime % 3 == 0) dog1->Bite(creature1);
		if (++wearCloth % 5 == 0) 	man->PrintAllClothes();
		
		Sleep(1000);
	}
	delete dog1;
	delete creature1;
	delete man;
	
	return 0;
}