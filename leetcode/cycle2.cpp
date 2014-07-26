
Linked List Cycle II
Total Accepted: 17205 Total Submissions: 56228

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space? 

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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (NULL == head) return NULL;
        
        ListNode* newh = head;
        while (newh != NULL) {
            newh = newh->next;
            if (NULL == newh)
                return NULL;
            ListNode* S = head;
            while (S!=newh) {
                if (newh->next == S)
                    return S;
                else 
                    S = S->next;
            }
            if (newh->next == S)
                return S;
        }
        
        return NULL;
    }
};
