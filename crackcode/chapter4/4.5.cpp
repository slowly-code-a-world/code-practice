/*
4.5	 Write an algorithm to find the ‘next’ node (i.e., in-order successor) of a given node in
        a binary search tree where each node has a link to its parent.
*/

#include <iostream>

class Solution {
public:
	struct node* find_next(struct node* p) {
		if (NULL != p->right) {
			struct node *tmp = p->right;
			if (NULL == tmp->left)
				return tmp;
			else {
				while (NULL != tmp->left)
					tmp = tmp->left;
				return tmp;
			}
		} else {
			struct node* parent = p->parent;
			if (NULL == parent) return NULL;
			if (parent->left == p) 
				return parent;
			else {
				while (NULL != parent->parent && parent->parent->right == parent)
					parent = parent->parent;
				if (NULL == parent->parent) return NULL;
				return parent->parent;				
			}
		}
	}	
};

