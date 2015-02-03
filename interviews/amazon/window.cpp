/*
Given a paragraph of text, write a program to find the first shortest sub-segment that contains each of the given k words at least once. A segment is said to be shorter than other if it contains less number of words
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	string convert(string &str) {
		string ret = str;
		for (int i = 0; i<ret.size(); i++) {
			if (ret[i] >= 'A' && ret[i] <= 'Z')
				ret[i] = ret[i] - 'A' + 'a';
		}
		int size = ret.size();
		if (ret[size-1] <'a' || ret[size-1]>'z')
			ret.pop_back();
		return ret;
	}
	string getMinSeg(string text, unordered_map<string, int> &dict) {
		vector<string> array;
		stringstream strem(text);
		string tmp;
		while (strem >> tmp) 
			array.push_back(tmp);
		int totalCnt = 0;
		for (auto it = dict.begin(); it!=dict.end(); it++)
			totalCnt += it->second;
		unordered_map<string, bool> record;
		int cnt = 0, start = 0, end = 0;
		int minSeg = INT_MAX, startPos = -1;
		for (end = 0; end < array.size(); end++) {
			string endStr = convert(array[end]);
			if (dict[endStr]!=0 && record[endStr] < dict[endStr])
				cnt++;
			if (cnt == totalCnt) {
				string startStr = convert(array[start]);
				while (dict[startStr] == 0 || (dict[startStr] > 0 && dict[startStr] < record[startStr])) {
					if (record[startStr] > 0) 
						record[startStr]--;
					start++;
				}
				if (end - start + 1 < minSeg) {
					minSeg = end - start + 1;
					startPos = start;
				}
			}
		}
		string ret = "";
		if (startPos == -1) return ret;
		for (int i = 0; i<minSeg; i++)
			ret+=array[startPos + i];
		return ret;
			
	}
};
