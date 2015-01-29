/*
1.3 for programing beauty 
*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <map>
using namespace std;

class Solution {
private:
	vector<int> array;
public:
	bool isSorted(vector<int>&array) {
		if (array.size() <= 1) return true;
		for (int i = 1; i<array.size(); i++) {
			if (array[i] < array[i-1]) return false;
		}
		return true;
	}
	void reverse(vector<int>&array, int start, int end) {
		while (start < end) {
			swap(array[start], array[end]);
			start++;
			end--;
		}
	}
	int realGet(vector<int>&array, map<vector<int>, int>&record, int steps, int limit) {
		if (isSorted(array)) return 0;
		if (record.find(array) != record.end()) return record[array];
		if (steps > limit) return INT_MAX;
		int ret = INT_MAX;
		for (int i = 1; i<array.size(); i++) {
			reverse(array, 0, i);
			int tmp = realGet(array, record, steps + 1, limit);
			if (tmp != INT_MAX) 
				ret = min(1 + tmp, ret);
			reverse(array, 0, i);
		}
		if (ret != INT_MAX) record[array] = ret;
		return ret;
	}
	int getCnt(vector<int> &array) {
		if (array.size() <= 1) return 0;
		map<vector<int>, int> record;
		int ret = realGet(array, record, 0, 2*(array.size()-1));
		return ret;
	}
	
	Solution(int size) {
		srand(time(0));
		for (int i = 0; i<size; i++) 
			array.push_back(rand()%10);
		print(array);
		cout << getCnt(array) << endl;
	}
	Solution() = default;
	void print(vector<int>&array) {
		for (int i = 0; i<array.size(); i++)
			cout << array[i] << " ";
		cout << endl;
	}
};

int main(void) {
	Solution S(5);
}
