#pragma once
#define SCV_COST 50
#define SCV_MININGTIME 2.0

typedef void(*REGISTER_CALLBACK)(int);
/// <summary>
/// 작성자 : 이승현
/// 
/// 내용 :
/// 광석이나 가스를 채굴하는 일꾼 SCV클래스
/// </summary>
class SCV {
public:

	enum STATE {
		IDLE,
		START_MINING,
		ON_MINING,
		FINISH_MINING
	};

	STATE m_state;
	double m_timeMark;
	int id;
	REGISTER_CALLBACK cb;

	SCV();
	void DoMine();
	void UpdateState();
	void NextState();
	void RegisterCallback(REGISTER_CALLBACK callback);
	static void SayImReady(int id);
};