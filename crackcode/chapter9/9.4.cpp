/*
9.4 Write a method to return all subsets of a set.
*/

#include <iostream>

class Solution {
public: 
	/*assume no dup elements*/	
	void find_all(vector<int> s) {
		vector<vector<int> > solution;	
		sort(s.begin(), s.end());
		generate(solution, s, s.size())	
	}	

	void generate(vector<vector<int> > &solution, vector<int> &s, int size) {
		if (0 == size) {
			vector<int> tmp;
			solution.push_back(tmp);
		} else {
			generate(solution, s, size - 1);
			for (int i = 0; i < solution.size(); i++) {
				vector<int> tmp = solution[i];
				tmp.insert(s[s.size() - 1]);
				solution.push_back(tmp);
			}
		}
	}

	vector<vector<int>> find_all_v2(vector<int> s) {
		vector<vector<int> > ret;
		if (0 == s.size()) return ret;
		if (1 == s.size()) {
			ret.push_back(s);
			vector<int> tmp;
			ret.push_back(tmp);
			return ret;
		}

		int size = s.size();
		int numbers = 1 << size;	
		vector<int> tmp; int t;
		for (int i = 0; i<numbers; i++) {
			tmp.clear();
			t = i;
			for (int j = 0; j<size; j++) {
				if (1 == t & 1) { 
					tmp.push_back(s[j]);
					t = t >> 1;
				}
			}
			ret.push_back(tmp);
		}
	}
};
