/*
3.2	 How would you design a stack which, in addition to push and pop, also has a function
    min which returns the minimum element? Push, pop and min should all operate in
   O(1) time.

*/

#include <iostream>

class Solution {
private:
	vector<int> s;
	vector<int> smin;
public:
	void push(int element) {
		if (0 == s.size()) {
			s.push_back(element);
			smin.push_back(element);
			return;	
		}
		S.push_back(element);
		int tmp = smin[smin.size()-1];
		if (element < tmp) 
			Smin.push_back(element);
		else Smin.push_back(tmp);
	}

	int pop(void) {
		if (0 == s.size()) { 
			std::cout << "empty stack" << std::endl;

			return -1;
		}

		int ret = s[s.size()-1];
		s.pop_back();
		smin.pop_back();
		
		return ret;
	}

	int getmin(void) {
		if (0 == s.size()) {
			std::cout << "empty stack" << std::endl;

			return -1;
		}

		int ret = smin[smin.size()-1];

		return ret;
	}			
};

