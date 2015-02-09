/*
Given a binary search tree (BST), write a mehtod that will convert this BST into a doubly linked list that is sorted (ascending or descending order) and returns the first element in this list. You may assume you are given following Node class:


public class Node {
	public Node left, right;
	public String val;
}
Example: The following BST 
G 
/ \ 
A T 
can be converted into a list 
A = G = T 

Do it in place! Hnce the memory complexity of your algorithm shoul be O(1).
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	void realConvert(Node* root, Node* &head, Node* &tail) {
		if (root == NULL) {
			head = tail = NULL;
			return;
		}
		if (root->left == NULL && root->right == NULL) {
			head = tail = root;
			return;
		}
		Node* leftHead = NULL, *leftTail = NULL;
		realConvert(root->left, leftHead, leftTail);
		Node* rightHead = NULL, *rightTail = NULL;
		realConvert(root->right, rightHead, rightTail);
		leftTail->right = root;
		root->left = leftTail;
		root->right = rightHead;
		rightHead->left = root;
		return leftHead;
	}
	Node* convert(Node* root) {
		Node* head = NULL, *tail = NULL;
		realConvert(root, head, tail);	
		return head;
	}
};
