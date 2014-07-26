
Merge Two Sorted Lists
Total Accepted: 19347 Total Submissions: 58841

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (NULL == l1) return l2;
        if (NULL == l2) return l1;
        ListNode* b1, *c1, *b2, *c2;
        b1 = c1 = l1;
        b2 = c2 = l2;
        while (NULL != c1 && NULL != c2) {
            while (NULL!=c1 && c1->val <= c2->val) {
                b1 = c1;
                c1 = c1->next;
            }
            if (NULL == c1) {
                b1->next = c2;
                return l1;
            }
            while (NULL != c2->next && c2->next->val <= c1->val)
                c2 = c2->next;
            if (b1 == c1)
                l1 = l2;
            else b1->next = b2;
            b2 = c2->next;
            c2->next = c1;
            c2 = b2;
            b1 = c1;
        }
        if (NULL == c2) 
            return l1;
    }
};
