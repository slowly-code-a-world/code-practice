
Remove Duplicates from Sorted List II
Total Accepted: 14956 Total Submissions: 60690

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3. 

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
    ListNode *deleteDuplicates(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (NULL == head) return NULL;
        ListNode* curr, *detect;
        curr = head;
        while (curr != NULL) {
            detect = curr->next;
            if (NULL == detect) 
                return head;
            if (detect->val != curr->val) 
                curr = detect;
            else {
                while (detect->val == curr->val) {
                    detect = detect->next;
                    if (NULL == detect) {
                        if (curr == head) 
                            return NULL;
                        else {
                            ListNode* tmp = head;
                            while (tmp->next!=curr)
                                tmp = tmp->next;
                            tmp->next = NULL;    
                            return head;
                        }    
                    }
                }
                if (curr == head) { 
                    curr = detect;
                    head = detect;
                }    
                else {
                    ListNode *tmp = head;
                    while (tmp->next!=curr) 
                        tmp=tmp->next;
                    tmp->next = detect;
                    curr = detect;
                }
           }
        }
    }  
};
