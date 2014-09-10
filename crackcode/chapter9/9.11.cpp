/*
9.11 Given a boolean expression consisting of the symbols 0,1, &, |, and A, and a
    desired boolean result value result, implement a function to count the number
   of ways of parenthesizing the expression such that it evaluates to result.
EXAMPLE
Expression: 1 A 01011
Desired result: false (0)
Output: 2 ways. 1A( (010) 11) and 1 A (91 (011)).
*/

#include <iostream>

class Solution {
public:
	int count(string exp, bool result, int s, int e, vector<vector<vector<int>> > map) {
		if (s == e) {
			if ('1' == exp[s] && result) return 1;
			if ('0' == exp[s] && false == result) return 1;
			return 0;
		}

		if (-1 != map[s][e][result?1:0]) return map[s][e][result?1:0]; 

		int c = 0;
		if (result) {
			for (int i = s + 1; i < e; i = i+2) {
				char op = exp[i];
				if ('&' == op) 
					c+=count(exp, true, s, i-1)*count(exp, true, i+1, e);
				else if ('|' == op){
					c+=count(exp, true, s, i-1)*count(exp, true, i+1, e);
					c+=count(exp, true, s, i-1)*count(exp, false, i+1, e);
					c+=count(exp, false, s, i-1)*count(exp, true, i+1, e);
				} else if ('^' == op) {
					c+=count(exp, true, s, i-1)*count(exp, false, i+1, e);
					c+=count(exp, false, s, i-1)*count(exp, true, i+1, e);
				}
			}
			map[s][e][1] = c;			
		} else {
			for (int i = s+1; i<e; i+=2) {
				char op = exp[i];
				if ('&' == op) {
					c+=count(exp, false, s, i-1)*count(exp, true, i+1, e);
					c+=count(exp, false, s, i-1)*count(exp, false, i+1, e);
					c+=count(exp, true, s, i-1)*count(exp, false, i+1, e);
				} else if ('|' == op) 
					c+=count(exp, false, s, i-1)*count(exp, false, i+1, e);
				else if ('^' == op) {
					c+=count(exp, false, s, i-1)*count(exp, false, i+1, e);
					c+=count(exp, true, s, i-1)*count(exp, true, i+1, e);
				}		
			}
			map[s][e][0] = c;
		}
				
		return c;
	}	
};
