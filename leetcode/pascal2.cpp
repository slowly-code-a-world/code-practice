
Pascal's Triangle II
Total Accepted: 13211 Total Submissions: 43666

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space? 

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ret;
        
        if (rowIndex < 0) return ret;
        if (0 == rowIndex) {
            ret.push_back(1);
            return ret;
        } else if (1 == rowIndex) {
            ret.push_back(1);
            ret.push_back(1);
            return ret;
        } else {
            ret.push_back(1);
            ret.push_back(1);
            for (int i = 1; i < rowIndex; i++) {
                // cal the next level
                int j, tmp1, tmp2;
                tmp1 = ret[0]; 
                for (int j = 0; j < i; j++) {
                    tmp2 = ret[1+j];
                    ret[1+j] = tmp1 + tmp2;
                    tmp1 = tmp2;
                }
                ret.push_back(1);
            }
        }
        return ret;
    }
};
