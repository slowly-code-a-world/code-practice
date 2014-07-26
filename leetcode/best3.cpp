
Best Time to Buy and Sell Stock III
Total Accepted: 11740 Total Submissions: 53173

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if (0 == len || 1 == len) return 0;
        int *forward = new int[len];
        int *back = new int[len];
        forward[0] = 0;
        int min = prices[0];
        for (int i = 1; i< len; i++) {
            if (prices[i] - min > forward[i-1]) {
                forward[i] = prices[i] - min;
            } else forward[i] = forward[i-1];
            if (prices[i] < min) min = prices[i];
        }
        back[len - 1] = 0;
        int max = prices[len-1];
        for (int i = 1; i < len; i++) {
            if (max - prices[len-1-i] > back[len -i]) {
                back[len-1-i] = max - prices[len-1-i];
            } else back[len-1-i] = back[len-i];
            if (prices[len-1-i] > max) max = prices[len-1-i];
        }
        int sum = forward[0] + back[0];
        for (int i = 1; i<len; i++) {
            if (forward[i] + back[i] > sum)
                sum = forward[i] + back[i];
        }    
        return sum;
    }
};
