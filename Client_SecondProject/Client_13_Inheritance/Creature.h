#pragma once
class Creature {
public:
	int weight;
	int height;
	int age;

public:
	// 디폴트 생성자를 오버로딩 하지 않고 기본 제공되는 생성자를 사용할 경우
	// 자동으로 멤버들을 0으로 초기화 해주는 디폴트 생성자가 제공된다.
	virtual void Breath();
	virtual void Grow() = 0; 
	/* 순수 가상함수 정의를 하지않는 가상함수로 이 클래스를 상속받은 클래스는 반드시 이 함수를 오버라이드 해야함.
	 순수 가상함수를 가지는 클래스는 추상클래스라고 하며 추상클래스는 인스턴스화가 불가능함*/
	/* 인터페이스처럼 특정기능으로 객체들을 묶어서 사용할때 사용*/
};

