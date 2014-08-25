/*
4.6	 Design an algorithm and write code to find the first common ancestor of two nodes
    in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
   necessarily a binary search tree.
*/

#include <iostream>

class Solution {
public:
	void find_path(struct node* root, struct node* p, vector<struct node*> &path, vector<struct node*> &solution) {
		if (NULL == root) return;
		if (root == p) {
			solution = path;
			return;
		}
		path.push_back(root);
		if (0 == solution.size() && NULL != root->left) {
			path.push_back(root->left);
			find_path(root->left, p, path, solution);
			path.pop_back();
		}
		if (0 == solution.size() && NULL != root->right) {
			path.push_back(root->right);
			find_path(root->right, p, path, solution);
			path.pop_back();
		}
	}	

	struct node* ancestor(struct node* root, struct node* pa, struct node* pb) {
		
		if (NULL == pa || NULL == pb) return NULL;
		if (pa == pb) return pa;
		if (pa == root || pb == root) return root;
				
		vector<struct node*> path, solution1, solution2;
		
		find_path(root, pa, path, solution1);
		path.clear();
		find_path(root, pb, path, solution2);
		for (int i = 0; i < solution1.size() && i < solution2.size(); i++) {
			if (solution1[i] != solution2[i]) 
				return solution1[i-1];
		}
	}
};
