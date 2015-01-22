/*
You are given a n*n matrix.Every cell of the matrix contain some value 
(positive). You are currently standing at (0,0) and you have to go to 
right most and botom most cell ((n-1)*(n-1)) You can move either right 
or down. 

Q1. Find the most optimal path.
Q2. Find the second most optimal path.
Q3. Find the kth most optimal path. 
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
struct node {
	int x, y;
	int cost;
};
bool operator<(node n1, node n2) { return n1.cost > n2.cost; }
class Solution {
public:
	int getOptimalPath(vector<vector<int>>&matrix, int k) {
		priority_queue<node> PQ;
		node start;
		start.x = start.y = 0;
		start.cost = matrix[0][0];
		int row = matrix.size(), col = matrix[0].size();
		PQ.push(start);
		int cnt = 1;
		while (!PQ.empty()) {
			node top = PQ.top();
			if (top.x == row-1 && top.y == col-1) {
				if (cnt == k) return top.cost;
				cnt++;
			} 
			if (top.x+1 < row) { 
				node n;
				n.x = top.x + 1;
				n.y = top.y;
				n.cost = top.cost + matrix[n.x][n.y];
				PQ.push(n);
			} 
			if (top.y + 1 < col) {
				node n;
				n.x = top.x;
				n.y = top.y + 1;
				n.cost = top.cost + matrix[n.x][n.y];
				PQ.push(n);
			}
			PQ.pop();
		}
	}
};

int main(void) {
	Solution S;
	vector<vector<int>> matrix = {{1, 2}, {3, 4}};
	int ret = S.getOptimalPath(matrix, 1);
	cout << ret << endl;
}
