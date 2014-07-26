
Generate Parentheses
Total Accepted: 15890 Total Submissions: 50906

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()" 

class Solution {
public:
    void generate_all(int left, int right, vector<string> &ret, string solution) {
        if (0 == left && 0 == right) {
            ret.push_back(solution);
            return;    
        }
        if (0 == left) {
            generate_all(0, right-1, ret, solution+')');
            return;
        }
        if (left > right) {
            return;
        }
        
        generate_all(left-1, right, ret, solution+'(');
        generate_all(left, right-1, ret, solution+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if (0 == n) return ret;
        string solution;
        generate_all(n, n, ret, solution);
        return ret;
    }
};
