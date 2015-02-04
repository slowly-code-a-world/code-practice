/*
Count Inversions in an array
Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
Example:
The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
	int realGet(vector<int>&array, int start, int end) {
		if (start >= end) return 0;
		int middle = (start + end)/2;
		int ret = 0;
		ret += realGet(array, start, middle);
		ret += realGet(array, middle+1, end);
		vector<int> tmp(end - start + 1, 0);
		int index1 = start, index2 = middle + 1;
		int pos = 0;
		while (index1 <= middle && index2 <= end) {
			if (array[index1] <= array[index2]) {
				tmp[pos++] = array[index1++];
			} else {
				tmp[pos++] = array[index2++];
				ret += middle - index1 + 1;
			}
		}
		while (index1 <= middle) {
			tmp[pos++] = array[index1++];
		}
		for (int i = 0; i<pos; i++) 
			array[start + i] = tmp[i];
		return ret;
	}

	int getReverseCount(vector<int> &array) {
		if (array.size() <= 1) return 0;
		return realGet(array, 0, array.size()-1);
	}
};

int main(void) {
	Solution S;
	vector<int> test = {2, 4, 1, 3, 5};
	cout << S.getReverseCount(test) << endl;
	for (int i = 0; i<test.size(); i++)
		cout << test[i] << " ";
	cout << endl;
}
