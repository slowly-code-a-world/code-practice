/*
题目是找字符串中最高频率出现的word。我先扯了idea：切分出一个个单独的word，然后用他们建立个hashtable用于查询和统计出现的频率。
*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <tr1/unordered_map>
#include <sstream>
using namespace std;
using namespace std::tr1;
class Solution {
public:
	string getLargestFreq(string text) {
		vector<string> words;
		string tmp;
		stringstream strem(text);
		unordered_map<string, int> record;
		while (getline(strem, tmp, ' ')) {
			words.push_back(tmp);
			record[tmp]++;
		}
		int maxVal = INT_MIN;
		string ret;
		for (auto it=record.begin(); it!=record.end(); it++) {
			if (it->second > maxVal) {
				maxVal = it->second;
				ret = it->first;
			}
		}
		if (maxVal == INT_MAX) return "";
		return ret;
	}
};

int main(void) {
	Solution S;
	cout << S.getLargestFreq("love test love real test cases test") << endl;
}
