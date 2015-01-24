/*
One Edit Distance
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool oneEditDistance(string s, string t) {
		int size1 = s.size(), size2 = t.size();
		if (abs(size1 - size2) >= 2) return false;
		if (size1 == size2) {
			int cnt = 0;
			for (int i = 0; i<size1; i++) {
				if (s[i] != t[i]) 
					cnt++;
			}
			if (cnt == 1) return true;
			return false;
		}
		if (size1 > size2) {
			int cnt = 0;
			for (int i = 0; i<size2; i++) {
				if (s[i] != t[i]) {
					if (cnt == 0) {
						s.erase(s.begin() + i);
						i--;
					}
					cnt++;
				}
			}
			if (cnt == 1) return true;
			return false;
		}
		int cnt = 0;
		for (int i = 0; i<size1; i++) {
			if (s[i] != t[i]) {
				if (cnt == 0) {
					t.erase(t.begin() + i);
					i--;
				}
				cnt++;
			}
		}
		if (cnt == 1) return true;
		return false;
	}
};
