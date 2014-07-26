
Word Ladder
Total Accepted: 13771 Total Submissions: 76435

Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.


class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (0 == start.compare(end)) return 1;
        if (0 == dict.size()) return 0;
        unordered_map<string, int> map;
        queue<string> store;
        if (dict.find(start)!=dict.end()) dict.erase(start);
        if (dict.find(end)!=dict.end()) dict.erase(end);
        int step = 0; string tmp;
        store.push(start);
        while (0 == store.empty()) {
            int size = store.size();
            for (int i = 0; i<size; i++) {
                for (int j = 0; j<store.front().size(); j++) {
                    tmp = store.front();
                    for (char k = 'a'; k<='z'; k++) {
                        if (tmp[j] != k) tmp[j] = k;
                        if (0 == tmp.compare(end)) return step + 2;
                        if (dict.find(tmp)!=dict.end() && 0 == map[tmp]) {
                            map[tmp] = 1;
                            store.push(tmp);
                        }
                    }
                }
                store.pop();
            }
            step++;
        }
        return 0;
    }
};
