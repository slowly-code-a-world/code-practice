
Sort Colors
Total Accepted: 18089 Total Submissions: 57291

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

class Solution {
public:
    /*
    void sortColors(int A[], int n) {
        int red = 0;
        int white = 0;
        int blue = 0;
        for (int i = 0; i<n; i++) {
            if (0 == A[i]) red++;
            else if (1 == A[i]) white++;
            else blue++;
        }
        for (int i = 0; i<red; i++)
        A[i] = 0;
        for (int i = red; i< red + white; i++)
        A[i] = 1;
        for (int i = red+ white; i<n; i++)
        A[i] = 2;
    }*/
    void sortColors(int A[], int n) {
        int h = 0;
        while (0 == A[h]) {
            if (n-1 == h) return;    
            h++;
        }
        int t = n-1;    
        while (2 == A[t]) {
            if (0 == t) return;
            t--;
        }   
        int loc = h;
        while (loc <= t) {
            if (0 == A[loc]) {
                A[loc] = A[h];
                A[h] = 0;
                while (0 == A[h]) {
                    if (n-1 == h) return;
                    h++;
                }    
                if (h == t) return;
                if (h > loc)
                    loc = h;
            } else if (1 == A[loc]) {
                loc++;
            } else {
                A[loc] = A[t];
                A[t] = 2;
                while (2 == A[t]) {
                    if (0 == t) return;
                    t--;
                }    
                if (t <= h) return;
            }
        }
    }
};
