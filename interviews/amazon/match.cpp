/*
已知字符流包括 (,[,{ 和 ),],}，检查是否balance
解：不用数maintain，而改用一个stack，碰到匹配的就pop，否则push，空栈再碰到任
意右括号，直接return false。如果全扫完是空栈return true, 否则return false
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
	bool isBalance(string input) {
		stack<char> S;
		for (int i = 0; i<input.size(); i++) {
			if (input[i] == '(' || input[i] == '[' || input[i] == '{') 
				S.push(input[i]);
			else if (input[i] == ')') {
				if (S.empty()) return false;
				if (S.top() != '(') return false;
				S.pop();
			} else if (input[i] == ']') {
				if (S.empty()) return false;
				if (S.top() != '[') return false;
				S.pop();
			} else if (input[i] == '}') {
				if (S.empty()) return false;
				if (S.top() != '{') return false;
				S.pop();
			}
		}	
		if (S.empty()) return true;
		return false;
	}
};
