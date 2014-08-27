/*
1.8	 Assume you have a method isSubstring which checks if one word is a substring of
    another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using
   only one call to isSubstring (i.e., “waterbottle” is a rotation of “erbottlewat”).
O(n^2)
*/

#include <iostream>

using namespace std;

class Solution {
public:
	bool isrotation(string s1, string s2) {
		if (s1.size() != s2.size()) return false;
		if (1 == s1.size() || 0 == s1.size()) return false;

		for (int i = 0; i < s1.size()-1; i++) {
			string p1, p2;
			p1.clear(); 	p2.clear();
			p1 = s1.substr(0, i + 1);
			p2 = s1.substr(i + 1, s1.size() - p1.size());
			p2.append(p1);
			if (0 == s2.compare(p2)) return true;
		}
		return false;
	}
};

int main(void) {

	Solution S;
	string s1("abcde"), s2("eafcd");

	cout << S.isrotation(s1, s2) << endl;

	return 0;	
}	
