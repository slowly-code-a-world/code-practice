/*
Palindrome phrases | 1 point(s)

A Palindrome phrase is a string starting at the beginning of a word and ending at the end of a word that contains the same alphanumeric characters both from left to right and right to left. Given lines of text, find the largest palindrome phrase in each line.
Clarifications

An alphanumeric character is a character that is a number or a letter (punctuation and white space do not count).
For comparing letters, case should be ignored (for example, “Race Car” would be considered a palindrome phrase).
The beginning of a word is an alphanumeric character that is:
preceded by a non-alphanumeric character, or
is the first character in the line.
The end of a word is an alphanumeric character that is:
followed by a non-alphanumeric character, or
is the last character in the line.
The length of the palindrome phrase is measured by the count of the alphanumeric characters it contains (the ignored punctuation, whitespace, etc. do not count toward its length).

Input description/format

Multiple lines of text, each potentially containing a palindrome phrase.
Output description/format

One line for each line of input. Each line should be the substring that is the longest palindrome phrase found in the source line (this should be in the original casing and include any ignored characters). If no palindrome phrase is found, leave a blank line.
Example input

Dee saw a seed.
Unicode has some weird stuff in it. Do not, bob to ☃ nod.

Example output

Dee saw a seed
Do not, bob to ☃ nod


*/
#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
class Solution {
public:
	bool isTarget(char t) {
		if (t >= 'a' && t <= 'z') return true;
		if (t >= 'A' && t <= 'Z') return true;
		return false;
	}
	bool isEqual(char s1, char s2) {
		if (s1 == s2) return true;
		if (s1 >= 'A' && s1 <= 'Z') {
			s1 = s1 - 'A' + 'a';
			if (s1 == s2) return true;
			return false;
		}
		if (s1 >= 'a' && s1 <= 'z') {
			s2 = s2 - 'A' + 'a';
			if (s1 == s2) return true;
			return false;
		}	
		return false;
	}
	bool isValid(string line, int s, int e, int size) {
		if (0 == s) { 
			if (e == size - 1) return true;
			if (isTarget(line[e]) == false) return true;
			return false;
		}
		if (e == size - 1) {
			if (isTarget(line[s]) == false) return true;
			return false;
		}
		if (isTarget(line[s]) == false && isTarget(line[e]) == false)
			return true;
		return false;
	}
	int getLen(string& line, int s, int e) {
		int cnt = 0;
		for (int i = s; i<=e; i++) 
			if ((line[i]>='a' && line[i] <='z') || (line[i] >= 'A' && line[i] <='Z'))
				cnt++;
		return cnt;
	}	
	string get(string& line) {
		int size = line.size();
		vector<vector<bool>> record(size, vector<bool>(size, 0));
		for (int i = 0; i<size; i++)
			record[i][i] = true;
		for (int i = size-2; i>=0; i--) {
			for (int j = i+1; j<size; j++) {
				if (isTarget(line[i]) && isTarget(line[j])) {
					if (isEqual(line[i], line[j])&& record[i+1][j-1])
						record[i][j] = true;
				} else if (isTarget(line[i]) && !isTarget(line[j]))
					record[i][j] = record[i][j-1];
				else if (!isTarget(line[i]) && isTarget(line[j]))
					record[i][j] = record[i+1][j];
				else record[i][j] = record[i+1][j-1];
			}
		}
		int maxLen = INT_MIN, start = -1, end = -1;
		for (int i = 0; i<size; i++) {
			for (int j = i; j<size; j++) {
				if (record[i][j] && isValid(line, i, j, size)) {
					int len = getLen(line, i, j);		
					if (len > maxLen) {
						maxLen = len;
						start = i;
						end = j;
					}
				}
			}
		}
		while (start < end && isTarget(line[start]) == false)
			start++;
		while (end > start && isTarget(line[end]) == false)
			end--;
		if (start == end) {
			if (isTarget(line[start]) == false) return "";
			return line.substr(start, 1);
		}	
		return line.substr(start, end - start + 1);
	}
};

int main(void) {
	string line;
	Solution S;
	while (getline(cin, line)) 
		cout << S.get(line) << endl;
	return 0;
}
