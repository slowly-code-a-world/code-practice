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
};
