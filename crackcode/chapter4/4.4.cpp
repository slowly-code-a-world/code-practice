/*
4.4	 Given a binary search tree, design an algorithm which creates a linked list of all the
    nodes at each depth (i.e., if you have a tree with depth D, you’ll have D linked lists).
*/

#include <iostream>

class Solution {
private:
	vector<struct node*> list;
public:
	void create(struct node* root) {
		vector <struct node*> s;
		s.push_back(root);
		struct node* end, *start;
		struct node* head, *tail;
		start = end = root;
		while (0 == s.empty()) {
			struct node* tmp = s[0];
			if (tmp == start || tmp == end) {
						
				if (NULL != tmp->left) 
					s.push_back(tmp->left);
					
				if (NULL != tmp->right) 
					s.push_back(tmp->right);	

				if (tmp == start) {
					head = tail = tmp;
					tail->next = NULL;
					s.erase(s.begin());
				} else {
					if (1 == s.size()) 
						start = end = NULL;
					else {
						start = s[1];
						end = s[s.size()-1];
					}
					tail->next = s.begin();
					tail = tail->next;
					list.push_back(head);			
					s.erase(s.begin());
				}
			} else {
				if (NULL != tmp->left)
					s.push_back(tmp->left);
				if (NULL != tmp->right)
					s.push_back(tmp->right);
				tail->next = s.begin();
				tail = tail->next;
				s.erase(s.begin());	
			}		
		}
	} 
};

