#include <iostream>
using namespace std;

typedef struct tag_Node {
	int Member;
}Node;

int main(void) {
	
	Node* head = (Node*)malloc(sizeof(Node));
	free(head);
	/* C������ �����Ҵ��� void*�����ͷ� ���ϵǼ� ���� ĳ��������� �ϰ� �����ؼ� C++���� new��� Ű���尡 ���γ��Դ�. */
	Node* tail = new Node; /* new��� Ű������ �� �ٸ����� �����Ҵ��Ϸ��� ������ Ŭ�����̸� �����ڸ� ȣ�����ش�. ��, ��ü�� �ʱ�ȭ ���شٴ°�*/
	tail->Member = 100;
	//free(tail);/* ������ �ϴ�?*/
	delete tail; /* �����ÿ��� �����ڸ� ȣ�����ذ� ó�� �����ϴ� delete�� �ı��ڸ� ȣ�����ش�. malloc���� ������ free�� �ؾ��ϰ� new�� ������ delete�� �ؾ���*/

	return 0;
}