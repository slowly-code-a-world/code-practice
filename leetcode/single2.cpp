
Single Number II
Total Accepted: 20184 Total Submissions: 60401

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

class Solution {
public:
    int singleNumber(int A[], int n) {
        int count[32];
        int result = 0;
        for (int i = 0;i < 32;++i) {
            count[i] = 0;
            for (int j = 0;j < n;++j) {
                if ((A[j] >> i) & 1) count[i] = (count[i] + 1) % 3;
            }
            if (0 != count[i])
                result |= (1 << i);
        }
        return result;
    }
};
