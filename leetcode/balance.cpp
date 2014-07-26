
Balanced Binary Tree
Total Accepted: 18887 Total Submissions: 58421

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode *root){
        if (NULL == root) return 0;
        if (NULL == root->left && NULL == root->right) return 1;
        int left = depth(root->left);
        int right = depth(root->right);
        return (left < right)? 1 + right : 1+left; 
    }
    
    bool isBalanced(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (NULL==root) return true;
        if (NULL==root->left && NULL == root->right) return true;
        if (NULL!=root->left && NULL == root->right) {
            if (NULL==root->left->left && NULL == root->left->right)
                return true;
            return false;    
        }
        if (NULL== root->left && NULL!=root->right) {
            if (NULL==root->right->left && NULL==root->right->right)
                return true;
            return false;    
        }
        if (isBalanced(root->left) && isBalanced(root->right)) {
            int left = depth(root->left);
            int right = depth(root->right);
            if (abs(left-right)<=1)
                return true;
            return false;    
        }
        return false;
    }
};
