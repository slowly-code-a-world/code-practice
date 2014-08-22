#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <stdlib.h>

struct node {
	int data;
	struct node *next;	
};

class linkedlist {
private:
	struct node *head;
	struct node *tail;
public:
	linkedlist() { head = tail = NULL; }

	struct node* get_head (void) { return head; }
	struct node* get_tail (void) { return tail; }
	void set_head(struct node *p) { head = p; }
	void set_tail(struct node *p) { tail = p; }			

	void remove_head(void) {
		if (NULL == head) return;
		if (NULL == head->next) {
			delete head;
			head = tail = NULL;
		}
		struct node *death = head;
		head = head->next;
		delete death;
	}	

	void print_list(void) {
		struct node *p = head;
		while (NULL != p) {
			std::cout << p->data << " ";
			p = p->next;
		}
		std::cout << std::endl;
	}	

	void generate_list(void) {
		srand(time(NULL));
		for (int i = 0; i < 10; i++) {
			struct node *p = new node;
			p->data = rand() % 10;
			if (NULL == head) {
				p->next = NULL;
				head = tail = p;
			} else {
				p->next = head;
				head = p;
			}
		}
	}
};

#endif
