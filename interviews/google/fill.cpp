/*
You are given an array of integers 'a' that can fit in a memory. Write a method that retuns an array of the same lenght such that each element 'i' of this array is a sum of 'a' except the element a[i]. You are not allowed to use '-' operator.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<int> fillArray(vector<int>&array) {
		if (array.size() <= 1) return {};
		vector<int> ret(array.size(), 0);
		int sum = 0;
		for (int i = 1; i<array.size(); i++) {
			sum += array[i-1];
			ret[i] = sum;
		}
		sum = 0;
		for (int i = array.size()-2; i>=0; i--) {
			sum += array[i+1];
			ret[i] += sum;
		}
		return ret;
	}
};

int main(void) {
	Solution S;
	vector<int> test = {-10, 2, 3, 6, 5, 1};
	// expect {17, 5, 4, 1, 2, 6};
	vector<int> ret = S.fillArray(test);
	for (int i = 0; i<ret.size(); i++)
		cout << ret[i] << " ";
	cout << endl;		
}
