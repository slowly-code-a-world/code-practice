/*
Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
How would you solve this problem if a temporary buffer is not allowed?
*/

#include <iostream>
#include <tr1/unordered_map>
#include <stdlib.h>

using namespace std;
using namespace std::tr1;

struct node {
	int data; // assume it is int, other types the same
	struct node* next;
};

class Solution {
private:
	struct node* head;	
public:
	void remove_dup(struct node* head) {
		if (NULL == head || NULL == head->next) return;
		struct node* prev, *curr, *death;
		unordered_map<int, int> map;
	
		curr = head->next;
		prev = head;
		map[prev->data] = 1;

		while (NULL != curr) {
			while (NULL != curr && 1 == map[curr->data]) {
				death = curr;
				curr = curr->next;
				delete death;
			}

			if (NULL == curr) {
				prev->next = NULL;
				return;
			}

			if (prev->next != curr) prev->next = curr;			 
			prev = curr;
			map[prev->data] = 1;
			curr = curr->next;
		}		
	}

	void remove_dup2(struct node* head) {
		if (NULL == head || NULL == head->next) return;
		struct node* prev, *curr, *death;
		
		prev = head;
		curr = head->next;	
		while (NULL != curr) {
			int found = 0;
			struct node *p = head;
			while (p != curr) {
				if (p->data == curr->data) {
					found = 1;
					break;
				}
				p = p->next;
			}
			if (0 == found) {
				prev = curr;
				curr = curr->next;
			} else {
				death = curr;
				curr = curr->next;
				delete death;
				prev->next = curr;
			}
		}
	}
		
	struct node *get_head (void) {
		return head;
	}

	void set_head(struct node *h) {
		head = h;
	}
	
	Solution() {
		set_head(NULL);
	}

	void generate_list(void) {
		srand(time(NULL));
		for (int i = 0; i<10; i++) {
			if (NULL == get_head()) {
				head = new node;
				head->next = NULL;
				head->data = rand() % 10; // random
			} else {
				struct node* p = new node;
				p->next = head;
				p->data = rand() % 10;
				head = p;
			}
		}
	}

	void print_list(void) {
		struct node* p = head;
		while (NULL != p) {
			cout << p->data << " ";
			p = p->next;
		}	
		cout << endl;
	}
};

int main(void) {
	
	Solution S;
	S.generate_list();
	S.print_list();
	S.remove_dup2(S.get_head());
	S.print_list();

	return 0;		
}

