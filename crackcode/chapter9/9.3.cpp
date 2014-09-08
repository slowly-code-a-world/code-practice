/*
9.3
A magic index in an array A [ 0 . . .n-1] is defined to be an index such that A[i]
= i. Given a sorted array of distinct integers, write a method to find a magic
index, if one exists, in array A.
FOLLOW UP
What if the values are not distinct?
*/

#include <iostream>

class Solution {
public:
	int index(int A[], int n, int start) {
		if (start >= n) return -1;
		if (A[start] == start) return start;
		if (A[start] > start) return -1;
		return index(A, n, start + 1);
	}

	int index_v2(int A[], int n, int start) {
		if (start >= n) return -1;
		if (A[start] == start) return start;
		return index(A, n, start + 1);
	}

	int index_v3(int A[], int n, int start, int end) {
		if (start > end) return -1;
		if (start == end) return (A[start] == start)?start : -1;
		int mid = (start + end)/2;
		if (A[mid] == mid) return mid;
		else if (A[mid] < mid) return index_v3(A, n, mid+1, end);
		else return index_v3(A, n, start, mid-1);   
	}

	int index_v4(int A[], int n, int start, int end) {
		if (start > end) return -1;
		if (start == end) return A[start == start]? start: -1;
		int mid = (start + end)/2;
		if (A[mid] == mid) return mid;
		if (A[mid] > mid) return index_v4(A, n, mid+1, end);
		int tmp = index_v4(A, n, mid+1, end);
		if (-1 == tmp) return index_v4(A, n, start, min(mid-1, A[mid]));
	}
};
