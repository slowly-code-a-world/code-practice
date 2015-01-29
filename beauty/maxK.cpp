/*
 *  2.5
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
class Solution {
public:
	vector<int> getMaxK(int K, vector<int>&array) {
		if (K > array.size()) return {};
		priority_queue<int> PQ;
		for (int i = 0; i<array.size(); i++) 
			PQ.push(array[i]);
		vector<int> ret;
		for (int i = 0; i<K; i++) {
			ret.push_back(PQ.top());
			PQ.pop();
		}
		return ret;
	}

	vector<int> getMinK(int K, vector<int>&array) {
		if (K > array.size()) return {};
		priority_queue<int, vector<int>, greater<int>> PQ;
		for (int i = 0; i<array.size(); i++)
			PQ.push(array[i]);
		vector<int> ret;
		for (int i = 0; i<K; i++) {
			ret.push_back(PQ.top());
			PQ.pop();
		}
		return ret;
	}	
};

int main(void) {
	Solution S;
	vector<int> test = {1, 5, 2, 4, 3};
	vector<int> maxArray = S.getMaxK(3, test);
	vector<int> minArray = S.getMinK(3, test);
	for (int i = 0; i<maxArray.size(); i++)
		cout << maxArray[i] << " ";
	cout << endl;
	for (int i = 0; i<minArray.size(); i++)
		cout << minArray[i] << " ";
	cout << endl;
}
