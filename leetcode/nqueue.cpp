
N-Queens
Total Accepted: 11172 Total Submissions: 43383

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]


class Solution {
public:
    bool can_place(vector<vector<int> > visited, int step, int i, int n) {
        if (0 == step) return true;
        bool found = false;
        for (int l = 0; l<step; l++) {
            if (1 == visited[l][i]) {
                found = true;
                break;
            }
        }
        if (found) return false;
        found = false;
        for (int l = 0; l <step; l++) {
            if (step+i-l >=0 && step+i-l < n && 1 == visited[l][step+i-l]) {
                found = true;
                break;
            }
        }
        if (found) return false;
        for (int l = 0; l<step; l++) {
            if (l+i-step >=0 && l+i-step<n && 1 == visited[l][l+i-step]) {
                found = true;
                break;
            }
        }
        if (found) return false;
        return true;
    }
    void get_all(int n, vector<vector<string> > &ret, vector<string> &solution, int step, vector<vector<int> > &visited) {
        if (n == step) {
            ret.push_back(solution);
            return;
        }
        
        for (int i = 0; i<n; i++) {
            if (can_place(visited, step, i, n)) {
                visited[step][i] = 1;
                solution[step][i] = 'Q';
                get_all(n, ret, solution, step+1, visited);
                visited[step][i] = 0;
                solution[step][i] = '.';
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ret;
        if (n <=0 || 2 == n || 3 ==n) return ret;
        if (1 == n) {
            vector<string> s;
            string q;
            q.push_back('Q');
            s.push_back(q);
            ret.push_back(s);    
            return ret;
        } 
        
        string s(n, '.');
        vector<string> solution;
        for (int i = 0; i<n; i++) 
            solution.push_back(s);
        vector<vector<int> > visited;
        vector<int> zero(n, 0);
        for (int i = 0; i<n; i++) 
            visited.push_back(zero);
            
        get_all(n, ret, solution, 0, visited); 
        return ret;
    }
};
