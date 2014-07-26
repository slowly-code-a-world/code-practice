
Remove Duplicates from Sorted List
Total Accepted: 20588 Total Submissions: 59401

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. 

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
    ListNode *deleteDuplicates(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (NULL == head) return NULL;
        ListNode *curr, *next;
        curr = head;
        while (NULL != curr) {
            next = curr->next;
            if (NULL == next) return head;
            while (curr->val == next->val) {
                next = next->next;
                if (NULL == next) {
                    curr->next = NULL;
                    return head;
                }    
            }
            curr->next = next;
            curr = curr->next;
        }
        return head;
    }
};
