/*
Given two words of equal length that are in a dictionary, write a method to
transform one word into another word by changing only one letter at a time.
The new word you get in each step must be in the dictionary.
EXAMPLE
Input: DAMP, LIKE
Output: DAMP -> LAMP -> LIMP -> LIME -> LIKE
*/

void find(unordered_set<string> &dict, string start, string end, unordered_map<string, bool> &map, vector<string> &solution, vector<vector<string> > &ret) {

	if (start == end) {
		ret.push_back(solution);
		return;
	}

	assert(start.size() >= 1 && end.size() >= 1 && start.size() == end.size());
	string key;
	for (int i = 0; i < start.size(); i++) {
		for (char c = 'A'; c <= 'Z'; c++) {
			key = start;
			if (c != start[i]) {
				key[i] = c;
				if (dict.find(key) != dict.end() && 0 == map[key] && 0 == ret.size()) {
					solution.push_back(key);
					map[key] = 1;
					find(dict, key, end, map);
					map[key] = 0;
					solution.pop_back();
				}
				
			}
						
		}
	}
}
