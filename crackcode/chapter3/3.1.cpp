/*
3.1	 Describe how you could use a single array to implement three stacks.
*/

#include <iostream>

using namespace std;

#define SIZE	1024
class Solution {
private:
	int array[SIZE];
	int pointer[3];
public:
	Solution() {
		for (int i = 0; i < 3; i++)
			pointer = -1;
	}		

	void push(int element, int stack) {
		
		if (pointer[stack] == SIZE/3 - 1) {
			cout << "stack " << stack << " is full" << endl;
			return;
		}

		pointer[stack]++;
		array[stack*SIZE/3 + pointer[stack]] = element;
		return;
	}		
		
	int pop(int stack) {

		if (-1 == pointer[stack]) {
			cout << "stack " << stack << " has no element to pop" << endl;
			return;
		}

		int ret = array[stack*SIZE/3 + pointer[stack]];
		pointer[stack]--;

		return ret;
	}
	
};

struct stackNode {
	int previous;
	int value;
	stackNode(int prev, int val) {
		previous = prev;
		value = val;
	}	
};

class Solutionv2 {
private:
	struct node* array[SIZE];
	int pointer[3];
	int currentUsed;
public:
	Solutionv2() {
		for (int i = 0; i < 3; i++)
			pointer = -1;
		currentUsed = 0;
	}	

	void push(int element, int stack) {
		int prev = pointer[stack];

		array[currentUsed] = new stackNode(prev, element);
		pointer[stack] = currentUsed;
		currentUsed++;
	}

	int pop(int stack) {
		if (-1 == pointer[stack]) {
			cout << "stack " << stack << " have no element to pop" << endl;
			return 0;
		}

		int index = pointer[stack];
		int prev = array[index]->previous;
		int value = array[index];
		pointer[stack] = prev;
		array[index] = NULL;

		return value;
	}
};
