
Edit Distance
Total Accepted: 11476 Total Submissions: 45758

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

class Solution {
public:
    int getmin(int a, int b, int c) {
        if (a <=b) {
            if (a <= c) return a;
            return c;
        }
        if (c > b) return b;
        return c;    
    }
    int minDistance(string word1, string word2) {
        int **dis = new int*[word1.size() +1];
        for (int i = 0; i<word1.size() + 1; i++) {
            dis[i] = new int[word2.size()+1];
        }
        for (int i = 0; i<word1.size()+1; i++) 
            for (int j = 0; j<word2.size()+1; j++) 
                dis[i][j] = 0;
                
        for (int j = 0; j<word2.size()+1; j++) 
            dis[0][j] = j;
        for (int i = 0; i<word1.size()+1; i++)
            dis[i][0] = i;
        for (int i = 1; i<word1.size()+1; i++) {
            for (int j = 1; j<word2.size()+1; j++) {
                if (word1[i-1] == word2[j-1])
                    dis[i][j] = getmin(dis[i-1][j]+1, dis[i][j-1]+1, dis[i-1][j-1]);
                else dis[i][j] = getmin(dis[i-1][j]+1, dis[i][j-1]+1, dis[i-1][j-1]+1);    
            }
        } 
        return dis[word1.size()][word2.size()];
    }
};
