#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
	void rearrange(vector<int> &array) {
		if (array.size() <= 1) return;
		int cnt = count(array.begin(), array.end(), 0);
		if (cnt == 0) return;
		int zeropos = 0, valpos = 0;
		while (zeropos < array.size() && valpos < array.size()) {
			while (zeropos < array.size() && array[zeropos] != 0) 
				zeropos++;
			if (zeropos >= array.size()) return;
			if (valpos < zeropos) valpos = zeropos;
			while (valpos < array.size() && array[valpos] == 0)
				valpos++;
			if (valpos >= array.size()) return;
			swap(array[zeropos], array[valpos]); 
		}
	}
};

int main(void) {
	Solution S;
	vector<int> test = {1,0,2,0,3,0,0,4,5,6,7,0,0,0};
	S.rearrange(test);
	for (int i = 0; i<test.size(); i++)
		cout << test[i] << " ";
	cout << endl;
}
