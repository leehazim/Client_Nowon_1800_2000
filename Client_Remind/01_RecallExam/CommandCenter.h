#pragma once
#include <vector>
#include "SCV.h"

const int START_SCV_COUNT = 2;

class CommandCenter {
#pragma region 싱글톤
private:
	static CommandCenter* _instance;

public:
	static CommandCenter* GetInstance();
#pragma endregion

private:
	int _minerals;
	int _unitSpawnCount;
	
public:
	std::vector<SCV> SCVs;

public:
	// SCV에게 명령을 내릴때 호출할 콜백
	static void SCVCallBack(int id);

	void UpdateAllSCVs();	// 모든 SCV상태 갱신
	bool TrySpawnSCV();		// 자원개수에 따른 SCV소환 시도
	void SpawnSCV();		// SCV소환

	void Register(SCV& scv); // SCV를 벡터에 등록
	void IncreaseMinerals(int amount);
	int GetUnitSpawnCount();
};