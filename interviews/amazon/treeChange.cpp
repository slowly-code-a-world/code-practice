/*
Convert a Binary tree into another binary tree whose in-order traversal gives a sorted list
This has to be done in-place

Eg.

        1
    2       3
 4   5   6     7

should be converted into

        4
    2       6
 1   3   5     7

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};
bool compare(TreeNode* n1, TreeNode* n2) {
	return n1->val < n2->val;
}
class Solution {
public:	
	void inorderTraversal(TreeNode* root, vector<TreeNode*>&list) {
		if (root == NULL) return;
		if (root->left == NULL && root->right == NULL) {
			list.push_back(root);
			return;
		}
		inorderTraversal(root->left, list);
		list.push_back(root);
		inorderTraversal(root->right, list);
	}
	TreeNode* convert(TreeNode* root) {
		if (root == NULL) return NULL;
		if (root->left == NULL && root->right == NULL) return root;
		vector<TreeNode*> origList;
		inorderTraversal(root, origList);
		
		vector<TreeNode*> newList;
		for (int i = 0; i<origList.size(); i++) {
			TreeNode* p = new TreeNode(origList[i]->val);
			newList.push_back(p);
		}
		sort(newList.begin(), newList.end(), compare);
		for (int i = 0; i<origList.size(); i++)
			origList[i]->val = newList[i]->val;
		return root;
	}
	void printTree(TreeNode* root) {
		if (root == NULL) return;
		if (root->left == NULL && root->right == NULL) {
			cout << root->val << " ";
			return;
		}	
		printTree(root->left);
		cout << root->val << " ";
		printTree(root->right);
	}
};

int main(void) {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	Solution S;
	S.printTree(root);
	cout << endl;
	S.convert(root);
	S.printTree(root);
	cout << endl;
}
