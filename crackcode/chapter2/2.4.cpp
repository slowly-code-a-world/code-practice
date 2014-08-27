/*
2.4	
You have two numbers represented by a linked list, where each node contains a sin-
gle digit. The digits are stored in reverse order, such that the 1’s digit is at the head of
the list. Write a function that adds the two numbers and returns the sum as a linked
list.
EXAMPLE
Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
Output: 8 -> 0 -> 8
*/

#include <iostream>
#include "linked_list.h"

using namespace std;

class Solution {
private:
	linkedlist l1;
	linkedlist l2;
public:
	void generate_lists(void) {
		srand(time(NULL));
		l1.generate_list();
		l2.generate_list();
	}

	void print_lists(void) {
		l1.print_list();
		l2.print_list();
	}

	void print_a_list(struct node* head) {
		struct node* p = head;
		while (NULL != p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;	
	}

	void print_after_sum(void) {
		print_a_list(sum_lists());
	}

	struct node* sum_lists(struct node* l1, struct node* l2, int carry) {
		if (NULL == l1 && NULL == l2 && 0 == carry) return NULL;

		struct node* result = new node;
		result->value = carry;
		if (NULL != l1) 
			result->value += l1->data;
		if (NULL != l2)	
			result->value += l2->data;
		bool have_carry = false;
		if (result->value >= 10)
			have_carry = true;
		result->value = result->value % 10;
		result->next = sum_lists((NULL == l1)? NULL : l1->next, (NULL == l2)? NULL : l2->next, have_carry ? 1 : 0);
		
	}
	struct node* sum_lists(void) {

		if (NULL == l1.get_head()) return l2.get_head();
		if (NULL == l2.get_head()) return l1.get_head();
		int carry = 0;
		struct node *p1 = l1.get_head(), *p2 = l2.get_head();
		while (NULL != p1 && NULL != p2) {
			int sum = p1->data + p2->data + carry;
			if (sum >= 10) { 
				carry = 1; 
				p2->data = sum - 10;
			} else { 
				p2->data = sum;	
				carry = 0;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		if (NULL == p1) {
			if (NULL == p2) {
				if (1 == carry) {
					struct node *p = new node;
					p->data = 1;
					p->next = NULL;
					l2.get_tail()->next = p;
					l2.set_tail(p);
				}				
			} else {
				while (NULL != p2) {
					int sum = p2->data + carry;
					if (sum >= 10) {
						carry = 1;
						p2->data = sum - 10;
					} else {
						p2->data = sum;
						carry = 0;
					}
					p2 = p2->next;
				}
				if (1 == carry) {
					struct node *p = new node;
					p->data = 1;
					p->next = NULL;
					l2.get_tail()->next = p;
					l2.set_tail(p);
				}
			}
		} else {
			while (NULL != p1) {
				l2.get_tail()->next = p1;	
				int sum = p1->data + carry;
				if (sum >= 10) {
					carry = 1;
					p1->data = sum - 10;
				} else {
					carry = 0;
					p1->data = sum;
				}
				p1 = p1->next;
			}
		}
		return l2.get_head();
	}
};

int main(void) {

	Solution S;
	S.generate_lists();
	S.print_lists();
	S.print_after_sum();	

	return 0;
}
