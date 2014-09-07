/*
9.8
Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5
cents) and pennies (1 cent), write code to calculate the number of ways of repre-
senting n cents.
*/

#include <iostream>

class Solution {
public:
	void get_all(vector<string> &ret, string &solution, int total) {
		if (0 == total) {
			ret.push_back(solution);
			return;
		}

		if (total >= 25) {
			solution.push_back('q');
			get_all(ret, solution, total - 25);
			solution.pop_back();
		}

		if (total >= 10) {
			solution.push_back('d');
			get_all(ret, solution, total - 10);
			solution.pop_back();
		}
		
		if (total >= 5) {
			solution.push_back('f');
			get_all(ret, solution, total - 5);
			solution.pop_back();
		}

		if (total >=1) {
			solution.push_back('o');
			get_all(ret, solution, total - 1);
			solution.pop_back();
		}

	}
	vector<string> ways(int n) {
		vector<string> ret;
		string solution;
		if (n <= 0) return ret;
		get_all(ret, solution, n);
		
		return ret;	
	}	
};
