
Multiply Strings
Total Accepted: 10297 Total Submissions: 50552

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

class Solution {
public:
    string generate(string &large, char c, int len) {
        string ret;
        int carrier = 0;
        for (int i = large.size()-1; i>=0; i--) {
            int tmp = (large[i] - '0')*(c - '0') + carrier;
            int a = tmp % 10; int b = (tmp - a)/10;
            ret.insert(ret.begin(), a + '0');
            carrier = b;
        }
        if (0!=carrier) 
            ret.insert(ret.begin(), carrier + '0');
        if (0 == len)    
            return ret;
        for (int i = 0; i<len; i++)
            ret.push_back('0');
        return ret;    
    }
    
    void add_two_string(string &ret, string &tmp) {
        string r;
        if (0 == ret.size()) {
            ret = tmp;
            return;
        }    
        int carrier = 0;
        int min = (ret.size() < tmp.size())? ret.size(): tmp.size();
        for (int i = 0; i< min; i++) {
            int sum = ret[ret.size()-1-i] - '0' + tmp[tmp.size()-1-i] - '0' + carrier;
            int a = sum % 10; int b = (sum -a) /10;
            r.insert(r.begin(), a + '0');
            carrier = b;
        }
        if (ret.size() == tmp.size()) {
            if (0!=carrier)
                r.insert(r.begin(), carrier + '0');
            ret = r;
            return;
        }
        if (ret.size() > tmp.size()) {
            for (int i = 0; i < ret.size() - min; i++) {
                int sum = ret[ret.size() - min - 1 - i] - '0' + carrier;
                int a = sum % 10; int b = (sum - a)/10;
                r.insert(r.begin(), a + '0');
                carrier = b;
            }
            if (0!=carrier)
                r.insert(r.begin(), carrier + '0');
            ret = r;
            return;
        }
        
        for (int i = 0; i<tmp.size() - min; i++) {
            int sum = tmp[tmp.size()- min -1 -i] - '0' + carrier;
            int a = sum%10; int b = (sum - a)/10;
            r.insert(r.begin(), a + '0');
            carrier = b;
        }
        if (0!=carrier)
            r.insert(r.begin(), carrier + '0');
        ret = r;
        return;
    }
    string multiply(string num1, string num2) {
        if (0 == num1.size() || 0 == num2.size()) return "";
        string small, large;
        if (num1.size() < num2.size()) {
            small = num1; large = num2;
        } else {
            small = num2; large = num1;
        }
        if (1 == small.size()) {
            if ('0' == small[0]) return "0";
            if ('1' == small[0]) return large; 
        }
        string ret;
        for (int i = small.size()-1; i>=0; i--) {
            string tmp = generate(large, small[i], small.size() - 1 - i);
            add_two_string(ret, tmp);
        }
        return ret;
    }
};
