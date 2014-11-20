/*
Problem
Vincenzo decides to make cube IV but only has the budget to make a square maze. Its a perfect maze, every room is in the form of a square and there are 4 doors (1 on each side of the room). There is a big number written in the room. A person can only move from one room to another if the number in the next room is larger than the number in his current room by 1. Now, Vincenzo assigns unique numbers to all the rooms (1, 2, 3, .... S2) and then places S2 people in the maze, 1 in each room where S is the side length of the maze. The person who can move maximum number of times will win. Figure out who will emerge as the winner and the number of rooms he will be able to move.
Input

The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of S which is the side length of the square maze. Then S2 numbers follow like a maze to give the numbers that have been assigned to the rooms.

1 2 9 
5 3 8 
4 6 7 

Output

For each test case, output one line containing "Case #x: r d", where x is the test case number (starting from 1), r is the room number of the person who will win and d is the number of rooms he could move. In case there are multiple such people, the person who is in the smallest room will win.
Limits

1 ≤ T ≤ 100.
Small dataset

1 ≤ S ≤ 10
Large dataset

1 ≤ S ≤ 103.
Sample

Input
  	
Output
 

2
2
3 4
1 2 


3
1 2 9 
5 3 8 
4 6 7 

	

Case #1: 1 2
Case #2: 6 4
*/
#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
	void flood(vector<vector<int>>&matrix, vector<vector<bool>>&mark, int sx, int sy, int &id, int &len) {
		int ex = sx, ey = sy, ve = matrix[ex][ey], vs = matrix[sx][sy];
		int rows = matrix.size(), cols = matrix[0].size();
		for (;;) {
			if (ex - 1 >= 0 && mark[ex-1][ey] == false && matrix[ex-1][ey] == ve + 1) {
				mark[ex-1][ey] = true;
				ve ++;
				ex = ex - 1;
				continue;
			}
			if (ex + 1 < rows && mark[ex+1][ey] == false && matrix[ex+1][ey] == ve + 1) {
				mark[ex+1][ey] = true;
				ve ++;
				ex = ex + 1;
				continue;
			}
			if (ey - 1 >= 0 && mark[ex][ey-1] == false && matrix[ex][ey-1] == ve + 1) {
				mark[ex][ey-1] = true;
				ve ++;
				ey = ey - 1;
				continue;
			}
			if (ey + 1 < cols && mark[ex][ey + 1] == false && matrix[ex][ey + 1] == ve + 1) {
				mark[ex][ey + 1] = true;
				ve ++;
				ey = ey + 1;
				continue;
			}
			break;
		}

		for (;;) {
			if (sx - 1 > 0 && mark[sx-1][sy] == false && matrix[sx-1][sy] == vs - 1) {
				mark[sx-1][sy] = true;
				vs --;
				sx = sx - 1;
				continue;
			}
			if (sx + 1 < rows && mark[sx+1][sy] == false && matrix[sx+1][sy] == vs - 1) {
				mark[sx+1][sy] = true;
				vs --;
				sx = sx + 1;
				continue;
			}
			if (sy - 1 > 0 && mark[sx][sy-1] == false && matrix[sx][sy-1] == vs - 1) {
				mark[sx][sy - 1] = true;
				vs --;
				sy = sy - 1;
				continue;
			}
			if (sy + 1 < cols && mark[sx][sy+1] == false && matrix[sx][sy+1] == vs - 1) {
				mark[sx][sy+1] = true;
				vs --;
				sy = sy + 1;
				continue;
			}
			break;
		}
		id = matrix[sx][sy];
		len = ve - vs + 1;
	}
	void find(vector<vector<int>>&matrix, int &id, int &len) {
		int rows = matrix.size(), cols = matrix[0].size();
		vector<vector<bool>> mark(rows, vector<bool>(cols, false));
		for (int i = 0; i<rows; i++) {
		for (int j = 0; j<cols; j++) {
			if (mark[i][j]) continue;
			int tmpId = -1, tmpLen = -1;
			mark[i][j] = true;
			flood(matrix, mark, i, j, tmpId, tmpLen);
			if (tmpLen > len) {
				len = tmpLen;
				id = tmpId;
			} else if (tmpLen == len) 
				id = min(id, tmpId);			
		}}
	}
};

int main(void) {
	int cases, size, val;
	vector<vector<int>> matrix;
	vector<int> tmp;
	Solution S;
	cin >> cases;	
	for (int i = 0; i<cases; i++) {
		cin >> size;
		matrix.clear();
		for (int j = 0; j<size; j++) {
			tmp.clear();
			for (int k = 0; k<size; k++) {
				cin >> val;
				tmp.push_back(val);
			}
			matrix.push_back(tmp);	
		}
		int id = INT_MAX, len = INT_MIN;
		S.find(matrix, id, len);
		cout << "Case #" << i + 1 << ": " << id << " " << len << endl;
	}	
}
