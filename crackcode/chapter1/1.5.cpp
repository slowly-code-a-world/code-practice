/*
Write a method to replace all spaces in a string with ‘%20'
*/

#include <iostream>

using namespace std;
class Solution {
public:
	/*O(n^2)*/	
	void replace(string &s) {
		const string c("%20");
		for (int i = 0; i < s.size(); i++) {
			if (' ' == s[i]) s.replace(i, 1, c);
		}
	}

	/*O(n) time*/
	void replace_v2(string &s) {
		int count = 0;
		for (int i = 0; i < s.size(); i++) {
			if (' ' == s[i]) count++;
		}
		if (0 == count) return;
		int size = s.size();
		s.resize(size + 2*count);
		int i = size - 1;
		int j = size + 2*count - 1;
		while (j > i) {
			if (' ' != s[i]) {
				s[j] = s[i];
				i --;
				j --;
			} else {
				s[j] = '0'; j--;
				s[j] = '2'; j--;
				s[j] = '%'; j--;
			}
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
