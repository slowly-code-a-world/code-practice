
Permutations
Total Accepted: 18640 Total Submissions: 59997

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 

class Solution {
public:
    void generate_permute(vector<vector<int> > &ret, vector<int>&num, int step, vector<int>&visited, vector<int> &solution)
    {
        if (step == num.size()) {
            ret.push_back(solution);
            return;    
        }
        
        for (int i = 0; i<num.size(); i++) {
            if (0 == visited[i]) {
                solution.push_back(num[i]);
                visited[i] = 1;
                generate_permute(ret, num, step+1, visited, solution);
                solution.pop_back();
                visited[i] = 0;
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        vector<int> solution;
        if (0 == num.size()) return ret;
        vector<int> visited(num.size(), 0);
        generate_permute(ret, num, 0, visited, solution);
        return ret;
    }
};
