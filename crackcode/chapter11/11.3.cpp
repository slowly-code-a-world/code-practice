/*
11.3 Given a sorted array of n integers that has been rotated an unknown number of
    times, write code to find an element in the array. You may assume that the array
   was originally sorted in increasing order.
EXAMPLE
Input: find 5 in {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14}
Output: 8 (the index of 5 in the array)
*/

#include <iostream>

class Solution {
public:
	int real_search(vector<int> &rotated, int num, int left, int right) {
		if (left > right) return -1;
		if (left == right) return (rotated[left] == num)? left : -1;
		int mid = (left + right)/2;
		if (A[mid] == num) return mid;
		if (A[mid] > num) {
			if (A[mid] > A[0]) {
				int tmp = real_search(rotated, num, left, mid - 1);
				if (-1 == tmp) 
					return real_search(rotated, num, mid+1, right);
			} else return real_search(rotated, num, mid+1, right);
		}
	
		if (A[mid] > A[0]) 
			return real_search(rotated, num, mid+1, right);
		int tmp = real_search(rotated, num, left, mid-1);
		if (-1 == tmp) return real_search(rotated, num, mid+1, right);	
	}	
	int search(vector<int> &rotated, int num) {
		if (0 == rotated.size()) return -1;
		if (1 == rotated.size()) return (rotated[0] == num)? 0 : -1;
		return real_search(rotated, num, 0, rotated.size() - 1);
	}
};
