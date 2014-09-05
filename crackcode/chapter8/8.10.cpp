/*
design and implement hash table use linked list to handle collisions
*/

#include <iostream>

struct node {
	int key;	
	int data;
	struct node *next;
	node(int key, int data) {
		this->key = key;
		this->data = data;	
		next = NULL;
	}	
};

class hash_table {
private:
	vector<struct node*> table;
public:
	void insert(int key, int data) {
		int index = calculate_index(key, table.size());
		struct node *p = new node(key, data);
		if (NULL == table[index]) 
			table[index] = p;
		else { 
			p->next = table[index];
			table[index] = p;
		}
	}

	int get_data(int key) {
		int index = calculate_index(key, table.size());
		if (NULL == table[index])
			return INT_MAX;
		struct node* p = table[index];
		while (NULL != p) {
			if (key == p->key) 
				return p->data;
			p = p->next;
		}

		return INT_MAX;	
	}

	unsigned long calculate_index(int key, int size) {
		return key % size;
	}
};
