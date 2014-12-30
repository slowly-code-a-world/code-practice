#include <stdlib.h>
#include <stdio.h>

int find(struct node* root) {
	if (root == NULL) return -1;
	if (root->left == NULL && root->right == NULL) return -1;
	if (root->right == NULL) {
		struct node* tmp = root->left;
		while (tmp->right != NULL)
			tmp = tmp->right;
		return tmp->val;
	}
	struct node* tmp = root->right;
	struct node* prev = root;
	while (tmp->right!=NULL) {
		prev = tmp;
		tmp = tmp->right;
	}
	if (tmp->left == NULL) return prev->val;
	tmp = tmp->left;
	while (tmp->right!=NULL)
		tmp = tmp->right;
	return tmp->val;	
}
