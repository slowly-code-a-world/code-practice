
Plus One
Total Accepted: 15134 Total Submissions: 48397

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int>  ret;
        if (0 == digits.size()) return ret;
        int carray = 0;
        int loc = digits.size() - 1;
        int tmp = carray + digits[loc] + 1;
        while (loc>=0) {
            if (tmp >= 10) {
                carray = 1;
                digits[loc] = 0;
            } else {
                digits[loc] = tmp;
                carray = 0;
            }
            ret.insert(ret.begin(), digits[loc]);
            loc --;
            if (-1 != loc)
                tmp = carray + digits[loc];
        }
        if (1 == carray) 
            ret.insert(ret.begin(), 1);
            
        return ret;    
        
    }
};
