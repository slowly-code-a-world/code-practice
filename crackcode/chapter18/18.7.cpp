/*
Given a list of words, write a program to find the longest word made of other
words in the list.
EXAMPLE
Input: cat,
banana, dog, nana, walk, walker, dogwalker
Output: dogwalker
*/

bool compare(string s1, string s2) {
	return s1.size() > s2.size();
}
string printLongestWord(vector<string> &array) {
	unordered_map<string, bool> map;
	for (int i = 0; i < array.size(); i++)
		map[array[i]] = true;
	sort(array.begin(), array.end(), compare);
	for (int i = 0; i < array.size(); i++) {
		if (canbuild(array[i], map, true))
			return array[i];
	}
	return "";
}

bool canbuild(string s, unordered_map<string, bool> &map, bool isorig) {
	for (int i = 0; i < s.size() - 1; i++) {
		string substr = s.substr(0, i + 1);
		string second = s.substr(i + 1, s.size() - 1 - i);
		if (true == map[substr] && canbuild(second, map, false))
			return true;
	}	

	map[s] = false;
	return false;
}
