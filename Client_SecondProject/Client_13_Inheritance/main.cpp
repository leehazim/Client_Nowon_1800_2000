#include <iostream>
#include <Windows.h>
#include "Dog.h"
#include "Human.h"
#include "WHuman.h"
#include "YHuman.h"
#include "BHuman.h"

/* ����� �ʿ伺: �ڵ��� ��Ȱ�� �� Ȯ�强�� ���ؼ� ������ ���� ��*/
/* �����Լ� virtual 
�����Լ��� ���ǵ� �Լ��� ���Ŭ���� �����ͷ� �Ļ�Ŭ���� ��ü�� ȣ���Ͽ����� �Ļ�Ŭ�������� �������̵� �� �޼ҵ带 ȣ���Ѵ�.*/

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

	//// Ŭ������ ������ ������ �������� Ư¡ ���Ŭ������ �����ͷ� �Ļ���ü ���� ����
	///* �����Լ��� ������� ���� ��쿡�� ���Ŭ������ �ִ� ������� ������ �����ϴ�.*/
	//Human* Ym = new YHuman;
	//Human* Bm = new BHuman;
	//Human* Wm = new WHuman;

	Human* humans[99];
	for (int i = 0; i < 99; i += 3) {
		humans[i] = new YHuman;
		humans[i + 1] = new BHuman;
		humans[i + 2] = new WHuman;
	}

	man->WearCloth("û����");
	man->WearCloth("����");
	man->WearCloth("�߱�����");
	man->WearCloth("��Ʈ");
	man->WearCloth("�尩");
	
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
	//		/*std::cout << i << " �� ���� :" << humans[i]->age << ", Ű : " << humans[i]->height << ", ���� : " << humans[i]->weight << std::endl;*/
	//		Print(humans[i]);
	//	}
	//	
	//	
	//	/*std::cout << "Ȳ�� ����:" << Y->age << " Ȳ�� Ű:" << Y->height << " Ȳ�� ����:" << Y->weight << std::endl;
	//	std::cout << "���� ����:" << B->age << " ���� Ű:" << B->height << " ���� ����:" << B->weight << std::endl;
	//	std::cout << "���� ����:" << W->age << " ���� Ű:" << W->height << " ���� ����:" << W->weight << std::endl;*/

	//	// ���� ������
	//	//creature1->Breath();
	//	//std::cout << "ũ��ó ���� : " << creature1->age << " ũ��ó ���� : " << creature1->height << " ũ��ó ���� : " << creature1->weight << std::endl;
	//	//
	//	//// �� ������
	//	//dog1->Breath();
	//	//std::cout << "�� ���� : " << dog1->age << " �� ���� : " << dog1->height << " �� ���� : " << dog1->weight << std::endl;

	//	//man->Breath();
	//	//std::cout << "��� ���� : " << man->age << " ��� ���� : " << man->height << " ��� ���� : " << man->weight << std::endl;

	//	//// 3�ʸ��� ����
	//	//if (++elapsedTime % 3 == 0) dog1->Bite(creature1);
	//	///* 5�ʸ��� �԰��ִ� ���� ����*/
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