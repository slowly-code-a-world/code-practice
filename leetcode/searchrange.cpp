
Search for a Range
Total Accepted: 14856 Total Submissions: 54701

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 

class Solution {
public:
    int find_right(int A[], int low, int high, int target) {
        int l = low, r = high, m;
        while (l < r) {
            m = (l + r)/2;
            if (target < A[m]) {
                r = m;
            } else {
                l = m;
            }
            if (l+1 == r)
                break;
        }
        if (A[r] == target)
            return r;
        else if (A[l] == target)
            return l;
        else return -1;    
    }
    int find_left(int A[], int low, int high, int target) {
        int l = low, r = high, m;
        while (l < r) {
            m = (l + r)/2;
            if (target <= A[m]) {
                r = m;
            } else {
                l = m;
            }
            if (l + 1 == r)
                break;
        }
        if (A[l] == target)
            return l;
        else if (A[r] == target)
            return r;
        else return -1;    
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret;
        if (1 == n) {
            if (target == A[0]) {
                ret.push_back(0);
                ret.push_back(0);
                return ret;
            }
            else {
                ret.push_back(-1);
                ret.push_back(-1);
                return ret;
            }
                
        }
        int index = find_left(A, 0, n-1, target);
        if (-1 == index) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        } else {
            int ind = find_right(A, 0, n-1, target);
            ret.push_back(index);
            ret.push_back(ind);
            return ret;
        }
    }
};
