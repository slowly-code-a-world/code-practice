
4Sum
Total Accepted: 11226 Total Submissions: 52773

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

    Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
    The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)


class Solution {
public:
    void get_all(vector<vector<int>> &ret, int start, int end, int target, vector<int> &num, vector<int> &solution) {
        int l = start, r = end - 1;
        if (l >= r) return;
        while (l < r) {
            if (num[l] + num[r] == target) {
                solution.push_back(num[l]);
                solution.push_back(num[r]);
                ret.push_back(solution);
                solution.pop_back();
                solution.pop_back();
                l++;
                while (l < r && num[l] == num[l-1]) l++;
                r--;
                while (l < r && num[r] == num[r+1]) r--;
                
            } else if (num[l] + num[r] > target) {
                r--;
            } else { l++; }    
        }
    }
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> ret;
        int size = num.size();
        if (size <=3) return ret;
        sort(num.begin(), num.end());
        vector<int> visited(size, 0);
        vector<int> solution;
        int sum = 0;
        for (int i = 0; i<size; i++) {
            if (0 == visited[i]) {
                if (i >0 && num[i] == num[i-1] && 0 == visited[i-1]) 
                    continue;
                visited[i] = 1;
                solution.push_back(num[i]);
                sum+=num[i];
                for (int j = i+1; j< size; j++) {
                    if (0 == visited[j]) {
                        if (num[j] == num[j-1] && 0 == visited[j-1])
                            continue;
                        visited[j] = 1;
                        solution.push_back(num[j]);
                        sum+=num[j];
                        get_all(ret, j+1, size, target-sum, num, solution);
                        sum-=num[j];
                        solution.pop_back();
                        visited[j] = 0;
                    }
                }
                sum-=num[i];
                solution.pop_back();
                visited[i] = 0;
            }
        }
    }
};
