/*
Find count of a number in sorted array
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	int findLeftPos(vector<int>&array, int start, int end, int target) {
		int middle = (start + end)/2;
		if (array[middle] == target) {
			if (middle > start) {
				if (array[middle - 1] < target) return middle;
				return findLeftPos(array, start, middle - 1, target);
			}
			return middle;
		}
		if (array[middle] > target) 
			return findLeft(array, start, middle-1, target);
		return findLeft(array, middle+1, end, target);
	}
	int getCnt(vector<int> &array, int number) {
		if (array.size() <= 0) return 0; 
		if (array.size() == 1) return array[0] == number? 1 : 0;
		int left = findLeftPos(array, 0, array.size()-1, number);
		int right = findRightPos(array, 0, array.size()-1, number);
		return right - left + 1;
	} 
};
