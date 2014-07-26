
Valid Sudoku
Total Accepted: 10747 Total Submissions: 38689

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated. 

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<vector<int>> col;
        vector<vector<int>> row;
        vector<vector<int>> mix;
        vector<int> zero(9, 0);
        for (int i =0; i<9; i++) {
            col.push_back(zero);
            row.push_back(zero);
            mix.push_back(zero);
        }
        for (int i = 0; i<9; i++) {
            for (int j = 0; j<9; j++) {
                if ('.' != board[i][j]) {
                    if (0 == row[i][board[i][j]-'0'-1]) 
                        row[i][board[i][j]-'0'-1] = 1; 
                    else return false;
                    if (0 == col[j][board[i][j]-'0'-1])
                        col[j][board[i][j]-'0'-1] = 1;
                    else return false;    
                    int x = i / 3; int y = j / 3;
                    if (0 == mix[3*x+y][board[i][j]-'0'-1])
                        mix[3*x+y][board[i][j]-'0'-1] = 1;    
                    else return false;    
                }
            }
        }
        return true;

    }
};
