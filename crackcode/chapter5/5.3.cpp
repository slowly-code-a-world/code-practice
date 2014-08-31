/*
5.3 Given a positive integer, print the next smallest and the next largest number
   that have the same number of 1 bits in their binary representation
*/

#include <iostream>

class Solution {
public:
	int get_min(int bits, number) {
		int ret = 0;
		for (int i = 0; i < bits; i++) {
			ret |= (1 << i);
		}

		if (ret == number) {
			std::cout << "no such min number" << endl;
			return 0; 
		}

		int tmp = number - 1;
		while (bits != get_bits(tmp))	
			tmp--;

		return tmp;	
	}

	int get_max(int bits, int number) {
		int ret = 0;
		for (int i = 0; i < bits; i++) {
			ret |= (1 << (i + 31 - bits));
		}

		if (ret == number) {
			std::cout << "no such max number" << endl;
			return 0;
		}

		int tmp = number + 1;
		while (bits != get_bits(tmp))
			tmp ++;

		return tmp;
	}

	int get_bits(int number) {
		int cnt = 0;
		while (number > 0) {
			int tmp = number & 1;	
			if (tmp > 0) cnt++;
			number = number >> 1;
		}
		
		return cnt;
	}

	int get_max_v2(int number) {
		int tmp = number;
		int c0 = 0, c1 = 0;
		while ((0 == tmp & 1) && (tmp != 0)) {
			c0 ++;
			tmp = tmp >> 1; 
		}
		
		while (1 == tmp & 1) {
			c1 ++;
			tmp = tmp >> 1;
		}	

		if (c0 + c1 == 31 || c0 + c1 == 0) {
			std::cout << "ERROR" << std::endl;
			return 0;
		}	

		number = number & (1 << (c0 + c1));
		number = number | (1 << (c0 + c1));
		number = number | ((1 << (c1 - 1)) - 1);

		return number;
	}

	int get_min_v2(int number) {
		int tmp = number;
		int c1 = 0, c0 = 0;
		
		while (1 == tmp & 1) {
			c1 ++;
			tmp = tmp >> 1;
		}

		if (0 == tmp) {
			std::cout << "ERROR" << std::endl;
			return 0;
		}	

		while (0 == tmp & 1) {
			c0 ++;
			tmp = tmp >> 1;
		}

		number = number & (1 << (c0 + c1 + 1));
		number = number | ((1 << (c0 + c1 + 1)) - 1);
		number = number & (1 << c0);

		return number;
	}	
};
