
Minimum Depth of Binary Tree
Total Accepted: 17756 Total Submissions: 60576

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
    int minDepth(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (NULL == root) return 0;
        if (NULL == root->left && NULL == root->right) return 1;
        if (NULL == root->left && NULL != root->right) return 1 + minDepth(root->right);
        if (NULL!=root->left && NULL == root->right) return 1 + minDepth(root->left); 
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left <= right) return left + 1;
        return right + 1;
        
    }
};
