#include <iostream>
using namespace std;

/* 클래스
 객체를 정의(생성)하기위한 사용자 정의 데이터형
 형식 =>
 class 클래스명{
 접근제어자:
 멤버변수
( 접근제어자:)
 멤버메소드
 };*/

/* 접근제어자
1.public: 클래스 외부에서 접근이 가능한 멤버들
2.private: 클래스 외부에서 접근이 불가능한 멤버들 
3.protected: 상속받은 클래스까지만 접근이 가능한 멤버 외부에서는 접근이 불가능

존재 이유: OOP언어가 OOP언어가 되게 해주는 언어적 특성 캡슐화 때문에
  클래스를 사용하는데 있어서 접근되어서는 안되는 멤버들을 보호하기 위해서 존재한다.
  데이터베이스와 연결되게 해주는 링크 변수라던가 하는 변수들은 초기화 이후에 건드려지면 아주 복잡한 버그가 될것이다.
  이를 방지하기 위해 있는 것
  
*/

/* 생성자, 소멸자
생성자 클래스이름()	: 객체를 생성할때 자동으로 호출된다. 생성시 초기화를 목적을 가지고 있다. 쓰래기값을치우고 포인터 멤버변수 링크할 시기를 줌
소멸자 ~클래스이름()	: 객체의 사용이 끝나고 파괴해야할때 보통은 함수가끝나거나 프로그램이 끝날때 자동 호출된다. 동적할당되었던 변수들을 해제할 타이밍을 준다.
*/
class Coord {
private:
	int m_x, m_y;

public:

	/*생성자와 소멸자 둘다 함수다.*/
	Coord() { SetCoord(0, 0); }
	Coord(int x, int y) { 
		if (SetCoord(x, y) == false) {
			SetCoord(0, 0);
		}
	} /* 생성자 오버로딩*/
	~Coord() {}

	bool SetCoord(int x, int y) {
		if ((x <= 100 && x >= 0) && (y <= 100 && y >= 0)) {
			m_x = x; m_y = y;
			return true;
		}
		return false;
		/* 이런 식으로 외부에서 값을 변경하려고 할때 그 값을 객체가 알아서 가능 범위를 검사해서 논리적으로 가지면 버그가 될 값들을 알아서 차단할 수 있게 하기위함
		접근제어자로 멤버에 접근못하게 하고 함수에서 입력을 받을때 값의 범위를 판단하게 하는것이 좋다.*/
	}
	int GetX() { return m_x; }
	int GetY() { return m_y; }
	bool operator()(int x, int y) {	return SetCoord(x, y); }
	Coord& operator =(const Coord& Other) {
		/* 연산자 오버로딩 이건 현재 디폴트 대입연산이랑 다를게 없긴하다.*/
		SetCoord(Other.m_x, Other.m_y);
		return *this;
	}
	Coord& operator +(const Coord& Other) { 
		/* 오버로딩에서 매개변수가 하나만 있을 수 있는 이유는 매개변수에  this가 디폴트로 있어서 그렇다.this키워드는 객체 자기 자신을 가리키는 포인터라고 보면 된다.*/
		Coord tmp;
		tmp.SetCoord(m_x + Other.m_x, m_y + Other.m_y);
		return tmp;
	}
	Coord& operator +=(const Coord& Other) {
		*this = *this + Other;
		return *this;
	}
};

int main(void) {
	Coord coord1; 
	coord1(20,20);
	cout << "(" << coord1.GetX() << "," << coord1.GetY() << ")" << endl;
	
	Coord* coord2Ptr = new Coord(1, 2);
	cout << "(" << coord2Ptr->GetX() << "," << coord2Ptr->GetY() << ")" << endl;
	
	Coord coord3 = coord1 = *coord2Ptr; 
	/*디폴트 대입연산자가 정의되어있기 때문에 가능하다. 멤버메소드도 가지고 있는데 대입이 되는 이유는 모든 객체가 메소드를 가지는게 아니라
	클래스의 메소드들이 저장된 포인터를 가지고있다고 보는게 더 타당할 것이다.*/
	cout << "coord1 = (" << coord1.GetX() << "," << coord1.GetY() << ")" << endl;
	cout << "coord3 = (" << coord3.GetX() << "," << coord3.GetY() << ")" << endl;


	Coord coord4 = coord3 + coord1;
	cout << "coord3 = (" << coord3.GetX() << "," << coord3.GetY() << ")" << " ";
	cout << "coord4 = (" << coord4.GetX() << "," << coord4.GetY() << ")" << endl;

	coord3 += coord4;
	cout << "coord3 = (" << coord3.GetX() << "," << coord3.GetY() << ")" << " ";
	cout << "coord4 = (" << coord4.GetX() << "," << coord4.GetY() << ")" << endl;
	delete coord2Ptr;	
 	return 0;
}