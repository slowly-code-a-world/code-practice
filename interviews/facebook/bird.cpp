/*
There are n trees in a circle. Each tree has a fruit value associated with it. A bird can sit on a tree for 0.5 sec and then he has to move to a neighbouring tree. It takes the bird 0.5 seconds to move from one tree to another. The bird gets the fruit value when she sits on a tree. We are given n and m (the number of seconds the bird has), and the fruit values of the trees. We have to maximise the total fruit value that the bird can gather. The bird can start from any tree.
*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;
class Solution {
public:
	int getMaxValue(vector<int>&values, int currentVal, int pos, int currStep, int limit) {
		if (currStep >= limit) return currentVal;
		int left = pos;
		if (left > 0) left--; 
		else left = values.size()-1;
		int goLeft = getMaxValue(values, currentVal + values[left], left, currStep + 1, limit);
		int right = pos;
		if (right < values.size()-1) right++;
		else right = 0;
		int goRight = getMaxValue(values, currentVal + values[right], right, currStep + 1, limit);
		return max(goLeft, goRight);
	}
	int getTotal(vector<int> &values, int steps) {
		if (values.size() <= 1) return 0;
		int ret = INT_MIN;
		for (int i = 0; i<values.size(); i++) {
			int tmp = getMaxValue(values, values[i], i, 0, steps);
			ret = max(ret, tmp);
		}
		return ret;
	}
};

int main(void) {
	Solution S;
	vector<int> test = {7, 8, 4, 1, 6};
	int ret = S.getTotal(test, 6);
	cout << ret << endl;
}
