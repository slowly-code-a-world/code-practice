
Sum Root to Leaf Numbers
Total Accepted: 16634 Total Submissions: 56522

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25. 

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
    int sumNumbers(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (NULL == root) return 0;
        if (NULL == root->left && NULL == root->right) return root->val;
        
        queue<TreeNode*> BFS;
        queue<int> value;
        int sum = 0;
        BFS.push(root);
        value.push(root->val);
        while (!BFS.empty()) {
            TreeNode* tmp = BFS.front();
            BFS.pop();
            int tmpval = value.front();
            value.pop();
            if (NULL == tmp->left && NULL == tmp->right) {
                sum += tmpval;
                continue;
            } 
            if (NULL!=tmp->left) {
                BFS.push(tmp->left);
                value.push(10*tmpval + tmp->left->val);
                
            }
            if (NULL!=tmp->right) {
                BFS.push(tmp->right);
                value.push(10*tmpval + tmp->right->val);
            }
        }
        return sum;
    }
};
