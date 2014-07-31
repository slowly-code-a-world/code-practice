/*
Write a method to decide if two strings are anagrams or not.
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isanagrams(string &s1, string &s2) {
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());

		if (s1.size() != s2.size()) return false;
		for (int i = 0; i < s1.size(); i++) 
			if (s1[i] != s2[i]) return false;

		return true;
	}	
};

int main(void) {
	class Solution S;
	string s1("abcdccc"), s2("cccdcba");
		
	cout << S.isanagrams(s1, s2) << endl;		
}
