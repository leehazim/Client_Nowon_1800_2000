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

	man->WearCloth("û����");
	man->WearCloth("����");
	man->WearCloth("�߱�����");
	man->WearCloth("��Ʈ");
	man->WearCloth("�尩");

	while (true) {
		// ���� ������
		creature1->Breath();
		std::cout	<< "ũ��ó ���� : "		<< creature1->age 
					<< " ũ��ó ���� : "		<< creature1->height 
					<< " ũ��ó ���� : "		<< creature1->weight 
					<< std::endl;
		
		// �� ������
		dog1->Breath();
		std::cout	<< "�� ���� : "		<< dog1->age 
					<< " �� ���� : "		<< dog1->height
					<< " �� ���� : "		<< dog1->weight 
					<< std::endl;

		man->Breath();
		std::cout	<< "��� ���� : "		<< man->age
					<< " ��� ���� : "		<< man->height
					<< " ��� ���� : "		<< man->weight
					<< std::endl;

		// 3�ʸ��� ����
		if (++elapsedTime % 3 == 0) dog1->Bite(creature1);
		if (++wearCloth % 5 == 0) 	man->PrintAllClothes();
		
		Sleep(1000);
	}
	delete dog1;
	delete creature1;
	delete man;
	
	return 0;
}