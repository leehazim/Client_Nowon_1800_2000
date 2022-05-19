#include "SCV.h"
#include <iostream>
#include <chrono>
#include "CommandCenter.h"

SCV::SCV() : m_state(STATE::IDLE), m_timeMark(0.0) {
	CommandCenter* commandCenter = CommandCenter::GetInstance();
	id = commandCenter->GetUnitSpawnCount();
	commandCenter->Register(*this);
}

void SCV::DoMine() {
	cb(id);
	m_state = STATE::START_MINING;
}

void SCV::UpdateState() {
	switch (m_state)
	{
	case SCV::IDLE:
		// �ƹ��͵� ���� �ʴ´�.
		break;

	case SCV::START_MINING:
		m_timeMark = clock();
		NextState();
		break;

	case SCV::ON_MINING:
		// ä���� �������� �˻�
		if ((clock() - m_timeMark) > SCV_MINING_TIME) {
			NextState();
		}
		break;

	case SCV::FINISH_MINING:
		CommandCenter::GetInstance()->IncreaseMinerals(SCV_MINING_AMOUNT);
		m_state = STATE::IDLE;
		break;

	default:
		break;
	}
}

void SCV::NextState() {
	m_state = (STATE)(m_state + 1);
}

void SCV::RegisterCallback(REGISTER_CALLBACK callback) {
	cb = callback;
}