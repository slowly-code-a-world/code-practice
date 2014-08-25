/*
4.7	 You have two very large binary trees: T1, with millions of nodes, and T2, with hun-
    dreds of nodes. Create an algorithm to decide if T2 is a subtree of T1.
*/

#include <iostream>

class Solution {
public:
	int height(struct node* root) {
		if (NULL == root) return;
		if (NULL == root->left && NULL == root->right) { 
			root->height = 1;
			return root->height;
		}

		if (NULL == root->left) {
			root->height = 1 + height(root->right);
			return root->height;
		}	

		if (NULL == root->right) {
			root->height = 1 + height(root->left);
			return root->height;
		}

		int left = height(root->left);
		int right = height(root->right);
		root->height = 1 + max(left, right);

		return root->height;	
	}

	bool same_tree(struct node* T1, struct node* T2) {
		if (NULL == T1 && NULL == T2) return true;
		if (NULL == T1 && NULL != T2 || NULL != T1 && NULL == T2) return false;
		if (T1->data != T2->data) return false;
		return same_tree(T1->left, T2->left) && same_tree(T1->right, T2->right);  
	}

	void is_subtree(struct node* T1, struct node* T2, bool &flag) {
		if (true == flag) 
			return;
		if (T1->height == T2->height) {
			if (same_tree(T1, T2))
				flag = true; 
			return;
		}

		if (T1->height < T2->height)
			return;

		is_subtree(T1->left, T2, flag);
		is_subtree(T1->right, T2, flag);
	}

	bool subtree(struct node* T1, struct node* T2) {
		bool flag = false;

		is_subtree(T1, T2, flag);
		return flag;
	}				
};
