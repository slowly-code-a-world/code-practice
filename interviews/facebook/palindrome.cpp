/*
Given a string, check if it is a palindrome by ignoring spaces. E.g. race car would be a palindrome.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	bool isTarget(char c) {
		if (c >= 'a' && c <= 'z') return true;
		if (c >= 'A' && c <= 'Z') return true;
		return false;
	}
	bool isPalindrome(string str) {	
		int size = str.size();
		if (size == 0) return true;
		int start = 0, end = size - 1;
		while (start < end) {
			if (!isTarget(str[start])) 
				start++;
			if (!isTarget(str[end]))
				end--;
			if (str[start] != str[end]) return false;
			else {
				start++;
				end--;
			}
		}
		return true;
	}
};

int main(void) {
	Solution S;
	cout << S.isPalindrome("race car") << endl;
}
