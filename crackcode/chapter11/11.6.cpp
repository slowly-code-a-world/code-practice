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
		if (0 == columns) return res;
		res = get(matrix, element, 0, 0, rows-1, columns - 1);
		return res;	
	}

	pair<int, int> find_v2(vector<vector<int> > &matrix, int element) {
		pair<int, int> res = make_pair(-1, -1);
		int rows = matrix.size();
		if (0 == rows) return res;
		int columns = matrix[0].size();
		if (0 == columns) return res;
		int startx = 0; int starty = columns - 1;
		while (startx < rows && starty >=0) {
			if (element == matrix[startx][starty]) return make_pair(startx, starty);
			if (matrix[startx][starty] > element) starty--;
			else startx++;
		}

		return res;
	}

	pair<int, int> real_find(vector<vector<int> > &matrix, int element, int sx, int sy, int ex, int ey) {
		pair<int, int> res = make_pair(-1, -1);
		if (sx > ex || sy > ey)	return res;
		if (sx == ex && sy == ey) return (matrix[sx][sy] == element)? make_pair(sx, sy) : res;
		int cnt = 0;
		while (sx + cnt <= ex && sy + cnt <= ey && matrix[sx + cnt][sy + cnt] < element) 
			cnt++;
		if (sx + cnt > ex) 
			return real_find(matrix, element, sx, sy + cnt, sx + cnt, ey);
		if (sy + cnt > ey)
			return real_find(matrix, element, sx + cnt, sy, ex, ey);
		if (matrix[sx + cnt][sy + cnt] == element) return make_pair(sx + cnt, sy + cnt);
		pair<int, int> tmp = real_find(matrix, element, sx, sy + cnt, sx + cnt, ey);
		if (-1 == tmp.first)
		return real_find(matrix, element, sx + cnt, sy, ex, sy + cnt);
	}

	pair<int, int> find_v3(vector<vector<int> > &matrix, int element) {
		pair<int, int> res = make_pair(-1, -1);
		int rows = matrix.size();
		if (0 == rows) return res;
		int columns = matrix[0].size();
		if (0 == columns) return res;
		return real_find(matrix, element, 0, 0, rows-1, columns-1);
	}
};
