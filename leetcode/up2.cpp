
Unique Paths II
Total Accepted: 11616 Total Submissions: 42004

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths is 2.

Note: m and n will be at most 100.

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        vector<vector<int> > fill = obstacleGrid;
        int row = fill.size();
        int col = fill[0].size();
        fill[row-1][col-1] = (1 == fill[row-1][col-1])? 0: 1;
        int i, j;
        for (i = 1; i<row; i++) 
            if (1 == fill[row-1-i][col-1])
                fill[row-1-i][col-1] = 0;
            else fill[row-1-i][col-1] = fill[row-i][col-1];
            
        for (i=1; i<col; i++)
            if (1 == fill[row-1][col-1-i])
                fill[row-1][col-1-i] = 0;
            else fill[row-1][col-1-i] = fill[row-1][col-i];
            
        for (i=1; i<row; i++) {
            for (j=1; j<col; j++) {
                if (1 == fill[row-1-i][col-1-j])
                    fill[row-1-i][col-1-j] = 0;
                else fill[row-1-i][col-1-j] = fill[row-i][col-1-j] + fill[row-1-i][col-j];    
            }
        }
        return fill[0][0];
            
    }
};
