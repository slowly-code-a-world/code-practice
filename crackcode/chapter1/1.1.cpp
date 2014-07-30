
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
};

int main(void) {
	class solution solu;
	cout << solu.isunique("helo") << endl; 

	return 0;
}
