/*
4.8	 You are given a binary tree in which each node contains a value. Design an algorithm
    to print all paths which sum up to that value. Note that it can be any path in the tree
   - it does not have to start at the root.
*/

#include <iostream>

class Solution {
public:
	void print_path(int sum, vector<struct node*>&path) {
		int total = 0;
		int loc = path.size() - 1;
		int left = -1, right = -1;

		while (loc >= 0) {
			total += path[loc]->data;
			if (total > sum) 
				break;
			if (total == sum) {
				if (-1 == right)
					right = loc;
				else left = loc;
			}
			loc --;
		}

		if (-1 == right && -1 == left) return;
		if (-1 != right && -1 == left) {
			for (int i = right; i < path.size(); i++) 
				std::cout << path[i]->data << " ";
			std::cout << std::endl;
		} 	
		for (int i = left; i <= right; i++) {
			for (int j = i; j < path.size(); j++) 
				std::cout << path[j]->data << " ";
			std::cout << std::endl;
		}

	}

	void print_all(struct node* root, int sum, vector<struct node*>&path) {
		if (NULL == root) return;
		path.push_back(root);
		print_path(sum, path);	
		if (NULL != root->left)
			print_all(root->left, sum, path);
		if (NULL != root->right)
			print_all(root->right, sum, path);
		path.pop_back();			
	}

	void print_path(struct node* root, int sum) {
		vector<struct node*> path;
		print_all(root, sum, path);				
	}	
};
