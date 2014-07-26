
Partition List
Total Accepted: 13474 Total Submissions: 51089

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5. 

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
    ListNode *partition(ListNode *head, int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (NULL == head) return NULL;
        if (NULL == head->next) return head;
        ListNode *head_less, *head_greater, *tail_less, *tail_greater, *it;
        head_less = head_greater = tail_less = tail_greater = NULL;
        it = head; 
        while (NULL != it) {
            if (it->val < x) {
                if (NULL == head_less) {
                    head_less = tail_less = it;
                
                } else { 
                    tail_less->next = it;
                    tail_less = it;    
                    
                }
            } else {
                if (NULL == head_greater) {
                    head_greater = tail_greater = it;
                } else {
                    tail_greater->next = it;
                    tail_greater = it;
                }
            }
            ListNode *tmp = it->next;
            it->next = NULL;
            it = tmp;
        }
        if (NULL!=tail_less){
            tail_less->next = head_greater;
            return head_less;
        } else return head_greater;
    }
};
