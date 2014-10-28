/*
Given a tree | 3 point(s)
Overview

In computer science, trees are a very interesting data structure with many different algorithmic applications. This problem focuses specifically on Binary Trees.

A binary tree is a tree structure in which each node has at most two child nodes (often referred to as a left and right).[1]

There are several different ways to traverse an existing tree, but in this problem we involve 3 specific traversals.

In-order
Post-order
Breadth-first

In this problem, you will be provided a binary tree as input. The tree will be represented by in-order and post-order traversals.

The task is to build up a binary tree solely from the given traversals and output a breadth-first traversal.

The input tree can be invalid, meaning that it does not represent a binary tree.
You have to make sure to handle invalid input and output Invalid Input if you determine the input to be invalid.
An example of invalid input could be something like this 1-2-3-4-5-6 or this is not a valid binary tree input.

See the input and output for more examples of valid and invalid inputs.
Clarifications

Tree node values are unique, so don't worry about ambiguity caused by duplicate values
If the tree or input is invalid, the result should be the string InvalidInput
The input trees are not balanced
The input trees have no node value rules
These are binary trees, so remember, at most two children per node

Input description/format

A string consisting of two lines.
Each line is a comma separated list of numbers, representing the in-order and post-order traversals.
The numbers themselves are the node values.
Output description/format

A string representing the breadth-first-order traversal of the tree, where node values are comma separated to represent the tree nodes.
Example input

4,2,7,5,8,1,3,9,6,11,10
4,7,8,5,2,9,11,10,6,3,1

Example output

1,2,3,4,5,6,7,8,9,10,11
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int v):val(v),left(NULL),right(NULL){}
};

struct Res{
	bool res;
	TreeNode *root;
};

Res BuildTree(vector<int> inorder,int il,int ir,vector<int> postorder,
		int pl,int pr){
	Res res;
	res.root = NULL;
	if(il>ir&&pl>pr){
		res.res = true;
	   	return res;
	}
	if(il>ir||pl>pr){
		res.res = false;   
		return res;
	}
	int v = postorder[pr];
	TreeNode *root = new TreeNode(v);
	int i=il;
	for(;i<=ir;++i){
		if(inorder[i]==v)
			break;
	}
	Res resl = BuildTree(inorder,il,i-1,postorder,pl,pl+i-il-1);
	if(resl.res){
		Res resr = BuildTree(inorder,i+1,ir,postorder,pl+i-il,pr-1);
		if(resr.res){
			root->left = resl.root;
			root->right = resr.root;
			res.root = root;
			res.res = true;
			return res;
		}
	}
	res.res = false;
	return res;
}


bool GetBFS(vector<int> inorder,vector<int> postorder,vector<int> &bfs){
	int n = inorder.size();
	if(postorder.size()!=n)
	   	return false;
	Res res = BuildTree(inorder,0,n-1,postorder,0,n-1);
	if(!res.res) return false;
	queue<TreeNode*> my_queue;
	if(res.root!=NULL) my_queue.push(res.root);
	while(!my_queue.empty()){
		TreeNode *tmp = my_queue.front();
		my_queue.pop();
		bfs.push_back(tmp->val);
		if(tmp->left!=NULL) my_queue.push(tmp->left);
		if(tmp->right!=NULL) my_queue.push(tmp->right);
	}
	return true;
}

vector<int> Split(string line){
	vector<int> res;
	string tmp;
	while(line.size()>0){
		int pos = line.find_first_of(',');
		if(pos==-1){
			pos = line.size();
			tmp = line;
			line = "";
		}else{
			tmp = line.substr(0,pos);
			line = line.substr(pos+1);
		}
		res.push_back(atoi(tmp.c_str()));
	}
	return res;
}

int main(int argc,char*argv[]){
	string line1,line2;
	cin>>line1>>line2;
	vector<int> inorder = Split(line1);
	vector<int> postorder = Split(line2);
	vector<int> bfs;
	if(GetBFS(inorder,postorder,bfs)){
		for(int i=0;i<bfs.size();++i){
			if(i!=0) cout << ",";
			cout << bfs[i];
		}
		cout << endl;
	}else cout << "Invalid Input" << endl;
	return 0;
}
