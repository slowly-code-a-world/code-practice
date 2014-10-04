#include <iostream>
#include <string>
using namespace std;
class IdentifyingWood {
public:
	bool getCheckResult(string s, int sstart, string t, int tstart) {
		if (tstart >= t.size() && sstart <= s.size()) return true;
		bool res;
		for (int i = sstart; i<s.size(); i++) {
			if (s[i] == t[tstart]) {
				res = getCheckResult(s, i+1, t, tstart + 1);	
				if (res == true) return true;	
			}	
		}
		return false;	
	}
	string check(string s, string t) {
		if (t == "") return "Yep, it's wood.";
		if (t.size() > s.size()) return "Nope.";
		if (t.size() == s.size()) {
			if (t.compare(s) == 0) 
				return "Yep, it's wood.";
			return "Nope.";	
		}
		bool res = getCheckResult(s, 0, t, 0);
		if (res) return "Yep, it's wood.";
		return "Nope.";
			
	}
};

int main(int argc, char* argv[]) {
	IdentifyingWood test;
	cout << test.check(argv[1], argv[2]) << endl;
	return 0;
}
