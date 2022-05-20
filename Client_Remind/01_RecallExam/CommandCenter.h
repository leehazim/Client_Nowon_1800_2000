#pragma once
#include <vector>
#include "SCV.h"

const int START_SCV_COUNT = 2;

class CommandCenter {
#pragma region �̱���
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
	// SCV���� ����� ������ ȣ���� �ݹ�
	static void SCVCallBack(int id);

	void UpdateAllSCVs();	// ��� SCV���� ����
	bool TrySpawnSCV();		// �ڿ������� ���� SCV��ȯ �õ�
	void SpawnSCV();		// SCV��ȯ

	void Register(SCV& scv); // SCV�� ���Ϳ� ���
	void IncreaseMinerals(int amount);
	int GetUnitSpawnCount();
};