/*
9.5
Write a method to compute all permutations of a string.
*/

#include <iostream>

class Solution {
public:
	void get_all(vector<string> &ret, string solution, string &s, int size, vector<bool> &visited) {
		if (solution.size() == s.size()) {
			ret.push_back(solution);
			return;
		}

		for (int i = 0; i<s.size(); i++) {
			if (0 == visited[i]) {
				if (i > 0 && s[i] == s[i-1] && false == visited[i-1])
					continue;
				visited[i] = true;
				solution += s[i];
				get_all(ret, solution, s, size, visited);
				solution.pop_back();
				visited[i] = false;
			}
		}
	}
	vector<string> permutations(string s) {
		if (0 == s.size()) return;
		sort(s.begin(), s.end());
		vector<string> ret;
		string solution
		vector<bool> visited(s.size(), false);
		get_all(ret, solution, s, s.size(), visited);
	
		return ret;	
	}
};
