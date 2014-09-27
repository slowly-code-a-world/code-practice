class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 1) return A[0];
        vector<int> cache, multiply;
        vector<pair<int, int>> neg_cnt;
        
        int cnt = 0, loc = -1;
        int fac = 1;
        for (int i = 0; i<n; i++) {
            if (A[i] != 0) {
                fac *= A[i];
                multiply.push_back(fac);
            } else {
                fac = 1;
                multiply.push_back(0);
            }
        }
        for (int i = 0; i < n; i++) {
            cache.push_back(A[i]);
            if (A[i] == 0) {
                neg_cnt.push_back(make_pair(0, -1));
                cnt = 0; loc = -1;
            } else if (A[i] < 0) {
                cnt++;
                if (cnt == 1) {
                    loc = i + 1;
                    neg_cnt.push_back(make_pair(cnt, loc));
                } else neg_cnt.push_back(make_pair(cnt, loc));   
            } else 
                neg_cnt.push_back(make_pair(cnt, loc));
        }

        int ret = cache[0];    
        for (int i = 1; i < cache.size(); i++) {
            if (A[i] == 0) cache[i] = 0;
            else if (A[i] > 0) {
                if (neg_cnt[i-1].first % 2 == 0) 
                    cache[i] = max(A[i] * cache[i-1], A[i]);
                else {
                    int start = neg_cnt[i-1].second;
                    cache[i] = multiply[i] / multiply[start - 1];
                }
            } else {
                if (neg_cnt[i-1].first % 2 == 0) {
                    int start = neg_cnt[i-1].second;
                    if (start != -1)
                        cache[i] = multiply[i] / multiply[start - 1];
                } else cache[i] *= multiply[i-1];
                    
            }
            ret = max(cache[i], ret);    
        }   
        return ret;
    }
};
