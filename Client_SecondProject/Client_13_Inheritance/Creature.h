#pragma once
class Creature {
public:
	int weight;
	int height;
	int age;

public:
	// 디폴트 생성자를 오버로딩 하지 않고 기본 제공되는 생성자를 사용할 경우
	// 자동으로 멤버들을 0으로 초기화 해주는 디폴트 생성자가 제공된다.
	void Breath();
	void Grow();
};

