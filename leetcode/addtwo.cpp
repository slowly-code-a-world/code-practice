
Add Two Numbers
Total Accepted: 17869 Total Submissions: 78838

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (NULL == l1 && NULL == l2)
            return NULL;
        if (NULL == l1)
            return l2;
        if (NULL == l2)
            return l1;
        ListNode *head = new ListNode(0);
        ListNode *it = head, *itl1 = l1, *itl2 = l2;
        int carray = 0;
        while (NULL!= itl1 && NULL!=itl2) {
            it->val = itl1->val + itl2->val + carray;
            carray = 0;
            if (it->val >= 10) {
                it->val -= 10;
                carray = 1;
            }
            itl1 = itl1->next;
            itl2 = itl2->next;
            if (NULL == itl1 && NULL == itl2 && 0 == carray)
                return head;
            it->next = new ListNode(0);
            it = it->next;
        }   
        if (NULL == itl1 && NULL == itl2) {
            it->val = 1;
            return head;
        }
        if (NULL == itl1) {
            while (NULL!=itl2) {
                it->val = itl2->val + carray;    
                carray = 0;
                if (it->val >= 10) {
                    it->val -= 10;
                    carray = 1;
                }
                itl2 = itl2->next;
                if (NULL == itl2 && 0 == carray)
                    return head;
                it->next = new ListNode(0);
                it = it->next;
            }
            it->val = 1;
            return head;
        } else {
            while (NULL!=itl1) {
                it->val = itl1->val + carray;
                carray = 0;
                if (it->val >=10) {
                    it->val -= 10;
                    carray = 1;
                }
                itl1 = itl1->next;
                if (NULL == itl1 && 0 == carray)
                    return head;
                it->next = new ListNode(0);
                it = it->next;
            }
            it->val = 1;
            return head;
        }
        
    }
};
