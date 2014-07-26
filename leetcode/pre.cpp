
Binary Tree Preorder Traversal
Total Accepted: 25596 Total Submissions: 72411

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        /*
        vector<int> order;
        if (NULL == root) return order;
        order.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        order.insert(order.end(), left.begin(), left.end());
        order.insert(order.end(), right.begin(), right.end());
        
        return order;
        */
        
        vector<int> order;
        if (NULL == root) return order;
        stack<TreeNode*> S;
        S.push(root);
        
        while (!S.empty()) {
            TreeNode* tmp = S.top();
            S.pop();
            order.push_back(tmp->val);
            if (NULL != tmp->right)
                S.push(tmp->right);
            if (NULL != tmp->left)
                S.push(tmp->left);
            
        }
        return order;
    }
};
