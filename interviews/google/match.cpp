/*
Given an input string S write a function which returns true if it satisfies S = nT. Basically you have to find if a given string can be represented from a substring by iterating it “n” times. n >= 2

An example would suffice –

Function should return true if

1) S = “abab”

2) S = “abcdabcd”

3) S = “abcabcabc”

4) S = “zzxzzxzzx”

Function should return false if

1) S = “abac”

2) S = “abcdabbd”

3) S = “abcabcefg”

4) S = “zzxzzyzzx”

It would be easy to understand if you can give an algo instead of saying use kmp or suffix tree or…

I came up with O(n*n) solution. Wondered how to do in O(n) 
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	bool repeated(string str) {
		if (str.size() <= 1) return false;
		int size = str.size();
		for (int len = 1; len <= size/2; len++) {
			if (size % len != 0) continue;
			int n = size / len;
			string tmp = "";
			for (int i = 0; i<n; i++)
				tmp += str.substr(0, len);
			if (tmp == str) return true; 
		}
		return false;
	}
	
	bool repeated2(string str) {
		if (str.size() <= 1) return false;
		int size = str.size();
		vector<int> record(size, 0);
		for (int i = 1; i<size; i++) {
			int last = i - 1;
			int index = record[last];
			while (index != 0) {
				if (str[index] == str[i]) { 
					record[i] = record[last] + 1;
					break;
				} else {
					last = index;
					index = record[last-1];
				}
			}
			if (index == 0 && str[i] == str[0]) 
				record[i] = 1;
		}
		int remain = size - record[size-1];
		if (remain != size && 0 == size % remain) return true;
		return false;
	}
};

int main(void) {
	Solution S; 
	vector<string> test = {"abab", "abcdabcd", "abcabcabc", "zzxzzxzzx", "abac", "abcdabbd", "abcabcefg", "zzxzzyzzx"};
	for (int i = 0; i<test.size(); i++)
		cout << S.repeated2(test[i]) << endl;
}

