
Insertion Sort List
Total Accepted: 16354 Total Submissions: 65289

Sort a linked list using insertion sort.

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
    ListNode *insertionSortList(ListNode *head) {
        if (NULL == head || NULL == head->next) return head;
        ListNode* r = head->next, *next, *tail =  head;
        int max = head->val;
        while (NULL != r) {
            next = r->next;
            // insert r into head
            if (r->val >= max) {
                max = r->val;
                tail = r;
            } else {
                if (r->val <= head->val) {
                    r->next = head;
                    head = r;
                } else {
                    ListNode* s, *n;
                    s = head;
                    n = s->next;
                    while (n->val < r->val) {
                        s = n;
                        n = n->next;
                    }
                    r->next = n;
                    s->next = r;
                }
            }
            r = next;
            tail->next = r;
        }
        return head;
    }
};
