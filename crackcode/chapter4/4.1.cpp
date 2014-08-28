/*
4.1	 Implement a function to check if a tree is balanced. For the purposes of this question,
    a balanced tree is defined to be a tree such that no two leaf nodes differ in distance
   from the root by more than one.
*/

#include <iostream>

class Solution {
public:

	int min_height(struct node* root) {
		if (NULL == root) return 0;
		int left = min_height(root->left);
		int right = min_height(root->right);
		
		return min(left, right) + 1;
	}

	int max_height(struct node* root) {
		if (NULL == root) return 0;
		int left = max_height(root->left);
		int right = max_height(root->right);

		return max(left, right) + 1;
	}

	bool balanced(struct node* root) {
		if (NULL == root) return true;
		int min = min_height(root);
		int max = max_height(root);
		if (abs(max - min) >= 2) return false;
		
		return true;
	}	
};
