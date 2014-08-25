/*
4.4	 Given a binary search tree, design an algorithm which creates a linked list of all the
    nodes at each depth (i.e., if you have a tree with depth D, you’ll have D linked lists).
*/

#include <iostream>

class Solution {
private:
	vector<struct node*> list;
public:
	void create(struct node* root) {
		stack<struct node*> s;
		s.push(root);
		struct node* end, *start;
		struct node* head, *tail;
		start = end = root;
		while (0 == s.empty()) {
			struct node* tmp = s.top();
			if (tmp == start) {
				head = tail = tmp;
				tail->next = NULL;
				start = NULL;
				if (NULL != tmp->left) {
					s.push(tmp->left);
					if (NULL == start)
						start = tmp->left;
				}
				if (NULL != tmp->right) {
					s.push(tmp->right);
					if (NULL == start) 
						start = tmp->left;
				}
			} 
			
			if (tmp == end) {
				s.push(head);
				head = tail = NULL;
			}
			else {
				tail->next = tmp;
				tail = tmp;
			}

						
		}
	} 
};

