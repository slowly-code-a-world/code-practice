/*
4.2	 Given a directed graph, design an algorithm to find out whether there is a route be-
    tween two nodes.
*/

#include <iostream>

struct node {
	vector<struct *node> list;
};

class Solution {
public:
	void exists(struct node* pa, struct node* pb, bool &flag, unordered_map<struct node*, bool> &map) {
		map[pa] = true;
		if (pa == pb) {
			flag = true;
			return;
		}	

		for (int i = 0; i < pa->list.size(); i++) {
			if (0 == map[pa->list[i]] && 0 == flag) 
				exists(pa->list[i], pb, flag, map);
		}				
	}

	bool exist_route(struct node* pa, struct node* pb) {

		bool connected = false;
		unordered_map<struct node*, bool> map;
		exists(pa, pb, connected, map);
		return connected;
	}	
};

