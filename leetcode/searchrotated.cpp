
Search in Rotated Sorted Array
Total Accepted: 19322 Total Submissions: 67776

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

class Solution {
public:
    int search(int A[], int n, int target) {
        int mid;
        if (0 == n) return -1;
        if (1 == n) {
            if (A[0] == target) return 0;
            return -1;
        }
        if (target == A[0]) return 0;
        int s = 0, e = n-1;
        
        if (A[s] > A[e]) {
            mid = (s + e)/2;
            while (s+1 != e) {
                if (A[mid] >= A[0]) {
                    s = mid;
                } else {
                    e = mid;
                }
                mid = (s + e)/2;
            }
            if (target > A[0]) {
                e = s;
                s = 1;
            } else {
                s = e;
                e = n-1;
            }
        } else {
            s = 0; e = n-1;
        }    
        if (e == s) {
            if (target == A[s]) return s;
            return -1;
        } 
        if (s > e || target < A[s] || target > A[e]) return -1;
    
        while (s+1 !=e) {
            if (target == A[s]) return s;
            if (target == A[e]) return e;
            mid = (s + e)/2;
            if (A[mid] == target) return mid;
            else if (A[mid] > target) 
                e = mid;
            else s = mid;    
        }
        if (A[s] == target) return s;
        if (A[e] == target) return e;
        return -1;
        
    }
};
