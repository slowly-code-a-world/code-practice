#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node* left, *right;
};

void inorder(struct node* root) {
	if (root == NULL) return;
	inorder(root->left);
	printf("%d ", root->val);
	inorder(root->right);
}

int main(int argc, char*argv[]) {
	struct node* root = malloc(sizeof(struct node));
	root->val = 1;
	root->left = malloc(sizeof(struct node));
	root->right = malloc(sizeof(struct node));
	root->left->val = 2;
	root->left->left = NULL;
	root->right->val = 3;
	root->right->right = NULL;
	root->left->right = malloc(sizeof(struct node));
	root->left->right->val = 4;
	root->left->right->left = root->left->right->right = NULL;
	root->right->left = malloc(sizeof(struct node));
	root->right->left->val = 5;
	root->right->left->left = root->right->left->right = NULL;
	inorder(root);	
	printf("\n");
} 
