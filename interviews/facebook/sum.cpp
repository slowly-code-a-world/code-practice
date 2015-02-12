/*
You have an array of n elements, and a sum. Check if any 2 elements in the array sum to the given sum. ( Expected time complexity O(n). Use hashing)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	bool twoSum(vector<int>&array, int value) {
		if (array.size() <= 1) return false;
		unordered_map<int, int> record;
		for (int i = 0; i<array.size(); i++) 
			record[array[i]] ++;
		for (int i = 0; i<array.size()-1; i++) {
			if (value - array[i] != array[i] && record[value-array[i]])
				return true;
			if (value - array[i] == array[i] && record[array[i]] >= 2) 
				return true;
		}
		return false;
	}

	bool threeSum(vector<int>&array, int value) {
		if (array.size() <= 2) return false;
		unordered_map<int, int> record;
		for (int i = 0; i<array.size(); i++)
			record[array[i]] ++;
		for (int i = 0; i<array.size()-2; i++) {
		for (int j = i+1; j<array.size()-1; j++) {
			int left = value - array[i] - array[j];
			if (record[left] {
				if (array[i] != array[j]) {
					if (left != array[i] && left != array[j]) 
						return true;
					if (left == array[i] && record[array[i]] >= 2)
						return true;
					if (left == array[j] && record[array[j]] >= 2)
						return true;
				} else {
					if (left != array[i]) return true;
					if (record[left] >= 3) return true;
				}
			}
		}}
		return false;
	}
};
