
Jump Game II
Total Accepted: 13010 Total Submissions: 53634

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.) 

class Solution {
public:
    int jump(int A[], int n) {
        if (1 == n) return 0;
        int target = A[0];
        int i = 0;
        int max, maxloc;
        int step = 0;
        while (i <= target) {
            if (target >= n-1) {
                step++;
                return step;    
            }
            max = i + 1 + A[i+1];
            maxloc = i + 1;
            for (int j = 2; j<=A[i]; j++) 
                if (i + j + A[i + j] > max) {
                    max = i + j + A[i+j];
                    maxloc = i + j;
                }
            if (max > target)
                target = max;
            step++;
            
            i = maxloc;
        }
    }
};
