/*
11.8
Imagine you are reading in a stream of integers. Periodically, you wish to be able
to look up the rank of a number x (the number of values less than or equal tox).
Implement the data structures and algorithms to support these operations.That
is, implement the method track(int x), which is called when each number
is generated, and the method getRankOfNumber(int x), which returns the
number of values less than or equal to x (not including x itself).
EXAMPLE
Stream (in order of appearance): 5, 1
, 4, 4, 5, 9, 7, 13, 3
getRankOfNumber(l) = 0
getRankOfNumber(3) = 1
getRankOfNumber(4) = 3
*/

#include <iostream>

class Solution {
public:
	void track(vector<int>& array, int x) {
		array.push_back(x);
	}

	int getRankOfNumber(vector<int>& array, int x) {
		if (0 == array.size()) return -1;
		if (1 == array.size() && array[0] == x) return 0;
		if (1 == array.size() && array[0] != x) return -1;
		sort(array.begin(), array.end());
		for (int i = 0; i<array.size(); i++) {
			if (array[i] > x) {
				if (array[i-1] == x) return i-1;
				return -1;
			}
		}
		return -1;	
	}	
};
