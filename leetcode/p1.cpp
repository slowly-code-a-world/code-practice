/*
Binary Tree Upside Down
Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.
For example:
Given a binary tree {1,2,3,4,5},

    1
   / \
  2   3
 / \
4   5

return the root of the binary tree [4,5,2,#,#,3,1].

   4
  / \
 5   2
    / \
   3   1  

*/
#include <iostream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left, *right;
	TreeNode(int v) {
		val = v;
		left = right = NULL;
	}	
};
class Solution {
public:
	TreeNode* build(TreeNode* root, TreeNode* &newRoot) {
                if (NULL == root) return NULL;
                if (NULL == root->left && NULL == root->right) {
			newRoot = root;
			return root;
		}
                TreeNode* rightMost = build(root->left, newRoot);
                TreeNode* origRight = root->right;
                root->left = root->right = NULL;
                rightMost->right = root;
                rightMost->left = origRight;
                return rightMost->right;

	}
	TreeNode *upsideDownBinaryTree(TreeNode *root) {
		TreeNode* ret = NULL;
		build(root, ret);	
		return ret;
	}
};

int main(void) {
	Solution S;
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(3);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root = S.upsideDownBinaryTree(root);
	cout << root->val << endl;
	cout << root->left->val << " " << root->right->val << endl;
	cout << root->right->left->val << " " << root->right->right->val << endl;
}

