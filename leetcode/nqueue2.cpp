N-Queens II
Total Accepted: 10121 Total Submissions: 31014

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

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
    void get_all(int n, int step, vector<vector<int> > &visited, int &sum) {
        if (n == step) {
            sum+=1;
            return;
        }
        
        for (int i = 0; i<n; i++) {
            if (can_place(visited, step, i, n)) {
                visited[step][i] = 1;
                get_all(n, step+1, visited, sum);
                visited[step][i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        if (n <=0 || 2 == n || 3 ==n) return 0;
        if (1 == n) 
            return 1;
        
        vector<vector<int> > visited;
        vector<int> zero(n, 0);
        for (int i = 0; i<n; i++) 
            visited.push_back(zero);
        int sum = 0;    
        get_all(n, 0, visited, sum); 
        return sum;
    }
};
