#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v), left(NULL), right(NULL) {}
};
class Solution {
public:
	int getDiameter(TreeNode* root, int &acrossRoot) {
		if (root == NULL) return 0;
		int leftacross = 0;
		int left = getDiameter(root->left, leftacross);
		acrossRoot = max(acrossRoot, leftacross);
		int rightacross = 0;
		int right = getDiameter(root->right, rightacross);
		acrossRoot = max(acrossRoot, rightacross);
		acrossRoot = max(acrossRoot, left + right + 1);
		return max(left, right) + 1;
	}
	int Diameter(TreeNode* root) {
		if (root == NULL) return 0;
		if (root->left == NULL && root->right == NULL) return 1;
		int acrossRoot = 0;
		int ret = INT_MIN;
		int left = getDiameter(root->left, acrossRoot);
		ret = max(ret, acrossRoot);
		acrossRoot = 0;
		int right = getDiameter(root->right, acrossRoot);
		ret = max(ret, acrossRoot);
		return max(ret, left + right + 1);
	}
};

int main(void) {
	Solution test;
	vector<TreeNode*> nodes;
	for (int i = 0; i<15; i++)
		nodes.push_back(new TreeNode(i+1));
	nodes[0]->left = nodes[1];
	nodes[0]->right = nodes[2];
	nodes[2]->right = nodes[3];
	nodes[1]->left = nodes[4];
	nodes[1]->right = nodes[5];
	nodes[4]->left = nodes[6];
	nodes[4]->right = nodes[7];
	nodes[7]->left = nodes[8];
	nodes[8]->left = nodes[9];
	nodes[8]->right = nodes[10];
	nodes[5]->right = nodes[11];
	nodes[11]->left = nodes[12];
	nodes[11]->right = nodes[13];
	nodes[13]->right = nodes[14];
	int ret = test.Diameter(nodes[0]);
	cout << ret << endl;
}
