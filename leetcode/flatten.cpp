
Flatten Binary Tree to Linked List
Total Accepted: 17188 Total Submissions: 62130

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6


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
    void flatten(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (NULL == root) return;
        if (NULL == root->left && NULL == root->right) return;
        if (NULL!=root->left && NULL == root->right) {
            flatten(root->left);
            root->right = root->left;
            root->left = NULL;
            return;
        }
        if (NULL == root->left && NULL!=root->right) {
            flatten(root->right);
            return;
        }
        flatten(root->left);
        TreeNode *left = root->left;
        flatten(root->right);
        TreeNode *right = root->right;
        root->left = NULL;
        root->right = left;
        TreeNode* it = left;
        while(NULL != it->right)
            it = it->right;
        it->right = right;
        return;
    }
};
