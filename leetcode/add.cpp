
Add Binary
Total Accepted: 13226 Total Submissions: 51480

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". 

class Solution {
public:
    string addBinary(string a, string b) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int alen = a.length();
        int blen = b.length();
        
        if (0 == alen) return b;
        if (0 == blen) return a;
        string c;
        int min = (alen > blen)? blen:alen;
        int carray = 0;
        for (int i = 0; i < min; i++) {
            if ('1' == a[alen-1-i] && '1' == b[blen-1-i]) {
                if (1 == carray) 
                    c.insert(c.begin(),'1');
                else 
                    c.insert(c.begin(), '0');
                carray = 1;
            } else if ('0' == a[alen-1-i] && '0' == b[blen-1-i]) {
                if (1 == carray) 
                    c.insert(c.begin(), '1');
                else 
                    c.insert(c.begin(), '0');
                carray = 0;    
            } else {
                if (1 == carray) {
                    c.insert(c.begin(), '0');
                    carray = 1;
                } else {
                    c.insert(c.begin(), '1');
                    carray = 0;
                }
            }
        }
        if (alen == blen) {
            if (1 == carray) {
                c.insert(c.begin(), '1');
                return c;
            } else 
                return c;
        } else if (alen > blen) {
            for (int i = 0; i<alen - min; i++) {
                if (0 == carray)  
                    c.insert(c.begin(), a[alen-min-1-i]);
                else {
                    if ('1' == a[alen-min-1-i]) {
                        c.insert(c.begin(), '0');
                        carray = 1;
                    } else {
                        c.insert(c.begin(), '1');
                        carray = 0;
                    }
                }     
            }
            if (1 == carray)
                c.insert(c.begin(), '1');
            return c;
        } else {
            for (int i = 0; i<blen - min; i++) {
                if (0 == carray) 
                    c.insert(c.begin(), b[blen-min-1-i]);
                else {
                    if ('1' == b[blen - min-1 -i]) {
                        c.insert(c.begin(), '0');
                        carray = 1;
                    } else {
                        c.insert(c.begin(), '1');
                        carray = 0;
                    }
                }    
            }
            if (1 == carray)
                c.insert(c.begin(), '1');
            return c;
        }
    }
};
