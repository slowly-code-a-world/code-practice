/*
Given n, find the smallest number for which product of the digits is n, if no such number exists, print -1
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;
class Solution {
public:
	int getMin(int val) {
		assert(val >= 0);
		if (val >= 0 && val <=9) return val;
		vector<int> ret;
		while (true)  {
			bool found = false;
			for (int i = 9; i>=2; i--) {
				if (val % i == 0) {
					found = true;
					ret.push_back(i);
					val /= i;
					break; 
				}
			}
			if (!found) return -1;
			if (val == 1) break;
		} 
		sort(ret.begin(), ret.end());
		int retVal = 0;
		for (int i = 0; i<ret.size(); i++)
			retVal = 10*retVal + ret[i];
		return retVal;
	}
};

int main(void) {
	Solution S;
	cout << S.getMin(36) << endl;
}
