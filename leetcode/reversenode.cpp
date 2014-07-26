
Reverse Nodes in k-Group
Total Accepted: 11259 Total Submissions: 45414

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 

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
    void reverse_group(ListNode* &h, ListNode* &t, int k) {
        ListNode* p, *q, *r, *x;
        p = x = h;
        q = p->next;
        r = q->next;
        for (int i = 1; i<=k-1; i++) {
            q->next = p;
            p = q;
            q = r;
            if (NULL != r)
                r = r->next;
        }
        x->next = q;
        h = p;
        t = x;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k<=1) return head;
        if (NULL == head) return NULL;
        int len = 0;
        ListNode* p = head;
        while (p!=NULL) {
            len++;
            p = p->next;
        }
        if (k > len) return head;
        int turn = len/k;
        ListNode *h, *t, *h1, *t1;
        h = head;
        reverse_group(h, t, k);
        head = h;
        h1 = t->next;
        for (int i = 2; i<=turn; i++) {
            reverse_group(h1, t1, k);
            t->next = h1;
            h = h1;
            t = t1;
            h1 = t1->next;
        }
        return head;
    }
};
