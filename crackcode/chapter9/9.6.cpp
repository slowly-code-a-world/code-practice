/*
9.6
Implement an algorithm to print all valid (e.g., properly opened and closed)
combinations of n-pairs of parentheses.
EXAMPLE
Input: 3
Output: ( ( ( ) ) ) , ( ( ) ( ) ) , ( ( ) ) ( ) , ( ) ( ( ) ) , ( ) ( ) ( )
*/

#include <iostream>

class Solution {
public:
	void get_all(vector<string>& ret, string &solution, int left, int right) {
		if (0 == left && 0 == right) {
			ret.push_back(solution);
			return;
		}

		if (0 == left) get_all(ret, solution + ')', 0, right-1);
		if (left > right) return;

		get_all(ret, solution + '(', left - 1, right);
		get_all(ret, solution + ')', left, right - 1);
	}

	vector<string> generate(int n) {
		vector<string> ret;
		if (0 == n) return ret;
		string solution;
		get_all(ret, solution, n, n);
		
		return ret;			
	}		
};
