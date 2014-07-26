
Reorder List
Total Accepted: 15244 Total Submissions: 76020

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 

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
    void reorderList(ListNode* head) {
        if (NULL == head || NULL == head->next || NULL == head->next->next) return;
        if (NULL == head->next->next->next) {
            ListNode* tmp = head->next;
            head->next = tmp->next;
            head->next->next = tmp;
            tmp->next = NULL;
            return;
        }
        int cnt = 0;
        ListNode* loc = head;
        while (NULL != loc) {
            cnt++;
            loc = loc->next;    
        }
        int bound; 
        if (0 == cnt % 2) bound = cnt/2; 
        else bound = 1 + cnt/2;
        loc = head;
        for (int i = 1; i<=bound-1; i++) 
            loc = loc->next;
        ListNode* part2 = loc->next;
        loc->next = NULL;
        ListNode* head2 = NULL;
        while (NULL!=part2) {
            ListNode* tmp = part2->next;
            part2->next = head2;
            head2 = part2;
            part2 = tmp;
        }
        
        loc = head;
        ListNode* loc2 = head2;
        while (NULL != loc2) {
            ListNode* tmp = loc->next;
            ListNode* tmp2 = loc2->next;
            loc->next = loc2;
            loc2->next = tmp;
            loc = tmp;
            loc2 = tmp2;
        }
    }
};
