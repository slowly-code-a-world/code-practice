
Permutations II
Total Accepted: 12900 Total Submissions: 52270

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1]. 

class Solution {
public:
    void get_all(vector<int> &num, vector<int> &visited, int step, vector<int> solution, vector<vector<int> > &ret) {
        if (num.size() == solution.size()) {
            ret.push_back(solution);
            return;    
        }
        
        for (int i = 0; i<num.size(); i++) {
            if (0 == visited[i]) {
                if (i>0 && num[i-1] == num[i] && 0 == visited[i-1])
                    continue;
                visited[i] = 1;
                solution.push_back(num[i]);
                get_all(num, visited, step+1, solution, ret);
                solution.pop_back();
                visited[i] = 0;
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ret;
        if (0 == num.size()) 
            return ret;
        sort(num.begin(), num.end());
        vector<int> visited(num.size(), 0);
        vector<int> solution;
        get_all(num, visited, 0, solution, ret);
        return ret;
    }
};
