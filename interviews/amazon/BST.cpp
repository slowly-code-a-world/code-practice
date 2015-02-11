/*
that a binary tree is a binary search tree. 如果不用多余空间，
只要再用到一个全局变量记录上一个访问节点的数值就行了
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	bool isBST(TreeNode* root) {
		if (root == NULL) return true;
		if (root->left == NULL && root->right == NULL) return true;
		TreeNode* prev = root;
		while (prev->left != NULL) 
			prev = prev->left;
		while (true) {
			TreeNode* next = getNext(root, prev);
			if (next == NULL) return true;
			if (next->val < prev->val) 
				return false;
			prev = next;
		}
	}
	TreeNode* getNext(TreeNode* root, TreeNode* prev) {
		if (prev->right != NULL) {
			prev = prev->right;
			while(prev->left != NULL)
				prev = prev->left;
			return prev;
		}
		TreeNode* next = NULL;
		while (root != NULL) {
			if (prev->val < root->val) {
				next = root;
				root = root->left;
			} else if (prev->val > root->val)
				root = root->right;
			else break;
		}
		return next;
	}
};
