#pragma once
#define SCV_COST 50
#define SCV_SPAWN_TIME 4000
#define SCV_MINING_TIME 2000
#define SCV_MINING_AMOUNT 8

typedef void(*REGISTER_CALLBACK)(int);

/// <summary>
/// �ۼ��� : �̽���
/// 
/// ���� :
/// �����̳� ������ ä���ϴ� �ϲ� SCVŬ����
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
};