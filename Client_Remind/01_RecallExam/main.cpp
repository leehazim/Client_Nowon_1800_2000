#include <iostream>
#include <windows.h>
#include "SCV.h"
#include "CommandCenter.h"


int main(void) {

	/*CommandCenter* commandCenter = CommandCenter::GetInstance();*/
	// 기본적으로 SCV를 2마리 가지고 시작.
	//for (int i = 0; i < START_SCV_COUNT; i++)
	//	CommandCenter::GetInstance()->SpawnSCV();

	//float scv_timer = SCV_SPAWN_TIME;
	//float delta_time = 16.6666667f; // 초당 60프레임기준 프레임당 돌아가는 시간
	//while (true) {

	//	if (scv_timer <= 0) {
	//		if (CommandCenter::GetInstance()->TrySpawnSCV()) {
	//			scv_timer = SCV_SPAWN_TIME;
	//		}
	//	}
	//	// SCV모두가 일하도록 업데이트
	//	CommandCenter::GetInstance()->UpdateAllSCVs();

	//	Sleep(delta_time);
	//	scv_timer -= delta_time; // SCV 생성 주기를 카운트
	//}

	
	return 0;
}