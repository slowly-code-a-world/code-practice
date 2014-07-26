
Two Sum
Total Accepted: 25948 Total Submissions: 142313

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2 

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        for (int index1 = 0; index1 < numbers.size(); index1 ++) 
            for (int index2 = index1 + 1; index2 < numbers.size(); index2 ++) {
                    if (target == numbers[index1] + numbers[index2]) {
                        vector<int> retvec(2);
                        retvec[0] = index1 + 1;
                        retvec[1] = index2 + 1;
                        return retvec;    
                    }
            }
    }
};
