
Convert Sorted Array to Binary Search Tree
Total Accepted: 16218 Total Submissions: 50211

Given an array where elements are sorted in ascending order, convert it to a height balanced BST

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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int size = num.size();
        if (0 == size) return NULL;
        if (1 == size) return new TreeNode(num[0]);
        TreeNode* root = new TreeNode(num[size/2]);
        vector<int> left, right;
        for (int i= 0; i<size/2; i++)
            left.push_back(num[i]);
        for (int i= 1 + size/2; i<size; i++)
            right.push_back(num[i]);
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
        
    }
};
