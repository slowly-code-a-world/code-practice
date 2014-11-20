/*
Problem

Given a string, find the longest substring that contains only two unique characters. For example, given "abcbbbbcccbdddadacb", the longest substring that contains 2 unique character is "bcbbbbcccb". 
*/
#include <iostream>
#include <set>
#include <vector>
#include <climits>

using namespace std;
class Solution {
public:
	string getLongest(string target) {
		if (target.size() <= 2) return target;
		int s = 0;
		set<char> window;
		window.insert(target[0]);	
		int retLen = INT_MIN, retPos = -1;
		for (int i = 1; i<target.size(); i++) {
			if (window.find(target[i]) != window.end())
				continue;
			if (window.size() < 2) {
				window.insert(target[i]);
				continue;
			}
			window.insert(target[i]);
			if (i - s > retLen) {
				retLen = i - s;
				retPos = s;
			}
			s = i - 2;
			while (target[s] == target[i-1])
				s--;
			window.erase(target[s]);
			s++;
		}
		if (target.size() - s > retLen) {
			retLen = target.size() - s;
			retPos = s;
		}
		return target.substr(retPos, retLen);
	}
};

int main(void) {
	Solution S;
	cout << S.getLongest("abcbbbbcccbdddadacb") << endl;	
}
