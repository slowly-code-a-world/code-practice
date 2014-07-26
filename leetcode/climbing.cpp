
Climbing Stairs
Total Accepted: 18381 Total Submissions: 54980

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 

class Solution {
public:
    int climbStairs(int n) {
        
        if (0 == n) return 0;
        if (1 == n) return 1;
        if (2 == n) return 2;
    
        int ways[3];
        ways[0] = 0;
        ways[1] = 1;
        ways[2] = 2;
        for (int i = 3; i<=n; i++) {
            ways[i%3] = ways[(i-1)%3] + ways[(i-2)%3];
        }
        return ways[n%3];
    }
};
