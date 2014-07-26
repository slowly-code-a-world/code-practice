
Longest Substring Without Repeating Characters
Total Accepted: 18021 Total Submissions: 82137

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size()<=1) return s.size();
        int start = 0;
        unordered_map<char, int> map;
        map[s[start]] = 0;
        int i = 1;  int max = INT_MIN;
        while (i < s.size()) {
            if (map.find(s[i]) == map.end() || map[s[i]] < start) {
                map[s[i]] = i;
                i++;
            } else {    
                int record = map[s[i]];
                if (i - start > max) 
                    max = i - start;
                map[s[i]] = i;    
                start = record + 1;
                i++;
            }
        }
        if (i - start > max)
            max = i - start;
        return max;    
    }
};
