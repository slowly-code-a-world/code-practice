
Reverse Words in a String
Total Accepted: 22822 Total Submissions: 163724

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.


class Solution {
public:
    void reverseWords(string &s) {
        if (0 == s.size()) return;
        
        stack<string> output;
        string tmp;
        int i = 0;
        while (i < s.size()) {
            while (i < s.size() && ' ' == s[i]) i++;
            if (i >=s.size()) break;
            tmp.clear();
            while (i < s.size() && ' ' != s[i]) {
                tmp.push_back(s[i]);
                i++;
            }    
            if (i>=s.size()) {
                output.push(tmp);
                break;    
            } else output.push(tmp);    
        }
        s.clear();
        if (0 == output.empty()) {
            s += output.top();
            output.pop();
        }    
        while (0 == output.empty()) {
            s += " ";
            s += output.top();
            output.pop();
        }
        
    }
};
