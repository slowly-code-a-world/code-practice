/*
3.3	Imagine a (literal) stack of plates. If the stack gets too high, it might topple. There-
    fore, in real life, we would likely start a new stack when the previous stack exceeds
   some threshold. Implement a data structure SetOfStacks that mimics this. SetOf-
  Stacks should be composed of several stacks, and should create a new stack once
 the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should
behave identically to a single stack (that is, pop() should return the same values as it
would if there were just a single stack).
FOLLOW UP
Implement a function popAt(int index) which performs a pop operation on a specific
sub-stack.
*/

#include <iostream>

class SetOfStacks {
private:
	vector<vector<int> > s;
	vector<int> curr;
	int size_of_each_stack;
public:
	SetOfStacks(int size) {
		size_of_each_stack = size;
	}

	void push(int element) {
		if (curr.size() == size_of_each_stack) {
			s.push_back(curr);
			curr.clear();
			curr.push_back(element);

			return;
		}

		curr.push_back(element);	
	}

	int pop(void) {
		if (0 == curr.size()) {
			if (0 == s.size()) {
				std::cout << "no elements to pop" << std::endl;
				return -1;
			}
			curr = s[s.size()-1];
			s.pop_back();
			int ret = curr[curr.size()-1];
			curr.pop_back();
			return ret;
		}

		int ret = curr[curr.size()-1];
		curr.pop_back();
				
		return ret;	
	}

	int popAt(int index) {
		if (index > s.size()) {
			std::cout << "no such many substacks" << std::endl;
			return -1;
		}

		if (index == s.size()) {
			if (0 == curr.size()) {
				std::cout << "no element in the index to pop" << endl;
				return -1;
			}		
			int ret = curr[curr.size()-1];
			curr.pop_back();
		
			return ret;	
		} 

		if (0 == s[index].size()) {
			std::cout << "no element in the index to pop" << std::endl;
			return -1;
		}

		int ret = s[index][s[index].size()-1];
		s[index].pop_back();
		
		return ret;
	}	
};

using namespace std;

int main(void) {
}
