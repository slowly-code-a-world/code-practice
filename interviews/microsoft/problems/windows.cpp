#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class window {
public:
	string change(string input) {
		string ret = "";
		for (int i = 0; i<input.size(); i++) {
			if (input[i] >='A' && input[i]<='Z')
				ret+=input[i] - 'A' + 'a';
			else ret+=input[i];
		}
		return ret;
	}
	void count(string token, vector<string> &processed) {
		int totalMatch = 0, prefix = 0;
		string firstMatch; bool getFirst = false;
		string newToken = change(token);
		for (int i = 0; i<processed.size(); i++) {
			string s = change(processed[i]);
			if (newToken == s)
				totalMatch++;
			if (newToken.size() <= s.size() && newToken == s.substr(0, newToken.size())) {
				prefix++;
				if (getFirst == false) {
					firstMatch = s;
					getFirst = true;
				}
			}
		}
		cout << totalMatch<<";"<< prefix << ";"<< firstMatch << endl;
	}
};

int main(void) {
	string token, tmp;
	cin >> token;
	vector<string> processed;
	while (cin >> tmp) {
		while (tmp.size() > 0) {
			if ((tmp.back() >= 'a' && tmp.back() <= 'z') || (tmp.back() >= 'A' && tmp.back() <= 'Z')) {
				if (tmp.size() > 0)
					processed.push_back(tmp);
				break;				
			}
			tmp.pop_back();	
		 }
	}	
	window w;
	w.count(token, processed);
}
