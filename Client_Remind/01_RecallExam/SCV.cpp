#include "SCV.h"
#include <iostream>
#include <chrono>

SCV::SCV() : m_state(STATE::IDLE), m_timeMark(0.0) {
	RegisterCallback(SayImReady);
	cb(this->id);
}

void SCV::DoMine() {
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
		m_state = STATE::ON_MINING;
		break;

	case SCV::ON_MINING:
		// ä���� �������� �˻�
		if ((clock() - m_timeMark) > SCV_MININGTIME) {
			NextState();
		}
		break;

	case SCV::FINISH_MINING:
		DoMine();
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

void SCV::SayImReady(int id) {
	std::cout <<  "SCV" << id<<  "�غ�Ϸ�!" << std::endl;
}
