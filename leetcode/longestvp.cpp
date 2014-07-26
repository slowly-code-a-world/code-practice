
Longest Valid Parentheses
Total Accepted: 11914 Total Submissions: 62084

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 

class Solution {
public:
    int longestValidParentheses(string s) {
        const char* str = s.c_str();  
        int nMax=0;  
        const char *p = str;  
        vector<const char*> sta;  
        while(*p !='\0')  
        {  
             if(*p == '(')  
             {  
                      sta.push_back(p);                      
             }  
             else  
             {  
                  if(!sta.empty() && *sta.back()=='(')  
                  {  
                       sta.pop_back();  
                       nMax = max(nMax, p-(sta.empty()?str-1:sta.back()));  
                  }  
                  else  
                  {  
                       sta.push_back(p);  
                  }  
             }  
             p++;  
        }  
        return nMax; 
    }    
};
