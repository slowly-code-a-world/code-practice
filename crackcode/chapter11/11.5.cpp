/*
11.5
Given a sorted array of strings which is interspersed with empty strings, write a method to find the location of a given string.
*/

#include <iostream>

class Solution {
public:
	int get(vector<string> &array, string &target, int left, int right) {
		if (left > right) return;
		if (left == right) return (array[left] == target)? left : -1;
		int middle = (left + right)/2;
		if (array[middle] == target) return middle;
		if (array[middle] == "") {
			int mid1 = middle;
			while (mid1>=left && array[mid1] == "") mid1--;
			int mid2 = middle;
			while (mid2<=right && array[mid2] == "") mid2++;
			if (array[mid1] < left) return get(array, target, mid2, right);
			if (array[mid1] == target) return mid1;
			if (array[mid1] < target) return get(array, target, mid2, right);
			return get(array, target, left, mid1);
		}
		if (array[middle] > target) return get(array, target, left, middle - 1);
		return get(array, target, middle+1, right);
	}
	int get_index(vector<string>& array, string &target) {
		if (0 == array.size()) return -1;
		if ("" == target) return -1;
		return get(array, target, 0, array.size()-1);
	}	
};
