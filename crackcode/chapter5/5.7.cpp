/*
5.7 An array A contains all the integers from 0 to n, except for one number which is
   missing. In this problem, we cannot access an entire integer in A with a single
  operation. The elements of A are represented in binary, and the only operation
 we can use to access them is "fetch the jth bit of A[i]," which takes constant
time. Write code to find the missing integer. Can you do it in 0(n) time?
*/

#include <iostream>

class Solution {
public:
	int fetch(int j, int num) {
		return num & (1 << j);
	}

	int find_missing(vector& array, int n) {
		if (0 == n) return 0;
		int total = n*(n+1)/2;
		int sum = 0;
		for (int i = 0; i < array.size(); i++) {
			for (int j = 0; j < 31; j++) {
				if (fetch(j, array[i]) > 0)
					sum += 1 << j;
			}			
		}

		return total - sum;
	}
};
