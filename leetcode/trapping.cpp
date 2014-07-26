
Trapping Rain Water
Total Accepted: 12298 Total Submissions: 43123

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 

class Solution {
public:
    int cal(int A[], int n, int left, int right, vector<int> &all_rights, int normal) {
         int sum = 0;
         if (1 == normal) {
                for (int i = left+1; i<right; i++)
                        sum += A[left] - A[i];
                return sum; 
         } 
              
         int max = -1; int loc = -1;
         int start = left;      
         if (all_rights.size() <=1) 
                return sum;
         for (;;) {     
                for (int i = 1; i<all_rights.size(); i++) {
                        if (all_rights[i] > start && A[all_rights[i]] > max) {
                                loc = all_rights[i];
                                max = A[all_rights[i]];
                        }
                }
                int up = min(A[start], max);
                for (int i = start + 1; i<loc; i++) 
                        if (A[i] < up) sum+=up - A[i];
                start = loc;
                max = -1; 
                if (start >= right) break;
         }              

         return sum;
    }

    int trap(int A[], int n) {
        if (n <=1) return 0;
        int left = 0, i = 1;
        while (i < n && A[i] >= A[left]) {
            left = i; i++;
        }
        if (n == i) return 0;
        vector<int> all_rights;
        int right = i, sum = 0;
        while (right < n) {
            int flag = 0;
            while (right < n && A[right] < A[left]) {
                if (A[right] <= A[right-1]) {
                    if (0 == flag) {
                        all_rights.push_back(right-1);
                        flag = 1;
                    }
                    right++;
                } else {
                    if (1 == flag) flag = 0;
                    right++;
                }
            }

            if (n == right) {
                all_rights.push_back(n-1);
                sum+=cal(A, n, left, right-1, all_rights, 0);
                return sum;
            }

            all_rights.push_back(right);
            sum+= cal(A, n, left, right, all_rights, 1);
            while (right < n && A[right] >= A[right - 1]) right++;
            if (n == right) return sum;
            left = right - 1;
            all_rights.clear();
        }

        return sum;
    }

};
