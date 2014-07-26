
Set Matrix Zeroes
Total Accepted: 13472 Total Submissions: 44115

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row_has_zero = 0, col_has_zero = 0;
        int i, j;
        for (i = 0; i<n; i++) {
            if (0 == matrix[0][i]) {
                row_has_zero = 1;
                break;
            }
        }
        for (i = 0; i<m; i++) {
            if (0 == matrix[i][0]) {
                col_has_zero = 1;
                break;
            }
        }
        
        for (i = 1; i<m ; i++) {
            for (j = 1; j<n; j++) {
                if (0 == matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (i = 1; i<m; i++) {
            if (0 == matrix[i][0]) {
                for (j = 1; j<n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (j = 1; j<n; j++) {
            if (0 == matrix[0][j]) {
                for (i = 1; i<m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row_has_zero) {
            for (j = 0; j<n; j++)
                matrix[0][j] = 0;
        }
        if (col_has_zero) {
            for (i = 0; i<m; i++)
                matrix[i][0] = 0;
        }
    }
};
