
Unique Paths
Total Accepted: 15277 Total Submissions: 49076

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

class Solution {
public:
    int uniquePaths(int m, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int C[101][101];
        int i,j;
        for (i = 0; i<101; i++) {
            C[0][i] = 0; C[1][i] = 1;
        }    
        for (i = 0; i<101; i++) {
            C[i][0] = 0; C[i][1] = 1;    
        }    
        for (i = 2; i < 101; i++) 
            for (j = 2; j< 101; j++)
                C[i][j] = C[i][j-1] + C[i-1][j];
        return C[m][n];
    }
};
