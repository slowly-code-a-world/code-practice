/*
 Find the path | 2 point(s)

 You are faced with a stepping puzzle. You know the word needed to get from one side to the other safely, but you need to find the path.

 Using a given word and 2D grid of letters, find a path from the top left to the bottom right of the grid. This path must only use adjacent spaces (no diagonals) and it can't use the same space twice. After you have found the path, change all other letters in the grid to periods (.) to let the rest of your friends cross safely.
 Input description/format

 The input will be the word to follow followed by a grid of characters.
 Output description/format

 The output will be the grid of characters with only the correct path remaining, each other letter in the grid will be replaced with a period (.)
 Example input

 SNICKERDOODLE
 SNICKE
 NRCRDO
 IEKODS
 CRDOLE

 Example output

 SNI...
 ..C...
 .EKOD.
 .RDOLE
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Test {
public:
	void find(string&S, int sindex, vector<string>&grid, int x, int y, vector<vector<bool>>&mark, vector<vector<bool>>&solution) {
		if (x == mark.size()-1 && y == mark[0].size()-1 && sindex == S.size()-1 && S[sindex] == grid[x][y]) {
			mark[x][y] = true;
			solution = mark;
			mark[x][y] = false;
			return;
		}	
		if (S[sindex] != grid[x][y]) return;
		mark[x][y] = true;
		if (x-1 >=0 && mark[x-1][y] == false)
			find(S, sindex+1, grid, x-1, y, mark, solution);
		if (x+1 < mark.size() && mark[x+1][y] == false)
			find(S, sindex+1, grid, x+1, y, mark, solution);
		if (y-1 >=0 && mark[x][y-1] == false)
			find(S, sindex+1, grid, x, y-1, mark, solution);
		if (y+1< mark[0].size() && mark[x][y+1] == false)
			find(S, sindex+1, grid, x, y+1, mark, solution);	
		mark[x][y] = false;
	}
	void print(vector<string>&grid) {
		for (int i = 0; i<grid.size(); i++) {
			for (int j = 0; j<grid[0].size(); j++)
				cout << grid[i][j];
			cout << endl;
		}
	}	
};
int main(void) {
	string S, tmp;
	cin >> S;
	vector<string> grid;
	while (cin >> tmp)
		grid.push_back(tmp);

	Test t;
	t.print(grid);
	vector<vector<bool>> mark(grid.size(), vector<bool>(grid[0].size(), false)), solution = mark;
	t.find(S, 0, grid, 0, 0, mark, solution);
	for (int i = 0; i<grid.size(); i++) {
		for (int j = 0; j<grid[0].size(); j++) {
			if (solution[i][j] == false)
				grid[i][j] = '.';
		}
	}
	t.print(grid);
}
