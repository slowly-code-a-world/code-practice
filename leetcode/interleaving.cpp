
Interleaving String
Total Accepted: 11433 Total Submissions: 60396

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false. 

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        if (0 == s1.size()) {
            for (int i = 0; i<s2.size(); i++) {
                if (s2[i] != s3[i])
                    return false;
            }
            return true;
        }
        
        if (0 == s2.size()) {
            for (int i = 0; i<s1.size(); i++) {
                if (s1[i] != s3[i]) 
                    return false;
            }
            return true;
        }
        
        int **M = new int*[s1.size()+1];
        for (int i = 0; i<s1.size()+1; i++) {
            M[i] = new int[s2.size()+1];
            memset(M[i], 0, 4*(s2.size()+1));
        }
        M[0][0] = 1;
        for (int j = 1; j<s2.size()+1; j++) {
            if (s3[j-1] == s2[j-1]) {
                M[0][j] |= M[0][j-1];
            } else M[0][j] = 0;    
        }
        
        for (int i = 1; i<s1.size()+1; i++) {
            if (s3[i-1] == s1[i-1]) {
                M[i][0] |= M[i-1][0];
            } else M[i][0] = 0;
        }
        
        for (int i = 1; i<s1.size()+1; i++) {
            for (int j = 1; j<s2.size()+1; j++) {
                if (s3[i+j-1] == s1[i-1] && 1 == M[i-1][j]) {
                    M[i][j] = 1;
                    continue;
                } 
                
                if (s3[i+j-1] == s2[j-1] && 1 == M[i][j-1]) 
                    M[i][j] = 1;
            }
        }
        return M[s1.size()][s2.size()];
    }
};
