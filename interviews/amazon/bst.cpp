#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	bool checkBST(TreeNode* root) {
		if (root == NULL) return true;
		if (root->left == NULL && root->right == NULL) return true;
		checkBST(root->left);
		checkBST(root->right);
		TreeNode* left = root->left;
		if (left != NULL) {
			while (left->right!=NULL)
				left = left->right;
			if (left->val > root->val) return false;
		}
		TreeNode* right = root->right;
		if (right != NULL) {
			while (right->left != NULL) 
				right = right->left;
			if (right->val <= root->val) return false;
		}
		return true;
	}
};
