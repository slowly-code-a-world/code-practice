
Search a 2D Matrix
Total Accepted: 15214 Total Submissions: 49070

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return true.

class Solution {
public:
    /*return row or col number*/
    int searchMatrixDetail(vector<vector<int> > &matrix, int target, bool row_fixed, int num) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (row_fixed) {
            int lower = 0;
            int upper = n-1;
            if (target == matrix[num][lower]) return lower;
            if (lower == upper) return 0;
            int middle = (lower + upper)/2;
            while (lower < upper) {
                if (lower +1 == upper)
                    return upper;
                if (target == matrix[num][middle])
                    return middle;
                else if (target > matrix[num][middle])
                    lower = middle;
                else    
                    upper = middle;
                middle = (lower + upper)/2;    
            }
        } else {
            int lower = 0; //matrix 0, n-1
            int upper = m-1; // matrix m-1, n-1
            if (target == matrix[lower][n-1]) return lower;
            if (target == matrix[upper][n-1]) return upper;
            if (target > matrix[upper][n-1]) return -1;
            if (target < matrix[lower][n-1]) return 0;
            if (lower == upper) return 0;
            int middle = (lower + upper)/2;
            while (lower < upper) {
                if (lower + 1 == upper) 
                    return upper;
                
                if (target == matrix[middle][n-1])
                    return middle;
                else if (target > matrix[middle][n-1]) 
                    lower = middle;
                else 
                    upper = middle;
                
                middle = (lower + upper)/2;
            }
        }
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix[0].size();
        int row = searchMatrixDetail(matrix, target, false, 0);
        if (-1 == row) return false;
        if (matrix[row][n-1] == target) return true;
        
        int col = searchMatrixDetail(matrix, target, true, row);
        if (matrix[row][col] == target) return true;
        return false;
    }
};
