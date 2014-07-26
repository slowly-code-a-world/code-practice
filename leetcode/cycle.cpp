
Linked List Cycle
Total Accepted: 23718 Total Submissions: 66939

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space? 

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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        /*
        if (NULL == head) return false;
        map <ListNode *, int> S;
        S.insert(pair<ListNode*, int>(head, 0));
        while (head !=NULL) {
            head = head->next;
            if (S.find(head) == S.end())
                S.insert(pair<ListNode*, int>(head, 0));
            else
                return true;
        }
        return false;
        */
        if (NULL == head) return false;
        ListNode *newhead = head;
        while (newhead!=NULL) {
            newhead = newhead->next;
            if (NULL == newhead) 
                return false;
                
            ListNode *start = head;
            while (start!=newhead) {
                if (newhead->next == start)
                    return true;
                else start = start->next;    
            }
            if (newhead->next == start)
                return true;
        }
        return false;
    }
};
