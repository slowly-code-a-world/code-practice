/*
9.8
Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5
cents) and pennies (1 cent), write code to calculate the number of ways of repre-
senting n cents.
*/

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
class Solution {
public:
	void get_all(set<string> &ret, string &solution, int total, int max) {
		if (0 == total) {
			string tmp = solution;
			sort(tmp.begin(), tmp.end());
			if (ret.find(tmp)!=ret.end())
				cout << "dup" << endl;
			else ret.insert(tmp);
			return;
		}

		if (total >= 25 && max >= 25) {
			solution.push_back('Q');
			get_all(ret, solution, total - 25, 25);
			solution.pop_back();
		}

		if (total >= 10 && max >= 10) {
			solution.push_back('D');
			get_all(ret, solution, total - 10, 10);
			solution.pop_back();
		}
		
		if (total >= 5 && max >= 5) {
			solution.push_back('N');
			get_all(ret, solution, total - 5, 5);
			solution.pop_back();
		}

		if (total >=1 && max >= 1) {
			solution.push_back('P');
			get_all(ret, solution, total - 1, 1);
			solution.pop_back();
		}

	}
	set<string> ways(int n, int max) {
		set<string> ret;
		string solution; 
		solution.clear();
		if (n <= 0) return ret;
		get_all(ret, solution, n, max);
		
		return ret;	
	}

	int ways_v2(int n, int denom) {
		int next_denom = 0;
		switch(denom) {
		case 25:
			next_denom = 10;
			break;
		case 10:
			next_denom = 5;
			break;
		case 5:
			next_denom = 1;
			break;
		case 1:
			return 1;	
		}

		int ways = 0;
		for (int i = 0; i*denom <= n; i++) {
			ways += ways_v2(n - i*denom, next_denom);
		}	
		return ways;
	}	
};

int main(void) {
	Solution S;
	set<string> ret;
	ret = S.ways(25, 25);

	set<string>::iterator it;
	for(it = ret.begin(); it != ret.end(); it++) 
		cout << *it << endl;
		
	cout << ret.size() << endl;
	cout << S.ways_v2(25, 25) << endl;
	return 0;
}	
