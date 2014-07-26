
Remove Duplicates from Sorted Array II
Total Accepted: 14886 Total Submissions: 49049

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3]. 

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (0 == n) return 0;
        int i = 0;
        while (i<n) {
            int j;
            for (j = i+1; j<n; j++) {
                if (A[i] != A[j])
                    break;
            }
            if (n == j)  {
                if (j - i <= 2)
                    return n;
                else return i+2;    
            }
                
            if (j - i <=2 ) {
                i = j;
            } else {
                i = i + 2;
                for (int k = j; k<n; k++) 
                    A[i+k-j] = A[k];
                
                n = n - j + i;
            } 
        }
    }
};
