
Binary Tree Postorder Traversal
Total Accepted: 23176 Total Submissions: 75230

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3

return [3,2,1].

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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        /*
        vector<int> order;
        if (NULL == root) return order;
        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
        order.insert(order.end(), left.begin(), left.end());
        order.insert(order.end(), right.begin(), right.end());
        order.push_back(root->val);
        
        return order;
        */
        vector <int> order;
        if (NULL == root) return order;
        stack<TreeNode*> s; stack<int> tag;
        s.push(root); tag.push(0);
        while (!s.empty()) {
            TreeNode *tmp = s.top();
            if (2 == tag.top()) {
                order.push_back(tmp->val);
                s.pop();
                tag.pop();
            } else if (NULL == tmp->left && NULL == tmp->right) {
                order.push_back(tmp->val);
                s.pop();
                tag.pop();
            } else if (0 == tag.top() && NULL != tmp->left){
                s.push(tmp->left);
                tag.pop();
                tag.push(1);
                tag.push(0);
            } else if (0 == tag.top() && NULL == tmp->left && NULL != tmp->right) {
                s.push(tmp->right);
                tag.pop();
                tag.push(2);
                tag.push(0);
            } else if (1 == tag.top() && NULL != tmp->left && NULL == tmp->right) {
                order.push_back(tmp->val);
                s.pop();
                tag.pop();
            } else if (1 == tag.top() && NULL != tmp->left && NULL!=tmp->right) {
                s.push(tmp->right);
                tag.pop();
                tag.push(2);
                tag.push(0);
            } else if (1 == tag.top() && NULL == tmp->left && NULL!=tmp->right) {
                s.push(tmp->right);
                tag.pop();
                tag.push(2);
                tag.push(0);
            }  
        }
        
        return order;
    }
};
