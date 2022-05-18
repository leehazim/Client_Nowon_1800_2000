#pragma once
#include <vector>
#include "SCV.h"
class CommandCenter {
public:
	int m_minerals;
	std::vector<SCV> SCVs;

	CommandCenter();
	void UpdateAllSCVs();
	bool TrySpawnSCV();
	void SCVCallBack(int id);
	void Register(SCV& scv, REGISTER_CALLBACK cb);
};

