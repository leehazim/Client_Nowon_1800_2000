#include "CommandCenter.h"
#include <iostream>

#pragma region ΩÃ±€≈Ê
CommandCenter* CommandCenter::_instance = nullptr; 

CommandCenter* CommandCenter::GetInstance() {
    if (_instance == nullptr) 
        _instance = new CommandCenter();
    
    return _instance;
}
#pragma endregion


void CommandCenter::UpdateAllSCVs() {
    std::vector<SCV>::iterator iter = SCVs.begin();
    for (; iter != SCVs.end(); iter++) {
        if (iter->m_state == SCV::STATE::IDLE)
            iter->DoMine();

        iter->UpdateState();
    }
}

bool CommandCenter::TrySpawnSCV() {
    if (_minerals > SCV_COST) {
       _minerals -= SCV_COST;
       SpawnSCV();
       return true;
    }
    return false;
}

void CommandCenter::SpawnSCV() {
    new SCV();
    _unitSpawnCount++;
}

void CommandCenter::SCVCallBack(int id) {  
    std::cout << "SCV (Unit ID : " << id << ") ¡ÿ∫Òøœ∑·" << std::endl;
}

void CommandCenter::Register(SCV& scv) {
    scv.RegisterCallback(SCVCallBack);
    SCVs.push_back(scv);
}

void CommandCenter::IncreaseMinerals(int amount) {
    _minerals += amount;
    std::cout << "«ˆ¿Á πÃ≥◊∂ˆ : " << _minerals << std::endl;
}

int CommandCenter::GetUnitSpawnCount() {
    return _unitSpawnCount;
}
