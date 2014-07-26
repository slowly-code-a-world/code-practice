
Subsets
Total Accepted: 17000 Total Submissions: 61731

Given a set of distinct integers, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


class Solution {
public:
    void generate_all(vector<int> &S, int size, vector<vector<int> > &ret){
        if (1 == size) {
            vector<int> tmp;
            tmp.clear();
            ret.push_back(tmp);
            tmp.clear();
            tmp.push_back(S[0]);
            ret.push_back(tmp);
            return;
        } else {
            generate_all(S, size-1, ret);
            int loops = ret.size();
            for (int i = 0; i<loops; i++) {
                vector<int> tmp;
                tmp.clear();
                tmp = ret[i];
                tmp.push_back(S[size-1]);
                ret.push_back(tmp);
            }
        }
    }
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ret; 
        if (0 == S.size()) {
            vector<int> tmp;
            ret.push_back(tmp);
            return ret;
        } 
        sort(S.begin(), S.end());
        generate_all(S, S.size(), ret);
        return ret;
    }
};
