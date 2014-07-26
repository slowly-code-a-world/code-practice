
Maximum Subarray
Total Accepted: 19950 Total Submissions: 59723

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ret = A[0], maxprev = A[0];
        for (int i = 1; i<n; i++) {
            maxprev = max(maxprev + A[i], A[i]);
            ret = max(maxprev, ret);
        }
        return ret;
    }
};
