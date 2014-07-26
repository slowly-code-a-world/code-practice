
Merge k Sorted Lists
Total Accepted: 14176 Total Submissions: 64627

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity

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
    ListNode* merge(vector<ListNode*> &lists, int s, int e) {
        if (e < s) return NULL;
        if (e == s) return lists[s];
        ListNode* p1 = merge(lists, s, (e+s)/2);
        ListNode* p2 = merge(lists, 1 + (e+s)/2, e);
    
        ListNode* head, *tail, *record;
        head = tail = NULL;
        for (;;) {
            int min = INT_MAX; record = NULL;
            if (NULL!=p1 && p1->val < min) {
               record = p1;
               min =p1->val;
            }
            if (NULL!=p2 && p2->val < min) {
                record = p2;
                min = p2->val;
            }
            if (NULL == record) break;
            else {
                   if (NULL == head) {
                        head = tail = record;
                        if (record == p1) p1 = p1->next;
                        else p2 = p2->next;
                        tail->next = NULL;
                    } else {
                        tail->next = record;
                        tail = tail->next;
                        if (record == p1) p1 = p1->next;
                        else p2 = p2->next;
                        tail->next = NULL;
                    }
                }
            }
            return head;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (0 == lists.size()) return NULL;
        if (1 == lists.size()) return lists[0];
        return merge(lists, 0, lists.size()-1);
    }
};
