
Palindrome Partitioning II
Total Accepted: 11771 Total Submissions: 65962

Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut. 

class Solution {
public:
    int minCut(string s) {
            int len = s.size();  
            int D[len+1];  
            bool P[len][len];  
            //the worst case is cutting by each char  
            for(int i = 0; i <= len; i++)   
            D[i] = len-i;  
            for(int i = 0; i < len; i++)  
            for(int j = 0; j < len; j++)  
            P[i][j] = false;  
            for(int i = len-1; i >= 0; i--){  
                 for(int j = i; j < len; j++){  
                      if(s[i] == s[j] && (j-i<2 || P[i+1][j-1])){  
                           P[i][j] = true;  
                           D[i] = min(D[i],D[j+1]+1);  
                      }  
                 }  
            }  
            return D[0]-1;          
    }
};
