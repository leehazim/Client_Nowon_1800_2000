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
		// 아무것도 하지 않는다.
		break;

	case SCV::START_MINING:
		m_timeMark = clock();
		NextState();
		break;

	case SCV::ON_MINING:
		// 채굴이 끝났는지 검사
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

// enum은 결국 32비트 정수값이라서 지정할 수 있는 상태의 크기는 33이다.
// 0000 ~ 1000000000
enum LayerMask {
	GHOST = 0 << 0,
	PLAYER = 1 << 0,
	WALL = 1 << 1,
	GROUND = 1 << 2,
};
// 그에 대한 해결책으로 C++에서 제공하는 enum class도 있다.
// 그러나 파일로 출력하고 입력하는 과정에서 상당히 복잡하기 때문에 
// 추천할 만한 방식은 아니다.
enum class LAYER_MASK_64 : unsigned __int64 {
	IDLE = 0x0000000000000000000LL,
	PLAYER = 1 << 0,
};

void SCV::NextState() {
	m_state = (STATE)(m_state + 1);
}

void SCV::RegisterCallback(REGISTER_CALLBACK callback) {
	cb = callback;
}