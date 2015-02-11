/*matrix multiply*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> multiply(vector<vector<int>>M1, vector<vector<int>>&M2) {
		vector<vector<int>> ret;
		int row1 = M1.size();
		if (row1 == 0) return ret;
		int col1 = M1[0].size();
		if (col1 == 0) return ret;
		int row2 = M2.size();
		if (row2 == 0) return ret;
		int col2 = M2[0].size();
		if (col2 == 0) return ret;
		if (col1 != row2) return ret;
		ret = vector<vector<int>>(row1, vector<int>(col2, 0));
		for (int i = 0; i<row1; i++) {
		for (int j = 0; j<col2; j++) {
			// ret[i][j]
			int sum = 0;
			for (int k = 0; k<col1; k++) 
				sum += M1[i][k]*M2[k][j];
			ret[i][j] = sum;
		}}
		return ret;
	}
};
