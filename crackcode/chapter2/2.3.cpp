/*
2.3	 Implement an algorithm to delete a node in the middle of a single linked list, given
    only access to that node.
EXAMPLE
Input: the node ‘c’ from the linked list a->b->c->d->e
Result: nothing is returned, but the new linked list looks like a->b->d->e
*/

#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
private:
	linkedlist l;	
public:
	void remove_node(struct node* a) {
		if (NULL == a) return;
		struct node *p = l.get_head();
		if (p == a) 
			l.remove_head();
		else {
			while (p->next != a) 
				p = p->next;

			p->next = a->next;
			delete a;
		}
	}

	void generate_list(void) {
		l.generate_list();
	}
	
	void print_list(void) {
		l.print_list();
	}	
	
	struct node* set_pointer(void) {
		struct node* p = l.get_head();
		srand(time(NULL));
		int loc = rand() % 10;
		cout << "location is " << loc << endl;
		for (int i = 0; i < loc; i++) {
			p = p->next;
		}
		return p;
	}
};

int main(void) {

	Solution S;
	S.generate_list();
	S.print_list();
	struct node* p = S.set_pointer();
	S.remove_node(p);
	S.print_list();

	return 0;
};
