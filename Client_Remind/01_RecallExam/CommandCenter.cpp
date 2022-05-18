#include "CommandCenter.h"

void CommandCenter::UpdateAllSCVs() {
    std::vector<SCV>::iterator iter = SCVs.begin();
    for (; iter != SCVs.end(); iter++) {
        iter->UpdateState();
    }
}

bool CommandCenter::TrySpawnSCV() {
    if (m_minerals > SCV_COST) {
       m_minerals -= SCV_COST;
       new SCV();
       return true;
    }
    return false;
}

void CommandCenter::SCVCallBack(int id) {}

void CommandCenter::Register(SCV& scv, REGISTER_CALLBACK cb) {
    SCVs.push_back(scv);

}
