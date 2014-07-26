
3Sum Closest
Total Accepted: 12729 Total Submissions: 47347

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int ret;
        int size = num.size();
        sort(num.begin(), num.end());
        vector<int> solution;
        
        int min = INT_MAX;
        for (int i = 0; i<size; i++) {
            int start = i+1, end = size - 1;
            int t = target - num[i];
            if (start >= end) 
                continue;
            while (start < end) {
                if (num[start] + num[end] == t)
                    return target;
                else if (num[start] + num[end] > t) {
                    int tmp = num[start] + num[end]-t;
                    if (tmp < min) {
                        min = tmp;
                        solution.clear();
                        solution.push_back(num[start]);
                        solution.push_back(num[end]);
                        solution.push_back(num[i]);
                    }
                    end--;
                } else {
                    int tmp = t - num[start] - num[end];
                    if (tmp < min) {
                        min = tmp;
                        solution.clear();
                        solution.push_back(num[start]);
                        solution.push_back(num[end]);
                        solution.push_back(num[i]);                     
                    }
                    start ++;
                }    
            }
            
        } 
        return solution[0] + solution[1] + solution[2];
    }
};
