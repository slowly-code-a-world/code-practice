
Palindrome Number
Total Accepted: 16940 Total Submissions: 57907

Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x>=0 && x<=9) return true;
        int cnt = 0;
        int y = x;
        while (0!=y) {
            y /= 10;
            cnt++;
        }
        int l, r = 0, mod = 10, div = 1;
        for (int i = 1; i<=cnt-1; i++) 
            div *= 10;
        for (int i = 1; i<=cnt/2; i++) {
            l = (x/div) % 10;
            r = (x % mod -r)/(mod/10);
            if (l!=r) return false;
            div = div/10;
            mod = mod*10;
        }  
        return true;
    }
};
