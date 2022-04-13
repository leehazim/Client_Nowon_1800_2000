#include <iostream>
#include <string>
using namespace std;

int main(void) {

	//const int DEFAULT_SIZE = 4;
	///* 기존 C문자열*/
	//char firstName[DEFAULT_SIZE];
	//char lastName[DEFAULT_SIZE];
	///*wchar_t 기본 문자는 1바이트지만 한글은 2바이트를 사용한다. 이 문자형이 다른 문자도 2바이트를 사용할 수 있게 해준다.*/
	//
	//cout << "성을 입력하세요 : "; /*cin >> firstName;*/
	//cin.get(firstName, DEFAULT_SIZE).get();
	///*cin.get(firstName, DEFAULT_SIZE).ignore();*/ /* 문자열의 길이 값이 넉넉하지 않거나 잘못된 입력시 개행문자등을 제거해주어야한다.*/
	//cout << "이름을 입력하세요 : "; /*cin >> lastName;*/ cin.get(lastName, DEFAULT_SIZE);
	//cout << firstName << " " << lastName << endl;

	/* 그래서 문자열도 동적메모리 자료구조처럼 자동으로 입력의 길이에 따라 크기가 재할당되면 좋겠다는 생각하에 새로운 데이터형을 라이브러리 클래스로 제공됨
	String 데이터형이 존재한다,.
	클래스를 이용해서 만들어졌고 객체 사용법에 대한 공부하기 좋다.*/
	string FirstName;
	string LastName;

	cout << "성을 입력하세요 : ";	
	getline(cin, FirstName);
	cout << "이름을 입력하세요 : "; 
	getline(cin, LastName);
	cout << "성은 " << FirstName << "이고, 이름은 " << LastName << "입니다." << endl;
	
	cout << FirstName[0] << endl;
	for (int i = 0; i < FirstName.size(); i++) cout << FirstName[i] << " ";
	cout << endl;

	cout << FirstName.size() << " == " << FirstName.length() << endl;

	/* 문자열 클래스의 함수들
	1. size(), length() 현재할당된 문자열이 차지하고 있는 사이즈를 리턴 즉 문자열 길이를 리턴
	append() : strcat이랑 같은 함수라고 생각해도 좋을거 같다. == 문자열을 추가하는 메소드	*/
	string str1, str2, str3;
	str1.append("Hello World");
	str2.append("Hello World", 6, 5); /*strncat*/
	str3.append(4, '!'); 
	/* append라는 같은 이름의 함수를 사용하고 있는데 함수들이 다 다른작업을 하고있으며 매개변수를 다르게 받는게 가능하다. 함수 오버로드*/
	cout << str1 << " " << str2 << " " << str3 << endl;
	/*
	find : 문자열을 검색해주는 메소드 strstr */
	string tmp = "My Programm";
	int i = tmp.find("Pro"); cout << i; /* 3번째 인덱스부터 Pro가 시작함을 리턴해줌*/
	if (tmp.find("Pro") != string::npos) cout << "Pro 찾았다." << endl;
	else cout << "Pro 없어" << endl;

	/*
	compare() : 두 문자열을 비교해서 같은 문자열인지 비교 strcmp*/
	cout << ((str1.compare(str2) == 0) ? "같아" : "달라") << endl;
	string s1 = "a", s2 = "b";
	cout << s1.compare(s2) << endl; /* 메소드를 호출한 객체가 사전적으로 앞에 있으면 음수*/
	
	/* replace() 인자로 넣어준 문자열을 찾아서 다른 문자열로 대체하는 메소드
	string.replace(대체문자열시작위치, 대체문자열길이, 새로운 문자열)*/
	str1.replace(6, 5, "C++  "); cout << str1 << endl;
	string::iterator it;
	for (it = str1.begin(); it != str1.end(); it++) cout << *it; cout << endl;
	cout << str1.capacity() << endl; /* 문자열이 동적으로 할당되어있는 길이를 리턴해주는 메소드*/
	str1.append("hdkkkekdkkekkdkkdkkekkdk");
	cout << str1.size() << " " << str1.capacity() << endl;

	return 0; 
}