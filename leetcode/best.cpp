
Best Time to Buy and Sell Stock
Total Accepted: 18306 Total Submissions: 59025

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (0 == prices.size() || 1 == prices.size())
            return 0;
        
        int len = prices.size();
        /*
        int **record = new int*[len];
        for (int i = 0; i< len; i++)
            record[i] = new int[2];
        */
        int record[100000][2];
        record[0][0] = 0; // max profit  
        record[0][1] = prices[0];  // min value  
        if (prices[1] <= prices[0]) {
            record[1][0] = 0;
            record[1][1] = prices[1];
        } else {
            record[1][0] = prices[1] - prices[0];
            record[1][1] = prices[0];
        }    
        
        for (int i = 2; i< len; i++) {
            if (prices[i] - record[i-1][1] <= record[i-1][0]) 
                record[i][0] = record[i-1][0];
            else 
                record[i][0] = prices[i] - record[i-1][1];
            
            if (record[i-1][1] < prices[i])
                record[i][1] = record[i-1][1];
            else
                record[i][1] = prices[i];
        } 
        
        int tmp = record[len-1][0];
        /*
        for (int i = 0; i<len; i++)
            delete [] record[i];
        delete[] record;    
        */
        return tmp;
    }    
};
