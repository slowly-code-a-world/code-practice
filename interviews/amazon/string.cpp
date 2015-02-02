#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	int lastIndexOfString(string s1, string s2) {
		auto index = s1.rfind(s2);
		if (index == string::npos) return -1;
		return index;
	}
};

int main(void) {
	Solution S;
	cout << S.lastIndexOfString("test test", "tes") << endl;
}
