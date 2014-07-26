
Swap Nodes in Pairs
Total Accepted: 17183 Total Submissions: 53281

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed

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
    ListNode *swapPairs(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (NULL == head) return NULL;
        if (NULL == head->next) return head;
        ListNode* curr, *next, *before;
        
        before = curr = head;
        next = head->next;
        for (;;) {
            curr->next = next->next;
            next->next = curr;
            if (before == head) 
                head = next;
            else 
                before->next = next;
            
            before = curr;
            curr = curr->next;
            if (NULL == curr)
                return head;
            next = curr->next;
            if (NULL == next)
                return head;
        }
    }
};
