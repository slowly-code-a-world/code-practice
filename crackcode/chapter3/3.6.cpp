/*
3.6	 Write a program to sort a stack in ascending order. You should not make any assump-
    tions about how the stack is implemented. The following are the only functions that
   should be used to write this program: push | pop | peek | isEmpty.

*/

#include <iostream>

class Solution {
private:
	stack<int> Sa;
	stack<int> Sb;
public:
	void sort(void) {
		if (0 == Sa.size() || 1 == Sa.size()) return;
		
		int size = Sa.size();
		int count, min;
		while (0 != size) {
			min = Sa.top();
			for (int i = 0; i < size; i++) {
				if (Sa.top() < min) {
					min = Sa.top();
					count = 1;
				} else if (Sa.top() == min) 
					count ++;
				
				Sb.push(Sa.top());
				Sa.pop();
			}
			for (int i = 0; i < count; i++) 
				Sa.push(min);
			for (int i = 0; i < Sb.size(); i++) {
				Sa.push(Sb.top());
				Sb.pop();
			}
			size = size - count;
		}
	}	
}
