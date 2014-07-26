
Decode Ways
Total Accepted: 12192 Total Submissions: 77022

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2. 

class Solution {
public:
    int count(string &s, int start, unordered_map<int, int> &map) {
        if (start >= s.size()) { 
            map[s.size()] = 1;
            return 1;
        }    
        
        
        if (start == s.size()-1) { 
            if ('0' == s[start]) {
                map[s.size()-1] = 0;
                return 0;
            } else {
                map[s.size()-1] = 1;
                return 1;
            }
        }    
        
        if ('0' == s[start]) {
            map[start] = 0;
            return 0;
        }    

        int sum = (s[start]-'0')*10 + (s[start+1]-'0');
        if (sum <=26) {
            bool f1 = false, f2 = false;
            if (map.find(start+1)!=map.end()) 
                f1 = true;
            
            if (map.find(start+2)!=map.end()) 
                f2 = true;
            
            int part1, part2;
            if (f1) part1 = map[start+1];
            else { 
                part1 = count(s, start+1, map);
                map[start+1] = part1;
            }    
            
            if (f2) part2 = map[start+2];
            else {
                part2 = count(s, start+2, map);    
                map[start+2] = part2;
            }    
            
            map[start] = part1 + part2;
            return part1 + part2;
        }  else {
            bool f1 = false;
            if (map.find(start+1) !=map.end()) 
                f1 = true;
                
            int part1;    
            if (f1) part1 = map[start+1];
            else part1 = count(s, start+1, map);    
            map[start] = part1;
            return part1;
        }    
        
    }
    int numDecodings(string s) {
        if (0 == s.size()) return 0;
        if (1 == s.size()) {
            if ('0' == s[0]) return 0;
            return 1;
        }    
        unordered_map<int, int> map;
        return count(s, 0, map);
    }
};
