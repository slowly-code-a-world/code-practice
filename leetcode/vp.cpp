
Valid Parentheses
Total Accepted: 14753 Total Submissions: 52561

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

class Solution {
public:
    bool isValid(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (1 == s.empty()) 
            return true;
        if (1 == s.length()%2)    
            return false;
        stack <char> STA;
        for (int i = 0; i < s.length(); i++) {
            if ('(' == s[i] || '{' == s[i] || '[' == s[i])    
                STA.push(s[i]);
            else {
                char a;
                if (')' == s[i]) {
                    if (STA.empty() || '(' != STA.top())
                        return false;
                    STA.pop();        
                } else if (']' == s[i]) {
                    if (STA.empty() || '[' != STA.top()) 
                        return false;  
                    STA.pop();    
                } else {
                    if (STA.empty() || '{' != STA.top())
                        return false;
                    STA.pop();    
                }
            }    
        }
        if (1 == STA.empty())
            return true;
        else
            return false;
    }
};
