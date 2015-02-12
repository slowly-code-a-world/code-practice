/*
Given two very large strings, consisting of only digits, multiply the two strings and return the result as a string
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
// str1 = 123 * 456 = 
class Solution {
public:
	string multiplyOneDigit(char c, string &str) {
		int factor = c - '0';
		int carry = 0;
		string ret = "";
		int size = str.size();
		for (int i = size - 1; i>=0; i--) {
			int val = str[i] - '0';
			int sum = carry + val*factor;
			carry = sum / 10;
			ret.insert(ret.begin(), sum % 10 + '0');
		
		if (carry == 0) return ret;
		ret.insert(ret.begin(), carry + '0');
		return ret;
	}

	string addString(string str1, string str2) {
		if (str1 == "") return str2;
		if (str2 == "") return str1;
		string ret = "";
		int carry = 0;
		int size1 = str1.size(), size2 = str2.size();
		for (int i = 0; i<min(size1, size2); i++) {
			int val = str1[size1-1 - i] - '0' + str2[size2-1-i] - '0' + carry;
			if (val <= 9) {
				carry = 0;
				ret.insert(ret.begin(), val + '0');
			} else {
				carry = 1;
				ret.insert(ret.begin(), val - 10 + '0');
			}
		}
		if (size1 == size2) {
			if (carry == 0) return ret;
			ret.insert(ret.begin(), '1');
			return ret;
		}
		if (size1 > size2) {
			for (int i = size1 - size2 -1; i>=0; i--) {
				int val = str1[i] - '0' + carry;
				if (val <= 9) {
					carry = 0;
					ret.insert(ret.begin(), val + '0');
				} else {
					carry = 1;
					ret.insert(ret.begin(), val - 10 + '0');
				}
			}
			if (carry == 0) return ret;
			ret.insert(ret.begin(), '1');
			return ret;
		}
		for (int i = size2 - size1 - 1; i>=0; i--) {
			int val = str2[i] - '0' + carry;
			if (val <= 9) {
				carry = 0;
				ret.insert(ret.begin(), val + '0');
			} else {
				carry = 1;
				ret.insert(ret.begin(), val - 10 + '0');
			}
		}
		if (carry == 0) return ret;
		ret.insert(ret.begin(), '1');
		return ret;
	}
	void shift(string &str, int size) {
		for (int i = 0; i<size; ++i)
			str.push_back('0');
	}
	
	string multiply(string str1, string str2) {
		if (str1.size() == 0 || str2.size() == 0) return "";
		string res = "";
		for (int i = 0; i<str1.size(); i++) {
			string tmpRes = multiplyOneDigit(str1[str1.size()-1-i], str2);
			shift(tmpRes, i);
			res = addString(tmpRes, res);
		}
		return res;
	}
};

int main(void) {
	Solution S;
	cout << S.multiply("123", "56") << endl;
	cout << S.addString("1120", "168") << endl;
}
