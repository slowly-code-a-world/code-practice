/*
given a vector of integers, v[i] represent the stock price on day i. Now you may do at most K transactions. you must sell your stock before you buy it again and that means you can NOT have two stocks at the same time. write a program to find max profit you can get.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	int getMax(vector<int> &prices, int start, int K) {
		if (K <= 0) return 0;
		if (start >= prices.size()) return 0;
		int ret = 0;
		if (K == 1) {
			int maxVal = prices[prices.size()-1];
			for (int i = prices.size()-1; i>=start; i--) {
				maxVal = max(maxVal, prices[i]);
				ret = max(ret, maxVal - prices[i]);
			}
			return ret;
		}
		for (int i = start+1; i<prices.size(); i++) {
			if (prices[i] <= prices[start]) continue;
			int tmp = getMax(prices, i+1, K-1);
			tmp += prices[start] - prices[i];
			ret = max(ret, tmp);
		}
		return ret;                         
	}		
};
