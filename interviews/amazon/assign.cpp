/*
Given an unsorted array, assign every element to its immediate larger number after the current number, assign to -1 if no such number exists
Eg. 3 1 2 5 9 4 8 should be converted to
5 2 5 9 -1 8 -1

*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
class Solution {
public:
	vector<int> assign(vector<int>&array) {
		vector<int> ret(array.size(), -1);
		if (array.size() == 0) return {};
		if (array.size() == 1) return ret;
		int size = array.size();
		for (int i = 0; i<size-1; i++) {
			int tmp = array[i];
			for (int j = i+1; j<size; j++) 
				tmp = max(tmp, array[j]);
			if (tmp != array[i])
				ret[i] = tmp;
		}
		return ret;
	}

	vector<int> assignv2(vector<int> &array) {
		vector<int> ret(array.size(), -1);
		if (array.size() == 0) return {};
		if (array.size() == 1) return ret;
		int size = array.size();
		stack<int> S;
		S.push(0);
		for (int i = 1; i<array.size(); i++) {
			int top = S.top();
			if (array[i] <= array[top])
				S.push(i);
			else {
				while (!S.empty() && array[i] > array[top]) {
					ret[top] = array[i];
					S.pop();
					if (!S.empty()) top = S.top();
				}
				S.push(i);
			}
		}
		return ret;
	}
};

int main(void) {
	Solution S;
	vector<int> test = {3, 1, 2, 5, 9, 4, 8};
	vector<int> ret = S.assignv2(test);
	for (int i = 0; i<ret.size(); i++) 
		cout << ret[i] << " ";
	cout << endl;
}
