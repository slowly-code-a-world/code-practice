
Restore IP Addresses
Total Accepted: 11098 Total Submissions: 54652

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 

class Solution {
public:
    int convert(string &s, int start, int end) {
        if (start == end) return s[start]-'0';
        int i = start + 1;
        int ret = s[start] - '0';
        while (i<=end) {
            ret *= 10;
            ret += s[i] - '0';
            i++;
        }
        return ret;
    }
    
    
    void get_all(string &s, int start, vector<string> &ret, string& solution, int step) {
        if (4 == step && start>=s.size()) {
            ret.push_back(solution);
            return;
        }
        int i = start;
        while (i<s.size()) {
            int val = convert(s, start, i);
            if (0 == val) {
                if (0 == step) {
                    solution += "0";
                } else solution += ".0";
                get_all(s, i+1, ret, solution, step+1);
                solution.erase(solution.end()-1);
                if (0!=step)
                    solution.erase(solution.end()-1);
                break;
            } else if (val>0 && val<256) {
                if (0!=step)
                    solution+=".";
                for (int j = start; j<=i; j++)
                    solution.push_back(s[j]);
                get_all(s, i+1, ret, solution, step+1);

                if (0!=step)
                    solution.erase(solution.end()-(i-start+2), solution.end());
                else solution.clear();
                i++;
            } else break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        if (s.size() < 4 || s.size()>12) return ret;
        string solution;
        get_all(s, 0, ret, solution, 0);
        return ret;
    }

};
