/*
2.5	
Given a circular linked list, implement an algorithm which returns node at the begin-
ning of the loop.
DEFINITION
Circular linked list: A (corrupt) linked list in which a node’s next pointer points to an
earlier node, so as to make a loop in the linked list.
EXAMPLE
input: A -> B -> C -> D -> E -> C [the same C as earlier]
output: C
*/

#include <iostream>
#include <stdlib.h>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

struct node {
	int data;
	struct node *next;	
};

class Solution {
private:
	struct node *head, *tail;
public:
	Solution() { head = NULL; }
	void generate_list(void) {
		srand(time(NULL));	
		for (int i= 0; i < 10; i++) {
			if (NULL == head) {
				struct node *p = new node;
				p->data = rand() % 10;
				p->next = NULL;
				head = tail = p;
			} else {
				struct node *p = new node;
				p->data = rand() % 10;
				p->next = head;
				head = p;
				if (9 == i) {
					int loc = rand() % 10;
					cout << loc << endl;
					p = head;
					for (int i = 0; i < loc; i++) 
						p = p->next;
					tail->next = p;
				}
			}
		}	
	}

	void print_list(void) {
		struct node* p = head;
		while (p != tail) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << tail->data << endl;
	}

	struct node* find(void) {
		unordered_map<struct node*, int> map;
		struct node *p = head;
		map[head] = 1;
		p = p->next;	
		while (1) {
			if (1 == map[p]) 
				return p;
			map[p] = 1;
			p = p->next;
		}
	}
};

int main(void) {
	
	Solution S;
	S.generate_list();
	S.print_list();
	cout << S.find()->data << endl;

	return 0;	
}
