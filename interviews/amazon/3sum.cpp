#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>&array, int K) {
		vector<vector<int>> ret;
		if (array.size() < 3) return ret;
		sort(array.begin(), array.end());
		for (int i = 0; i<array.size()-2; i++) {
			int j = i+1, k = array.size()-1;
			if (i!=0 && array[i] == array[i-1]) continue;
			while (j < k) {
				if (array[j] + array[k] == K - array[i]) {
					vector<int> tmp;
					tmp.push_back(array[i]);
					tmp.push_back(array[j]);
					tmp.push_back(array[k]);
					ret.push_back(tmp);
					j++;
					while (j < k && array[j] == array[j-1]) j++;
					k--;
					while (j < k && array[k] == array[k+1]) k--;
				} else if (array[j] + array[k] > K - array[i])
					k--;
				else j++;
			}
		}
		return ret;
	}
};
