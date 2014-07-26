
Substring with Concatenation of All Words
Total Accepted: 9732 Total Submissions: 54453

You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter). 

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        if (0 == S.size()) 
            return ret;
                
        unordered_map<string, int> map;
        unordered_map<string, int> used;
        for (int i = 0; i< L.size(); i++)
            map[L[i]] ++;
            
        int words = L.size(); int len = L[0].size();
        if (S.size() < words * len) return ret;
        int cnt = 0;
        string key;
        for (int i = 0; i<=S.size() - words*len; i++) {
            used.clear();
            bool flag = true;
            for (int j = 0; j<words; j++) {
                key = S.substr(i+len*j, len);
                if (map.find(key)==map.end()) {
                    flag = false;
                    break;
                }
                used[key]++;
                if (used[key]>map[key]) {
                    flag = false;
                    break;
                }
            }
            if (true == flag)
                ret.push_back(i);
        }
        
        return ret;
    }
};

