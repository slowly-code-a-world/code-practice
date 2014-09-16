/*
Write a method that takes a pointer to a Node structure as a parameter and
returns a complete copy of the passed in data structure. The Node data structure
contains two pointers to other Nodes.
*/

class Solution {
public:
	struct node* copy_recursive(struct node* root, unordered_map<struct node*, struct node*>&map) {
		if (NULL == root) return NULL;
		if (map.find(root) != map.end()) return map[root];
		struct node* tmp = new node;
		map[root] = tmp;
		copy_recursive(root->ptr1, map);
		copy_recursive(root->ptr2, map);
	}

	Node* copy_structure(struct node* root) {
		unordered_map<struct node*, struct node*> map;
		return copy_recursive(root, map);
	}
};
