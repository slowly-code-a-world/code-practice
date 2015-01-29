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

	vector<int> getMajor(vector<int>&array) {
		int ntimes[3] = {0}, candidates[3] = {0};
		for (int i = 0; i<array.size(); i++) {	
			bool found = false;
			for (int j = 0; j<3; j++) {
				if (ntimes[j] > 0 && candidate[j] == array[i]) {
					ntimes[j]++;
					found = true;
					break;
				}
			}
			if (found) continue;
			found = false;
			for (int j = 0; j<3; j++) {
				if (ntimes[j] == 0) {
					candidates[j] = array[i];
					ntimes[j] = 1;
					found = true;
					break;
				}
			}
			if (found) continue;
			for (int j = 0; j< 3; j++) ntimes[j] --;
		}
		return vector<int>(candidates, candidates + 3);
	}
};
