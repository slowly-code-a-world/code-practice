
Longest Consecutive Sequence
Total Accepted: 15478 Total Submissions: 55875

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity. 

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (0 == num.size()) return 0;
        unordered_map<int, vector<int> > hashmap;
        for (int i= 0; i< num.size(); i++) {
            vector<int> tmp;
            tmp.clear();
            tmp.push_back(num[i]);
            tmp.push_back(num[i]);
            hashmap[num[i]] = tmp;
        }
        unordered_map<int, vector<int> >::iterator it;
        for (it=hashmap.begin(); it!=hashmap.end(); it++) {
            while (hashmap.find(it->second[0]-1)!=hashmap.end()) {
                hashmap.erase(it->second[0]-1);
                it->second[0]--;
            }
            while (hashmap.find(it->second[1]+1)!=hashmap.end()) {
                hashmap.erase(it->second[1]+1);
                it->second[1]++;
            }
        }
        int max = 0;
        for (it=hashmap.begin(); it!=hashmap.end(); it++) {
            if (it->second[1]-it->second[0]+1 > max) 
                max = it->second[1] - it->second[0] + 1;
        }
        return max;
    }
};
