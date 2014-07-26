
Spiral Matrix
Total Accepted: 10757 Total Submissions: 52413

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5]. 

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        if (0 == matrix.size()) 
            return ret;
        
        int m = matrix.size(), n = matrix[0].size();
        int row = 0, col = 0, token = 0, elements = 0;
        vector<vector<int> > visited;
        for (int i = 0; i<m; i++) {
            vector<int> tmp(n, 0);
            visited.push_back(tmp);
        }
        while (elements < m*n) {
            elements++;
            ret.push_back(matrix[row][col]);
            visited[row][col] = 1;
            if (0 == token) {
                if (n-1 == col || 0 != visited[row][col+1]) {
                    row++;
                    token = (1 + token)%4;
                } else col++;
            } else if (1 == token) {
                if (m-1 == row || 0 != visited[row+1][col]) {
                    col--;
                    token = (1 + token)%4;
                } else row++;
            } else if (2 == token) {
                if (0 == col || 0 != visited[row][col-1]) {
                    row --;
                    token = (1 + token)%4;
                } else col--;
            } else {
                if (0 == row || 0 != visited[row-1][col]) {
                    col++;
                    token = (1 + token)%4;
                } else row--;
            }            
        }
        return ret;
    }
};
