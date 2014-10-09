#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *build(vector<int> &inorder, int s1, int e1, vector<int> &postorder, int s2, int e2) {
        	if (s1 > e1 || s2 > e2) return NULL;
        	if (inorder[e1] == postorder[e2]) {
            		TreeNode *root = new TreeNode(inorder[e1]);
            		root->left = build(inorder, s1, e1 - 1, postorder, s2, e2 -1);
            		return root;
        	}
        
        	int index = e1;
        	while (inorder[index] != postorder[e2]) index --;
       		TreeNode* root = new TreeNode(postorder[e2]);
        	root->left = build(inorder, s1, index - 1, postorder, s2, s2 - s1 + index - 1);
        	root->right = build(inorder, index + 1, e1, postorder, s2 - s1 + index, e2 - 1);
        	return root;
	}

	TreeNode *buildTree(vector<int>&inorder, vector<int>&postorder) {
		if (inorder.size() == 0) return NULL;
		else if (inorder.size() == 1) {
			TreeNode* root = new TreeNode(inorder[0]);
			return root;
		}
		return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size() - 1);
	}
	void BFS(TreeNode* root) {
		vector<TreeNode*> record;
		if (NULL == root) return;
		record.push_back(root);
		int cnt = 0;
		while (record.size() > 0) {
			int size = record.size();
			for (int i = 0; i<size; i++) {
				if (record[0]->left != NULL)
					record.push_back(record[0]->left);
				if (record[0]->right!=NULL)
					record.push_back(record[0]->right);
				if (cnt == 0) 
					cout << record[0]->val;
				else cout << "," << record[0]->val;
				record.erase(record.begin());
				cnt++;
			}
			
		}
		cout << endl;	
	}
	void convert(vector<int> inorder, vector<int> postorder) {
		if (inorder.size()!=postorder.size()) {
			cout << "InvalidInput" << endl;
			return;
		}
		vector<int> tmpin = inorder;
		vector<int> tmppost = postorder;
		sort(tmpin.begin(), tmpin.end());
		sort(tmppost.begin(), tmppost.end());
		for (int i = 0; i < tmpin.size(); i++) {
			if (tmpin[i] != tmppost[i]) {
				cout << "InvalidInput" << endl;
				return;
			}	
		}
		if (inorder.size() == 0) {
			cout << "InvalidInput" << endl;
			return;
		}		
		TreeNode* root = buildTree(inorder, postorder);
		BFS(root);
	}	
};

int main(int argc, char* argv[]) {
	string line;
	char buffer[25];
	ifstream file(argv[1]);
	vector<int> inorder, postorder;	
	int number;	
	int index = 0;
	int cnt = -1;
	memset(buffer, 0 , 25);	
	if (file.is_open()) {
		while (getline(file, line)) {
			//cout << line << endl;
			//cout << endl;
			cnt ++;
			for (int i = 0; i<line.size(); i++) {
				if (line[i] == ',') {
					number = atoi(buffer);
					index = 0;			
					if (cnt == 0) inorder.push_back(number);
					else postorder.push_back(number);
					memset(buffer, 0, 25);					
				} else {
					buffer[index] = line[i];
					index++;
				}
				if (i == line.size() - 1) {
					number = atoi(buffer);
					memset(buffer, 0, 25);
					index = 0;
					if (0 == cnt) inorder.push_back(number);
					else postorder.push_back(number);
				}
			}
		}
		file.close();
	}
	
	Solution S;
	S.convert(inorder, postorder);
	/*
	for (int i = 0; i<inorder.size(); i++)
		cout << inorder[i] << " ";
	cout << endl;

	for (int i = 0; i<postorder.size(); i++) 
		cout << postorder[i] << " ";
	cout << endl;		
	*/
	return 0;
}
