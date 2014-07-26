
Same Tree
Total Accepted: 22140 Total Submissions: 52925

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value. 

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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (NULL == p && NULL == q) return true;
        if (NULL == p || NULL == q) return false;
        if (p->val != q->val) return false;
        bool left = isSameTree(p->left, q->left);
        if (!left) return false;
        bool right = isSameTree(p->right, q->right);
        if (!right) return false;
        
        return true;
    }
};
