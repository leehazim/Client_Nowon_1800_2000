/* 객체지향 프로그래밍 (OOP, Object Oriented Programming) 
 객체들을 단위로 프로그램을 만드는 것
 데이터들을 객체화 해서, 조립한다고 생각하는 것도 좋다.
 
 객체만들기(과정)
 1. 객체 선정
 2. 객체의 상태와 행동들에 대해 생각(추상화)
 3. 객체와 상태와 행돌들에 대해 클래스화(객체 설계도를 만들기)
 4. 객체를 구체화.
 
 ex> 
 1 - 객체 선정
  - 검사를 만들자
 2- 검사한테 필요한 상태및 행위
  - 상태
	= 체력, 공격력, 방어력, 
  - 행위
    = 벤다
 3 - 클래스화 
 4 - 클래스를 가지고 검사의 구체적인 값을 넣어서 검사를 만든다. 어떤 검사는 체력이 작거나 크고 할 수 있다.
 */

/* 클래스 객체 인스턴스
	객체의 정의 : 사물 또는 특정한 행위나 상태를 포함한 사물 혹은 개념
	=> 프로그램의 객체로 바꾸면 상태(변수)나 행위(함수)를 가지고 있는 하나의 사용자형 데이터
	그 사용자형 데이터를 만들기 위해서 설계해 놓은 것이 클래스 그 객체의 테이블이라고 생각하면 좋을지도.
	객체 A 에는 변수, 사용자 정의 데이터, 상수, 함수등이 있다. 
	객체로 이 모든 것을 묶었을때 변수, 함수, 상수들은 객체의 멤버라고 한다.

	클래스는 객체를 만들었을때 객체가 가지고있어야할 공간들과 행위들을 정의하는 거라고 생각하면 되고 
	인스턴스란 클래스에서 객체를 구체화해서 메모리에 장착하는 것을 의미한다.

	즉, 클래스느 구조체, 열거형 등과 같은 사용자 저의 데이터형이고
	객체는 클래스 데이터형의 변수라고 생각하면 편하다.
	그때 클래스 데이터형의 변수인 객체를 인스턴스 변수라고 한다.
*/
#include <iostream>
#include <string>
/* 표준입출력 스트림 헤더파일
stdio.h는 표준입출력 스트림링크로 인해 자동으로 링크된다.

namespace 
C++ 에서는 변수, 함수, 사용자정의 데이터형 등을 서로 구분하기 위해서
이름이 중복되더라도 구분할 수 있도록 상위 식별자를 가질 수 잇도록 한다.
그것이 네임스페이스. 
일반적으로 헤더파일에 선언해두고 사용한다. 특정, 네임스페이스에 접근하려면 
네임스페이스이름::(스코프연산자)데이터
형식으로 접근해야한다.
*/

/*
using 키워드 
namespace를 해당 소스파일에서 전역으로 쓰고 싶을때 사용한다.
아니면, 변수에 별명을 주고 싶을때 사용할 수 있다.
*/

using namespace std;

void Swap(int& a, int& b) {
	int t = a;
	a = b; 
	b = t;
}

int main(void) {
	/* auto키워드
	auto를 자료형 처럼 사용하면서 동시에 선언과 동시에 초기화 하면 초기화 값의 형태로 자동으로 데이터형을 선언해줌*/
	auto i = "string"; // 별로 쓸만한 키워드는 아닌거 같은데... 상수를 표현하기에는 좋을지도.
	// NULL => nullptr

	cout << i;
	cout.width(12);	cout << right << "Hello C++!" << endl;

	int age = 2; 
	cout << "안녕! 몇살이니? : ";
	cin >> age;
	cout << "안녕! 나는 " << age << "살이야!" << endl;
	
	char name[20];
	cout << "이름이 뭐니? : "; cin >> name;
	cout << "내 이름은 " << name << "이야" << endl;
	
	int a = 3, b = 4; Swap(a, b); 
	cout << a << " " << b << endl;

	return 0;
}