
Surrounded Regions
Total Accepted: 10257 Total Submissions: 74556

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,

X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X


class Solution {
public:
     void solve(vector<vector<char>> &board) {
        int row = board.size();  //get row number
        if (row==0){return;}
        int col = board[0].size(); // get column number
         
        vector<vector<bool> > bb(row, vector<bool>(col)); //result vector
         
        queue<pair<int,int> > q; // queue for BFS
         
        //search "O" from 1st row
        for (int i=0;i<col;i++){
            if (board[0][i]=='O'){
                q.push(make_pair(0,i));
                bb[0][i]=true;
            }
        }
         
        //search "O" from 1st column
        for (int i=0;i<row;i++){
            if (board[i][0]=='O'){
                q.push(make_pair(i,0));
                bb[i][0]=true;
            }
        }
         
        //search "O" from last row
        for (int i=0;i<col;i++){
            if (board[row-1][i]=='O'){
                q.push(make_pair(row-1,i));
                bb[row-1][i]=true;
            }
        }
         
        //search "O" from last column
        for (int i=0;i<row;i++){
            if (board[i][col-1]=='O'){
                q.push(make_pair(i,col-1));
                bb[i][col-1]=true;
            }
        }
         
        //BFS
        int i,j; // current position
        while (!q.empty()){
            //get current live "O"
            i = q.front().first;
            j = q.front().second;
             
            //pop up queue
            q.pop();
             
            //search four directions
            if (i-1>0 && board[i-1][j]=='O' && bb[i-1][j]==false){bb[i-1][j]=true; q.push(make_pair(i-1,j));} //top
            if (i+1<row-1 && board[i+1][j]=='O'&& bb[i+1][j]==false){bb[i+1][j]=true; q.push(make_pair(i+1,j));} // bottom
            if (j-1>0 && board[i][j-1]=='O'&& bb[i][j-1]==false){bb[i][j-1]=true; q.push(make_pair(i,j-1));} // left
            if (j+1<col-1 && board[i][j+1]=='O'&& bb[i][j+1]==false){bb[i][j+1]=true; q.push(make_pair(i,j+1));} // right
        }
         
        //Get result
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (board[i][j]=='O'&&bb[i][j]==false){
                    board[i][j]='X';
                }
            }
        }
         
        return;
            
    }
};
