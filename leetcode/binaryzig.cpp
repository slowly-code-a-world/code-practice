
Binary Tree Zigzag Level Order Traversal
Total Accepted: 12166 Total Submissions: 45979

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > out;
        if (NULL == root)
            return out;
        if (NULL == root->left && NULL == root->right) {
            vector<int> tmp;
            tmp.push_back(root->val);
            out.push_back(tmp);
            return out;
        }
        queue<TreeNode*> q;
        queue<int> level;
        vector<int> tmp;
        q.push(root);
        level.push(0);
        int current_level = 0;
        while (!q.empty()) {
            TreeNode *node = q.front();
            int tmp_level = level.front();
            q.pop();
            level.pop();
            if (NULL != node->left) {
                q.push(node->left);
                level.push(tmp_level + 1);
            }    
            if (NULL != node->right) {
                q.push(node->right);
                level.push(tmp_level + 1);
            }    
            if (tmp_level == current_level) {
                if (0 == current_level%2) {
                    tmp.push_back(node->val);
                } else {
                    tmp.insert(tmp.begin(), node->val);
                }
            } else {
                out.push_back(tmp);
                tmp.clear();
                current_level ++;
                tmp.push_back(node->val);
            }    
        }
        out.push_back(tmp);
        return out;
    }
};
