
/*
Implement an algorithm to determine if a string has all unique characters. What if you
can not use additional data structures?

time complexity: O(n) n is the number of chars in the string
*/

#include <iostream>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

class solution {
public:
	bool isunique(string s) {
		unordered_map < char, bool > map;
		for (int i = 0; i < s.size(); i++) {
			if (true == map[s[i]]) return false;
			map[s[i]] = true;
		}
		return true;
	}
		
	/*char types cannot be larger than 32*/
	bool isunique_v2(string s) {
		int value = 0;
		for (int i = 0; i < s.size(); i++) {
			if (value & (1 << (s[i]-'a')) > 0) return false;
			value |= (1 << (s[i] - 'a'));
		}
	}

	bool isunique_v3(string s) {
		for (int i = 1; i < s.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (s[i] == s[j]) 
					return false;
			}
		}
		return true;	
	}		

	bool isunique_v4(string s) {
		sort(s.begin(), s.end());
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == s[i-1]) return false;
		}
		return true;
	}	
};

int main(void) {
	class solution solu;
	cout << solu.isunique("helo") << endl; 

	return 0;
}
