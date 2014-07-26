
Word Break
Total Accepted: 17766 Total Submissions: 86126

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code". 

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int *match = new int [s.size()+1];
        memset(match, 0, 4*(s.size()+1));
        for (int i = 1; i<s.size()+1; i++) {
            if (dict.find(s.substr(0, i)) != dict.end()) {
                match[i] = 1;
                continue;
            }   
            
            unordered_set<string>::iterator it;
            for (it=dict.begin(); it!=dict.end(); it++) {
                int len = (*it).size();
                if (i>=len) {
                    if (dict.find(s.substr(i-len, len))!=dict.end() && 1 == match[i-len]) {
                        match[i] = 1;
                        break;
                    }
                }
            }
        }
        return match[s.size()];
    }
};
