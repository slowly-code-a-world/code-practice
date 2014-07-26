
Evaluate Reverse Polish Notation
Total Accepted: 18300 Total Submissions: 92877

Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> S;
        int left, right;
        for (int i = 0; i< tokens.size(); i++) {
            if (0 == tokens[i].compare("+")) {
                right = S.top(); S.pop();
                left  = S.top(); S.pop();
                S.push(left + right);
            } else if (0 == tokens[i].compare("-")) {
                right = S.top(); S.pop();
                left  = S.top(); S.pop();
                S.push(left - right);
            } else if (0 == tokens[i].compare("*")) {
                right = S.top(); S.pop();
                left  = S.top(); S.pop();
                S.push(left * right);
            } else if (0 == tokens[i].compare("/")) {
                right = S.top(); S.pop();
                left  = S.top(); S.pop();
                S.push(left / right);
            } else {
                S.push(atoi(tokens[i].c_str()));
            }
        }
        return S.top();
    }
};
