
Roman to Integer
Total Accepted: 11867 Total Submissions: 35497

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    void RTI(string &s, int start, int &ret) {
        if (start == s.size()) return;
        if ('M' == s[start]) {
            int cnt = 0;
            for (int i = start; i<s.size(); i++) {
                if ('M' == s[i]) cnt++;
                else break;
            }
            ret+=cnt*1000;
            RTI(s, start + cnt, ret);
            return;
        }
        
        if ('C' == s[start]) {
            start++;
            if (start == s.size()) {
                ret += 100;
                return;
            }
            if ('D' == s[start]) {
                ret += 400;
                start++;
                RTI(s, start, ret);
                return;
            }
            
            if ('M' == s[start]) {
                ret += 900;
                start++;
                RTI(s, start, ret);
                return;
            }
            
            int cnt = 0;
            for (int i = start; i<s.size(); i++) {
                if ('C' == s[i]) cnt++;
                else break;
            }
            ret += (cnt+1)*100;
            RTI(s, start + cnt, ret);
            return;
        }
        
        if ('D' == s[start]) {
            start++;
            int cnt = 0;
            for (int i = start; i<s.size(); i++) {
                if ('C' == s[i]) cnt++;
                else break;
            }
            ret+=cnt*100 + 500;
            RTI(s, start + cnt, ret);
            return;
        }
        
        if ('X' == s[start]) {
            start++;
            if (start == s.size()) {
                ret+=10;
                return;
            }
            
            if ('L' == s[start]) {
                ret+=40;
                start++;
                RTI(s, start, ret);
                return;
            }
            
            if ('C' == s[start]) {
                ret+=90;
                start++;
                RTI(s, start, ret);
                return;
            }
            
            int cnt = 0;
            for (int i = start; i<s.size(); i++) {
                if ('X' == s[i]) cnt++;
                else break;
            }
            
            ret+=(cnt+1)*10;
            start += cnt;
            RTI(s, start, ret);
            return;
        }
        
        if ('L' == s[start]) {
            start++;
            int cnt = 0;
            for (int i = start; i<s.size(); i++) {
                if ('X' == s[i]) cnt++;
                else break;
            }
            ret+= 50+cnt*10;
            start+=cnt;
            RTI(s, start, ret);
            return;
        }
        
        if ('I' == s[start]) {
            start++;
            if (start == s.size()) {
                ret+=1;
                return;
            }
            if ('V' == s[start]) {
                ret+=4;
                return;
            }
            
            if ('X' == s[start]) {
                ret+=9;
                return;
            }
            
            int cnt = 0;
            for (int i = start; i<s.size(); i++) {
                if ('I' == s[i]) cnt++;
                else break;
            }
            ret+=cnt+1;
            return;
        }
        
        if ('V' == s[start]) {
            start++;
            int cnt = 0;
            for (int i = start; i<s.size(); i++) {
                if ('I' == s[i]) cnt++;
                else break;
            }
            ret+=5+cnt;
            return;
        }
    }
    int romanToInt(string s) {
        int ret = 0;
        RTI(s, 0, ret);
        return ret;
    }
};
