
Word Break II
Total Accepted: 11942 Total Submissions: 74771

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"]. 

class Solution {
public:
    void judge(string &s, unordered_set<string> &dict, int start, vector<string> &solution, vector<string>&ret, vector<bool>&possible) {
        if (start == s.size()) {
            string XXX;
            if (1 == solution.size())
                XXX+=solution[0];
            else {
                XXX+=solution[0];
                for (int i = 1; i<solution.size(); i++) {
                    XXX+=" ";
                    XXX+=solution[i];
                }
            }    
            ret.push_back(XXX);
            return;
        }
        unordered_set<string>::iterator it;
        int size = ret.size();
        for (it = dict.begin(); it!=dict.end(); it++) {
            int len = (*it).size();
            if (0 == s.substr(start, len).compare(*it) && true == possible[start]) {
                solution.push_back(*it);
                judge(s, dict, start+len, solution, ret,possible);
                solution.pop_back();
            }
        }
        if (ret.size() == size) possible[start] = false;
    }    
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> ret;
        if (0 == s.size()) {
            if (0 != dict.size())
                return ret;
            else {
                ret.push_back("");
                return ret;
            }    
        }    
        vector<string> solution;
        vector<bool> possible(s.size()+1, true);
        judge(s, dict, 0, solution, ret, possible);
        return ret;
    }    
};
