
Symmetric Tree
Total Accepted: 19257 Total Submissions: 60288

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.

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
    bool compareTrees(TreeNode *left, TreeNode* right) {
        if (NULL == left && NULL == right) return true;
        if (NULL == left || NULL == right) return false;
        if (left->val != right->val) return false;
        return compareTrees(left->left, right->right) && compareTrees(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root) {
        if (NULL == root) return true;
        if (NULL == root->left && NULL == root->right) return true;
        if (NULL == root->left || NULL == root->right) return false;
        return compareTrees(root->left, root->right);
    }
};
