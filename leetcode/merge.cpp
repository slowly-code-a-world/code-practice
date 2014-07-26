
Merge Sorted Array
Total Accepted: 17940 Total Submissions: 56313

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int *C = new int[m + n];
        int i = 0, j = 0, loc = 0;
        while (i < m && j<n) {
           if (A[i] <= B[j]) {
               C[loc] = A[i];
               i++;
               loc++;
           } else  {
               C[loc] = B[j];
               j++;
               loc++;
           }
        }
        if (m == i) {
            while (j < n) {
                C[loc] = B[j];
                j++;
                loc++;
            }
        } else if (n == j) {
            while (i < m) {
                C[loc] = A[i];
                i++;
                loc++;
            }
        }
        
        for (i = 0; i< m+n; i++)
            A[i] = C[i];
        delete[] C;
    }
};
