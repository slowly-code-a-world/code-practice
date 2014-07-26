
Length of Last Word
Total Accepted: 14269 Total Submissions: 49187

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5. 

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (NULL == s) return 0;
        if (strlen(s) == 0) return 0;
        int len = strlen(s);
        int loc = len - 1;
        int start_loc, end_loc;
        while (' ' == s[loc] && loc >= 0) 
            loc --;
        if (loc == -1)
            return 0;
        end_loc = loc;
        if (0 == end_loc) return 1;
        
        loc = end_loc;
        while (loc >=0 && ' ' != s[loc])
            loc --;
        if (-1 == loc)
            start_loc = 0;
        else start_loc = loc + 1;
        
        return end_loc - start_loc + 1;
    }
};
