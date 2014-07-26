
Rotate List
Total Accepted: 12763 Total Submissions: 58491

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
    ListNode *rotateRight(ListNode *head, int k) {
        if (NULL == head) return NULL;
        if (NULL == head->next) return head;
        
        ListNode* loc = head, *tail = NULL; int cnt = 0;
        while (NULL != loc) {
            cnt++;
            if (NULL == loc->next);
                tail = loc;
            loc = loc->next;
        }
        k = k % cnt;
        if (0 == k)
            return head;
            
        tail->next = head;
        loc = head;
        for (int i = 1; i<=cnt-k; i++)
            loc = loc->next;
        head = loc;
        tail = head;
        while (tail->next!=head) 
            tail = tail->next;
        tail->next = NULL;
        return head;
    }
};
