/*
You are given the start time and finish time of n intervals. You have to write a a function that returns boolean value indicating if there was any overlapping interval in the set of existing intervals. (Sort and check, time complexity O(nlogn))
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool hasOverlap(vector<int> start, vector<int> end) {
		vector<pair<int, int>> record;
		for (int i = 0; i<start.size(); i++) {
			pair<int, int> tmp(start[i], end[i]);
			record.push_back(tmp);
		}
		sort(record.begin(), record.end());
		for (int i = 1; i<record.size(); i++) {
			if (record[i].first <= record[i-1].second)
				return true;
		}
		return false;
	}
};
