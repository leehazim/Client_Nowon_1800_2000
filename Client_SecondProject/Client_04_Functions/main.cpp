#include <iostream>
#include <string>
using namespace std;

int add(int, int, int);
int add(int, int = 1);
/* ����Ʈ �Ű����� �Լ� ����ο��� ���ڸ� �ѱ��� �ʾƵ� �⺻���� �μ������� ����ϰ� �ϴ� �⺻���� �����ϴ� ��
����!! ������ �ڿ��� ���� ����Ʈ�� �־���ϰ�, ����Ʈ�� �ְԵǾ� ���� �Ű������� ������ ���¸� ������ �ִٸ� �����Ϸ��� ���� �Լ��� ȣ���ؾ��ϴ��� �ָ�������.*/
double add(double, double = 3.4);
string add(string, string);

/* �ζ��� �Լ� 
�����Ͻ� �Լ����� �������� ȣ���ؼ� ����ϴ� ����� �Լ��� �ƴ϶�, �Լ��� ȣ��Ǵ� ������ �Լ������� �ٿ����� ��
���� �Ҵ� ���� �۾��� ��� ����ӵ��� ������, ������ ���������� �뷮�� Ŀ���� ������ �ִ�.*/

inline int Sub(int, int);

int main(void) {
	cout << add(1, 2) << endl;
	cout << add(1.2, 3.4) << endl;
	cout << add("Wow! ", "Hello World") << endl;
	cout << Sub(2, 1) << endl;
	return 0; 
}

/* ������ ���� ���Ŭ�������� �Ļ��Ǿ� ���� Ŭ�������� ȣ��Ǿ����� �ڱ��ڽ��� ȣ��Ǵ� ��*/
/* �Լ� �����ε� �����̸��� �Լ����� �Ű������� �ٸ��� �־ ������ ������ �� �ִ°� */
int add(int a, int b, int c) { return a + b + c; }
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
string add(string a, string b) { return a.append(b); }
inline int Sub(int a, int b) { return a - b; }