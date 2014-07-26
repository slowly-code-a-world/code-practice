
Binary Tree Maximum Path Sum
Total Accepted: 14488 Total Submissions: 73199

Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3

Return 6. 

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
    int maxPathSum(TreeNode *root) {
        if (NULL == root) return 0;
        if (NULL == root->left && NULL == root->right) return root->val;
        stack<TreeNode*> node;
        stack<int>value;
        map<TreeNode*, int> themap;
        map<TreeNode*, int> maxfromroot;
        node.push(root);
        value.push(0);
        int max;
        while (!node.empty()) {
            TreeNode* treetop = node.top();
            int valtop = value.top();
            int have_left = 0, have_right = 0;
            if (NULL != treetop->left && 1!= valtop)  {
                node.push(treetop->left);
                have_left = 1;
            }
            if (NULL!= treetop->right && 1!= valtop)  {
                node.push(treetop->right);
                have_right = 1;
            }
            if (1 == have_left || 1 == have_right) {
                value.pop();
                value.push(1);
                if (1 == have_left)
                    value.push(0);
                if (1 == have_right)
                    value.push(0);
            } else {
                node.pop();
                value.pop();
                if (NULL== treetop->left && NULL == treetop->right) {
                    themap[treetop] = treetop->val;
                    maxfromroot[treetop] = treetop->val;
                }
                else {
                    int left1, right1, left2, right2;
                    if (NULL!=treetop->left && NULL == treetop->right) {
                        left1 = maxfromroot[treetop->left];
                        if (left1 > 0)
                                maxfromroot[treetop] = treetop->val + left1;
                        else maxfromroot[treetop] = treetop->val;
                    } else if (NULL==treetop->left && NULL!=treetop->right) {
                        right1 = maxfromroot[treetop->right];
                        if (right1 > 0)
                                maxfromroot[treetop] = treetop->val + right1;
                        else maxfromroot[treetop] = treetop->val;
                    } else {
                        left1 = maxfromroot[treetop->left];
                        right1 = maxfromroot[treetop->right];
                        int tmp = (left1 > right1) ? left1 + treetop->val: right1 + treetop->val;

                        if (treetop->val > tmp)
                                maxfromroot[treetop] = treetop->val;
                        else maxfromroot[treetop] = tmp;
                    }

                    if (NULL !=treetop->left && NULL == treetop->right)
                        max = left2 = themap[treetop->left];
                    else if (NULL ==treetop->left && NULL!=treetop->right)
                        max = right2 = themap[treetop->right];
                    else {
                        left2 = themap[treetop->left];
                        right2 = themap[treetop->right];
                        max = (left2 > right2)? left2: right2;
                    }

                    int middle = treetop->val;
                    if (NULL!=treetop->left && left1 > 0)
                        middle += left1;
                    if (NULL!=treetop->right && right1 > 0)
                        middle += right1;
                    max = (max > middle)? max: middle;
                    themap[treetop] = max;
                }
            }
        }
	return max;
    }
};

