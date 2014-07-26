
3Sum
Total Accepted: 17810 Total Submissions: 107998

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)


class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> ret;
        int size = num.size();
        if (size <=2) return ret;
        sort(num.begin(), num.end());
        unordered_map<int, int> hashmap;
        for (int i = 0; i<size; i++) 
            hashmap[num[i]] = 1;
        vector<int> solution;    
        int sum = 0;
        vector<int> visited (size, 0);
        for (int i = 0; i<size; i++) {
            if (i>0 && num[i] == num[i-1] && 0 == visited[i-1])
                continue;
            visited[i] = 1;
            solution.push_back(num[i]);
            sum+= num[i];
            for (int j = i+1; j<size; j++) {
                if (num[j] == num[j-1] && 0 == visited[j-1])
                    continue;
                visited[j] = 1;
                sum+=num[j];
                solution.push_back(num[j]);
                if (1 == hashmap[-sum] && j+1<size && -sum >= num[j+1]) {
                        solution.push_back(-sum);
                        ret.push_back(solution);
                        solution.pop_back();    
                }
                solution.pop_back();
                sum-=num[j];
                visited[j] = 0;
            }
            sum-=num[i];
            solution.pop_back();
            visited[i] = 0;
        }

        return ret;
    }
};
