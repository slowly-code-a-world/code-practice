
String to Integer (atoi)
Total Accepted: 13427 Total Submissions: 92531

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

spoilers alert... click to show requirements for atoi.

Have you been asked this question in an interview? 

class Solution {
public:
    int convert(const char *str, char* left, char* right, int positive) {
        if (left == right) {
            if (*left == '0')
                return 0;
            if (1 == positive)
                return *left - '0';
            return -(*left - '0');    
        }    
        char *p = left;
        while (right!=p && '0' == *p) p++; 
        if (p == right) {
            if ('0' == *right)
                return 0;
            if (1 == positive)
                return *right - '0';
            return -(*right - '0');    
        }
        left = p;
        p = left; int len = right-left+1;
        if (len > 10) {
            if (1 == positive) return INT_MAX;
            return INT_MIN;
        } 
        
        if (10 == len) {
            if (*left > '2') {
                if (1 == positive) return INT_MAX;
                return INT_MIN;
            }
            p = left;
            long long ret = *p - '0';
            p++;    
            while (p!=right) {
                ret *= 10;
                ret+=*p - '0';
                p++;
            }
            ret*=10;
            ret+=*right - '0';
            if (1 == positive) {
                if (ret >= (long long)2147483647) return INT_MAX;
                return ret;
            } else {
                if (ret >= (long long)2147483648) return INT_MIN;
                return -ret;
            }    
        }
        
        int ret = *p - '0';
        p++;
        while (p!=right) {
            ret = 10*ret;
            ret += *p - '0';
            p++;
        }
        ret*=10;
        ret+=*right - '0';
        if (1 == positive)
            return ret;
        return -ret;    
    }
    int atoi(const char *str) {
        if (NULL == str) return 0;
        char *p = (char*)str; char* left = NULL, *right = NULL;
        int positive = 1; 
        while (' '==*p) p++;
        if ('\0' == *p) return 0;
        if ('+' == *p) p++;
        else if ('-' == *p) {
            positive = 0;
            p++;
        }
        if (*p >= '0' && *p <='9') {
            left = p;
        } else return 0;
        
        p++;
        while ('\0' != *p && *p >= '0' && *p <='9') p++;
        p--;
        right = p;
        return convert(str, left, right, positive);
    }
};
