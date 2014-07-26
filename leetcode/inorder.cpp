
Binary Tree Inorder Traversal
Total Accepted: 23602 Total Submissions: 66860

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> inorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ret;
        if (NULL == root) return ret;
        if (NULL == root->left && NULL == root->right) {
            ret.push_back(root->val);
            return ret;    
        }
        vector<int> left = inorderTraversal(root->left);
        ret.insert(ret.end(), left.begin(), left.end());
        ret.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        ret.insert(ret.end(), right.begin(), right.end());
        
        return ret;
    }
};
