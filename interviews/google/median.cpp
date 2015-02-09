/*
Median of stream of numbers
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
class Solution {
public:
	void insert(priority_queue<int> &first, priority_queue<int, vector<int>, greater<int>>&second, int odd, int elem) {
		if (first.empty()) {
			first.push(elem);
			return;
		}
		if (elem <= first.top()) {
			if (odd % 2 == 0) first.push(elem);
			else {
				first.push(elem);
				int top = first.top();
				first.pop();
				second.push(top);
			}
		} else {
			if (odd % 2 == 0) {
				second.push(elem);
				int top = second.top();
				second.pop();
				first.push(top);
			} else second.push(elem);
		}
	}
	vector<int> getMedian(vector<int>&array) {
		priority_queue<int> firstHalf;
		priority_queue<int, vector<int>, greater<int>> secondHalf;
		vector<int> ret;
		for (int i = 0; i<array.size(); i++) {
			insert(firstHalf, secondHalf, i, array[i]);
			if (i % 2 == 0) ret.push_back(firstHalf.top());
			else {
				int median = (firstHalf.top() + secondHalf.top())/2;
				ret.push_back(median);
			}
		}	
		return ret;
	}
};

int main(void) {
	Solution S;
	vector<int> test = {8, 10, 4, 2, 6, 18};
	vector<int> ret = S.getMedian(test);
	for (int i = 0; i<ret.size(); i++)
		cout << ret[i] << " ";
	cout << endl;
}
