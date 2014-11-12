#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
using namespace std;
class checkIP {
public:
	void check(string left, string right, string target) {
		int cnt = 0;
		for (int i = 0; i<target.size(); i++) 
			if (target[i] == '.')
				cnt++;
		if (cnt != 3) {
			cout << "Invalid" << endl;
			return;
		}
		vector<int> parts;
		int start = 0;
		for (int i = 0; i<target.size(); i++) {
			if (target[i] == '.') {
				if (i - start == 0) {
					cout << "Invalid" << endl;
					return;
				}
				string tmp = target.substr(start, i - start);
				start = i + 1;
				int number = atoi(tmp.c_str());
				if (number < 0 || number > 255) {
					cout << "Invalid" << endl;
					return;
				}
				parts.push_back(number);
			}
		}
		if (target.size() - start == 0) {
			cout << "Invalid" << endl;	
			return;
		}
		string tmp = target.substr(start, target.size() - start);
		int number = atoi(tmp.c_str());
		if (number < 0 || number > 255) {
			cout << "Invalid" << endl;	
			return;
		}
		parts.push_back(number);
		vector<int> leftVec, rightVec;
		parse(left, leftVec);
		parse(right, rightVec);
		for (int i = 0; i<leftVec.size(); i++)
			cout << leftVec[i] << " ";
		cout << endl;
		for (int i = 0; i<rightVec.size(); i++)
			cout << rightVec[i] << " ";
		cout << endl;
		bool found = false;
		for (int i = 0; i<4; i++) {
			if (parts[i]<leftVec[i] || parts[i]>rightVec[i]) {
				found = true;
				break;
			}
		}
		if (found) {cout << "OutRange" << endl; return;}
		cout << "InRange" << endl;

		return;
	}
	void parse(string s, vector<int>& vec) {
		string tmp;
		int start = 0;
		for (int i = 0; i<s.size(); i++) {
			if (s[i] == '.') {
				tmp = s.substr(start, i-start);
				start = i+1;
				vec.push_back(atoi(tmp.c_str()));
			}
		}
		tmp = s.substr(start, s.size() - start);
		vec.push_back(atoi(tmp.c_str()));
	}
};

int main(void) {
	string left, right, target;
	checkIP	checker;
	while (cin >> left >> right >> target) {
		cout << left << " " << right << " " << target << endl;
		checker.check(left, right, target);
	}	
	return 0;
}
