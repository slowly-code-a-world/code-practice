
Validate Binary Search Tree
Total Accepted: 16409 Total Submissions: 64258

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

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
    bool isValidBST(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (NULL == root) return true;
        if (NULL == root->left && NULL == root->right) return true;
        if (NULL != root->left && root->left->val >= root->val) return false;
        if (NULL != root->right && root->right->val <= root->val) return false;
        int leftmax, rightmin;
        if (NULL != root->left && NULL == root->right) {
            TreeNode *left = root->left;
            leftmax = left->val;
            while (NULL!=left) {
                left = left->right;
                if (NULL!=left)
                    leftmax = left->val;
            }
            if (leftmax < root->val && isValidBST(root->left))
                return true;
            return false;    
        } else if (NULL != root->right && NULL == root->left) {
            TreeNode * right = root->right;
            rightmin = right->val;
            while (NULL!=right) {
                right = right->left;
                if (NULL!=right)
                    rightmin = right->val;
            }
            if (rightmin > root->val && isValidBST(root->right))
                return true;
            return false;    
        } else {
            TreeNode *left = root->left, *right = root->right;
            leftmax = left->val;
            while (NULL != left) {
                left = left->right;
                if (NULL!=left)
                    leftmax = left->val;
            }
            rightmin = right->val;
            while (NULL != right) {
                right = right->left;
                if (NULL!=right)
                    rightmin = right->val;
            }
            if (leftmax < root->val && rightmin > root->val && isValidBST(root->left) && isValidBST(root->right))
                return true;
            return false;    
        }
    }
};
