#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isLeft(TreeNode* root, TreeNode* n) {
		if (root == NULL) return false;
		if (n == root) return true;
		return isLeft(root->left, n) || isLeft(root->right, n);
	} 
	TreeNode* commonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
		if (root == NULL) return NULL;
		if (n1 == NULL) return n2;
		if (n2 == NULL) return n1;
		if (n1 == root || n2 == root) return root;
		bool ret1 = isLeft(root->left, n1), ret2 = isLeft(root->left, n2);
		if (ret1 != ret2) return root;
		if (ret1 == true) return commonAncestor(root->left, n1, n2);
		return commonAncestor(root->right, n1, n2);		
	}

	TreeNode* commonAncestor2(TreeNode* root, TreeNode* n1, TreeNode* n2, int &cnt) {
		if (root == NULL) return NULL;
		if (n1 == NULL) return n2;
		if (n2 == NULL) return n1;
		TreeNode* left = commonAncestor2(root->left, n1, n2, cnt);
		if (cnt == 2) return left;
		if (cnt == 1) {
			cnt++;
			return root; 
		}
		TreeNode* right = commonAncestor2(root->right, n1, n2, cnt);
		if (cnt == 2) return right;
		if (cnt == 1) {
			cnt++;
			return root;
		}
		if (root == n1 || root == n2) cnt++;
	}
};

int main(void) {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(5);
	TreeNode* p1 = root->left->right;
	TreeNode* p2 = root->left->right->left;
	int cnt = 0;
	Solution S;
	TreeNode* tmp = S.commonAncestor2(root, p1, p2, cnt);
	cout << p1->val << endl;
	cout << p2->val << endl;
	cout << tmp->val << endl;
	cout << cnt << endl;
}
