
Sudoku Solver
Total Accepted: 9482 Total Submissions: 45546

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution

class Solution {
public:
    void get_all(vector<vector<char> > &board, int step, vector<vector<bool> >&row, vector<vector<bool> >&col, vector<vector<bool> >&mix, int &flag) {
        if (81 == step) {
            flag = 1;
            return;
        }
        
        int i = step / 9; int j = step % 9;
        if ('.' != board[i][j]) {
            get_all(board, step + 1, row, col, mix, flag);
        } else {
            for (int k = 0; k<9; k++) {
                if (0 == flag && false == row[i][k] && false == col[j][k] && false == mix[(i/3)*3+j/3][k]) {
                    board[i][j] = k + 1 + '0';
                    row[i][board[i][j]-'0'-1] = true;
                    col[j][board[i][j]-'0'-1] = true;
                    int x = i/3; int y = j/3;
                    mix[3*x+y][board[i][j] - '0'-1] = true;
                    get_all(board, step+1, row, col, mix, flag);
                    if (1 == flag) return;
                    mix[3*x+y][board[i][j] - '0'-1] = false;
                    col[j][board[i][j]-'0'-1] = false;
                    row[i][board[i][j]-'0'-1] = false;
                    board[i][j] = '.';
                }
            }            
        }
    }
    void solveSudoku(vector<vector<char> > &board) {
        vector<bool> zero(9, false); 
        vector<vector<bool> > col(9, zero);
        vector<vector<bool> > row(9, zero);
        vector<vector<bool> > mix(9, zero);

        for (int i = 0; i<9; i++) {
            for (int j = 0; j<9; j++) {
                if ('.' != board[i][j]) {
                    row[i][board[i][j]-'0'-1] = true; 
                    col[j][board[i][j]-'0'-1] = true;
                    int x = i / 3; int y = j / 3;
                    mix[3*x+y][board[i][j]-'0'-1] = true;    
                }
            }
        }
        int flag = 0;
        get_all(board, 0, row, col, mix, flag);
    }    
};
