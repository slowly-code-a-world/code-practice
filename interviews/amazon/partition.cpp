#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;
class Solution {
public:
	int partition2(vector<int>&array, int s, int e) {
		int start = s + 1;
		int end = e;
		while(start < end) {
			while (start < end && array[start] <= array[s]) start++;
			if (start >= end) break;
			while (start < end && array[end] > array[s]) end--;
			if (start >= end) break;
			swap(array[start], array[end]);
		}
		end = e;
		while (array[end] > array[s]) end--;
		if (end == s || array[s] == array[end]) return end;
		swap(array[s], array[end]);
		return end;
	}
	int partition(vector<int>&array, int s, int e) {
		srand(time(0));
		int index = s + rand()%(e - s + 1);
		assert(index >= s && index <= e);
		int val = array[index];
		swap(array[index], array[e]);
		int pos = s;
		for (int i = s; i <= e - 1; i++) {
			if (array[i] <= val) {
				swap(array[i], array[pos]);
				pos++;
			}
		}
		swap(array[pos], array[e]);
		return pos;
	}
	void print(vector<int>&array) {
		for (int i = 0; i<array.size(); i++)
			cout << array[i] << " ";
		cout << endl;
	}
	int realFind(vector<int>&array, int s, int e, int k) {
		int index = partition(array, s, e);
		print(array);
		if (index - s == k) return array[index];
		if (index - s > k) return realFind(array, s, index - 1, k);
		return realFind(array, index + 1, e, k - (index - s + 1));
	}
	int kthmin(vector<int> &array, int k) {
		if (k >= array.size() || k < 1) return -1; 
		return realFind(array, 0, array.size()-1, k-1);
	}
};

int main(void) {
	Solution test;
	vector<int> t = {7, 10, 4, 3, 20, 15};
	int ret = test.kthmin(t, 3);
	cout << ret << endl;
}
