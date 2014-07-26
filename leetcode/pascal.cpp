
Pascal's Triangle
Total Accepted: 15057 Total Submissions: 47482

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]


class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int>> out;
        if (0 == numRows) 
            return out;
        for (int i = 0; i<numRows; i++) {    
            if (0 == i) {
                vector<int> tmp;
                tmp.push_back(1);
                out.push_back(tmp);
            } else if (1 == i) {
                vector<int> tmp;
                tmp.push_back(1); 
                tmp.push_back(1);
                out.push_back(tmp);
            } else {
                vector<int> last = out[i-1];
                vector<int> tmp;
                tmp.push_back(1);
                for (int i = 0; i<last.size()-1; i++) 
                    tmp.push_back(last[i] + last[i+1]);
                
                tmp.push_back(1);
                out.push_back(tmp);
            }
        }
        return out;
    }
};
