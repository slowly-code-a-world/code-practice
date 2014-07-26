
Combination Sum
Total Accepted: 14617 Total Submissions: 55311

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3] 

class Solution {
public:
    void get_all(vector<int> &candidates, int target, vector<vector<int> >&ret, int level, int &sum, vector<int> &solution) {
        if (sum > target) 
            return;
        if (sum == target) {
            ret.push_back(solution);
            return;
        }
        for (int i = level; i<candidates.size(); i++) {
            sum+= candidates[i];
            solution.push_back(candidates[i]);
            get_all(candidates, target, ret, i, sum, solution);
            solution.pop_back();
            sum-= candidates[i];
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ret;
        if (0 == candidates.size()) 
            return ret;
        
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        vector<int> solution;
        get_all(candidates, target, ret, 0, sum, solution);
        return ret;
    }
};
