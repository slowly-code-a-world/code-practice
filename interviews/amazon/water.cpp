#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	int rain(vector<int> &array) {
		int size = array.size();
		vector<int> left(size, 0);
		vector<int> right(size, 0);
		int maxLeft = array[0];
		for (int i = 0; i<array.size(); i++) {
			left[i] = maxLeft;
			maxLeft = max(left[i], maxLeft);
		}
		int maxRight = array[size-1];
		for (int i = size-1; i>=0; i--) {
			right[i] = maxRight;
			maxRight = max(maxRight, right[i]);
		}
		int ret = 0;
		for (int i = 1; i<array.size()-1; i++) {
			if (min(left[i], right[i]) > array[i])
				ret+=min(left[i], right[i]) - array[i];
		}
		return ret;
	}
};
