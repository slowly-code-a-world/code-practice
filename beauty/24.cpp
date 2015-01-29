/*
1.16
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	bool possible(vector<float>array) {
		if (array.size() == 2) {
			if (abs(abs(array[0] + array[1]) - 24) < 1e-5) return true;
			if (abs(abs(array[0] - array[1]) - 24) < 1e-5) return true;
			if (abs(abs(array[0] * array[1]) - 24) < 1e-5) return true;
			if (abs(abs(array[0]/array[1]) - 24) < 1e-5) return true;
			if (abs(abs(array[1]/array[0]) - 24) < 1e-5) return true;
			return false;
		}
		if (array.size == 3) {
			vector<float> tmp;
			tmp.push_back(array[2]);
			tmp.push_back(array[0] + array[1]);
			if (possible(tmp)) return true;
			tmp.pop_back();
			tmp.push_back(abs(array[0] - array[1]));
			if (possible(tmp)) return true;
			tmp.pop_back();
			tmp.push_back(array[0] * array[1]);
			if (possible(tmp)) return true;
			tmp.pop_back();
			tmp.push_back(array[0] / array[1]);
		}
	}
};
