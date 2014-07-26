
First Missing Positive
Total Accepted: 13262 Total Submissions: 59400

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space. 

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if (0 == n) return 1;
        int min = INT_MAX;
        for (int i = 0; i<n; i++) {
            if (A[i] > 0 && A[i] < min) {
                min = A[i];
            }
        }
        if (min == INT_MAX || 1 != min)
            return 1;
        else {
            for (int i = 0; i<n; i++) {
                while (A[i] > 0 && A[i]<=n && A[i]!=i+1 && A[A[i]-1]!=A[i]) {
                    int tmp = A[i];
                    int loc = A[i] - 1;
                    A[i] = A[loc];
                    A[loc] = tmp;
                }
            }
            
            for (int i = 0; i<n; i++) {
                if (A[i] != i+1)
                    return i+1;
            }
            
            return n+1;
        }
    }
};


