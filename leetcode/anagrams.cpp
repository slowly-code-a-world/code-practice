
Anagrams
Total Accepted: 11933 Total Submissions: 51268

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ret;
        if (strs.size()<=1) return ret;
        vector<string> strs_ordered;
        unordered_map<string, int> map;
        for (int i = 0; i<strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            strs_ordered.push_back(tmp);
            map[tmp]++;
        }
        
        for (int i = 0; i<strs_ordered.size(); i++) {
            if (map[strs_ordered[i]] > 1) {
                ret.push_back(strs[i]);
            }
        }
        
        return ret;
    }
};
