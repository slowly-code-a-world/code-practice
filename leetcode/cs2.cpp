
Combination Sum II
Total Accepted: 11437 Total Submissions: 47131

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6] 

class Solution {
public:
    void get_all(vector<int> &num, int target, vector<int> &visited, vector<vector<int>> &ret, vector<int> &solution, int next, int &ss) {
        if (ss > target) 
            return;
            
        if (ss == target){
            ret.push_back(solution);
            return;    
        }
        
        for (int i = next; i<num.size(); i++) {
            if (0 == visited[i]) {
                if (i >0 && num[i] == num[i-1] && 0==visited[i-1])
                    continue;
                visited[i] = 1;
                solution.push_back(num[i]);
                ss+=num[i];
                get_all(num, target, visited, ret, solution, i+1, ss);
                ss-=num[i];    
                solution.pop_back();
                visited[i] = 0;
            }
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ret;
        if (0 == num.size()) 
            return ret;
        else if (1 == num.size()) {
            vector<int> tmp;
            if (num[0] == target) {
                tmp.push_back(num[0]);
                ret.push_back(tmp);
                return ret;
            } else {
                return ret;
            }
        }    
        vector<int> visited(num.size(), 0);
        sort(num.begin(), num.end());
        vector<int> solution;
        int ss = 0;
        get_all(num, target, visited, ret, solution, 0, ss);
        
        return ret;
    }
};
