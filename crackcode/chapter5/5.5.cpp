/*
5.5
Write a function to determine the number of bits required to convert integer A
to integer B.
EXAMPLE
Input: 31,14
Output: 2
*/

#include <iostream>

class Solution {
public:
	int bits(int A, int B) {
		int C = A ^ B;
		int cnt = 0;
		for (int i = 0; i < 32; i++)
			if ((C & (1 << i)) > 0) cnt ++;

		return cnt;
	}
		
	int bits_v2(int A, int B) {
		int cnt = 0;
		for (int C = A^B; C!=0; C = C >> 1) {
			cnt += C & 1;
		}

		return cnt;
	}		

	int bits_v3(int A, int B) {
		int cnt = 0;
		for (int C = A^B; C!=0; C = C & (C-1)) {
			cnt++;
		}

		return cnt;
	}
};
