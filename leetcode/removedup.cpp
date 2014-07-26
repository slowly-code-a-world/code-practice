
Remove Duplicates from Sorted Array
Total Accepted: 20112 Total Submissions: 62880

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2]

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        for (int i=0; i<n; i++) {
            while (i+1<n && A[i+1] == A[i]) {
                for (int j=i; j < n-1; j++) 
                    A[j] = A[j+1];
                n -= 1;    
            }
        }
        
        return n;    
    }
};
