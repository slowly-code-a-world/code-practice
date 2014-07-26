
Best Time to Buy and Sell Stock II
Total Accepted: 18167 Total Submissions: 49586

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (0 == prices.size() || 1 == prices.size()) return 0;
        int e = prices.size() - 1;
        int s = e;
        int sum = 0, val = 0;
        while (s > 0) {
            if (prices[s-1] <= prices[s]) {
                s --;
                val = prices[e] - prices[s];    
            } else {
                sum += val;
                val = 0;
                e = s - 1;
                s --;
            }
        }
        sum += val;
        return sum;
    }
};
