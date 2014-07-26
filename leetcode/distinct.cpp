
Distinct Subsequences
Total Accepted: 11835 Total Submissions: 48272

Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3. 

class Solution {
public:
    int numDistinct(string S, string T) {
        int** status = new int*[T.size() + 1];
        for (int i = 0; i<T.size() + 1; i++) {
            status[i] = new int[S.size() + 1];
        }
        for (int i = 0; i<T.size() +1; i++) {
            for (int j = 0; j<S.size() +1; j++) {
                if (0 == i) status[i][j] = 1;
                else status[i][j] = 0;
            }
        }
        for (int i = 1; i<T.size()+1; i++) {
            for (int j = i; j<S.size()+1; j++) {
                if (T[i-1] == S[j-1]) 
                    status[i][j] = status[i][j-1] + status[i-1][j-1];
                else status[i][j] = status[i][j-1];
            }
        }
        return status[T.size()][S.size()];
    }
};
