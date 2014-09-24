/*
Consider a simple node-like data structure called BiNode, which has pointers to
two other nodes.
1 public class BiNode {
2
public BiNode nodel, node2j
3
public int data;
4
}
The data structure BiNode could be used to represent both a binary tree (where
nodel is the left node and node2 is the right node) or a doubly linked list (where
nodel is the previous node and node2 is the next node). Implement a method
to convert a binary search tree (implemented with BiNode) into a doubly linked
list. The values should be kept in order and the operation should be performed
in place (that is, on the original data structure).
*/

struct BiNode* convert(struct BiNode* root) {
	if (NULL == root) return NULL;
	if (NULL == root->left && NULL == root->right) return root;
	struct BiNode* left = convert(root->left);
	struct BiNode* right = convert(root->right);
	right->left = root;
	root->right = right;
	if (NULL == left) return root;
	struct BiNode* tmp = left;
	while (NULL != left->right) 
		left = left->right;
	left->right = root;
	root->left = left;
	
	return tmp;
}
