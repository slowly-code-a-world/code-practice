/*
9.2 Imagine a robot sitting on the upper left corner of an X by Y grid. The robot can
   only move in two directions: right and down. How many possible paths are there
  for the robot to go from (0,0) to (X,Y)?
FOLLOW UP
Imagine certain spots are "off limits," such that the robot cannot step on them.
Design an algorithm to find a path for the robot from the top left to the bottom
right.
*/

#include <iostream>

class Solution {
public:
	int count_ways(int startx, int starty, int x, int y) {
		if (startx == x && starty == y) return 0;
		if (startx > x || starty > y) return 0;
		if (startx == x) return 1;
		if (starty == y) return 1; 
		return count_ways(startx, starty + 1, x, y) + count_ways(startx + 1, starty, x, y);
	}

	int count_ways_v2(int x, int y, vector<vector<int> >&store) {
		if (x < 0 || y < 0) return 0;
		if (0 == x && 0 == y) return 0;
		if (0 == x || 0 == y) return 1;
		for (int i = 0; i<store.size(); i++) 
			for (int j = 0; j<store[0].size(); j++)
				store[i][j] = -1;
		store[0][0] = 0;
		for (int j = 1; j<vector[0].size(); j++)
			store[0][j] = 1;
		for (int i = 1; i<vector.size(); i++)
			store[i][0] = 1;

		for (int i = 1; i < vector.size(); i++) {
			for (int j = 1; j < vector[0].size(); j++) {
				vector[i][j] = vector[i-1][j] + vector[i][j-1];
			}
		}

		return vector[i][j];
	}	

	void find_path(vector<pair<int, int>> &solution, vector<pair<int, int>>&current, vector<vector<int>>&map, int x, int y, int sx, int sy, bool found) {
		if (sx == x && sy == y) {
			found = true;
			solution = current;
			return;
		}

		if (sx > x || sy > y) return;
		if (false == found && 0 == map[sx + 1][sy]) {
			current.push_back(make_pair(sx + 1, sy));
			find_path(solution, current, map, x, y, sx + 1, sy, found);
		}

		if (false == found && 0 == map[sx][sy + 1]) {
			current.push_back(make_pair(sx, sy + 1));
			find_path(solution, current, map, x, y, sx, sy + 1, found);	
		}
	}

	void find_path_v2(vector<pair<int, int>> &solution, int x, int y, vector<vector<int> > &store, vector<vector<int> >&path, vector<vector<int> >&map) {
		if (x < 0 || y < 0) return;
		if (0 == x && 0 == y) {
			if (0 == map[x][y]) 
				solution.push_back(make_pair(0, 0));
			
			return;
		}

		bool found = false;
		for (int j = 1; j < path[0].size(); j++) {
			if (false == found && 0 == map[i][j]) { 
				store[i][j] = 1;
				path[i][j] = 1; //left
			}
		}

		found = false;
		for (int i = 1; i<path.size(); i++) {
			if (false == found && 0 == map[i][j]) {
				store[i][j] = 1;
				path[i][j] = 2; //up
			}
		}

		for (int i = 1; i<path.size(); i++) {
			for (int j = 1; j < path[0].size(); j++) {
				if (0 == map[i][j]) {
					store[i][j] = store[i-1][j] + store[i][j-1];
					if (0 != store[i-1][j])
						path[i][j] +=2;
					if (0 != store[i][j-1])
						path[i][j] +=1;	
				} else store[i][j] = 0; 
			}	
		}
		if (0 == store[x][y]) return;
		int tmpx = x, tmpy = y;
		solution.push_back(make_pair(tmpx, tmpy));
		while (tmpx != 0 && tmpy != 0) {
			if (1 == path[tmpx][tmpy]) {
				solution.insert(solution.begin(), make_pair(tmpx, tmpy - 1));
				tmpy = tmpy - 1;
			} else if (path[tmpx][tmpy] >=2) {
				solution.insert(solution.begin(), make_pair(tmpx - 1, tmpy));
				tmpx = tmpx - 1;
			}
		}
	}	
};
