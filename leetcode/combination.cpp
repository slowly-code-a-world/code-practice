
Combinations
Total Accepted: 15550 Total Submissions: 51660

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

class Solution {
public:
    void get_all(int n, vector<int> &visited, int target, vector<vector<int> > &ret, int start, vector<int> &solution) {
        if (solution.size() == target) {
            ret.push_back(solution);
            return;
        }
        
        for (int i = start; i<n; i++) {
            if(0 == visited[i]) {
                visited[i] = 1;
                solution.push_back(i+1);
                get_all(n, visited, target, ret, i+1, solution);
                solution.pop_back();
                visited[i] = 0;
            }
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        if (1 == n) {
            vector<int> tmp;
            tmp.push_back(1);
            ret.push_back(tmp);
            return ret;
        } else {
            vector<int> visited(n, 0);
            vector<int> solution;
            get_all(n, visited, k, ret, 0, solution);
            return ret;
        }
    }
};
