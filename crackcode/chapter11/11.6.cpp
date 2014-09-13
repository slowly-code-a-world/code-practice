/*
11.6 Given an M x N matrix in which each row and each column is sorted in ascending
    order, write a method to find an element.
*/

#include <iostream>
 
class Solution {
public:
	pair<int, int> get(vector<vector<int> > &matrix, int element, int p1left, int p1right, int p2left, int p2right) {
		if (p1left > p2left || p1right > p2right) return;
		if (p1left == p2left && p1right == p2right) return (matrix[p1left][p1right] == element)? make_pair(p1left, p1right):make_pair(-1, -1);
		if (p1left == p2left) {
			int middle = (p1right + p2right)/2;
			if (matrix[p1left][middle] == element) return make_pair(p1left, middle);
			if (matrix[p1left][middle] > element) return get(matrix, element, p1left, p1right, p2left, middle-1);
			return get(matrix, element, p1left, middle+1, p1left, p2right);
		} 

		if (p1right == p2right) {
			int middle = (p1left + p2left)/2;
			if (matrix[middle][p1right] == element) return make_pair(middle, p1right);
			if (matrix[middle][p1right] > element) return get(matrix, element, p1left, p1right, middle-1, p2right);
			return get(matrix, element, middle+1, p1right, p2left, p1right);
		}

		int midx = (p1left + p2left)/2;
		int midy = (p1right + p2right)/2;
		if (matrix[midx][midy] == element) return make_pair(midx, midy);
		if (matrix[midx][midy] > element) {
			pair<int, int> tmp = get(matrix, element, p1left, p1right, midx, midy);
			if (tmp.first != -1) return tmp;
			tmp = get(matrix, element, 0, midy+1, midx, p2right);
			if (tmp.first != -1) return tmp;
			return get(matrix, element, midx+1, 0, p2left, midy);	 
		}	

		pair<int, int> tmp = get(matrix, element, midx, midy, p2left, p2right);
		if (tmp.first != -1) return tmp;
		tmp = get(matrix, element, midx, 0, p2left, midy-1);
		if (tmp.first != -1) return tmp;
		return get(matrix, element, 0, midy, midx-1, p2right);	
	}

	pair<int, int> find (vector<vector<int> > &matrix, int element) {
		pair<int, int> res = make_pair(-1, -1);
		int rows = matrix.size();
		if (0 == rows) return res;
		int columns = matrix[0].size(); 
		res = get(matrix, element, 0, 0, rows-1, columns - 1);
		return res;	
	}
};
