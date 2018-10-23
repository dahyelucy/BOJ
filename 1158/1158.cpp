#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int data;
	ListNode* link;
}ListNode;

int N; int M;

ListNode* create_node(int data, ListNode *list) {
	ListNode* newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->link = list;
	return newNode;
}
void insert_node(ListNode **phead, ListNode *newNode) {
	if (*phead == NULL) {
		*phead = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = (*phead)->link;
		(*phead)->link = newNode;
		*phead = newNode;
	}
}
void display_delete(ListNode * head, int m) {
	ListNode *p = head;
	ListNode * bf;
	printf("<");
	do {
		for (int i = 0; i < m - 1; i++)
		{
			p = p->link;
		}
		bf = p;
		p = p->link;
		bf->link = p->link;
		printf("%d, ", p->data);
		free(p);
		p = bf;

	} while (p->link!=p);

	printf("%d>", p->data);
}
void display(ListNode* head) {
	ListNode* p = head->link;
	do {
		printf("%d ", p->data);
		p = p->link;
	} while (p->link != head->link);
}

int main()
{
	ListNode* list = NULL;

	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		insert_node(&list, create_node(i, NULL));
	}
	display_delete(list, M);

	return 0;
}