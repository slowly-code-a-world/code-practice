/*
In a 2 D array where every row and column are sorted, give the nth smallest element
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>

using namespace std;
struct node {
	int val;
	int rowId;
	int colId;
};
bool operator<(node n1, node n2) {
	return n1.val > n2.val;
}
class Solution {
public:
	int getKth(vector<vector<int>>&matrix, int k) {
		int rows = matrix.size();
		if (rows == 0) return INT_MAX;
		int cols = matrix[0].size();
		if (k < 0 || k > rows*cols) return INT_MAX;
		if (cols == 0) return INT_MAX;
		priority_queue<node> PQ;
		for (int i = 0; i<cols; i++) {
			node tmp;
			tmp.val = matrix[0][i];
			tmp.rowId = 0;
			tmp.colId = i;
			PQ.push(tmp);
		}
		int ret = INT_MAX;
		for (int i = 0; i<k; i++) {
			node tmp = PQ.top();
			ret = tmp.val;
			int tmpRow = tmp.rowId;
			int tmpCol = tmp.colId;
			if (tmpRow + 1 < rows) {
				node tmpNode;
				tmpNode.val = matrix[tmpRow+1][tmpCol];
				tmpNode.rowId = tmpRow + 1;
				tmpNode.colId = tmpCol;
				PQ.push(tmpNode);
			}
			PQ.pop();
		}	
		return ret;
	}
};

int main(void) {
	vector<vector<int>> matrix = {{10, 20, 30, 40},
				      {15, 25, 35, 45},
				      {25, 29, 37, 48},
				      {32, 33, 39, 50}};
	Solution S;
	cout << S.getKth(matrix, 7) << endl;	
}
