
Permutation Sequence
Total Accepted: 10136 Total Submissions: 46512

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

    "123"
    "132"
    "213"
    "231"
    "312"
    "321"

Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

class Solution {
public:
    void actual_get(int n, int b, int step, vector<vector<int> > &tot, vector<int> &solution, int &cnt, vector<int> &visited) {
        if (solution.size() == n-1) {
            cnt ++;
            if (cnt == b) {
                tot.push_back(solution);   
            }
            return;
        }
        
        for (int i = 0; i<n; i++) {
            if (0 == visited[i] && 0 == tot.size()) {
                visited[i] = 1;
                solution.push_back(i+1);
                actual_get(n, b, step+1, tot, solution, cnt, visited);
                solution.pop_back();
                visited[i] = 0;
            }
        }
    }
    string getPermutation(int n, int k) {
        string ret;
        if (1 == n) {
            ret.push_back('1');
            return ret;
        } 
        
        int fac = 1;
        for (int i = 1; i<= n-1; i++) {
            fac = fac*i;
        }
        vector<int> visited(n, 0);
        int a = k/fac, b = k%fac;
        if (0 == b) {
            ret.push_back(a + '0');
            visited[a-1] = 1;
            for (int i = n-1; i>=0; i--) {
                if (0 == visited[i]) 
                    ret.push_back(i+1 + '0');
            }
            return ret;
        } else {
            visited[a] = 1;
            ret.push_back(a+1+'0');
            int cnt = 0;
            vector<int> solution;
            vector<vector<int> > tot;
            actual_get(n, b, 0, tot, solution, cnt, visited);
            for (int i = 0; i<tot[0].size(); i++) {
                ret.push_back(tot[0][i] + '0');
            }
            return ret;
        }
    }
};
