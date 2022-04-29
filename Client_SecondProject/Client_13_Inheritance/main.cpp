#include <iostream>
#include <Windows.h>
#include "Dog.h"
#include "Human.h"
#include "WHuman.h"
#include "YHuman.h"
#include "BHuman.h"

/* 상속의 필요성: 코드의 재활용 및 확장성을 위해서 계층을 만든 것*/
/* 가상함수 virtual 
가상함수로 정의된 함수는 기반클래스 포인터로 파생클래스 객체를 호출하였을때 파생클래스에서 오버라이드 된 메소드를 호출한다.*/

void Print(Human* dest) {
	dest->Print();
}

int main(void) {
	
	/*Creature* creature1 = new Creature();*/
	Dog* dog1 = new Dog();
	Human* man = new Human;
	int elapsedTime = 0;
	int wearCloth = 0;
	//YHuman* Y = new YHuman;
	//BHuman* B = new BHuman;
	//WHuman* W = new WHuman;

	//// 클래스가 계층을 가지고 있을때의 특징 기반클래스의 포인터로 파생객체 참조 가능
	///* 가상함수를 사용하지 않을 경우에는 기반클래스에 있는 멤버에만 접근이 가능하다.*/
	//Human* Ym = new YHuman;
	//Human* Bm = new BHuman;
	//Human* Wm = new WHuman;

	Human* humans[99];
	for (int i = 0; i < 99; i += 3) {
		humans[i] = new YHuman;
		humans[i + 1] = new BHuman;
		humans[i + 2] = new WHuman;
	}

	man->WearCloth("청바지");
	man->WearCloth("셔츠");
	man->WearCloth("야구모자");
	man->WearCloth("니트");
	man->WearCloth("장갑");
	
	ITwoLeggedWalker* twoLeggedWalkers[99];
	for (int i = 0; i < 99; i += 3) {
		twoLeggedWalkers[i] = new YHuman;
		twoLeggedWalkers[i + 1] = new BHuman;
		twoLeggedWalkers[i + 2] = new WHuman;
	}


	for (int i = 0; i < 99; i++) {
		twoLeggedWalkers[i]->Walk();
	}

	//while (true) {
	//	for (int i = 0; i < 99; i++) {
	//		humans[i]->Breath();
	//		/*humans[i]->Print();
	//		humans[i]->Dothing();*/
	//		/*std::cout << i << " 의 나이 :" << humans[i]->age << ", 키 : " << humans[i]->height << ", 무게 : " << humans[i]->weight << std::endl;*/
	//		Print(humans[i]);
	//	}
	//	
	//	
	//	/*std::cout << "황인 나이:" << Y->age << " 황인 키:" << Y->height << " 황인 무게:" << Y->weight << std::endl;
	//	std::cout << "흑인 나이:" << B->age << " 흑인 키:" << B->height << " 흑인 무게:" << B->weight << std::endl;
	//	std::cout << "백인 나이:" << W->age << " 백인 키:" << W->height << " 백인 무게:" << W->weight << std::endl;*/

	//	// 생물 숨쉬기
	//	//creature1->Breath();
	//	//std::cout << "크리처 나이 : " << creature1->age << " 크리처 높이 : " << creature1->height << " 크리처 무게 : " << creature1->weight << std::endl;
	//	//
	//	//// 개 숨쉬기
	//	//dog1->Breath();
	//	//std::cout << "개 나이 : " << dog1->age << " 개 높이 : " << dog1->height << " 개 무게 : " << dog1->weight << std::endl;

	//	//man->Breath();
	//	//std::cout << "사람 나이 : " << man->age << " 사람 높이 : " << man->height << " 사람 무게 : " << man->weight << std::endl;

	//	//// 3초마다 물기
	//	//if (++elapsedTime % 3 == 0) dog1->Bite(creature1);
	//	///* 5초마다 입고있는 옷을 나열*/
	//	//if (++wearCloth % 5 == 0) 	man->PrintAllClothes();
	//	
	//	Sleep(1000);
	//}
	delete dog1;
	/*delete creature1;*/
	delete man;
	delete humans[0];
	
	return 0;
}