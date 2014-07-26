
Jump Game
Total Accepted: 15308 Total Submissions: 56420

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false. 

class Solution {
public:
    bool canJump(int A[], int n) {
        if (0 == n) return false;
        if (1 == n) return true;
        int maxindex = A[0];
        int loc = 0;
        while (loc <= maxindex) {
            if (loc + A[loc] >= n-1)
                return true;
            if (loc + A[loc] > maxindex)
                maxindex = loc + A[loc];
            loc++;    
        }
        return false;
    }
};
