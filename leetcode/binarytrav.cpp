
Binary Tree Level Order Traversal
Total Accepted: 16974 Total Submissions: 55358

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector <vector<int>> out;
        if (NULL == root) return out;
        if (NULL == root->left && NULL == root->right) {
            vector<int> tmp;
            tmp.push_back(root->val);
            out.push_back(tmp);
            return out;
        }
        queue<TreeNode*> BFS;
        queue<int> level;
        BFS.push(root);
        level.push(0);
        int lastlevel = 0;
        vector<int> tmpv;
        
        while (!BFS.empty()) {
            TreeNode* tmp = BFS.front();
            int tmplevel = level.front();
            if (tmplevel == lastlevel) {
                tmpv.push_back(tmp->val);
            } else {
                out.push_back(tmpv);
                tmpv.clear();
                tmpv.push_back(tmp->val);
                lastlevel++;
            }
            BFS.pop();
            level.pop();
            if (NULL!=tmp->left) {
                BFS.push(tmp->left);
                level.push(tmplevel+1);
            }
            if (NULL!=tmp->right){
                BFS.push(tmp->right);
                level.push(tmplevel+1);
            }
        }
        out.push_back(tmpv);
        return out;
    }
};
