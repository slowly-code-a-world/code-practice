
Unique Binary Search Trees
Total Accepted: 18809 Total Submissions: 52123

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3


class Solution {
public:
    int numTrees(int n) {
   
        if (n<=0) return 0;
        if (1 == n) return 1;
        if (2 == n) return 2;
   
        int *f = new int[n+1];
        for (int i = 0; i<=n; i++)
            f[i] = 0;
        f[0] = 0;
        f[1] = 1; 
        f[2] = 2;
        for (int i = 3; i<=n; i++) {
            int sum = 0;
            for (int j=1; j<i-1; j++) 
                sum+=f[j]*f[i-1-j];
            f[i] = sum+2*f[i-1];    
        }
        return f[n];
    }
};
