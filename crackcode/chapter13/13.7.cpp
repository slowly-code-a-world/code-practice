/*
Write a method that takes a pointer to a Node structure as a parameter and
returns a complete copy of the passed in data structure. The Node data structure
contains two pointers to other Nodes.
*/

class Solution {
public:
	struct node* copy(struct node* param) {
		struct node* tmp = new node(param->data);
		tmp->left = new node(param->left->data);
		tmp->right = new node(param->right->data);
		return tmp;
	}
};
