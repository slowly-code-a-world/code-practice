
Rotate Image
Total Accepted: 13327 Total Submissions: 42705

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

class Solution {
public:
    void actual_rotate(vector<vector<int> >&matrix, int start, int end) {
        if (start >= end) return;
        
        for (int i = start; i<end; i++) {
            int tmp = matrix[start + end - i][start];
            matrix[start + end - i][start] = matrix[end][start + end - i];
            matrix[end][start + end - i] = matrix[i][end];
            matrix[i][end] = matrix[start][i];
            matrix[start][i] = tmp;
        }

        if (end == start+1) return;
        actual_rotate(matrix, start+1, end - 1);
    }
    void rotate(vector<vector<int> > &matrix) {
        if (matrix.size() <=1) return;
        actual_rotate(matrix, 0, matrix.size()-1);
    }
};
