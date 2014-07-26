
Remove Nth Node From End of List
Total Accepted: 16670 Total Submissions: 56091

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (NULL == head) return NULL;
        vector <ListNode*> store;
        ListNode* it = head;
        while (it!=NULL) {
            store.push_back(it);
            it = it->next;
        }
        int loc = store.size() - n;
        if (0 == loc) {
            head = head->next;
            return head;
        } else {
            store[loc-1]->next = store[loc]->next;
            return head;
        }
    }
};
