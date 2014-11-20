/*
Problem

Given an arranged chess board with pieces, figure out the total number of different ways in which any piece can be killed in one move. Note: in this problem, the pieces can be killed despite of the color.

For example, if there are 3 pieces King is at B2, Pawn at A1 and Queen at H8 then the total number of pieces that an be killed is 3. H8-Q can kill B2-K, A1-P can kill B2-K, B2-K can kill A1-P

A position on the chess board is represented as A1, A2... A8,B1.. H8

Pieces are represented as

    (K) King can move in 8 direction by one place.
    (Q) Queen can move in 8 direction by any number of places, but can't overtake another piece.
    (R) Rook can only move vertically or horitonzally, but can't overtake another piece.
    (B) Bishop can only move diagonally, but can't overtake another piece.
    (N) Knights can move to a square that is two squares horizontally and one square vertically OR one squares horizontally and two square vertically.
    (P) Pawn can only kill by moving diagonally upwards (towards higher number i.e. A -> B, B->C and so on). 

Input

The first line of the input gives the number of test cases, T. T Test cases follow. Each test case consists of the number of pieces , N. N lines follow, each line mentions where a piece is present followed by - with the piece type
Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the the total number of different ways in which any piece can be killed.
Limits

1 ≤ T ≤ 100.
Small dataset

1 ≤ N ≤ 10.
Pieces can include K, P
Large dataset

1 ≤ N ≤ 64.
Sample

Input
  	
Output
 

2
2
A1-K
A8-Q

3
B2-K
A1-P
H8-Q

	

Case #1: 1
Case #2: 3

*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;
class Solution {
private:
	map<pair<char, char>, bool> record;
public:
	char getType(string s) {
		int size = s.size();
		return s[size-1];
	}
	bool isKingTarget(vector<string> &locs, int from, int to) {
		char sx = locs[from][0], sy = locs[from][1];
		char ex = locs[to][0], ey = locs[to][1];
		int deltax = abs(sx - ex);
		int deltay = abs(sy - ey);
		if (deltax == 0 && deltay == 1)
			return true;
		if (deltax == 1 && deltay == 0)
			return true;
		if (deltax == 1 && deltay == 1)
			return true;
		return false;
	}
	bool isQueueTarget(vector<string> &locs, int from, int to) {
		char sx = locs[from][0], sy = locs[from][1];
		char ex = locs[to][0], ey = locs[to][1];
		int deltax = abs(sx - ex), deltay = abs(sy - ey);
		if (0 == deltax || 0 == deltay || deltax == deltay) {
			int dx = ex - sx, dy = ey - sy;
			if (dx > 0) dx = 1;
			else if (dx < 0) dx = -1;
			if (dy > 0) dy = 1;
			else if (dy < 0) dy = -1;
			char tmpx = sx, tmpy = sy;
			bool found = false;
			while (tmpx != ex && tmpy != ey) {
				tmpx += dx;
				tmpy += dy;
				if (tmpx == ex && tmpy == ey)
					break;
				if (record[make_pair(tmpx, tmpy)]) {
					found = true;
					break;
				}
			}
			if (!found) return true;
			return false;
		}
		return false;
	}
	bool isRookTarget(vector<string> &locs, int from, int to) {
		char sx = locs[from][0], sy = locs[from][1];
		char ex = locs[to][0], ey = locs[to][1];
		int deltax = abs(sx - ex), deltay = abs(sy - ey);
		if (0 == deltax || 0 == deltay) {
			int dx = ex - sx, dy = ey - sy;
			if (dx > 0) dx = 1;
			else if (dx < 0) dx = -1;
			if (dy > 0) dy = 1;
			else if (dy < 0) dy = -1;
			char tmpx = sx, tmpy = sy;
			bool found = false;
			while (tmpx != ex && tmpy != ey) {
				tmpx += dx;
				tmpy += dy;
				if (tmpx == ex && tmpy == ey)
					break;
				if (record[make_pair(tmpx, tmpy)]) {
					found = true;
					break;
				}
			}
			if (!found) return true;
			return false;
		}
		return false;
	}
	bool isBishopTarget(vector<string> &locs, int from, int to) {
		char sx = locs[from][0], sy = locs[from][1];
		char ex = locs[to][0], ey = locs[to][1];
		int deltax = abs(sx - ex), deltay = abs(sy - ey);
		if (deltax == deltay) {
			int dx = ex - sx, dy = ey - sy;
			if (dx > 0) dx = 1;
			else if (dx < 0) dx = -1;
			if (dy > 0) dy = 1;
			else if (dy < 0) dy = -1;
			char tmpx = sx, tmpy = sy;
			bool found = false;
			while (tmpx != ex && tmpy != ey) {
				tmpx += dx;
				tmpy += dy;
				if (tmpx == ex && tmpy == ey)
					break;
				if (record[make_pair(tmpx, tmpy)]) {
					found = true;
					break;
				}
			}
			if (!found) return true;
			return false;
		}
		return false;
	}
	bool isKnightsTarget(vector<string> &locs, int from, int to) {
		char sx = locs[from][0], sy = locs[from][1];
		char ex = locs[to][0], ey = locs[to][1];
		int deltax = abs(sx - ex), deltay = abs(sy - ey);
		if ((deltax == 2 && deltay == 1) || (deltax == 1 && deltay == 2))
			return true;
		return false;
	}
	bool isPawnTarget(vector<string> &locs, int from, int to) {
		char sx = locs[from][0], sy = locs[from][1];
		char ex = locs[to][0], ey = locs[to][1];
		int deltax = abs(sx - ex), deltay = abs(sy - ey);
		if (deltax == deltay && ex > sx && ey > sy) {
			int dx = 1, dy = ey - sy;
			if (dy > 0) dy = 1;
			else dy = -1;
			char tmpx = sx, tmpy = sy;
			bool found = false;
			while (tmpx != ex && tmpy != ey) {
				tmpx += dx;
				tmpy += dy;
				if (tmpx == ex && tmpy == ey)
					break;
				if (record[make_pair(tmpx, tmpy)]) {
					found = true;
					break;
				}
			}
			if (!found) return true;
			return false;
		}
		return false;
	}	
	void buildmap(vector<string>&locs) {
		for (int i = 0; i<locs.size(); i++) 
			record[make_pair(locs[i][0], locs[i][1])] = true;
	}
	int getKilled(vector<string>&locs) {
		record.clear();
		buildmap(locs);	
		int ret = 0;
		for (int i = 0; i<locs.size(); i++) {
		for (int j = 0; j<locs.size(); j++) {	
			if (i == j) continue;
			if (getType(locs[i]) == 'K') {
				if (isKingTarget(locs, i, j))	
					ret++;	
				continue;
			}
			if (getType(locs[i]) == 'Q') {
				if (isQueueTarget(locs, i, j))
					ret++;
				continue;
			}
			if (getType(locs[i]) == 'R') {
				if (isRookTarget(locs, i, j))
					ret++;
				continue;
			}
			if (getType(locs[i]) == 'B') {
				if (isBishopTarget(locs, i, j))
					ret++;
				continue;
			}
			if (getType(locs[i]) == 'N') {
				if (isKnightsTarget(locs, i, j))
					ret++;
				continue;
			}
			if (getType(locs[i]) == 'P') {
				if (isPawnTarget(locs, i, j))
					ret++;
				continue;
			}
		}}
		return ret;
	}	
};
int main(void) {
	int cases, pos;
	string tmp;
	Solution S;
	vector<string> locs;
	cin >> cases;
	for (int i = 0; i<cases; i++) {
		cin >> pos;
		locs.clear();
		for (int j = 0; j<pos; j++)  {
			cin >> tmp;
			locs.push_back(tmp);
		}
		cout << "Case #" << i + 1 << ": " << S.getKilled(locs) << endl;
	}
}
