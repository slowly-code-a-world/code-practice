#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	int getMajority(vector<int> &array) {
		int candidate = array[0], ntimes = 0;
		for (int i = 0; i<array.size(); i++) {
			if (ntimes == 0) {
				candidate = array[i];
				ntimes = 1;
			} else {
				if (array[i] == candidate)
					ntimes++;
				else ntimes--;
			}
		}
		return candidate;
	}
};
