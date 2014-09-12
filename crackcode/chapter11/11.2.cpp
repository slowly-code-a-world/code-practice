/*
11.2 Write a method to sort an array of strings so that all the anagrams are next to
    each other.
*/

#include <iostream>

class Solution {
public:
	void group(vector<string> &array) {
		if (array.size() <= 2) return;
		unordered_map<string, vector<string> > map;
		for (int i = 0; i<array.size(); i++) {
			string tmp = array[i];
			sort(tmp.begin(), tmp.end());
			map[tmp].push_back(array[i]);
		}
		
		int index = 0;
		for (auto it = map.begin(); it!=map.end(); it++) {
			for (int i = 0; i<it->second.size(); i++)
				array[index++] = it->second[i];
		}
	}	

	bool compare(string a, string b) {
		string tmpa = a, tmpb = b;
		sort(tmpa.begin(), tmpa.end());
		sort(tmpb.begin(), tmpb.end());
		return tmpa < tmpb;
	}
	void group_v2(vector<string> &array) {
		sort(array.begin(), array.end(), compare);
	}
};
