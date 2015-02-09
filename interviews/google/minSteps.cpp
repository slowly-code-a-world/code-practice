/*
2) Find minimum number of steps to reach the end of array from start (array value shows how much you can move). DP question
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	int getMin(vector<int> &array) {
		if (array.size() <= 1) return 0;
		int size = array.size();
		int start = 0, ret = 0;
		while (true) {
			int tmp = start + array[start];
			if (tmp >= array.size()-1)
				return ret + 1;
			int maxLoc = -1, maxVal = INT_MIN;
			for (int i = 1; i <= array[start]; i++) {
				if (start + i + array[start + i] > maxVal) {
					maxLoc = i;
					maxVal = start + i + array[start + i];
				}
			}
			if (maxLoc == -1) return -1;
			if (maxVal <= tmp) return -1;
			ret++;
			start = start + maxLoc;
		}
	}
};
