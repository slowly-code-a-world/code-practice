/*
Convert a sorted array to a balanced binary search tree
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	TreeNode* convert(vector<int>&array, int s, int e) {
		if (s > e) return NULL;
		if (s == e) return TreeNode(array[s]);
		int m = (s + e)/2;
		TreeNode* left = convert(array, s, m-1);
		TreeNode* right = convert(array, m+1, e);
		TreeNode* root = new TreeNode(array[m]);
		root->left = left;
		root->right = right;
		return root;
	}
};
