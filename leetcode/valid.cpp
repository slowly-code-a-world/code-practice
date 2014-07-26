
Valid Palindrome
Total Accepted: 15599 Total Submissions: 69227

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 

class Solution {
public:
    bool judgeP(string &n) {
        if (0 == n.size()) return true;
        int l = 0, r = n.size() -1;
        if (l >= r) return true;
        while (l < r) {
            if (n[l] != n[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        if (0 == s.size()) return true;
        string n;
        for (int i = 0; i<s.size(); i++) {
            if ((s[i]>='a' && s[i]<='z') || (s[i] >= '0' && s[i] <='9') || (s[i] >='A' && s[i] <='Z')) {
                if (s[i] >='A' && s[i] <='Z') {
                    n.push_back(s[i]-'A' + 'a');
                } else 
                    n.push_back(s[i]);
            }
        }
        return judgeP(n);
    }
};
