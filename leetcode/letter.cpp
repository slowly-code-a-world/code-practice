
Letter Combinations of a Phone Number
Total Accepted: 13014 Total Submissions: 50021

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want. 

class Solution {
public:
    void get_all(unordered_map<char, string> &map, string &digits, vector<string> &ret, int s, int e) {
        if (s > e) return;
        if (s == e) {
            if (digits[s] == '0' || digits[s] == '1')
                return;
            for (int i = 0; i<map[digits[s]].size(); i++)
                ret.push_back(map[digits[s]].substr(i, 1));
            return;    
        }
        get_all(map, digits, ret, s, e-1);
        vector<string> solution = ret;
        ret.clear();
        for (int i = 0; i<solution.size(); i++) {
            if (digits[e] == '0' || digits[e] == '1') 
                ret.push_back(solution[i]);
            else {
                for (int j = 0; j<map[digits[e]].size(); j++) {
                    ret.push_back(solution[i] + map[digits[e]].substr(j,1));
                }
            }    
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (0 == digits.size()) { 
            ret.push_back("");
            return ret;
        }    
        unordered_map<char, string> map;
        map['2'] = "abc"; map['3']="def"; map['4']="ghi";
        map['5'] = "jkl"; map['6'] = "mno"; map['7'] = "pqrs";
        map['8']="tuv"; map['9'] = "wxyz";
        get_all(map, digits, ret, 0, digits.size()-1);
        return ret;
    }
};
