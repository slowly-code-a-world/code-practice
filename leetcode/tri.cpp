
Triangle
Total Accepted: 14018 Total Submissions: 52749

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int len = triangle.size();
        if (0 == len) return 0;
        if (1 == len) return triangle[0][0];
        vector<int> tmp =triangle[len-1];
        for (int level = 1; level < len; level++) {
            for (int i = 0; i <= len -1 -level; i++) {
                tmp[i] = (tmp[i] < tmp[i+1])? tmp[i] + triangle[len-1-level][i]: tmp[i+1] + triangle[len-1-level][i];
            } 
        }
        return tmp[0];
    }
};
