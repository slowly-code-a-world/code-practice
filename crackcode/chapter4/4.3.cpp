/*
4.3	 Given a sorted (increasing order) array, write an algorithm to create a binary tree with
    minimal height.
*/

#include <iostream>

class Solution {
public:
	struct node* create(vector<int> &array, int start, int end) {
		if (start == end)
			return new node(array[start]);

		if (start > end) return NULL;

		int mid = (start + end)/2;
		struct node* root = new node(array[mid]);

		root->left = create(array, start, mid - 1);
		root->right = create(array, mid + 1, end);

		return root;
	}	
};
