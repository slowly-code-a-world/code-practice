
Binary Tree Level Order Traversal II
Total Accepted: 13919 Total Submissions: 44921

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > ret;
        if (NULL == root) return ret;
        if (NULL == root->left && NULL == root->right) {
            vector<int> tmp;
            tmp.push_back(root->val);
            ret.push_back(tmp);
            return ret;
        }
        stack <vector<int> > S;
        queue <TreeNode*> Q;
        queue <int> L;
        Q.push(root);
        L.push(0);
        int lastlevel = 0;
        vector <int> tmpv;
        while (!Q.empty()) {
            TreeNode* tmp = Q.front();
            int tmplevel = L.front();
            if (tmplevel == lastlevel) {
                tmpv.push_back(tmp->val);
            } else {
                S.push(tmpv);
                lastlevel++;
                tmpv.clear();
                tmpv.push_back(tmp->val);
            }
            if (NULL!=tmp->left) {
                Q.push(tmp->left);
                L.push(tmplevel+1);
            }
            if (NULL!=tmp->right) {
                Q.push(tmp->right);
                L.push(tmplevel+1);
            }
            Q.pop();
            L.pop();
        }
        S.push(tmpv);
        while (!S.empty()) {
            ret.push_back(S.top());
            S.pop();
        }
        return ret;
    }
};
