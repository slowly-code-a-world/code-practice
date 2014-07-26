
Minimum Path Sum
Total Accepted: 13451 Total Submissions: 43382

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

class Solution {
public:
    /*
    int minPathSumDetail(vector<vector<int> >&grid, int row, int col) {
        if (0 == grid.size()) return 0;
        if (row == grid.size()-1) {
            int sum = 0;
            for (int i = col; i < grid[row].size(); i++)
                sum+=grid[row][i];
            return sum;    
        } 
        if (col == grid[row].size()-1) {
            int sum = 0;    
            for (int i = row; i<grid.size(); i++)
                sum+=grid[i][col];
            return sum;    
        }
        int part1 = minPathSumDetail(grid, row+1, col) + grid[row][col];
        int part2 = minPathSumDetail(grid, row, col+1) + grid[row][col];
        if (part1 < part2) return part1;
        return part2;
    }
    int minPathSum(vector<vector<int> > &grid) {
        return minPathSumDetail(grid, 0, 0);
    }
    */
    int minPathSum(vector<vector<int> > &grid) {
        if (0 == grid.size()) return 0;
        vector<vector<int> > fill = grid;
        int row = grid.size();
        int col = grid[0].size();
        int sum = 0;
        if (1 == row) {
            for (int i = 0; i<col; i++)
                sum += fill[0][i];
            return sum;    
        } 
        if (1 == col) {
            for (int i = 0; i<row; i++)
                sum+= fill[i][0];
            return sum;    
        }
        for (int i = 0; i<col; i++) {
            sum += fill[row-1][col-1-i];
            fill[row-1][col-1-i] = sum;
        }   
        sum = 0;    
        for (int i = 0; i< row; i++) {
            sum+= fill[row-1-i][col-1];
            fill[row-1-i][col-1] = sum;
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j<col; j++) {
                fill[row-1-i][col-1-j] = (fill[row-i][col-1-j] > fill[row-1-i][col-j]) ? fill[row-1-i][col-1-j] + fill[row-1-i][col-j]: fill[row-1-i][col-1-j] + fill[row-i][col-1-j];
            }
        }
        return fill[0][0];
    }
};
