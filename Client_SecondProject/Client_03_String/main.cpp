#include <iostream>
#include <string>
using namespace std;

int main(void) {

	//const int DEFAULT_SIZE = 4;
	///* ���� C���ڿ�*/
	//char firstName[DEFAULT_SIZE];
	//char lastName[DEFAULT_SIZE];
	///*wchar_t �⺻ ���ڴ� 1����Ʈ���� �ѱ��� 2����Ʈ�� ����Ѵ�. �� �������� �ٸ� ���ڵ� 2����Ʈ�� ����� �� �ְ� ���ش�.*/
	//
	//cout << "���� �Է��ϼ��� : "; /*cin >> firstName;*/
	//cin.get(firstName, DEFAULT_SIZE).get();
	///*cin.get(firstName, DEFAULT_SIZE).ignore();*/ /* ���ڿ��� ���� ���� �˳����� �ʰų� �߸��� �Է½� ���๮�ڵ��� �������־���Ѵ�.*/
	//cout << "�̸��� �Է��ϼ��� : "; /*cin >> lastName;*/ cin.get(lastName, DEFAULT_SIZE);
	//cout << firstName << " " << lastName << endl;

	/* �׷��� ���ڿ��� �����޸� �ڷᱸ��ó�� �ڵ����� �Է��� ���̿� ���� ũ�Ⱑ ���Ҵ�Ǹ� ���ڴٴ� �����Ͽ� ���ο� ���������� ���̺귯�� Ŭ������ ������
	String ���������� �����Ѵ�,.
	Ŭ������ �̿��ؼ� ��������� ��ü ������ ���� �����ϱ� ����.*/
	string FirstName;
	string LastName;

	cout << "���� �Է��ϼ��� : ";	
	getline(cin, FirstName);
	cout << "�̸��� �Է��ϼ��� : "; 
	getline(cin, LastName);
	cout << "���� " << FirstName << "�̰�, �̸��� " << LastName << "�Դϴ�." << endl;
	
	cout << FirstName[0] << endl;
	for (int i = 0; i < FirstName.size(); i++) cout << FirstName[i] << " ";
	cout << endl;

	cout << FirstName.size() << " == " << FirstName.length() << endl;

	/* ���ڿ� Ŭ������ �Լ���
	1. size(), length() �����Ҵ�� ���ڿ��� �����ϰ� �ִ� ����� ���� �� ���ڿ� ���̸� ����
	append() : strcat�̶� ���� �Լ���� �����ص� ������ ����. == ���ڿ��� �߰��ϴ� �޼ҵ�	*/
	string str1, str2, str3;
	str1.append("Hello World");
	str2.append("Hello World", 6, 5); /*strncat*/
	str3.append(4, '!'); 
	/* append��� ���� �̸��� �Լ��� ����ϰ� �ִµ� �Լ����� �� �ٸ��۾��� �ϰ������� �Ű������� �ٸ��� �޴°� �����ϴ�. �Լ� �����ε�*/
	cout << str1 << " " << str2 << " " << str3 << endl;
	/*
	find : ���ڿ��� �˻����ִ� �޼ҵ� strstr */
	string tmp = "My Programm";
	int i = tmp.find("Pro"); cout << i; /* 3��° �ε������� Pro�� �������� ��������*/
	if (tmp.find("Pro") != string::npos) cout << "Pro ã�Ҵ�." << endl;
	else cout << "Pro ����" << endl;

	/*
	compare() : �� ���ڿ��� ���ؼ� ���� ���ڿ����� �� strcmp*/
	cout << ((str1.compare(str2) == 0) ? "����" : "�޶�") << endl;
	string s1 = "a", s2 = "b";
	cout << s1.compare(s2) << endl; /* �޼ҵ带 ȣ���� ��ü�� ���������� �տ� ������ ����*/
	
	/* replace() ���ڷ� �־��� ���ڿ��� ã�Ƽ� �ٸ� ���ڿ��� ��ü�ϴ� �޼ҵ�
	string.replace(��ü���ڿ�������ġ, ��ü���ڿ�����, ���ο� ���ڿ�)*/
	str1.replace(6, 5, "C++  "); cout << str1 << endl;
	string::iterator it;
	for (it = str1.begin(); it != str1.end(); it++) cout << *it; cout << endl;
	cout << str1.capacity() << endl; /* ���ڿ��� �������� �Ҵ�Ǿ��ִ� ���̸� �������ִ� �޼ҵ�*/
	str1.append("hdkkkekdkkekkdkkdkkekkdk");
	cout << str1.size() << " " << str1.capacity() << endl;

	return 0; 
}