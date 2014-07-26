
Sort List
Total Accepted: 15916 Total Submissions: 78401

Sort a linked list in O(n log n) time using constant space complexity.

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
    ListNode *sortList(ListNode *head) {
        if (NULL == head) return NULL;
        if (NULL == head->next) return head;
        int cnt = 0;
        ListNode* loc = head;
        while (NULL!=loc) {
            loc = loc->next;
            cnt++;
        }
        cnt = cnt/2;
        loc = head;
        for (int i = 0; i < cnt - 1; i++) 
            loc = loc->next;
        ListNode* head1 = loc->next;
        loc->next = NULL;
        head = sortList(head);
        head1 = sortList(head1);
        // merge
        ListNode* b, *c, *b1, *c1;
        b = c = head; b1 = c1 = head1;
        while (NULL!=c && NULL!=c1) {
            while (NULL!=c && c->val <= c1->val) {
                b = c;
                c = c->next;
            }
            if (NULL == c) {
                b->next = c1;
                return head;
            }
            while (NULL!=c1->next && c1->next->val <= c->val) 
                    c1 = c1->next;
            if (b == c)
                head = b1;
            else b->next = b1;
            b1 = c1->next;
            c1->next = c;
            c1 = b1;
            b = c;
        }
        if (c1 == NULL) 
            return head;
    }
};
