#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	void reverse(vector<int> &array, int k) {
		int size = array.size();
		k = k % size;
		if (k == 0) return;
		realReverse(array, 0, size-1);
		realReverse(array, 0, k-1);
		realReverse(array, k, size-1);
	}
	void realReverse(vector<int>&array, int start, int end) {
		if (start == end) return;
		while (start < end) {
			swap(array[start], array[end]);
			start++;
			end--;
		}
	}
};

int main(void) {
	Solution S;
	vector<int> test = {1, 2, 3, 4, 5};
	// expected 45123
	S.reverse(test, 2);
	for (int i = 0; i<test.size(); i++)
		cout << test[i] << " ";
	cout << endl;
}
