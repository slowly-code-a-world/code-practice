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

bool MyGet(vector<string> &mark,vector<string> grid,string S,
		int r,int c,int index);
vector<string> GetPath(vector<string> grid,string S){
	//up:0,right:1,down:2,left:3
	int m = grid.size();
	int n = grid[0].size();
	string dot = "";
	dot.append(n,'.');
	vector<string> mark(m,dot);
	int len = S.size();
	if(MyGet(mark,grid,S,0,0,0))
		return mark;
}
bool MyGet(vector<string> &mark,vector<string> grid,string S,
		int r,int c,int index){
	int m=grid.size();
	int n = grid[0].size();
	if(index>=S.size()&&r>=m-1&&c>=n-1) return true;
	if(r<0||r>=m||c<0||c>=n) return false;
	if(mark[r][c]!='.') return false;
	if(grid[r][c]==S[index]){
		mark[r][c] = S[index];
		if(MyGet(mark,grid,S,r+1,c,index+1))
			return true;
		if(MyGet(mark,grid,S,r,c+1,index+1))
			return true;
		if(MyGet(mark,grid,S,r,c-1,index+1))
			return true;
		if(MyGet(mark,grid,S,r-1,c,index+1))
			return true;
		mark[r][c] = '.';
	}
	return false;
}
int main(int argc,char*argv[]){
	string S;
	cin>>S;
	vector<string> grid;
	string line;
	while(cin>>line){
		grid.push_back(line);
	}
	vector<string> res = GetPath(grid,S);
	for(int i=0;i<res.size();++i){
		cout << res[i] << endl;
	}
	return 0;
}
