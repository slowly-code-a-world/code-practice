
Recover Binary Search Tree
Total Accepted: 12038 Total Submissions: 52019

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

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
    void put_pointers(TreeNode *root, int &prev, TreeNode* &prev_pointer, vector<vector<TreeNode*> > &parray) {
        if (NULL == root) return;
        if (NULL == root->left && NULL == root->right) {
            if (NULL == prev_pointer) {
                prev = root->val;
                prev_pointer = root;
            } else {
                if (root->val < prev) {
                    vector <TreeNode*> tmp;
                    tmp.push_back(prev_pointer);
                    tmp.push_back(root);
                    parray.push_back(tmp);
                }
                prev = root->val;
                prev_pointer = root;
            }
            return;
        }
        put_pointers(root->left, prev, prev_pointer, parray);
        if (NULL == prev_pointer) {
            prev = root->val;
            prev_pointer = root;
        } else {
            if (root->val < prev) {
                vector <TreeNode*> tmp;
                tmp.push_back(prev_pointer);    
                tmp.push_back(root);
                parray.push_back(tmp);
            } 
            prev = root->val;
            prev_pointer = root;
        }
        put_pointers(root->right, prev, prev_pointer, parray);
    } 
    
    void recoverTree(TreeNode *root) {
        int prev; 
        vector<vector<TreeNode*> > parray;
        TreeNode* prev_pointer = NULL;
        put_pointers(root, prev, prev_pointer, parray);
        if (parray.size() == 1) {
            int tmp = parray[0][0]->val;
            parray[0][0]->val = parray[0][1]->val;
            parray[0][1]->val = tmp;
        } else {
            int tmp = parray[0][0]->val;
            parray[0][0]->val = parray[1][1]->val;
            parray[1][1]->val = tmp;
        }
    }
};
/*
class Solution {
public:
    void get_order(TreeNode* root, vector<int> &order) {
        if (NULL == root) return;
        if (NULL == root->left && NULL == root->right) {
            order.push_back(root->val);
            return;    
        }    
        get_order(root->left, order);
        order.push_back(root->val);
        get_order(root->right, order);
    }
    
    void modify_tree(TreeNode* root, int count, int target_val, int &total) {
        if (NULL == root) return;
        if (NULL == root->left && NULL == root->right)  {
            total++;
            if (total == count) 
                root->val = target_val;
            return;    
        }
        modify_tree(root->left, count, target_val, total);
        total++;
        if (total == count) {
            root->val = target_val;
            return;
        }
        modify_tree(root->right, count, target_val, total);
            
    }
    void recoverTree(TreeNode *root) {
        vector <int> order;
        get_order(root, order);
        vector<int> loc;
        for (int i = 0; i<order.size()-1; i++) {
            if (order[i] > order[i+1])
                loc.push_back(i);
        } 
        if (1 == loc.size()) {
            int total = 0;
            modify_tree(root, loc[0]+1, order[loc[0]+1], total);
            total = 0;
            modify_tree(root, loc[0]+2, order[loc[0]], total);
        } else {
            int total = 0;
            modify_tree(root, loc[0]+1, order[loc[1]+1], total);
            total = 0;
            modify_tree(root, loc[1]+2, order[loc[0]], total);
        }
    }
};
*/
