/* ������ ũ��� ������ �浹�� �����Ǵ°��� ���� �ٶ����ϴ�. ����� �ʹ� ũ�� �� ������ ������ �� �ְ�
���� ������� ���� ���� �ؽð��� �ߺ��� �������� �Ҿ����ϴ�.
�ؽð��� ������ �Ͼ�� �浹�� ó���ϴ� �۾��� �ʿ��ϴ�.*/

/* �浹 �ذ���
1. ü�̴�(Chainning) : ��� Value�� LinkedList�� �����迭�� �����ϴ� ���
2. ���� ��巹��(Open Addressing) : 	�ؽ�Ű�� �浹�� �ٽ� �ؽð��� �����ϴ� ���
									ex) ö���ؽ� 35, �����ؽ� 35�϶� ���� �ؽ� 135�� ����� �ϰ� �ؽ����̺��� ũ�⸦ ����
*/

/* �ؽ� �������
1. ��ⷯ ��� ���
*/
#include <iostream>
#include "HashTable.h"
using namespace std;

int main(void) {
	HashTable* HT = new HashTable();
	HT->Add("joshua");
	HT->Add("mose");
	HT->Add("ojshua");
	cout << HT->ContainsValue("joshua") << endl;
	HT->PrintKey("joshua");
	HT->PrintKey("mose");
	return 0;
}