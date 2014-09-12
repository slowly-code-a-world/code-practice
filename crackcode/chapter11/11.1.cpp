/*
11.1 You are given two sorted arrays, A and B, where A has a large enough buffer at
    the end to hold B. Write a method to merge B into A in sorted order.
*/

#include <iostream>

class Solution {
public:
	void merge(vector<int> &A, vector<int> &B) {
		if (0 == B.size()) return;
		int i = A.size() - 1;
		A.push_back(B);
		int j = B.size() - 1;
		int current = A.size() - 1;
		for (;;) {
			if (A[i] > B[j]) {
				A[current] = A[i];
				i--; current--;	
			} else {
				A[current] = B[j];
				j--; current--;
			}
			if (i < 0 || j < 0) break;
		}

		while (j>=0) {
			A[current] = B[j];
			current--; j--;
		}
	}
};
