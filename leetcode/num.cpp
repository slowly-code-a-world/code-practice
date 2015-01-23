#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(int num1, int num2) {
    string str1 = to_string(num1), str2 = to_string(num2);
    if (str1.size() <= str2.size()) {
        if (str2.substr(0, str1.size()) == str1) {
            if (str1 + str2 < str2 + str1)
                return true;
            return false;    
        }
    } else {
        if (str1.substr(0, str2.size()) == str2) {
            if (str1 + str2 < str2 + str1)
                return true;
            return false;    
        }
    }    
    return to_string(num1) < to_string(num2);
}
class Solution {
public:
    string largestNumber(vector<int> &num) {
        string ret = "";
        sort(num.begin(), num.end(), compare);
        for (int i = num.size()-1; i>=0; i--)
            ret += to_string(num[i]);
        return ret;    
    }
};
int main(void) {
	Solution S;
	vector<int> v = {128, 12};
	cout << S.largestNumber(v) << endl;
}
