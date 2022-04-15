#include <iostream>
using namespace std;

/* Ŭ����
 ��ü�� ����(����)�ϱ����� ����� ���� ��������
 ���� =>
 class Ŭ������{
 ����������:
 �������
( ����������:)
 ����޼ҵ�
 };*/

/* ����������
1.public: Ŭ���� �ܺο��� ������ ������ �����
2.private: Ŭ���� �ܺο��� ������ �Ұ����� ����� 
3.protected: ��ӹ��� Ŭ���������� ������ ������ ��� �ܺο����� ������ �Ұ���

���� ����: OOP�� OOP�� �ǰ� ���ִ� ����� Ư�� ĸ��ȭ ������
  Ŭ������ ����ϴµ� �־ ���ٵǾ�� �ȵǴ� ������� ��ȣ�ϱ� ���ؼ� �����Ѵ�.
  �����ͺ��̽��� ����ǰ� ���ִ� ��ũ ��������� �ϴ� �������� �ʱ�ȭ ���Ŀ� �ǵ������ ���� ������ ���װ� �ɰ��̴�.
  �̸� �����ϱ� ���� �ִ� ��
  
*/

/* ������, �Ҹ���
������ Ŭ�����̸�()	: ��ü�� �����Ҷ� �ڵ����� ȣ��ȴ�. ������ �ʱ�ȭ�� ������ ������ �ִ�. �����Ⱚ��ġ��� ������ ������� ��ũ�� �ñ⸦ ��
�Ҹ��� ~Ŭ�����̸�()	: ��ü�� ����� ������ �ı��ؾ��Ҷ� ������ �Լ��������ų� ���α׷��� ������ �ڵ� ȣ��ȴ�. �����Ҵ�Ǿ��� �������� ������ Ÿ�̹��� �ش�.
*/
class Coord {
private:
	int m_x, m_y;

public:

	/*�����ڿ� �Ҹ��� �Ѵ� �Լ���.*/
	Coord() { SetCoord(0, 0); }
	Coord(int x, int y) { 
		if (SetCoord(x, y) == false) {
			SetCoord(0, 0);
		}
	} /* ������ �����ε�*/
	~Coord() {}

	bool SetCoord(int x, int y) {
		if ((x <= 100 && x >= 0) && (y <= 100 && y >= 0)) {
			m_x = x; m_y = y;
			return true;
		}
		return false;
		/* �̷� ������ �ܺο��� ���� �����Ϸ��� �Ҷ� �� ���� ��ü�� �˾Ƽ� ���� ������ �˻��ؼ� �������� ������ ���װ� �� ������ �˾Ƽ� ������ �� �ְ� �ϱ�����
		���������ڷ� ����� ���ٸ��ϰ� �ϰ� �Լ����� �Է��� ������ ���� ������ �Ǵ��ϰ� �ϴ°��� ����.*/
	}
	int GetX() { return m_x; }
	int GetY() { return m_y; }
	bool operator()(int x, int y) {	return SetCoord(x, y); }
	Coord& operator =(const Coord& Other) {
		/* ������ �����ε� �̰� ���� ����Ʈ ���Կ����̶� �ٸ��� �����ϴ�.*/
		SetCoord(Other.m_x, Other.m_y);
		return *this;
	}
	Coord& operator +(const Coord& Other) { 
		/* �����ε����� �Ű������� �ϳ��� ���� �� �ִ� ������ �Ű�������  this�� ����Ʈ�� �־ �׷���.thisŰ����� ��ü �ڱ� �ڽ��� ����Ű�� �����Ͷ�� ���� �ȴ�.*/
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
	/*����Ʈ ���Կ����ڰ� ���ǵǾ��ֱ� ������ �����ϴ�. ����޼ҵ嵵 ������ �ִµ� ������ �Ǵ� ������ ��� ��ü�� �޼ҵ带 �����°� �ƴ϶�
	Ŭ������ �޼ҵ���� ����� �����͸� �������ִٰ� ���°� �� Ÿ���� ���̴�.*/
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