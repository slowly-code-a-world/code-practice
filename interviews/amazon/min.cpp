#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<int> findMin(vector<int> &array, int k) {
		if (k >= array.size()) k = array.size();
		vector<int> ret;
		for (int i = 0; i<=k-array.size(); i++) {
			int minVal = INT_MAX;
			for (int j = i; j<i+k; j++) 
				minVal = min(minVal, array[j]);
			ret.push_back(minVal);
		}
		return ret;
	}
};
