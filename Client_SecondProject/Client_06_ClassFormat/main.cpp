#include "Warrior.h"
#include "Debuffer.h"
#include <string>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

int main(void) {
	/* �̱��� ���� 
	�Ѱ��� ��ü�� ��� ���� �����ϴ� ���α׷���Ÿ��, ��ü�� �ϳ����� �����ؼ� �����ϴ� ���*/
	/*Warrior* warrior = new Warrior();*/
	/*warrior->PrintState();*/
	
	//if (true/* ����� �߻�!*/) warrior->SetHP(warrior->GetHP() - 10);
	/*warrior->PrintState();*/

	Warrior::GetInstance()->PrintState();
	Debuffer* debuffer = new Debuffer;
	debuffer->DecreaseHP();
	Warrior::GetInstance()->PrintState();
	delete debuffer;

	Debuffer debuffer1;
	strcpy(debuffer1.Name, "�ϱ޵����");
	debuffer1.Damage = 10;
	
	Debuffer debuffer2 = debuffer1;
	strcpy(debuffer2.Name, "��޵����");
	debuffer2.Damage = 30;
	cout << "1�� " << debuffer1.Damage << "," << debuffer1.Name << endl;
	cout << "2�� " << debuffer2.Damage << "," << debuffer2.Name << endl;
	/*warrior->PrintState();*/
	/*delete warrior;*/
	/* ���� ���α׷� ����� ��ü�� �Ű������� ������ �����ϴµ� �������� ���ŷο� ��.*/
	return 0;
}