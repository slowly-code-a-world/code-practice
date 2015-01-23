/*
Given a sorted integer array where the range of elements are [0, 99] inclusive, return its missing ranges.
For example, given [0, 1, 3, 50, 75], return [“2”, “4->49”, “51->74”, “76->99”]
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<pair<int, int>> missRange(vector<int> &array) {
		vector<pair<int, int>> ret;
		if (array.size() == 0) {
			ret.push_back(make_pair(0, 99));
			return ret;
		}	
		int start = 0;  
		for (int i = 0; i<array.size(); i++) {
			if (array[i] == start) 
				start++;
			if (array[i] - start == 1) {
				ret.push_back(make_pair(start, start));
				start = array[i] + 1;
				if (start > 99) break;
			} else {
				ret.push_back(make_pair(start, array[i]-1))
				start = array[i] + 1;
				if (start > 99) break;
			}
		}
		if (start <= 99) 
			ret.push_back(make_pair(start, 99));
		return ret;
	}
};
