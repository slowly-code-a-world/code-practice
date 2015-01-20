#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tr1/unordered_map>
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
	void sortAnagrams(vector<string> &array) {
		sort(array.begin(), array.end(), compare);
	}
	void sortAnagrams2(vector<string> &array) {
		unordered_map<string, vector<string>> record;
		for (int i = 0; i<array.size(); i++) {
			string tmp = array[i];
			sort(tmp.begin(), tmp.end());
			record[tmp].push_back(array[i]);
		}
		vector<string> ret;
		for (auto it = record.begin(); it!=record.end(); it++)
			ret.insert(ret.end(), it->second.begin(), it->second.end());
		array = ret;
	}
};

int main(void) {
	vector<string> test = {"abc", "cba", "nimabi", "ibnima", "xyz", "aaa", "yzx"};
	Solution S;
	S.sortAnagrams2(test);
	for (int i = 0; i < test.size(); i++)
		cout << test[i] << " ";
	cout << endl;
}
