
Construct Binary Tree from Preorder and Inorder Traversal
Total Accepted: 11765 Total Submissions: 44990

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 

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
    TreeNode *buildTreeDetail(vector<int> &preorder, int prestart, vector<int> &inorder, int instart, int len) {
        if (0 == len) return NULL;
        if (1 == len) {
            TreeNode* root = new TreeNode(preorder[prestart]);
            return root;
        }
        int i;
        for (i = instart; i<=instart+len-1; i++) {
            if (inorder[i] == preorder[prestart])
                break;
        }
        if (instart == i) {
            TreeNode *root = new TreeNode(preorder[prestart]);
            root->right = buildTreeDetail(preorder, prestart+1, inorder, instart+1, len-1);
            return root;
        } else if (instart+len-1 == i) {
            TreeNode *root = new TreeNode(preorder[prestart]);
            root->left = buildTreeDetail(preorder, prestart+1, inorder, instart, len-1);
            return root;    
        } else {
            TreeNode *root = new TreeNode(preorder[prestart]);
            root->left = buildTreeDetail(preorder, prestart+1, inorder, instart, i-instart);
            root->right = buildTreeDetail(preorder, prestart+i+1-instart, inorder, i+1, instart+len-i-1);
            return root;
        }
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTreeDetail(preorder, 0, inorder, 0, preorder.size());
    }
};
