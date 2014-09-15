/*
Write a method to print the last K lines of an input file using C++.
*/

#include <iostream>
#include <fstream>
#include <vector>

class Solution {
	vector<string> getk(int k, string name) {
		ifstream input_file(name);
		vector<string> strs;
		string line; int cnt = 0;
		if (input_file.is_open()) {
			while (getline(input_file, line)) {
				cnt++;
				strs.push_back(line);
			}	
		}
		input_file.close();
		if (0 == k) return -1;
		if (strs.size() <= k) return strs;
		for (int i = 0; i<str.size() - k; i++)
			strs.erase(strs.begin());
		return strs;
	}

	vector<string> getk_v2(int k, string name) {
		ifstream input_file(name);
		vector<string> strs;
		string line; int cnt = 0;
		string* array;
		array = new string[k];
		int index = 0;
		if (input_file.is_open()) {
			while (getline(input_file, line)) {
				cnt++;
				array[index] = line;
				index = (index + 1) % k;
			}
		}

		if (cnt<=k) {
			for (int i = 0; i<cnt; i++)
				strs.push_back(array[i]);
			return strs;
		}
		
		for (int i = index; i<k; i++) 
			strs.push_back(array[i]);
		for (int i = 0; i < index; i++)
			strs.push_back(array[i]);
		return strs;
	}
};
