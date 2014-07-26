
Convert Sorted List to Binary Search Tree
Total Accepted: 14769 Total Submissions: 54677

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (NULL == head) return NULL;
        if (NULL == head->next) return new TreeNode(head->val);
        ListNode* it = head; 
        int count = 1;
        while (NULL!=it) {
            it = it->next;
            count++;
        }
        it = head; int loc = 1;
        while (loc!=count/2) {
            it = it->next;
            loc++;
        }
        TreeNode* root = new TreeNode(it->val);
        root->right = sortedListToBST(it->next);
        if (it == head) return root;
        ListNode* preit = head;
        while (preit->next!=it) 
            preit = preit->next;
        preit->next = NULL;
        root->left = sortedListToBST(head);
        return root;
    }
};
