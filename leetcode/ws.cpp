
Word Search
Total Accepted: 11673 Total Submissions: 59305

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

class Solution {
private:
    bool real_exist(vector<vector<char> >&board, string &word, vector<vector<bool>>&visited, int start, int x, int y) {
        if (start == word.size()) return true;
    
        if (x > 0 && false == visited[x-1][y] && word[start] == board[x-1][y]) {
            visited[x-1][y] = true;
            bool ret = real_exist(board, word, visited, start+1, x-1, y);
            if (ret) return true;
            visited[x-1][y] = false;
        }
            
        if (x < board.size()-1 && false == visited[x+1][y] && word[start] == board[x+1][y]) {
            visited[x+1][y] = true;    
            bool ret = real_exist(board, word, visited, start+1, x+1, y);
            if (ret) return true;
            visited[x+1][y] = false;
        }
            
        if (y > 0 && false == visited[x][y-1] && word[start] == board[x][y-1]) {
            visited[x][y-1] = true;
            bool ret = real_exist(board, word, visited, start+1, x, y-1);
            if (ret) return true;
            visited[x][y-1] = false;
        }
            
        if (y < board[0].size()-1 && false == visited[x][y+1] && word[start] == board[x][y+1]) {
            visited[x][y+1] = true;
            bool ret = real_exist(board, word, visited, start+1, x, y+1);
            if (ret) return true;
            visited[x][y+1] = false;
        }
            
        return false;
    }
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (0 == word.size()) return false;
        if (0 == board.size()) return false;
        if (0 == board[0].size()) return false;
        vector<bool> tmp(board[0].size(), false);
        vector<vector<bool> > visited(board.size(), tmp);
        for (int i = 0; i<visited.size(); i++) 
            for (int j = 0; j<visited[0].size(); j++) 
                visited[i][j] = false;
            
        for (int i = 0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (word[0] == board[i][j]) {
                    visited[i][j] = true;
                    bool ret = real_exist(board, word, visited, 1, i, j);
                    if (true == ret) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};
