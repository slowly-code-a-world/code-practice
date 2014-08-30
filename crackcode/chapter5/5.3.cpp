/*
5.3 Given a positive integer, print the next smallest and the next largest number
   that have the same number of 1 bits in their binary representation
*/

#include <iostream>

class Solution {
public:
	int get_min(int bits) {
		int ret = 0;
		for (int i = 0; i < bits; i++) {
			ret |= (1 << i);
		}

		return ret;		
	}

	int get_max(int bits) {
		int ret = 0;
		for (int i = 0; i < bits; i++) {
			ret |= (1 << (i + 31 - bits));
		}

		return ret;
	}

	int get_bits(int number) {
		int cnt = 0;
		for (int i = 0; i < 31; i++) {
			if ((number & (1 << i)) > 0)
				cnt ++;
		}
		
		return cnt;
	}	
};
