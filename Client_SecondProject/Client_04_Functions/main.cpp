#include <iostream>
#include <string>
using namespace std;

int add(int, int, int);
int add(int, int = 1);
/* 디폴트 매개변수 함수 선언부에서 인자를 넘기지 않아도 기본으로 인수값으로 사용하게 하는 기본값을 설정하는 것
주의!! 무조건 뒤에서 부터 디폴트를 주어야하고, 디폴트를 주게되어 앞의 매개변수가 동일한 형태를 가지고 있다면 컴파일러는 무슨 함수를 호출해야하는지 애매해진다.*/
double add(double, double = 3.4);
string add(string, string);

/* 인라인 함수 
컴파일시 함수들을 스택으로 호출해서 사용하는 방식의 함수가 아니라, 함수가 호출되는 곳마다 함수내용이 붙여지는 것
스택 할당 정리 작업이 없어서 실행속도가 빠르다, 하지만 실행파일의 용량이 커지는 단점이 있다.*/

inline int Sub(int, int);

int main(void) {
	cout << add(1, 2) << endl;
	cout << add(1.2, 3.4) << endl;
	cout << add("Wow! ", "Hello World") << endl;
	cout << Sub(2, 1) << endl;
	return 0; 
}

/* 다형성 같은 기반클래스에서 파생되어 나온 클래스들이 호출되었을때 자기자신이 호출되는 것*/
/* 함수 오버로딩 같은이름의 함수들을 매개변수를 다르게 주어서 여러개 선언할 수 있는것 */
int add(int a, int b, int c) { return a + b + c; }
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
string add(string a, string b) { return a.append(b); }
inline int Sub(int a, int b) { return a - b; }