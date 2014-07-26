
Longest Common Prefix
Total Accepted: 14173 Total Submissions: 52222

Write a function to find the longest common prefix string amongst an array of strings. 

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ret;
        if (0 == strs.size()) return ret;
        if (1 == strs.size()) return strs[0];
        int min = INT_MAX;
        for (int i = 0; i<strs.size(); i++) {
            if (0 == strs[i].size())
                return ret;
            if (strs[i].size() < min)
                min = strs[i].size();
        }
        for (int i = 0; i< min; i++) {
            int found = 0;
            for (int j = 1; j<strs.size(); j++) {
                if (strs[j][i] != strs[0][i]) {
                    found = 1;
                    break;
                }
            }
            if (0 == found)
                ret+=strs[0][i];
            else return ret;    
        }
        return ret;
        
    }
};
