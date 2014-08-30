/*
5.1
You are given two 32-bit numbers, N and M, and two bit positions, land j. Write
a method to insert M into N such that M starts at bit j and ends at bit i. You can
assume that the bits j through i have enough space to fit all of M. That is, if
M = 10011, you can assume that there are at least 5 bits between j and i. You
would not, for example, have j = 3 and i = 2, because M could not fully fit
between bit 3 and bit 2.
EXAMPLE
Input: N = 10000000000, M = 10011, i = 2, j = 6
Output: N = 10001001100 */

// what happens when M can fit into N, but j-i+1 > M.length? assume it will not 
// affect other bits
#include <iostream>

class Solution {
public:
	void insert(int &N, int &M, int i, int j) {
		if (i > j) return;
		for (int k = 0; k < j - i + 1; k ++) {
			int tmp = M & (1 << k);
			N = N & (~(1 << (k + i)));
			if (tmp > 0) 
				N = N & (1 << (k + i));
		}
	}	
};
