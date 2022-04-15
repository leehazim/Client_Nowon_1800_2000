#include "Warrior.h"
#include "Debuffer.h"
#include <string>
#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

int main(void) {
	/* 싱글톤 패턴 
	한개의 객체로 모든 것을 관리하는 프로그램스타일, 객체당 하나씩만 생성해서 관리하는 방법*/
	/*Warrior* warrior = new Warrior();*/
	/*warrior->PrintState();*/
	
	//if (true/* 디버프 발생!*/) warrior->SetHP(warrior->GetHP() - 10);
	/*warrior->PrintState();*/

	Warrior::GetInstance()->PrintState();
	Debuffer* debuffer = new Debuffer;
	debuffer->DecreaseHP();
	Warrior::GetInstance()->PrintState();
	delete debuffer;

	Debuffer debuffer1;
	strcpy(debuffer1.Name, "하급디버퍼");
	debuffer1.Damage = 10;
	
	Debuffer debuffer2 = debuffer1;
	strcpy(debuffer2.Name, "상급디버퍼");
	debuffer2.Damage = 30;
	cout << "1번 " << debuffer1.Damage << "," << debuffer1.Name << endl;
	cout << "2번 " << debuffer2.Damage << "," << debuffer2.Name << endl;
	/*warrior->PrintState();*/
	/*delete warrior;*/
	/* 현재 프로그램 방식은 객체를 매개변수로 전달을 자주하는데 생각보다 번거로울 것.*/
	return 0;
}