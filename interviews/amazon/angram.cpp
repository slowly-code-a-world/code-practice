/*
Anagram
给一个数组的单词，要求输出顺序为anagram，即如果有 tea, cat, eat, 那么tea和
eat一定要挨着
*/

#include <iostream>
#include <vector>
#include <string>
#include <tr1/unordered_map>
#include <algorithm>

using namespace std;
using namespace std::tr1;
bool compare(string str1, string str2) {
	string tmp1 = str1;
	sort(tmp1.begin(), tmp1.end());
	string tmp2 = str2;
	sort(tmp2.begin(), tmp2.end());
	return tmp1 < tmp2;
}
class Solution {
public:
	vector<string> generate(vector<string> &array) {
		unordered_map<string, vector<string>> record;
		for (int i = 0; i<array.size(); i++) {
			string tmp = array[i];
			sort(tmp.begin(), tmp.end());
			record[tmp].push_back(array[i]);
		}
		vector<string> ret;
		for (auto it = record.begin(); it!=record.end(); it++) 
			ret.insert(ret.end(), it->second.begin(), it->second.end());
		return ret;
	}

	vector<string> generate2(vector<string>&array) {
		sort(array.begin(), array.end(), compare);
		return array;
	}
};
int main(void) {
	Solution S;
	vector<string> array = {"tea", "cat", "eat"};
	vector<string> ret = S.generate2(array);
	for (int i = 0; i<ret.size(); i++)
		cout << ret[i] << " ";
	cout << endl;
}
