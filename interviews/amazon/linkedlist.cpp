/*
Convert a linkedlist with positive and negative integers into a list with first all negative integers, then positive. order amongst negative and positive numbers to be maintained
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	ListNode* convert(ListNode* head) {
		ListNode* negListHead = NULL, posListHead = NULL;
		ListNode* negListTail = NULL, posListTail = NULL;
		ListNode* h = head;
		if (NULL == h) return NULL;
		if (NULL == h->next) return head;
		while (h != NULL) {
			ListNode* tmp = h;
			h = h->next;
			if (tmp->val > 0) {
				if (posListHead == NULL) {
					tmp->next = NULL;
					posListHead = posListTail = tmp;
				} else {
					posListTail->next = tmp;
					posListTail = tmp;
				}
			} else {
				if (negListHead == NULL) {
					tmp->next = NULL;
					negListHead = negListTail = tmp;
				} else {
					negListTail->next = tmp;
					negListTail = tmp;
				}
			}
		}
		if (negListHead == NULL) return posListHead;
		negListTail->next = posListHead;
		return negListHead;
	}
};
