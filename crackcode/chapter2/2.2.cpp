/*
2.2      Implement an algorithm to find the nth to last element of a singly linked list.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
        int data;
        struct node *next;
};

class Solution {
private:
        struct node *head;
public:
        Solution() {
                head = NULL;
        }
        struct node* get_nth(int n) {
                if (n <= 0) return NULL;
                struct node* p = head;
                int size = 0;
                while (NULL != p) {
                        size ++;
                        p = p->next;
                }

                if (n > size) return NULL;
                int loc = size - n, i = 0;
                p = head;
                while (i < loc) {
			i++;
			p = p->next;
		}
                return p;
        }
        void generate_list(void) {
                srand(time(NULL));
                for (int i = 0; i< 10; i++) {
                        struct node *p = new node;
                        if (NULL == head) {
                                head = p;
                                head->next = NULL;
                                head->data = rand() % 10;
                        } else {
                                p->next = head;
                                p->data = rand() % 10;
                                head = p;
                        }
                }
        }
        void print_list(void) {
                struct node *p = head;
                while (NULL != p) {
                        cout << p->data << " ";
			p = p->next;
                }
                cout << endl;
        }
};

int main(void) {

        Solution S;
        S.generate_list();
        S.print_list();
        struct node *p = S.get_nth(11);
	if (NULL != p) cout << p->data << endl;
	else cout << "NULL pointer" << endl;

        return 0;
}
                                                     
