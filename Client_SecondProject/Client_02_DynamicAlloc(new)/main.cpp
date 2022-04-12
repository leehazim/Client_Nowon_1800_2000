#include <iostream>
using namespace std;

typedef struct tag_Node {
	int Member;
}Node;

int main(void) {
	
	Node* head = (Node*)malloc(sizeof(Node));
	free(head);
	/* C에서의 동적할당은 void*포인터로 리턴되서 직접 캐스팅해줘야 하고 불편해서 C++에서 new라는 키워드가 새로나왔다. */
	Node* tail = new Node; /* new라는 키워드의 또 다른점은 동적할당하려는 변수가 클래스이면 생성자를 호출해준다. 즉, 객체를 초기화 해준다는것*/
	tail->Member = 100;
	//free(tail);/* 가능은 하다?*/
	delete tail; /* 생성시에는 생성자를 호출해준거 처럼 해제하는 delete는 파괴자를 호출해준다. malloc으로 했으면 free롤 해야하고 new로 했으면 delete로 해야함*/

	return 0;
}