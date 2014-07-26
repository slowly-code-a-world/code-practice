
Pow(x, n)
Total Accepted: 17690 Total Submissions: 68114

Implement pow(x, n). 

class Solution {
public:
    double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int isneg = 0;
        if (n < 0) {
            isneg = 1;
            n = -n;
        }
        
        if (0 == n) return 1.0;
        if (1 == n) {
            if (0 == isneg)
                return x;
            else
                return 1/x;
        }
        if (0 == n%2) {
            double tmp = pow(x, n/2);
            if (0 == isneg)
                return tmp*tmp;
            else 
                return 1/(tmp*tmp);
        } else {
            double tmp = pow(x, (n-1)/2);
            if (0 == isneg)
                return x*tmp*tmp;
            else 
                return 1/(x*tmp*tmp);
        } 
    }
};
