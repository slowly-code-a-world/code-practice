#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<int>getOne(vector<int>&array) {
		int size = array.size();
		if (0 == size) return {};
		vector<int> sumRes(size, 0);
		int sum = 0;
		for (int i = 0; i<array.size(); i++) {
			if (array[i] == 1) return {1};
			sum += array[i];
			sumRes[i] = sum;
			if (sumRes[i] == 1) 
				return vector<int>(array.begin(), array.begin() + i + 1);
		}
		for (int i = 0; i<array.size()-1; i++) {
		for (int j = i+1; j<array.size(); j++) {
			if (sumRes[j] - sumRes[i] == 1) 
				return vector<int>(array.begin()+i+1, array.begin()+j+1);
		}}
		return {};
	}
};

int main(void) {
	Solution S;
	vector<int> test = {4, 3, 5, -3, -1, 2, -3, 10, 2};
	vector<int> ret = S.getOne(test);
	if (ret.size() > 0) {
		for (int i = 0; i<ret.size(); i++)
			cout << ret[i] << " ";
		cout << endl;
	}
	return 0;
}
