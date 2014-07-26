
Reverse Integer
Total Accepted: 23971 Total Submissions: 59885

Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321 

class Solution {
public:
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (0 == x) return 0;
        
        int array[20], i, is_neg=0;
        for (i = 0; i<20; i++)
            array[i] = -1;
        if (x < 0) {
            x = -x;
            is_neg = 1;
        }
        i = 0;
        while (x != 0) {
            int y = x/10;
            array[i] = x - 10*y;
            i++;
            x = y;
        }
        int sum = 0;
        for (int j = 0; j<i; j++) {
            sum = 10*sum + array[j]; 
        }
        if (is_neg)
            return -sum;
        return sum;    
    }
};
