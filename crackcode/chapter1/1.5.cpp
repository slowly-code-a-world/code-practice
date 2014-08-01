/*
Write a method to replace all spaces in a string with ‘%20'
*/

#include <iostream>

using namespace std;
class Solution {
public:
	void replace(string &s) {
		const string c("%20");
		for (int i = 0; i < s.size(); i++) {
			if (' ' == s[i]) s.replace(i, 1, c);
		}
	}
};

int main(void) {
	Solution S;
	string t("a b c");

	S.replace(t);
	cout << t << endl;

	return 0;
}
