
Count and Say
Total Accepted: 11788 Total Submissions: 43898

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string. 

class Solution {
public:
    void put_back(int c, string &s) {
        string org_rev;
        int a;
        while (c > 0) {
            a = c % 10;
            c = (c-a)/10;
            org_rev += a + '0';
        }
        for (int i = org_rev.size()-1; i>=0; i--) 
            s.push_back(org_rev[i]);       
    }
    string countAndSay(int n) {
        string ret;
        if (0 == n) return ret;
        if (1 == n) {
            ret+='1';
            return ret;
        } 
        string org;
        put_back(1, org);
        int cnt;
        for (int i = 2; i<=n; i++) {
            ret.clear();
            // generate ret;
            cnt = 0;
            if (org.size() > 1) {
                int j;
                for (j = 0; j<org.size()-1; j++) {
                    cnt ++;
                    if (org[j]!=org[j+1]) {
                        put_back(cnt, ret);
                        ret+=org[j];
                        cnt = 0;
                    }
                
                }
                if (org[j]!=org[j-1]) {
                    ret+='1';
                    ret+=org[j];
                } else {
                    cnt++;
                    put_back(cnt, ret);
                    ret+=org[j];
                }
            } else {
                ret+="11";
            }
            org.clear();
            org = ret;
        }    
        return ret;
    }
};
