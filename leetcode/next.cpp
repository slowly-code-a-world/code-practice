
Next Permutation
Total Accepted: 12015 Total Submissions: 47611

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

class Solution {
public:
    void reverse(int start, vector<int> &num) {
        int len = num.size() - start;
        for (int i = 1; i<=len/2; i++) {
            // swap num[start + i - 1] and num[num.size()- i)]
            int tmp = num[start + i -1];
            num[start+i-1] = num[num.size()-i];
            num[num.size()-i] = tmp;
        }
    }
    void nextPermutation(vector<int> &num) {
        if (num.size() <=1) return;
        int found = 0;
        int k, p;
        for (int i = num.size()-2; i>=0; i--) {
            if (num[i] < num[i+1]) {
                found =1;
                k = i;
                break;
            }
        }
        if (0 == found) {
            sort(num.begin(), num.end());
            return;
        }
        
        for (int i=num.size()-1; i>=0; i--) {
            if (num[i] > num[k]) {
                p = i;
                break;
            }
        }
        
        int tmp = num[k];
        num[k] = num[p];
        num[p] = tmp;
        reverse(k+1, num);
    }
};
