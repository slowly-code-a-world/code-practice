#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
	vector<float> generate(vector<int>&array, int size) {
		queue<int> window
		vector<float> ret;
		int sum = 0;
		for (int i = 0; i<array.size(); i++) {
			if (window.size() < size) {
				window.push(array[i]);
				ret.push_back(array[i]);
				sum += array[i];
			} else {
				sum += array[i] - window.front();
				window.pop();
				window.push(array[i]);
				ret.push_back(sum / window.size());
			}
		}
		return ret;
	}
};
