
Maximal Rectangle
Total Accepted: 8678 Total Submissions: 40125

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area. 

class Solution {
public:
    int getmax(int a, int b) {
        return (a > b) ? a : b;
    }
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if (0 == row) return 0;
        int col = matrix[0].size();
        if (0 == col) return 0;
        vector<vector<int> > area(row, vector<int>(col, 0));
        vector<vector<int> > record(row, vector<int>(col, 0));
        int ret = 0;
        
        for (int j = 0; j<col; j++) 
            record[row-1][j] = ('0' == matrix[row-1][j])? 0:1;

        for (int i = row-2; i>=0; i--) {
            for (int j = 0; j<col; j++) {
                if ('1' == matrix[i][j]) 
                    record[i][j] = record[i+1][j] + 1;
            }
        }
        for (int j = col-1; j>=0; j--) {
            if ('1' == matrix[row-1][j]) {
                if (col-1 == j) area[row-1][j] = 1;
                else area[row-1][j] = area[row-1][j+1] +1; 
                if (area[row-1][j] > ret) ret = area[row-1][j];
            }    
        }
        
        int val, min;
        for (int i = row-2; i>=0; i--) {
            for (int j = col-1; j >=0; j--) {
                if ('1' == matrix[i][j]) {
                    if (j < col-1 && '0' == matrix[i+1][j+1]) {
                        area[i][j] = 1 + getmax(area[i][j+1], area[i+1][j]);
                    } else if (j < col-1 && '0' == matrix[i][j+1]) {
                        area[i][j] = record[i][j];
                    } else {
                        val = min = record[i][j];
                        for (int k = j+1; k<col; k++) {
                            if (record[i][k] < min) min = record[i][k];
                            if ((k - j + 1)*min > val) val = (k-j+1)*min;
                            if (0 == min) break;
                        }
                        area[i][j] = val;
                    }
                    if (area[i][j] > ret) ret = area[i][j];
                }
            }
        }
        return ret;
    }
};
