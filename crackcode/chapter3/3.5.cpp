/*
3.5	 Implement a MyQueue class which implements a queue using two stacks
*/

#include <iostream> 
#include <stack>
#include <assert.h>

class MyQueue {
private:
	stack<int> Sa;
	stack<int> Sb;
public:
	void enqueue(int element) {
		assert(0 == Sb.size);		
		Sa.push(element);
	}

	int dequeue(void) {
		if (0 == Sa.size()) {
			std::cout << "no elements" << std::endl; 
			return -1;
		}

		while (0 == Sa.empty()) {
			int tmp = Sa.top();
			Sb.push(tmp);
			Sa.pop();
		}
		
		int ret = Sb.top();
		Sb.pop();

		return ret;	
	}		
};
