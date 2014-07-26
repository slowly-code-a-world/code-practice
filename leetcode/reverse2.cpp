
Reverse Linked List II
Total Accepted: 14176 Total Submissions: 54906

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. 

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        int cnt = 1;
        ListNode* p1 = head;
        ListNode* p3, *p2, *p2tail, *p3next;
        while (cnt < m-1) {
            cnt ++;
            p1 = p1->next;
        }
        if (1 != m) {
            p2tail = p2 = p1->next;
        } else {
            p2 = p2tail = head;
        }    
        p3 = p2->next;
        for (int i = m; i<n; i++) {

            p3next = p3->next;
            p3->next = p2;
            p2 = p3;  
            p3 = p3next;
        }
        if (1 == m)
            head = p2;
        else p1->next = p2;
        p2tail->next = p3;
        return head;
    }
};
