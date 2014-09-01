/*
7.7
Design an algorithm to find the kth number such that the only prime factors are
3,5, and 7.
*/

#include <iostream>

class Solution {
public:
	int find_kth(int k) {
		if (k <= 0) {
			std::cout << "ERROR" << std::endl;
			return -1;
		}

		if (1 == k) return 3*5*7;
		int cnt = 1; int start = 3*5*7;
		while (cnt < k) {
			start ++;
			if (0 == start % 3*5*7) {
				int left = start / (3*5*7);
				while (0 == left % 3) 
					left /= 3;
				if (1 == left) { 
					cnt ++;
					continue;
				}

				while (0 == left % 5)
					left /= 5;
				if (1 == left) {
					cnt ++;
					continue;
				}

				while (0 == left % 7)
					left /= 7;
				if (1 == left) {
					cnt ++;
					continue;
				}
			}
		}
		return start;		
	}	
};
