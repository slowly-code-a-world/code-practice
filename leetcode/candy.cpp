
Candy
Total Accepted: 14102 Total Submissions: 76431

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give? 

class Solution {
public:
    int candy(vector<int> &ratings) {
        int size = ratings.size();
        if (0 == size || 1 == size) return size;
        vector<int> cnt (size, 1);
        int s = 0; int has_turn = 0;
        for (int i = 1; i<size; i++) {
            if (ratings[i] >= ratings[i-1]) {
                if (0 == has_turn) {
                    if (ratings[i] > ratings[i-1])
                        cnt[i] = 1 + cnt[i-1];
                }        
                else {
                    for (int j = s+1; j<=i-2; j++) 
                        cnt[j] = i - j;
                    cnt[s] = (cnt[s] > i-s)? cnt[s]:i-s;
                    has_turn = 0;
                    if (ratings[i] > ratings[i-1])
                        cnt[i] = 1 + cnt[i-1];
                }    
            } else {
                if (0 == has_turn) {
                    s = i-1;
                    has_turn = 1;
                }
            }    
        }
        if (has_turn) {
            for (int j = s+1; j<=size-2; j++) 
                cnt[j] = size - j;
            cnt[s] = (cnt[s] > size - s)? cnt[s] : size - s;    
        }
        int sum = 0;
        for (int i = 0; i<size; i++)
            sum+=cnt[i];
        return sum;    
    }
};
