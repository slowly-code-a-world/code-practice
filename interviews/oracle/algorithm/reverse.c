#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};
struct node *reverse(struct node* head) {
	if (head == NULL) return NULL;
	if (head->next == NULL) return head;
	struct node* ret = NULL;
	struct node* p = head;
	while (p->next != NULL) {
		struct node* tmp = p->next;
		p->next = ret;
		ret = p;
		p = tmp;
	}
	p->next = ret;
	ret = p;
	return ret;
}

int main() {
	struct node* head = malloc(sizeof(struct node));
	head->data = 1;
	head->next = malloc(sizeof(struct node));
	head->next->data = 2;
	head->next->next = malloc(sizeof(struct node));
	head->next->next->data = 3;
	head->next->next->next = NULL;

	struct node* t = head;
	while (t !=NULL) {
		printf("%d ", t->data);
		t = t->next;
	}
	printf("\n");	
	struct node* p = reverse(head);
	while (p!=NULL) {
		printf ("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
