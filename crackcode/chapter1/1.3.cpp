/*
Design an algorithm and write code to remove the duplicate characters in a string
without using any additional buffer. NOTE: One or two additional variables are fine.
An extra copy of the array is not.
FOLLOW UP
Write the test cases for this method.
*/

#include <iostream>

using namespace std;

class Solution {
public:
	void removedup(string &s) {
		if (0 == s.size() || 1 == s.size()) return;
		for (int i = 1; i < s.size(); i++) {
start:			
			bool found = false;
			for (int j = 0; j < i; j++) {
				if (s[j] == s[i]) {
					found = true; 
					s.erase(s.begin() + i);
					break;
				}	
			}
			if (true == found) goto start;
		}
	}
};

int main(void) {
	class Solution s;
	string t("abcdaadadfsdf");
	
	s.removedup(t);
	cout << t << endl;

	return 0;
}
