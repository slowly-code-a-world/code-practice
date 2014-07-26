
Populating Next Right Pointers in Each Node II
Total Accepted: 13732 Total Submissions: 45841

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    int height(TreeLinkNode* root) {
        if (NULL == root) return 0;
        if (NULL == root->left && NULL == root->right) return 1;
        int left = height(root->left);
        int right = height(root->right);
        return (left > right)? 1 + left : 1 + right;
    }
    
    TreeLinkNode* outmost(TreeLinkNode* root, int h, int isright) {
        if (NULL == root) return NULL;
        if (1 == h) return root;
        TreeLinkNode* left = outmost(root->left, h-1, isright);
        TreeLinkNode* right = outmost(root->right, h-1, isright);
        if (1 == isright)  {
            if (NULL!=right) 
                return right;
            return left;    
        }        
        else {
            if (NULL!=left)
                return left;
            return right;    
        }    
    }
    void connect(TreeLinkNode *root) {
        if (NULL == root) return;
        if (NULL == root->left && NULL == root->right) return;
        int hleft = height(root->left);
        int hright = height(root->right);
        int min = (hleft > hright)? hright : hleft;
        for (int i = 1; i<=min; i++) {
            TreeLinkNode* left = outmost(root->left, i, 1);
            TreeLinkNode* right = outmost(root->right, i, 0);
            left->next = right;
        }
        connect(root->left);
        connect(root->right);
    }
};
