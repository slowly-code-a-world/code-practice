#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

class Solution {
public:
	bool isTheSame(string tmp, string temp) {
		string t1 = tmp, t2 = temp;
		sort(t1.begin(), t1.end());
		sort(t2.begin(), t2.end());
		return t1 == t2;
	}
	bool exist(string temp, string text) {
		if (temp.size() > text.size()) return false;
		if (temp.size() == text.size()) return temp == text;
		int tempLen = temp.size(), textLen = text.size();
		for (int i = 0; i <= textLen - tempLen; i++) {
			string tmp = text.substr(i, tempLen);
			if (isTheSame(tmp, temp)) return true;
		}
		return false;
	}
	bool isTheSame2(unordered_map<char, int>&check, unordered_map<char, int>&record) {
		for (auto it = check.begin(); it!=check.end(); it++){
			if (it->second != record[it->first]) return false;
		}
		for (auto it = record.begin(); it!=record.end(); it++) {
			if (it->second != check[it->first]) return false;
		}	
		return true;
	}
	bool exist2(string temp, string text) {
		if (temp.size() >= text.size()) return false;
		if (temp.size() == text.size()) return temp == text;
		unordered_map<char, int> record, check;
		for (int i = 0; i<temp.size(); i++)
			record[temp[i]]++;
		for (int i = 0; i<temp.size(); i++) 
			check[text[i]]++;
		if (isTheSame2(check, record)) return true;
		for (int i = temp.size(); i<text.size(); i++) {
			check[text[i]]++;
			check[text[i-temp.size()]]--;
			if (isTheSame2(check, record)) return true;
		}
		return false;
	}
};

int main(void) {
	Solution S;
	cout << S.exist2("cba", "my test abc is real!") << endl;
}
