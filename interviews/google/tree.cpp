#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TreeNode {
	int id;
	vector<TreeNode*> subTrees;
	TreeNode(int id) {
		this->id = id;
		subTrees.clear();
	}
};
class Solution {
public:
	int realGet(TreeNode* root, int &length) {
		if (root == NULL) return 0;
		if (root->subTrees.size() == 0) return 1;
		int ret = 1;
		for (int i = 0; i<root->subTrees.size(); i++) {
			int tmpRet = realGet(root->subTrees[i], length);
			if (root->subTrees[i]->id == root->id + 1) {
				tmpRet++;
				ret = max(tmpRet, ret);
				length = max(length, ret);
			}
		}
		return ret;
	}
	int getLongest(TreeNode* root) {
		if (root == NULL) return 0;
		int longest = 1;
		realGet(root, longest);
		return longest;
	}
};

int main() {
	Solution S;
	TreeNode *root = new TreeNode(1), *n1 = new TreeNode(2); 
	TreeNode *n2 = new TreeNode(6), *n3 = new TreeNode(7); 
	TreeNode *n4 = new TreeNode(8), *n5 = new TreeNode(8);
	root->subTrees.push_back(n1);
	root->subTrees.push_back(n2);
	n2->subTrees.push_back(n3);
	n2->subTrees.push_back(n4);
	n3->subTrees.push_back(n5); 
	cout << S.getLongest(root) << endl;
}
