
Minimum Window Substring
Total Accepted: 10585 Total Submissions: 59276

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 

class Solution {
public:
    string minWindow(string S, string T) {
        if (0 == T.size()) return "";
        if (0 == S.size()) return "";
        
        unordered_map<char, int> mapt;
        for (int i = 0; i<T.size(); i++) mapt[T[i]]++; 

        vector<int> record (S.size(), 0);
        for (int i = 0; i<S.size(); i++) {
            if (mapt.find(S[i])!=mapt.end()) {
                record[i] = 1;
            }
        }
        int start = -1, current_window, cnt, min_window = INT_MAX, begin_window=-1;
        unordered_map<char, int> maps;
        
        for (int i = 0; i< S.size(); i++) {
            if (1 == record[i]) {
                start = i;
                break;
            }
        }
        if (-1 == start) return "";
        current_window = cnt = 1;
        begin_window = start;
        maps[S[start]]++;
        int loop = start+1;
        while (loop < S.size()) {
            if (mapt.find(S[loop])==mapt.end()) {
                current_window++;
                loop++;
            } else {
                maps[S[loop]]++;
                if (maps[S[loop]] > mapt[S[loop]]) {
                    current_window++;
                    loop++;
                } else {
                    current_window++;
                    cnt++;
                    if (cnt == T.size()) {
                        while (cnt == T.size()) {    
                            if (current_window < min_window) {
                                min_window = current_window;
                                begin_window = start;
                            }
                            maps[S[start]]--;
                            int tmp = start;
                            start = -1;
                            for (int i = tmp+1; i<S.size(); i++) {
                                if (1 == record[i]) {
                                    start = i;
                                    break;
                                }
                            }
                            if (-1 == start) return S.substr(begin_window, min_window);
                            current_window -= (start - tmp);
                            if (maps[S[tmp]] < mapt[S[tmp]]) {
                                cnt--;
                                break;
                            }
                        }    
                        loop++;
                    } else loop++;
                }
            }
        }
        if (INT_MAX == min_window) {
            if (cnt == T.size()) return S.substr(begin_window, 1);
            else return "";
        }
        return S.substr(begin_window, min_window);
    }
};
