
Subsets II
Total Accepted: 13058 Total Submissions: 49084

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]


class Solution {
public:
    void get_all(vector<int> &S, vector<int> &visited, vector<vector<int> > &ret, int target, vector<int> &solution, int next)
    {
        if (target == solution.size()) {
            ret.push_back(solution);
            return;
        }       
        
        for (int i = next; i<S.size(); i++) {
            if (0 == visited[i]) {
                if (i>0 && S[i-1] == S[i] && 0 == visited[i-1])
                    continue;
                visited[i] = 1;
                solution.push_back(S[i]);
                get_all(S, visited, ret, target, solution, i+1);
                solution.pop_back();
                visited[i] = 0;
            }
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ret;    
        if (0 == S.size()) {
            vector<int> tmp;
            ret.push_back(tmp);
            return ret;
        } else {
            sort(S.begin(), S.end());
            vector<int> visited(S.size(), 0);
            vector<int> tmp;
            tmp.clear();
            ret.push_back(tmp);
            int loops = S.size();
            for (int i = 1; i<=loops; i++) {
                vector<int> solution;
                solution.clear();
                get_all(S, visited, ret, i, solution, 0);
            }
            return ret;
        }
    }
};
