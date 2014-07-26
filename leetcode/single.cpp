
Single Number
Total Accepted: 27791 Total Submissions: 61121

Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

class Solution {
public:
    int singleNumber(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        for (int i = 1; i < n; i++) 
            A[0] = A[0]^A[i]; 
        
        return A[0];
    }
};
