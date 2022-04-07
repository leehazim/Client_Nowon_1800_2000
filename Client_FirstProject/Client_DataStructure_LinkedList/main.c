#include <stdio.h>
#include <stdlib.h>

typedef struct tag_node{
	int id;
	int value;
	struct tag_node* next;
}Node;

Node* head = NULL, *tail = NULL, *tmp, *tmp2;

void push_back(int,int);
void push_front(int,int);
void Insert(int,int,int);
int Remove(int);
int Search(int Data);
void PrintNode();
int GetFirst();
int GetLast();

int main(void) {

	push_back(2, 11);
	push_back(3, 12);
	push_back(4, 13);
	push_front(1, 10);
	Insert(2, 5, 14);
	Remove(4);
	PrintNode();
	printf("%d\n", GetFirst());
	printf("%d\n", GetLast());
	return 0;
}

int GetFirst() {
	if (head == NULL) return -1;
	return head->value;
}

int GetLast() {
	if (tail == NULL) return -1;
	return tail->value;
}

void push_back(int aid, int Data) {
	tmp = (Node*)malloc(sizeof(Node));
	tmp->id = aid; tmp->value = Data; tmp->next = NULL;
	if (head == NULL) head = tail = tmp;
	else {
		tail->next = tmp;
		tail = tail->next;
	}
		
}

void push_front(int aid, int Data) {
	tmp = (Node*)malloc(sizeof(Node));
	if (head == NULL) {
		head = tmp;
		tail = tmp;
	}
	else tmp->next = head;
	tmp->id = aid; tmp->value = Data;
	head = tmp;
}

void Insert(int target_id, int aid, int Data) {
	tmp = head;
	tmp2 = (Node*)malloc(sizeof(Node));
	tmp2->id = aid; tmp2->value = Data;
	while (tmp) {
		if (tmp->id == target_id) {
			tmp2->next = tmp->next;
			tmp->next = tmp2;
			return;
		}
		tmp = tmp->next;
	}
}

void PrintNode() {
	tmp = head;
	while (tmp) {
		printf("ID = %d, Value = %d\n", tmp->id, tmp->value);
		tmp = tmp->next;
	}
}

int Remove(int target_id) {
	tmp = head;
	if (head == NULL) return -1;
	if (head->id == target_id) {
		head = head->next;
		free(tmp);
		return 1;
	}
	while (tmp) {
		if (tmp->next->id == target_id)  break;
		tmp = tmp->next;
	}
	if (tmp == NULL) return -1;
	tmp2 = tmp->next; 
	tmp->next = tmp->next->next;
	if (tmp2 == tail) tail = tmp;
	free(tmp2);

	return 1;
}