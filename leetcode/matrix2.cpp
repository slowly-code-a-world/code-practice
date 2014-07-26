
Spiral Matrix II
Total Accepted: 10819 Total Submissions: 35330

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:

[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret;
        for (int i = 0; i<n; i++) {
            vector<int> tmp(n, 0);
            ret.push_back(tmp);
        }
        int fill = 0;
        int row = 0, col = 0, token = 0;
        while (fill < n*n) {
            fill++;
            ret[row][col] = fill;
            if (0 == token) {
                if (n-1 == col || 0 != ret[row][col+1]) {
                    row++;
                    token = (1 + token)%4;
                } else col++;
            } else if (1 == token) {
                if (n-1 == row || 0 != ret[row+1][col]) {
                    col--;
                    token = (1 + token)%4;
                } else row++;
            } else if (2 == token) {
                if (0 == col || 0 != ret[row][col-1]) {
                    row --;
                    token = (1 + token)%4;
                } else col--;
            } else {
                if (0 == row || 0 != ret[row-1][col]) {
                    col++;
                    token = (1 + token)%4;
                } else row--;
            }
        }
        return ret;
    }
};
