
Longest Palindromic Substring
Total Accepted: 15237 Total Submissions: 74610

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

class Solution {
public:
    bool isp(string &s, int ss, int ee)
    {
        if (ss == ee) return true;
        int start = ss, end = ee;
        while (start < end) {
            if (s[start] != s[end]) 
                return false;
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ret;
        if (0 == s.size()) return ret;
        if (1 == s.size()) return s;
        int *len = new int[1000];
        for (int i = 0; i<1000; i++) 
            len[i] = 0;
        int end = s.size() - 1;
        len[end] = 1;
        end --;
        int max = INT_MIN; int begin;
        while (end >=0) {
            if (end + 1 + len[end+1] < s.size() && s[end] == s[end+1+len[end+1]]) {
                len[end] = len[end+1] + 2;       
                if (len[end] > max) {
                    max = len[end];
                    begin = end;
                }
                end --;
            } else {
                for (int i = end+len[end+1]; i>=end+1; i--) {
                    if (isp(s, end, i)) {
                        len[end] = i - end + 1;
                        if (len[end] > max) {
                            max = len[end];
                            begin = end;
                        }
                        break;
                    }    
                }
                if (0 == len[end])
                    len[end] = 1;
                end --;    
            }
        }
        return s.substr(begin, max);
    }
};
