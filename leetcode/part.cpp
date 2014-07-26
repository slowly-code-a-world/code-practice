
Palindrome Partitioning
Total Accepted: 14452 Total Submissions: 56051

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]


class Solution {
public:
    bool isp(int start, int end, string s, string &substr) {
        if (start >= end) {
            substr.push_back(s[start]);
            return true;
        }
        int l = start, r = end;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
       
        for (int i = start; i<=end; i++)
            substr.push_back(s[i]);
        return true;
    }
    void get_all(string s, int start, vector<vector<string>> &ret, vector<string> &solution) {
        if (start == s.size()) {
            ret.push_back(solution);
            return;    
        }
        for (int i = start; i < s.size(); i++) {
            string substr;
            substr.clear();
            if (true == isp(start, i, s, substr)) {
                solution.push_back(substr);
                get_all(s, i+1, ret, solution);
                solution.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        if (0 == s.size()) return ret;
        vector<string> solution;
        get_all(s, 0, ret, solution);
    
        return ret;
    }
};
