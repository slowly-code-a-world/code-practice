
Sqrt(x)
Total Accepted: 18099 Total Submissions: 82038

Implement int sqrt(int x).

Compute and return the square root of x.

class Solution {
public:
    int sqrt(int x) {
        if (0 == x) return 0;
        double EPS = 0.0001;
        double l = 0.0, r = x;
        double last = (l + r)/2.0, ret;
        ret = (last + x/last)/2;
        while (abs(ret - last) > EPS) {
            last = ret;
            ret = (last + x/last)/2;           
        }
        
        return ret;
        /*
        do {
            last = ret;
            ret = (last + x/last)/2;
        } while (abs(last - ret) > EPS);
        
        return ret;
        */
    }
};
