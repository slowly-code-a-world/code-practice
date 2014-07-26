
Copy List with Random Pointer
Total Accepted: 14908 Total Submissions: 65407

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Have you been asked this question in an interview? 

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (NULL == head) return NULL;
        
        RandomListNode* it1 = head;
        RandomListNode* it2 = NULL, *head2 = NULL;
        map<RandomListNode*, RandomListNode*> mapping;
        
        while (it1!=NULL) {
            RandomListNode* node = new RandomListNode(it1->label);
            mapping[it1] = node;
            if (NULL == head2) {
                head2 = node;
                it2 = head2;
            }  else it2->next = node;
            it1 = it1->next;
            if (NULL != it2->next)
                it2 = it2->next;
        }
        
        map<RandomListNode*, RandomListNode*>::iterator it = mapping.begin();
        for (; it!=mapping.end(); it++) {
            if (NULL == (*it).first->random)
                (*it).second->random = NULL;
            else {
                //it2 = mapping.find((*it).first->random);
                /*
                if (it2 == mapping.end()) { 
                    RandomListNode *node = new RandomListNode((*it).first->random->label);
                    (*it).second
                }    
                */
                (*it).second->random = (*mapping.find((*it).first->random)).second;
            }        
        }
        return head2;
    }
};
