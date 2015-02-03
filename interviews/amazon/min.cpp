/*
Given an array of size n, and an integer k. find minimum number in every subarray of size k
*/

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <climits>

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

	vector<int> findMinv2(vector<int> &array, int k) {
		if (k >= array.size()) k = array.size();
		vector<int> ret;
		deque<int> DQ;
		int i;
		for (i = 0; i<k; i++) {
			while (!DQ.empty() && array[i] < array[DQ.back()])
				DQ.pop_back();
			DQ.push_back(i);
		}			
		for (; i<array.size(); i++) {
			ret.push_back(array[DQ.front()]);
			while (!DQ.empty() && DQ.front() <= i - k)
				DQ.pop_front();
			while (!DQ.empty() && array[i] < array[DQ.back()])
				DQ.pop_back();
			DQ.push_back(i);	
		}
		ret.push_back(array[DQ.front()]);
		return ret;
	}
};

int main(void) {
	Solution S;
	vector<int> array = {12, 1, 78, 90, 57, 89, 56};
	vector<int> ret = S.findMinv2(array, 3);
	for (int i = 0; i<ret.size(); i++) 
		cout << ret[i] << " ";
	cout << endl;
}
