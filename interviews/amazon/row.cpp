/*
In a 2-D Matrix with the following properties:
    i. Contains only 1s and 0s
    ii. Every Row is sorted
Find the row with maximum zeroes.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	int getRowId(vector<vector<int>>&matrix) {
		int rows = matrix.size();
		if (rows == 0) return -1;
		int cols = matrix[0].size();
		if (cols == 0) return -1;
		if (rows == 1) return 0;
		int startCol = -1, ret = 0;
		for (int i = 0; i<cols; i++) {
			if (matrix[0][i] == 1) {
				startCol = i;
				break;
			}
		}
		if (startCol == -1) return ret;
		for (int i = 1; i<rows; i++) {
			if (matrix[i][startCol] == 0) {
				ret = i;
				bool found = false;
				for (int j = startCol; j < cols; j++) {
					if (matrix[i][j] == 1) {
						found = true;
						startCol = j;
						break;
					}
				}
				if (!found) return i;
			}
		}
		return ret;
	}
};

int main(void) {
	Solution S;
	vector<vector<int>> matrix = {{0, 0, 0, 1}, {0, 0, 1, 1}, {0, 0, 0, 0}};
	cout << S.getRowId(matrix) << endl;
}
