
Path Sum II
Total Accepted: 15719 Total Submissions: 58068

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]


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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > ret;
        if (NULL == root) return ret;
        if (NULL == root->left && NULL == root->right) {
            if (sum == root->val) {
                vector<int> tmp;
                tmp.push_back(root->val);
                ret.push_back(tmp);
            }  
            return ret;
        }
        
        vector<vector<int> > retleft = pathSum(root->left, sum-root->val);
        for (int i = 0; i<retleft.size(); i++) 
            retleft[i].insert(retleft[i].begin(), root->val);
        
        vector<vector<int> > retright = pathSum(root->right, sum-root->val);
        for (int i = 0; i<retright.size(); i++)
            retright[i].insert(retright[i].begin(), root->val);
            
        ret.insert(ret.end(), retleft.begin(), retleft.end());
        ret.insert(ret.end(), retright.begin(), retright.end());
        
        return ret;
    }
};
